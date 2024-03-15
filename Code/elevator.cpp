#include "elevator.h"
#include "qdebug.h"

Elevator::Elevator(int id, QObject *parent) : QObject(parent), id(id), currentFloor(0), state(ElevatorState::Idle), doorState(DoorState::Closed) {
    connect(&moveTimer, &QTimer::timeout, this, &Elevator::onMoveOneFloor);
    connect(&closeDoorTimer, &QTimer::timeout, this, &Elevator::oncloseDoorTimerTimeout);
    connect(&autoCloseDoorsTimer, &QTimer::timeout, this, &Elevator::closeDoors);
    connect(&openDoorsTimer, &QTimer::timeout, this, &Elevator::onOpenDoorsTimerTimeout);
    connect(&obstacleTimer, &QTimer::timeout, this, &Elevator::onObstacleTimerTimeout);
    connect(this, &Elevator::obstacleDetected, this, &Elevator::obstacleDetectedSlot);
}


Elevator::~Elevator() {
    // Clean up resources if necessary
}

// GETTERS

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

ElevatorState Elevator::getState() const {
    return state;
}

int Elevator::getElevatorId() const{
    return id;
}
// setter (set change auto triggers signal to update ui)
void Elevator::setState(ElevatorState state) {
    this->state = state;
    emit stateChange(getElevatorId(), getState());
}






// when receiving a command from ECS
void Elevator::moveToFloor(int floor, bool isPickupRequest) {
    if (getState() == ElevatorState::PowerOutage || getState() == ElevatorState::Fire){ //if we are in emergency
        openDoors();
    }
    else{

        targetFloor = floor;
        emit targetFloorChange(getElevatorId(), targetFloor);

        if (isPickupRequest) {
            // This request is to pick up a passenger.

            setState(ElevatorState::MovingToPickupRequest);

        } else {
            // This request is from a passenger inside the elevator.
            setState(ElevatorState::MovingToRequestedFloor);
        }
        qInfo() << "State changed: Elevator " << getElevatorId() << " is now " << elevatorStateToString(getState());


        // Only log and start moving if the doors are not open.
        if (doorState != DoorState::Open) {
            qInfo() << "Elevator " << getElevatorId() << " requested to move to floor " << floor << " from floor " << currentFloor << "from Elevator.cpp";
            startMoving();
        }
    }

}

QString Elevator::elevatorStateToString(ElevatorState state) {
    switch (state) {
    case ElevatorState::Idle:
        return "Idle";
    case ElevatorState::MovingToRequestedFloor:
        return "Moving to Requested Floor";
    case ElevatorState::MovingToPickupRequest:
        return "Moving to Pickup Request";
    default:
        return "Unknown State";
    }
}



// Moving Logic
void Elevator::onMoveOneFloor() { // essentially this function triggers everytime the timer times out
    if (getState() == ElevatorState::PowerOutage || getState() == ElevatorState::Fire) {
        moveTimer.stop(); //if emergency, we don't move anymore
        return;
    }

    if (currentFloor < targetFloor) {
        currentFloor++;
    } else if (currentFloor > targetFloor) {
        currentFloor--;
    }




    // Stop the timer if the elevator has reached the target floor
    if (currentFloor == targetFloor) {
        emit reachedFloor(currentFloor,getElevatorId(),true);
        qInfo() << "Elevator " << getElevatorId() << " reached TARGET floor " << currentFloor << " from Elevator.cpp";

        moveTimer.stop();
        openDoors();
    }
    else{
        emit reachedFloor(currentFloor,getElevatorId(),false);
    }


}

void Elevator::startMoving() {
    if (currentFloor != targetFloor) {
        moveTimer.start(3000); // 3s/ floor
    }
}
// passenger boarding/unboarding for overloaded

void Elevator::boardPassenger() {
    if(this->weight != 0){
        return;
    }
    emit passengerBoarded(passengerWeight, getElevatorId());
    this->weight += Elevator::passengerWeight;
    if (this->weight >= 300) {
        setState(ElevatorState::Overloaded);
    }
}

