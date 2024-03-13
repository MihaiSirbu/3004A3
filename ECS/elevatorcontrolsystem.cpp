#include "elevatorcontrolsystem.h"
#include "elevator.h"
#include <QDebug>

ElevatorControlSystem::ElevatorControlSystem(QObject *parent) : QObject(parent) {
                      // DONT FORGET MAKE CONNECTIONS
}

ElevatorControlSystem::~ElevatorControlSystem() {
    qDeleteAll(elevators); // This deletes all Elevator objects pointed to by the pointers in the list
    elevators.clear(); // Clear the list after deleting the objects
}

// setup
void ElevatorControlSystem::setupElevators(int numberOfElevators) {
    for(int i = 1; i < numberOfElevators+1; i++){
        addElevator(i);
        qInfo() << "Elevator " << i << " created";
    }
}
void ElevatorControlSystem::addElevator(int id) {
    Elevator *newElevator = new Elevator(id);
    this->elevators.append(newElevator);
    connect(newElevator, &Elevator::becameIdle, this, &ElevatorControlSystem::becameIdle); // for processing

    // further transfer to ui
    connect(newElevator, &Elevator::stateChange, this, &ElevatorControlSystem::stateChange);
    connect(newElevator, &Elevator::targetFloorChange, this, &ElevatorControlSystem::targetFloorChange);
    connect(newElevator, &Elevator::reachedFloor, this, &ElevatorControlSystem::elevatorArrived);
    connect(newElevator, &Elevator::doorOpened, this, &ElevatorControlSystem::elevatorDoorOpened);
    connect(newElevator, &Elevator::doorClosed, this, &ElevatorControlSystem::elevatorDoorClosed);
    connect(newElevator, &Elevator::startOpeningDoors, this, &ElevatorControlSystem::sendElevatorDoorOpening);
    connect(newElevator, &Elevator::startClosingDoors, this, &ElevatorControlSystem::sendElevatorDoorClosing);
    connect(newElevator, &Elevator::obstacleMessage, this, &ElevatorControlSystem::elevatorMessage);
    connect(newElevator, &Elevator::passengerBoarded, this, &ElevatorControlSystem::sendPassengerBoarded);
}

bool ElevatorControlSystem::removeElevator(int id) {
    for(int i = 0; i < elevators.size(); i++){
        if(elevators[i]->getElevatorId() == id){
            elevators.removeAt(i);
            return true;
        }
    }
    return false;
}


// handling signals from GUI

void ElevatorControlSystem::elevatorRequest(int starting_floor){
    qInfo() << "Elevator request received: Floor " << starting_floor << " requested.'(from ECS)";
    int elevatorId = findFreeElevator(starting_floor);
    if(elevatorId > -1){
        qInfo() << "Elevator " << elevatorId << " is ordered to move to start floor" << starting_floor << " .'(from ECS)";
        for(int i = 0; i < elevators.size(); i++){
            if(elevators[i]->getElevatorId() == elevatorId){
                elevators[i]->moveToFloor(starting_floor,true);
                break;
            }
        }

    }
}

void ElevatorControlSystem::floorRequest(int floorNumber, int elevatorNumber) {
    for(int i = 0; i < elevators.size(); i++){
        if(elevators[i]->getElevatorId() == elevatorNumber){
            elevators[i]->moveToFloor(floorNumber,false);
            break;
        }
    }
}

//doorObstacle

void ElevatorControlSystem::doorObstacle(int elevatorNumber) {
    for(int i = 0; i < elevators.size(); i++){
        if(elevators[i]->getElevatorId() == elevatorNumber){
            emit elevators[i]->obstacleDetected();
            break;
        }
    }
}

void ElevatorControlSystem::doorRequest(int elevatorID,bool isOpen){
    for(int i = 0; i < elevators.size(); i++){
        if(elevators[i]->getElevatorId() == elevatorID){
            if(isOpen){
               elevators[i]->openDoors();
            }else{
                elevators[i]->closeDoors();
            }
            break;
        }
    }
}


// relaying signals elevator -> ecs - > Gui

