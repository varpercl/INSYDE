/****************************************************************************
** Meta object code from reading C++ file 'shootingunit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ECGraphicInterface/shootingunit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shootingunit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ShootingUnit_t {
    QByteArrayData data[17];
    char stringdata[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ShootingUnit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ShootingUnit_t qt_meta_stringdata_ShootingUnit = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 16),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 15),
QT_MOC_LITERAL(4, 47, 15),
QT_MOC_LITERAL(5, 63, 12),
QT_MOC_LITERAL(6, 76, 9),
QT_MOC_LITERAL(7, 86, 7),
QT_MOC_LITERAL(8, 94, 14),
QT_MOC_LITERAL(9, 109, 5),
QT_MOC_LITERAL(10, 115, 4),
QT_MOC_LITERAL(11, 120, 17),
QT_MOC_LITERAL(12, 138, 5),
QT_MOC_LITERAL(13, 144, 8),
QT_MOC_LITERAL(14, 153, 24),
QT_MOC_LITERAL(15, 178, 21),
QT_MOC_LITERAL(16, 200, 13)
    },
    "ShootingUnit\0attackTimerEvent\0\0"
    "timerReachEvent\0enemyHasSighted\0"
    "QList<Unit*>\0aliedList\0enemies\0"
    "enemyHasKilled\0Unit*\0unit\0checkPointReached\0"
    "point\0checkAll\0pheromoneHasBeenDetected\0"
    "QList<PheromoneItem*>\0pheromoneList\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShootingUnit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x09,
       3,    0,   50,    2, 0x09,
       4,    2,   51,    2, 0x09,
       8,    1,   56,    2, 0x09,
      11,    1,   59,    2, 0x09,
      13,    0,   62,    2, 0x09,
      14,    1,   63,    2, 0x09,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QPointF,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void ShootingUnit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShootingUnit *_t = static_cast<ShootingUnit *>(_o);
        switch (_id) {
        case 0: _t->attackTimerEvent(); break;
        case 1: _t->timerReachEvent(); break;
        case 2: _t->enemyHasSighted((*reinterpret_cast< QList<Unit*>(*)>(_a[1])),(*reinterpret_cast< QList<Unit*>(*)>(_a[2]))); break;
        case 3: _t->enemyHasKilled((*reinterpret_cast< Unit*(*)>(_a[1]))); break;
        case 4: _t->checkPointReached((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 5: _t->checkAll(); break;
        case 6: _t->pheromoneHasBeenDetected((*reinterpret_cast< QList<PheromoneItem*>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Unit*> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Unit* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<PheromoneItem*> >(); break;
            }
            break;
        }
    }
}

const QMetaObject ShootingUnit::staticMetaObject = {
    { &OfensiveUnit::staticMetaObject, qt_meta_stringdata_ShootingUnit.data,
      qt_meta_data_ShootingUnit,  qt_static_metacall, 0, 0}
};


const QMetaObject *ShootingUnit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShootingUnit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ShootingUnit.stringdata))
        return static_cast<void*>(const_cast< ShootingUnit*>(this));
    return OfensiveUnit::qt_metacast(_clname);
}

int ShootingUnit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = OfensiveUnit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
