#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    // connecting all the buttons

    // Elevator Requests

    // Passenger 1
    connect(ui->FLOORDOWN_1, &QPushButton::clicked, this, [this]() {
        receiveElevatorRequest(ui->SF_P1_Box->currentText().toInt(),1);
    });

    connect(ui->FLOORUP_1, &QPushButton::clicked, this, [this]() {
        receiveElevatorRequest(ui->SF_P1_Box->currentText().toInt(),2);
    });

    // Passenger 2
    connect(ui->FLOORDOWN_2, &QPushButton::clicked, this, [this]() {
        receiveElevatorRequest(ui->SF_P2_Box->currentText().toInt(),3);
    });

    connect(ui->FLOORUP_2, &QPushButton::clicked, this, [this]() {
        receiveElevatorRequest(ui->SF_P2_Box->currentText().toInt(),4);
    });

    // Passenger 3
    connect(ui->FLOORDOWN_3, &QPushButton::clicked, this, [this]() {
        receiveElevatorRequest(ui->SF_P3_Box->currentText().toInt(),5);
    });

    connect(ui->FLOORUP_3, &QPushButton::clicked, this, [this]() {
        receiveElevatorRequest(ui->SF_P3_Box->currentText().toInt(),6);
    });


    // Floor Requests

    // INSIDE ELEVATOR PANEL
    // Passenger 1
    //btn 1
    connect(ui->ebtn1_1, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(1, 1); // ebtn1_1 means receiveFloorRequest will have a argument of 1, and then the elevatorNb
    });
    //btn 2
    connect(ui->ebtn2_1, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(2, 1);
    });
    //btn 3
    connect(ui->ebtn3_1, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(3, 1);
    });
    //btn 4
    connect(ui->ebtn4_1, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(4,1);
    });
    //btn 5
    connect(ui->ebtn5_1, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(5, 1);
    });
    //btn 6
    connect(ui->ebtn6_1, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(6, 1);
    });
    //btn 7
    connect(ui->ebtn7_1, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(7, 1);
    });



    //Passenger 2
    //btn 1
    connect(ui->ebtn1_2, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(1, 2);
    });
    //btn 2
    connect(ui->ebtn2_2, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(2, 2);
    });
    //btn 3
    connect(ui->ebtn3_2, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(3, 2);
    });
    //btn 4
    connect(ui->ebtn4_2, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(4, 2);
    });
    //btn 5
    connect(ui->ebtn5_2, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(5, 2);
    });
    //btn 6
    connect(ui->ebtn6_2, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(6, 2);
    });
    //btn 7
    connect(ui->ebtn7_2, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(7, 2);
    });


    // Passenger 3
    // btn 1
    connect(ui->ebtn1_3, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(1, 3);
    });
    // btn 2
    connect(ui->ebtn2_3, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(2, 3);
    });
    // btn 3
    connect(ui->ebtn3_3, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(3, 3);
    });
    // btn 4
    connect(ui->ebtn4_3, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(4, 3);
    });
    // btn 5
    connect(ui->ebtn5_3, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(5, 3);
    });
    // btn 6
    connect(ui->ebtn6_3, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(6, 3);
    });
    // btn 7
    connect(ui->ebtn7_3, &QPushButton::clicked, this, [this]() {
        receiveFloorRequest(7, 3);
    });

    // OPEN AND CLOSE DOORS ALL PASSENGERS

    connect(ui->OpenDoorsBtn_1, &QPushButton::clicked, this, [this]() {
        emit doorRequest(1,true);
    });
    connect(ui->CloseDoorsBtn_1, &QPushButton::clicked, this, [this]() {
        emit doorRequest(1,false);
    });
    connect(ui->OpenDoorsBtn_2, &QPushButton::clicked, this, [this]() {
        emit doorRequest(2,true);
    });
    connect(ui->CloseDoorsBtn_2, &QPushButton::clicked, this, [this]() {
        emit doorRequest(2,false);
    });
    connect(ui->OpenDoorsBtn_3, &QPushButton::clicked, this, [this]() {
        emit doorRequest(3,true);
    });
    connect(ui->CloseDoorsBtn_3, &QPushButton::clicked, this, [this]() {
        emit doorRequest(3,false);
    });


    //BLOCK DOORS
    connect(ui->BlockDoorBtn_1, &QPushButton::clicked, this, [this]() {
        emit doorObstacle(1);
        ui->MsgSystem1->setText("Door Obstacle Detected");
    });
    connect(ui->BlockDoorBtn_2, &QPushButton::clicked, this, [this]() {
        emit doorObstacle(2);
        ui->MsgSystem2->setText("Door Obstacle Detected");

    });
    connect(ui->BlockDoorBtn_3, &QPushButton::clicked, this, [this]() {
        emit doorObstacle(3);
        ui->MsgSystem3->setText("Door Obstacle Detected");
    });

    // FIRE BUTTONS

    connect(ui->fireBtn1, &QPushButton::clicked, this, [this]() {
        emit emergencyStop("fire",1);
        ui->fireBtn1->setStyleSheet("background-color: red");
        ui->MsgSystem1->setText("Fire Alarm Activated");
    });
    connect(ui->fireBtn2, &QPushButton::clicked, this, [this]() {
        emit emergencyStop("fire",2);
        ui->fireBtn2->setStyleSheet("background-color: red");
        ui->MsgSystem2->setText("Fire Alarm Activated");
    });
    connect(ui->fireBtn3, &QPushButton::clicked, this, [this]() {
        emit emergencyStop("fire",3);
        ui->fireBtn3->setStyleSheet("background-color: red");
        ui->MsgSystem3->setText("Fire Alarm Activated");
    });

    // HELP BUTTONS
    connect(ui->HelpBtn_1, &QPushButton::clicked, this, [this]() {
        helpRequested(1);
    });
    connect(ui->HelpBtn_2, &QPushButton::clicked, this, [this]() {
        helpRequested(2);
    });
    connect(ui->HelpBtn_3, &QPushButton::clicked, this, [this]() {
        helpRequested(3);
    });
    //help timer
    connect(&emergencyCallTimer, &QTimer::timeout, this, &MainWindow::onEmergencyCallTimerTimeout);

    // ADMIN PANEL

    //FIRE
    connect(ui->AdminFireBtn, &QPushButton::clicked, this, [this]() {
        emit emergencyStop("fire",0);
        ui->AdminFireBtn->setStyleSheet("background-color: red");
        for (int i = 1; i <= 3; i++) {
            printToElevatorMessagingSystem(i, "Fire Emergency");
        }

    });
    //OUTAGE
    connect(ui->AdminOutageBtn, &QPushButton::clicked, this, [this]() {
        emit emergencyStop("outage",0);
        ui->AdminOutageBtn->setStyleSheet("background-color: red");
        for (int i = 1; i <= 3; i++) {
            printToElevatorMessagingSystem(i, "Power Outage Emergency");
        }

    });
    //RESOLVED
    connect(ui->AdminResolvedBtn, &QPushButton::clicked, this, [this]() {
        if(ui->AdminFireBtn->styleSheet() == "background-color: red" || ui->AdminOutageBtn->styleSheet() == "background-color: red"){
            emit emergencyStop("resolved",0);
            ui->AdminFireBtn->setStyleSheet("background-color: white");
            ui->AdminOutageBtn->setStyleSheet("background-color: white");
            for (int i = 1; i <= 3; i++) {
                printToElevatorMessagingSystem(i, "Emergency Resolved");
            }
        }
        else if(ui->fireBtn1->styleSheet() == "background-color: red"){
            emit emergencyStop("resolved",1);
            ui->fireBtn1->setStyleSheet("background-color: white");
            printToElevatorMessagingSystem(1, "Emergency Resolved");
        }
        else if(ui->fireBtn2->styleSheet() == "background-color: red"){
            emit emergencyStop("resolved",2);
            ui->fireBtn2->setStyleSheet("background-color: white");
            printToElevatorMessagingSystem(2, "Emergency Resolved");
        }
        else if(ui->fireBtn3->styleSheet() == "background-color: red"){
            emit emergencyStop("resolved",3);
            ui->fireBtn3->setStyleSheet("background-color: white");
            printToElevatorMessagingSystem(3, "Emergency Resolved");
        }

    });

    //HELP
    connect(ui->AdminHelpBtn, &QPushButton::clicked, this, [this]() {
        resolveHelpRequest();
    });



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printToConsole(QString text) // ease of use
{
    ui->ConsoleLog->append(text);
}

