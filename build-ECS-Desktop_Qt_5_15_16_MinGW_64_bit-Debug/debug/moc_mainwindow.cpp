/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.16)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ECS/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.16. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[34];
    char stringdata0[553];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "sendElevatorRequest"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "starting_floor"
QT_MOC_LITERAL(4, 47, 16), // "sendFloorRequest"
QT_MOC_LITERAL(5, 64, 11), // "floorNumber"
QT_MOC_LITERAL(6, 76, 14), // "elevatorNumber"
QT_MOC_LITERAL(7, 91, 12), // "doorObstacle"
QT_MOC_LITERAL(8, 104, 13), // "emergencyStop"
QT_MOC_LITERAL(9, 118, 4), // "type"
QT_MOC_LITERAL(10, 123, 10), // "elevatorID"
QT_MOC_LITERAL(11, 134, 11), // "doorRequest"
QT_MOC_LITERAL(12, 146, 6), // "toOpen"
QT_MOC_LITERAL(13, 153, 22), // "receiveElevatorRequest"
QT_MOC_LITERAL(14, 176, 14), // "passengerBtnNb"
QT_MOC_LITERAL(15, 191, 19), // "receiveFloorRequest"
QT_MOC_LITERAL(16, 211, 13), // "helpRequested"
QT_MOC_LITERAL(17, 225, 18), // "resolveHelpRequest"
QT_MOC_LITERAL(18, 244, 27), // "onEmergencyCallTimerTimeout"
QT_MOC_LITERAL(19, 272, 24), // "receiveTargetFloorChange"
QT_MOC_LITERAL(20, 297, 11), // "targetFloor"
QT_MOC_LITERAL(21, 309, 18), // "receiveStateChange"
QT_MOC_LITERAL(22, 328, 13), // "ElevatorState"
QT_MOC_LITERAL(23, 342, 5), // "state"
QT_MOC_LITERAL(24, 348, 22), // "receiveElevatorArrived"
QT_MOC_LITERAL(25, 371, 5), // "floor"
QT_MOC_LITERAL(26, 377, 6), // "target"
QT_MOC_LITERAL(27, 384, 25), // "receiveElevatorDoorOpened"
QT_MOC_LITERAL(28, 410, 25), // "receiveElevatorDoorClosed"
QT_MOC_LITERAL(29, 436, 26), // "receiveElevatorDoorOpening"
QT_MOC_LITERAL(30, 463, 26), // "receiveElevatorDoorClosing"
QT_MOC_LITERAL(31, 490, 22), // "receiveElevatorMessage"
QT_MOC_LITERAL(32, 513, 23), // "receivePassengerBoarded"
QT_MOC_LITERAL(33, 537, 15) // "passengerWeight"

    },
    "MainWindow\0sendElevatorRequest\0\0"
    "starting_floor\0sendFloorRequest\0"
    "floorNumber\0elevatorNumber\0doorObstacle\0"
    "emergencyStop\0type\0elevatorID\0doorRequest\0"
    "toOpen\0receiveElevatorRequest\0"
    "passengerBtnNb\0receiveFloorRequest\0"
    "helpRequested\0resolveHelpRequest\0"
    "onEmergencyCallTimerTimeout\0"
    "receiveTargetFloorChange\0targetFloor\0"
    "receiveStateChange\0ElevatorState\0state\0"
    "receiveElevatorArrived\0floor\0target\0"
    "receiveElevatorDoorOpened\0"
    "receiveElevatorDoorClosed\0"
    "receiveElevatorDoorOpening\0"
    "receiveElevatorDoorClosing\0"
    "receiveElevatorMessage\0receivePassengerBoarded\0"
    "passengerWeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       4,    2,  112,    2, 0x06 /* Public */,
       7,    1,  117,    2, 0x06 /* Public */,
       8,    2,  120,    2, 0x06 /* Public */,
      11,    2,  125,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    2,  130,    2, 0x08 /* Private */,
      15,    2,  135,    2, 0x08 /* Private */,
      16,    1,  140,    2, 0x08 /* Private */,
      17,    0,  143,    2, 0x08 /* Private */,
      18,    0,  144,    2, 0x08 /* Private */,
      19,    2,  145,    2, 0x0a /* Public */,
      21,    2,  150,    2, 0x0a /* Public */,
      24,    3,  155,    2, 0x0a /* Public */,
      27,    1,  162,    2, 0x0a /* Public */,
      28,    1,  165,    2, 0x0a /* Public */,
      29,    1,  168,    2, 0x0a /* Public */,
      30,    1,  171,    2, 0x0a /* Public */,
      31,    1,  174,    2, 0x0a /* Public */,
      32,    2,  177,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   20,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 22,   10,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   25,   10,   26,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   33,   10,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendElevatorRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendFloorRequest((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->doorObstacle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->emergencyStop((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->doorRequest((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->receiveElevatorRequest((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->receiveFloorRequest((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->helpRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->resolveHelpRequest(); break;
        case 9: _t->onEmergencyCallTimerTimeout(); break;
        case 10: _t->receiveTargetFloorChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->receiveStateChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< ElevatorState(*)>(_a[2]))); break;
        case 12: _t->receiveElevatorArrived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 13: _t->receiveElevatorDoorOpened((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->receiveElevatorDoorClosed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->receiveElevatorDoorOpening((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->receiveElevatorDoorClosing((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->receiveElevatorMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->receivePassengerBoarded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendElevatorRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendFloorRequest)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::doorObstacle)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::emergencyStop)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::doorRequest)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendElevatorRequest(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sendFloorRequest(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::doorObstacle(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::emergencyStop(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::doorRequest(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
