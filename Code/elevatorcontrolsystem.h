#ifndef ELEVATORCONTROLSYSTEM_H
#define ELEVATORCONTROLSYSTEM_H

#include <QObject>
#include <QList>
#include <elevator.h>
#include <QQueue>

class ElevatorControlSystem : public QObject
{
    Q_OBJECT
public:
    explicit ElevatorControlSystem(QObject *parent = nullptr);
    ~ElevatorControlSystem();



    void setupElevators(int numberOfElevators);


signals:
    // to mainwindow
    void sendElevatorArrived(int floor,int elevatorID,bool target);

    void sendStateChange(int elevatorID, ElevatorState state);

    void sendElevatorDoorOpening(int elevatorID);
    void sendElevatorDoorOpened(int elevatorID);
    void sendElevatorDoorClosing(int elevatorID);
    void sendElevatorDoorClosed(int elevatorID);
    void sendTargetFloorChange(int elevatorID, int targetFloor);
    void sendElevatorMessage(int elevatorID);
    void sendPassengerBoarded(int passengerWeight,int elevatorID);


private:
    QList<Elevator*> elevators; // List to hold all elevator instances
    QQueue<int> floors; // List to hold all floor requested
    void addElevator(int id);
    bool removeElevator(int id);
    int findFreeElevator(int floor);

public slots:
    // from mainwindow
    void elevatorRequest(int starting_floor);
    void floorRequest(int floorNumber,int elevatorNumber);
    void doorObstacle(int elevatorNumber);
    void emergencyStop(QString type, int elevatorID);
    void doorRequest(int elevatorID,bool isOpen);

private slots:

    // from elevator
    void becameIdle(int elevatorNumber);
    void elevatorArrived(int floor, int elevatorID,bool target);
    void stateChange(int elevatorID, ElevatorState state);
    void targetFloorChange(int elevatorID, int targetFloor);
    void elevatorMessage(int elevatorID);
    void passengerBoarded(int passengerWeight, int ElevatorId);


    void elevatorDoorOpened(int elevatorID);
    void elevatorDoorClosed(int elevatorID);
    void elevatorDoorOpening(int elevatorID);
    void elevatorDoorClosing(int elevatorID);






};

#endif // ELEVATORCONTROLSYSTEM_H