void MainWindow::printToElevatorMessagingSystem(int elevatorNb, QString text)
{
    switch (elevatorNb) {
    case 1:
        ui->MsgSystem1->setText(text);
        break;
    case 2:
        ui->MsgSystem2->setText(text);
        break;
    case 3:
        ui->MsgSystem3->setText(text);
        break;
    }
}

// sends the signals from the GUI to the ECS for processing
void MainWindow::receiveElevatorRequest(int starting_floor, int passengerBtnNb)
{
    emit sendElevatorRequest(starting_floor);
    //illuminate button
    switch (passengerBtnNb) {
    case 1:
        ui->FLOORDOWN_1->setStyleSheet("background-color: green");
        break;
    case 2:
        ui->FLOORUP_1->setStyleSheet("background-color: green");
        break;
    case 3:
        ui->FLOORDOWN_2->setStyleSheet("background-color: green");
        break;
    case 4:
        ui->FLOORUP_2->setStyleSheet("background-color: green");
        break;
    case 5:
        ui->FLOORDOWN_3->setStyleSheet("background-color: green");
        break;
    case 6:
        ui->FLOORUP_3->setStyleSheet("background-color: green");
        break;
}
}


void MainWindow::receiveFloorRequest(int floorNumber,int elevatorNumber)
{
    emit sendFloorRequest(floorNumber,elevatorNumber);
    qInfo() << "from mainwindow inside elevator: " << elevatorNumber << " to floor: " << floorNumber;
}