void Elevator::unboardPassenger() {
    emit passengerBoarded(0, getElevatorId());
    this->weight -= Elevator::passengerWeight;
    if (this->weight < 300) {
        setState(ElevatorState::Idle);
    }
}



// Door logic

void Elevator::openDoors() {
    if(doorState == DoorState::Open && !onObstacleDetected){ // if doors are already open, do nothing
        return;
    }
    emit startOpeningDoors(getElevatorId());
    ringBell(); // Ring the bell when the doors open
    openDoorsTimer.start(3000); // 3s to open the doors


}

void Elevator::onOpenDoorsTimerTimeout() {//ie fully open
    openDoorsTimer.stop();
    doorState = DoorState::Open;
    emit doorOpened(getElevatorId());// notify ecs (which will tell the ui )
    if(getState() == ElevatorState::MovingToPickupRequest){
        boardPassenger();
        if(getState() == ElevatorState::Overloaded){
            return;
        }
    }
    else if(getState() == ElevatorState::MovingToRequestedFloor){
        unboardPassenger();
    }
    if (getState() == ElevatorState::Fire || getState() == ElevatorState::PowerOutage) {
        // If we are in emergency, keep the doors open
        return;
    }
    autoCloseDoorsTimer.start(10000); // 10s to close the doors automatically
}

void Elevator::onAutoCloseDoorsTimerTimeout() {
    autoCloseDoorsTimer.stop();
    closeDoors();

}

// Obstacle detection
void Elevator::obstacleDetectedSlot() {
    qInfo() << "Obstacle detected in elevator " << getElevatorId();
    if(obstructionCount == 0){
        obstructionCount = 1;
        obstacleTimer.start(40000); // 40s countdown, if it runs out and we have 3 obstacles, send alert
        qInfo() << "Obstacle timer started, obstruction count"<< obstructionCount;
    }
    else{
        obstructionCount += 1;
        qInfo() << "Obstruction count again, now: "<<obstructionCount;
    }
    onObstacleDetected = true;
    autoCloseDoorsTimer.stop();
    openDoorsTimer.stop();
    closeDoorTimer.stop();
    openDoors();// restart the open/close door loop

}

void Elevator::onObstacleTimerTimeout() {
    qInfo() << "obstruction Timer ran out, obstruction count"<< obstructionCount;
    obstacleTimer.stop();
    if(obstructionCount >= 3){
        emit obstacleMessage(getElevatorId());
    }
    obstructionCount = 0;
}




void Elevator::closeDoors() {
    if(doorState == DoorState::Closed){ // if doors are already closed, do nothing, this is good for the button that humans might press
        return;
    }
    autoCloseDoorsTimer.stop();
    emit startClosingDoors(getElevatorId());
    ringBell(); // Ring the bell when the doors close
    onObstacleDetected = false; // Reset the flag every time we attempt to close the doors
    closeDoorTimer.start(5000); // 5s to close the doors
}



void Elevator::ringBell() {
    // will have to output to console
}

void Elevator::oncloseDoorTimerTimeout() {
    closeDoorTimer.stop();
    if (onObstacleDetected) {
        // Obstacle detected, abort closing doors and reopen
        openDoors();
    } else {
        // No obstacle detected, close the doors fully
        obstacleTimer.stop(); // in case the timer was running
        // ... complete the door closing process ...
        emit doorClosed(getElevatorId());
        doorState = DoorState::Closed;
        if(state == ElevatorState::MovingToPickupRequest){ // so we just picked up a new person
            startMoving();
        }

        if(state == ElevatorState::MovingToRequestedFloor || state == ElevatorState::Fire || state == ElevatorState::PowerOutage){ // we just dropped off the person or we just resolved the emergency situations
            setState(ElevatorState::Idle);
            qInfo() << "State changed: Elevator " << getElevatorId() << " is now " << elevatorStateToString(getState());
            emit becameIdle(getElevatorId());
        }





    }

}