void ElevatorControlSystem::elevatorDoorOpened(int elevatorID){
    emit sendElevatorDoorOpened(elevatorID);
}
void ElevatorControlSystem::elevatorDoorClosed(int elevatorID){
    emit sendElevatorDoorClosed(elevatorID);
}
void ElevatorControlSystem::elevatorDoorOpening(int elevatorID){
    emit sendElevatorDoorOpening(elevatorID);
}
void ElevatorControlSystem::elevatorDoorClosing(int elevatorID){
    emit sendElevatorDoorClosing(elevatorID);
}

void ElevatorControlSystem::elevatorArrived(int floor, int elevatorID,bool target){
    emit sendElevatorArrived(floor, elevatorID, target);
}

void ElevatorControlSystem::stateChange(int elevatorID, ElevatorState state){
    emit sendStateChange(elevatorID,state);
}

void ElevatorControlSystem::targetFloorChange(int elevatorID, int targetFloor){
    emit sendTargetFloorChange(elevatorID,targetFloor);
}

void ElevatorControlSystem::elevatorMessage(int elevatorID){
    qInfo() << "Received multiple door blockage from elevator " << elevatorID;
    emit sendElevatorMessage(elevatorID);
}

void ElevatorControlSystem::passengerBoarded(int passengerWeight, int elevatorID){
    qInfo() << "Passenger boarded elevator " << elevatorID << " with weight " << passengerWeight;
    emit sendPassengerBoarded(passengerWeight, elevatorID);
}






// handling signal from elevator

// checks if there are any floors in queue, if so, it will assign the floor to the elevator
// if no floors in queue, it doesn't do anything
void ElevatorControlSystem::becameIdle(int elevatorNumber) {
    if(!floors.isEmpty()){
        int floor = floors.dequeue();
        for(int i = 0; i < elevators.size(); i++){
            if(elevators[i]->getElevatorId() == elevatorNumber){
                elevators[i]->moveToFloor(floor,true);
                return;
            }
        }
    }
}

// this will make all elevators stop and open doors at nearest floor / change elevator states
void ElevatorControlSystem::emergencyStop(QString type,int elevatorID) {
    if(type == "resolved"){
        for(int i=0; i<elevators.size(); i++){
            if(elevators[i]->getState() == ElevatorState::Fire || elevators[i]->getState() == ElevatorState::PowerOutage){ // for individual check
                qInfo() << "Emergency resolved for elevator " << elevators[i]->getElevatorId();
                elevators[i]->closeDoors(); //it will automatically change state to idle in the closedoors part
            }
        }
        return;
    }
    floors.clear(); // so if there's an emergency stop, we clear the queue of floors, meaning no more requests
    // if not resolved, we stop all elevators and open doors

    for(int i=0; i<elevators.size(); i++){

        if(type == "fire"){
            if(elevatorID == 0){ // for all
                elevators[i]->setState(ElevatorState::Fire);
            }
            else{
                if(elevators[i]->getElevatorId() == elevatorID){
                    elevators[i]->setState(ElevatorState::Fire);
                }
            }

        } else if(type == "outage"){
            if(elevatorID == 0){
                elevators[i]->setState(ElevatorState::PowerOutage);
            }
            else{
                if(elevators[i]->getElevatorId() == elevatorID){
                    elevators[i]->setState(ElevatorState::PowerOutage);
                }
            }

        } else {
            qInfo() << "Invalid emergency stop type:"<<type;
        }
        if(elevatorID == 0){
            elevators[i]->moveToFloor(elevators[i]->getCurrentFloor(),NULL);
        }
        else{
            if(elevatorID == elevators[i]->getElevatorId()){
                elevators[i]->moveToFloor(elevators[i]->getCurrentFloor(),NULL);
            }
        }

    }




}



int ElevatorControlSystem::findFreeElevator(int floor) {
    bool hasBeenFound = false;
    for(int i = 0; i < elevators.size(); i++){
        if(elevators[i]->getState() == ElevatorState::Idle){
            hasBeenFound = true;
            qInfo() << "Elevator " << elevators[i]->getElevatorId() << " is free and selected";
            return elevators[i]->getElevatorId();

        }
    }
    if(!hasBeenFound){
        //add to queue
        this->floors.enqueue(floor);
        qInfo() << "No free elevators, floor " << floor << " added to queue";
        return -1; // we add to floor queues and check later
    }
    return -2; // in case of logic error, for debugging later
}

