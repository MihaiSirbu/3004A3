#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <elevator.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendElevatorRequest(int starting_floor);
    void sendFloorRequest(int floorNumber,int elevatorNumber);
    void doorObstacle(int elevatorNumber);
    void emergencyStop(QString type,int elevatorID);
    void doorRequest(int elevatorID, bool toOpen);


private:
    Ui::MainWindow *ui;
    void printToConsole(QString text);
    void printToElevatorMessagingSystem(int elevatorNb, QString text);
    int helpRequestState;
    QTimer emergencyCallTimer;
private slots:
    void receiveElevatorRequest(int starting_floor,int passengerBtnNb);
    void receiveFloorRequest(int floorNumber,int elevatorNumber);
    void helpRequested(int elevatorID);
    void resolveHelpRequest();
    void onEmergencyCallTimerTimeout();
public slots:
    void receiveTargetFloorChange(int elevatorID, int targetFloor);
    void receiveStateChange(int elevatorID, ElevatorState state);
    void receiveElevatorArrived(int floor, int elevatorID,bool target);
    void receiveElevatorDoorOpened(int elevatorID);
    void receiveElevatorDoorClosed(int elevatorID);
    void receiveElevatorDoorOpening(int elevatorID);
    void receiveElevatorDoorClosing(int elevatorID);
    void receiveElevatorMessage(int elevatorID);
    void receivePassengerBoarded(int passengerWeight,int elevatorID);




};
#endif // MAINWINDOW_H