void MainWindow::helpRequested(int elevatorID)
{
    if(elevatorID == 1){
        ui->HelpBtn_1->setStyleSheet("background-color: yellow");
        helpRequestState = 1;
    }
    else if(elevatorID == 2){
        ui->HelpBtn_2->setStyleSheet("background-color: yellow");
        helpRequestState = 1;
    }
    else if(elevatorID == 3){
        ui->HelpBtn_3->setStyleSheet("background-color: yellow");
        helpRequestState = 1;
    }
    emergencyCallTimer.start(5000); //5s timer
}

void MainWindow::resolveHelpRequest()
{
    emergencyCallTimer.stop();
    if(helpRequestState == 1){
        helpRequestState = 0;
        if(ui->HelpBtn_1->styleSheet() == "background-color: yellow"){
            ui->HelpBtn_1->setStyleSheet("background-color: white");
            printToElevatorMessagingSystem(1, "Connected to Building Safety");
        }
        if(ui->HelpBtn_2->styleSheet() == "background-color: yellow"){
            ui->HelpBtn_2->setStyleSheet("background-color: white");
            printToElevatorMessagingSystem(2, "Connected to Building Safety");
        }
        if(ui->HelpBtn_3->styleSheet() == "background-color: yellow"){
            ui->HelpBtn_3->setStyleSheet("background-color: white");
            printToElevatorMessagingSystem(3, "Connected to Building Safety");
        }
    }
}

void MainWindow::onEmergencyCallTimerTimeout()
{
    if(helpRequestState == 1){
        if(ui->HelpBtn_1->styleSheet() == "background-color: yellow"){
            ui->HelpBtn_1->setStyleSheet("background-color: white");
            printToElevatorMessagingSystem(1, "911 call has been sent to the authorities");
            printToConsole("911 call has been sent to the authorities for elevator 1");
        }
        if(ui->HelpBtn_2->styleSheet() == "background-color: yellow"){
            ui->HelpBtn_2->setStyleSheet("background-color: white");
            printToElevatorMessagingSystem(2, "911 call has been sent to the authorities");
            printToConsole("911 call has been sent to the authorities for elevator 2");
        }
        if(ui->HelpBtn_3->styleSheet() == "background-color: yellow"){
            ui->HelpBtn_3->setStyleSheet("background-color: white");
            printToElevatorMessagingSystem(3, "911 call has been sent to the authorities");
            printToConsole("911 call has been sent to the authorities for elevator 3");
        }

    }
    helpRequestState = 0;
}





