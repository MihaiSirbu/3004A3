#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QTimer>

enum class ElevatorState {
    Idle,
    MovingToRequestedFloor,
    MovingToPickupRequest,
    Fire,
    PowerOutage,
    Overloaded
};



enum class DoorState {
    Open,
    Closed
};

class Elevator : public QObject {
    Q_OBJECT
public:
    explicit Elevator(int id, QObject *parent = nullptr);
    ~Elevator();

    void moveToFloor(int floor,bool isPickupRequest);
    void openDoors();
    void ringBell();

    ElevatorState getState() const;
    void setState(ElevatorState state);
    int getCurrentFloor() const;
    int getElevatorId() const;


signals:

    // send to itself
    void obstacleDetected();
    void obstacleMessage(int elevatorID);
    // to send to ECS
    void startOpeningDoors(int elevatorID);
    void startClosingDoors(int elevatorID);
    void doorClosed(int elevatorID);
    void doorOpened(int elevatorID);

    void becameIdle(int elevatorID);
    void reachedFloor(int floor, int elevatorID,bool target);

    void stateChange(int elevatorID, ElevatorState state);
    void targetFloorChange(int elevatorID, int targetFloor);
    void passengerBoarded(int passengerWeight, int ElevatorId);



public slots:
    void obstacleDetectedSlot();
    void closeDoors();

private:
    int obstructionCount = 0;
    int weight = 0;
    QString elevatorStateToString(ElevatorState state);
    void boardPassenger();
    void unboardPassenger();
    int passengerWeight = 70;
    void startMoving();
    int id;
    int currentFloor;
    int targetFloor;
    QTimer moveTimer;
    QTimer obstacleTimer;
    QTimer closeDoorTimer;
    QTimer autoCloseDoorsTimer;
    QTimer openDoorsTimer;
    ElevatorState state;
    DoorState doorState;
    bool onObstacleDetected = false;


    // functions
    void checkAndCloseDoors();

    private slots:
        void onOpenDoorsTimerTimeout();
        void onAutoCloseDoorsTimerTimeout();
        void oncloseDoorTimerTimeout();
        void onMoveOneFloor();
        void onObstacleTimerTimeout();
};

#endif // ELEVATOR_H
