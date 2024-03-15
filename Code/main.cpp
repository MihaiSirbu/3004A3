#include <QApplication>
#include "mainwindow.h"
#include "elevatorcontrolsystem.h"



// Forward declaration
void makeConnections(ElevatorControlSystem &ecs, MainWindow &mainWindow);




int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    ElevatorControlSystem ecs;
    ecs.setupElevators(3); //add 3 elevators , you can choose the number of elevators you want
    makeConnections(ecs, mainWindow);


    mainWindow.show();
    return app.exec();
}

void makeConnections(ElevatorControlSystem &ecs, MainWindow &mainWindow) {
    //send mainwindow-> ECS | elevator request
    QObject::connect(&mainWindow, &MainWindow::sendElevatorRequest,&ecs, &ElevatorControlSystem::elevatorRequest);
    QObject::connect(&mainWindow, &MainWindow::sendFloorRequest,&ecs, &ElevatorControlSystem::floorRequest);
    //send mainwindow-> ECS | door Obstacles
    QObject::connect(&mainWindow, &MainWindow::doorObstacle,&ecs, &ElevatorControlSystem::doorObstacle);
    //send mainwindow-> ECS | emergency stop
    QObject::connect(&mainWindow, &MainWindow::emergencyStop,&ecs, &ElevatorControlSystem::emergencyStop);
    QObject::connect(&mainWindow, &MainWindow::doorRequest,&ecs, &ElevatorControlSystem::doorRequest);



    //send ECS->mainwindow
    QObject::connect(&ecs, &ElevatorControlSystem::sendTargetFloorChange,&mainWindow, &MainWindow::receiveTargetFloorChange);
    QObject::connect(&ecs, &ElevatorControlSystem::sendStateChange,&mainWindow, &MainWindow::receiveStateChange);
    QObject::connect(&ecs, &ElevatorControlSystem::sendElevatorArrived,&mainWindow, &MainWindow::receiveElevatorArrived);
    QObject::connect(&ecs, &ElevatorControlSystem::sendElevatorDoorOpened,&mainWindow, &MainWindow::receiveElevatorDoorOpened);
    QObject::connect(&ecs, &ElevatorControlSystem::sendElevatorDoorClosed,&mainWindow, &MainWindow::receiveElevatorDoorClosed);
    QObject::connect(&ecs, &ElevatorControlSystem::sendElevatorDoorOpening,&mainWindow, &MainWindow::receiveElevatorDoorOpening);
    QObject::connect(&ecs, &ElevatorControlSystem::sendElevatorDoorClosing,&mainWindow, &MainWindow::receiveElevatorDoorClosing);
    QObject::connect(&ecs, &ElevatorControlSystem::sendElevatorMessage,&mainWindow, &MainWindow::receiveElevatorMessage);
    QObject::connect(&ecs, &ElevatorControlSystem::sendPassengerBoarded,&mainWindow, &MainWindow::receivePassengerBoarded);
}