// from ecs
void MainWindow::receiveElevatorArrived(int floor, int elevatorID, bool target)
{
    QString message = "Elevator " + QString::number(elevatorID) + " has arrived at floor " + QString::number(floor);
    // updating console
    printToConsole(message);
        //turn buttons off when elevator arrives
    if(target){
        if(ui->SF_P1_Box->currentText().toInt() == floor && ((ui->FLOORDOWN_1->styleSheet() == "background-color: green") || (ui->FLOORUP_1->styleSheet() == "background-color: green")))
        {
            ui->FLOORDOWN_1->setStyleSheet("background-color: white");
            ui->FLOORUP_1->setStyleSheet("background-color: white");
        }
        if(ui->SF_P2_Box->currentText().toInt() == floor && ((ui->FLOORDOWN_2->styleSheet() == "background-color: green") || (ui->FLOORUP_2->styleSheet() == "background-color: green")))
        {
            ui->FLOORDOWN_2->setStyleSheet("background-color: white");
            ui->FLOORUP_2->setStyleSheet("background-color: white");
        }
        if(ui->SF_P3_Box->currentText().toInt() == floor && ((ui->FLOORDOWN_3->styleSheet() == "background-color: green") || (ui->FLOORUP_3->styleSheet() == "background-color: green")))
        {
            ui->FLOORDOWN_3->setStyleSheet("background-color: white");
            ui->FLOORUP_3->setStyleSheet("background-color: white");
        }
    }


    if(elevatorID == 1)
    {
        ui->FloorNb1->setText(QString::number(floor));
    }
    else if(elevatorID == 2)
    {
        ui->FloorNb2->setText(QString::number(floor));
    }
    else if(elevatorID == 3)
    {
        ui->FloorNb3->setText(QString::number(floor));
    }

}

void MainWindow::receivePassengerBoarded(int passengerWeight, int elevatorID)
{
    QString message ="";
    if(passengerWeight == 0){
        message = "Passenger has disembarked elevator " + QString::number(elevatorID);
    }
    else{
        message = "Passenger has boarded elevator " + QString::number(elevatorID);
    }
    printToConsole(message);
    if(elevatorID == 1){
        ui->elevatorWeight1->setText(QString::number(passengerWeight));
    }
    else if(elevatorID == 2){
        ui->elevatorWeight2->setText(QString::number(passengerWeight));
    }
    else if(elevatorID == 3){
        ui->elevatorWeight3->setText(QString::number(passengerWeight));
}
}
void MainWindow::receiveElevatorMessage(int elevatorID){
    printToElevatorMessagingSystem(elevatorID,"Stop Obstructing Immediately. Door is blocked");
}

void MainWindow::receiveElevatorDoorOpened(int elevatorID)
{
    QString message = "Elevator " + QString::number(elevatorID) + " door has opened";
    printToConsole(message);
}

void MainWindow::receiveElevatorDoorClosed(int elevatorID)
{
    QString message = "Elevator " + QString::number(elevatorID) + " door has closed";
    printToConsole(message);
}
void MainWindow::receiveElevatorDoorOpening(int elevatorID)
{
    QString message = "Elevator " + QString::number(elevatorID) + " door is opening";
    printToConsole(message);
    message = "Elevator " + QString::number(elevatorID) + "'s bell rang";
    printToConsole(message);
}
void MainWindow::receiveElevatorDoorClosing(int elevatorID)
{
    QString message = "Elevator " + QString::number(elevatorID) + " door is closing";
    printToConsole(message);
    message = "Elevator " + QString::number(elevatorID) + "'s bell rang";
    printToConsole(message);
}

void MainWindow::receiveTargetFloorChange(int elevatorID, int targetFloor)
{
    if(elevatorID == 1){
        ui->targetLabel1->setText(QString::number(targetFloor));
    }
    else if(elevatorID == 2){
        ui->targetLabel2->setText(QString::number(targetFloor));
    }
    else if(elevatorID == 3){
        ui->targetLabel3->setText(QString::number(targetFloor));
    }
}

void MainWindow::receiveStateChange(int elevatorID, ElevatorState state)
{
    int toUpdate = 0;
    QString message = "None";
    switch (state) {
    case ElevatorState::Idle:
        message = "Idle";
        break;
    case ElevatorState::MovingToRequestedFloor:
        message = "Moving to requested floor";
        break;
    case ElevatorState::MovingToPickupRequest:
        message = "Moving to pickup request";
        break;
    case ElevatorState::Fire:
        message = "Fire";
        break;
    case ElevatorState::Overloaded:
        message = "Overloaded";
        toUpdate = 1;
        break;
    case ElevatorState::PowerOutage:
        message = "Power Outage";
        break;
    }



    if(elevatorID == 1){
        ui->stateLabel1->setText(message);
        if(toUpdate == 1){
            printToElevatorMessagingSystem(1,"Overloaded, please remove weight.");
        }
    }
    else if(elevatorID == 2){
        ui->stateLabel2->setText(message);
        if(toUpdate == 1){
            printToElevatorMessagingSystem(2,"Overloaded, please remove weight.");
        }
    }
    else if(elevatorID == 3){
        ui->stateLabel3->setText(message);
        if(toUpdate == 1){
            printToElevatorMessagingSystem(3,"Overloaded, please remove weight.");
        }
    }
}

