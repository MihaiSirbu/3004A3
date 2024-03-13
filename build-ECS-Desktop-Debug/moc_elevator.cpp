/****************************************************************************
** Meta object code from reading C++ file 'elevator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ECS/elevator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elevator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Elevator_t {
    QByteArrayData data[28];
    char stringdata0[402];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Elevator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Elevator_t qt_meta_stringdata_Elevator = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Elevator"
QT_MOC_LITERAL(1, 9, 16), // "obstacleDetected"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "obstacleMessage"
QT_MOC_LITERAL(4, 43, 10), // "elevatorID"
QT_MOC_LITERAL(5, 54, 17), // "startOpeningDoors"
QT_MOC_LITERAL(6, 72, 17), // "startClosingDoors"
QT_MOC_LITERAL(7, 90, 10), // "doorClosed"
QT_MOC_LITERAL(8, 101, 10), // "doorOpened"
QT_MOC_LITERAL(9, 112, 10), // "becameIdle"
QT_MOC_LITERAL(10, 123, 12), // "reachedFloor"
QT_MOC_LITERAL(11, 136, 5), // "floor"
QT_MOC_LITERAL(12, 142, 6), // "target"
QT_MOC_LITERAL(13, 149, 11), // "stateChange"
QT_MOC_LITERAL(14, 161, 13), // "ElevatorState"
QT_MOC_LITERAL(15, 175, 5), // "state"
QT_MOC_LITERAL(16, 181, 17), // "targetFloorChange"
QT_MOC_LITERAL(17, 199, 11), // "targetFloor"
QT_MOC_LITERAL(18, 211, 16), // "passengerBoarded"
QT_MOC_LITERAL(19, 228, 15), // "passengerWeight"
QT_MOC_LITERAL(20, 244, 10), // "ElevatorId"
QT_MOC_LITERAL(21, 255, 20), // "obstacleDetectedSlot"
QT_MOC_LITERAL(22, 276, 10), // "closeDoors"
QT_MOC_LITERAL(23, 287, 23), // "onOpenDoorsTimerTimeout"
QT_MOC_LITERAL(24, 311, 28), // "onAutoCloseDoorsTimerTimeout"
QT_MOC_LITERAL(25, 340, 23), // "oncloseDoorTimerTimeout"
QT_MOC_LITERAL(26, 364, 14), // "onMoveOneFloor"
QT_MOC_LITERAL(27, 379, 22) // "onObstacleTimerTimeout"

    },
    "Elevator\0obstacleDetected\0\0obstacleMessage\0"
    "elevatorID\0startOpeningDoors\0"
    "startClosingDoors\0doorClosed\0doorOpened\0"
    "becameIdle\0reachedFloor\0floor\0target\0"
    "stateChange\0ElevatorState\0state\0"
    "targetFloorChange\0targetFloor\0"
    "passengerBoarded\0passengerWeight\0"
    "ElevatorId\0obstacleDetectedSlot\0"
    "closeDoors\0onOpenDoorsTimerTimeout\0"
    "onAutoCloseDoorsTimerTimeout\0"
    "oncloseDoorTimerTimeout\0onMoveOneFloor\0"
    "onObstacleTimerTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Elevator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    1,  105,    2, 0x06 /* Public */,
       5,    1,  108,    2, 0x06 /* Public */,
       6,    1,  111,    2, 0x06 /* Public */,
       7,    1,  114,    2, 0x06 /* Public */,
       8,    1,  117,    2, 0x06 /* Public */,
       9,    1,  120,    2, 0x06 /* Public */,
      10,    3,  123,    2, 0x06 /* Public */,
      13,    2,  130,    2, 0x06 /* Public */,
      16,    2,  135,    2, 0x06 /* Public */,
      18,    2,  140,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    0,  145,    2, 0x0a /* Public */,
      22,    0,  146,    2, 0x0a /* Public */,
      23,    0,  147,    2, 0x08 /* Private */,
      24,    0,  148,    2, 0x08 /* Private */,
      25,    0,  149,    2, 0x08 /* Private */,
      26,    0,  150,    2, 0x08 /* Private */,
      27,    0,  151,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   11,    4,   12,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 14,    4,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Elevator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Elevator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->obstacleDetected(); break;
        case 1: _t->obstacleMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->startOpeningDoors((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->startClosingDoors((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->doorClosed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->doorOpened((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->becameIdle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->reachedFloor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 8: _t->stateChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< ElevatorState(*)>(_a[2]))); break;
        case 9: _t->targetFloorChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->passengerBoarded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->obstacleDetectedSlot(); break;
        case 12: _t->closeDoors(); break;
        case 13: _t->onOpenDoorsTimerTimeout(); break;
        case 14: _t->onAutoCloseDoorsTimerTimeout(); break;
        case 15: _t->oncloseDoorTimerTimeout(); break;
        case 16: _t->onMoveOneFloor(); break;
        case 17: _t->onObstacleTimerTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Elevator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::obstacleDetected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::obstacleMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::startOpeningDoors)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::startClosingDoors)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::doorClosed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::doorOpened)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::becameIdle)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::reachedFloor)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int , ElevatorState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::stateChange)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::targetFloorChange)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::passengerBoarded)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Elevator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Elevator.data,
    qt_meta_data_Elevator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Elevator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Elevator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Elevator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Elevator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Elevator::obstacleDetected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Elevator::obstacleMessage(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Elevator::startOpeningDoors(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Elevator::startClosingDoors(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Elevator::doorClosed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Elevator::doorOpened(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Elevator::becameIdle(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Elevator::reachedFloor(int _t1, int _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Elevator::stateChange(int _t1, ElevatorState _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Elevator::targetFloorChange(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Elevator::passengerBoarded(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
