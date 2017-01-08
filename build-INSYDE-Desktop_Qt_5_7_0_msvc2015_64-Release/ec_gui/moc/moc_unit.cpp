/****************************************************************************
** Meta object code from reading C++ file 'unit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/ec_gui/unit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'unit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Unit_t {
    QByteArrayData data[16];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Unit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Unit_t qt_meta_stringdata_Unit = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Unit"
QT_MOC_LITERAL(1, 5, 12), // "enemySighted"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "QList<Unit*>"
QT_MOC_LITERAL(4, 32, 5), // "units"
QT_MOC_LITERAL(5, 38, 5), // "alies"
QT_MOC_LITERAL(6, 44, 4), // "dead"
QT_MOC_LITERAL(7, 49, 5), // "Unit*"
QT_MOC_LITERAL(8, 55, 6), // "unidad"
QT_MOC_LITERAL(9, 62, 17), // "pheromoneDetected"
QT_MOC_LITERAL(10, 80, 21), // "QList<PheromoneItem*>"
QT_MOC_LITERAL(11, 102, 13), // "pheromoneList"
QT_MOC_LITERAL(12, 116, 17), // "checkPointReached"
QT_MOC_LITERAL(13, 134, 5), // "point"
QT_MOC_LITERAL(14, 140, 8), // "checkAll"
QT_MOC_LITERAL(15, 149, 2) // "pt"

    },
    "Unit\0enemySighted\0\0QList<Unit*>\0units\0"
    "alies\0dead\0Unit*\0unidad\0pheromoneDetected\0"
    "QList<PheromoneItem*>\0pheromoneList\0"
    "checkPointReached\0point\0checkAll\0pt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Unit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       1,    2,   47,    2, 0x06 /* Public */,
       6,    1,   52,    2, 0x06 /* Public */,
       9,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   58,    2, 0x09 /* Protected */,
      14,    1,   61,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    5,    4,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,   13,
    QMetaType::Void, QMetaType::QPointF,   15,

       0        // eod
};

void Unit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Unit *_t = static_cast<Unit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enemySighted((*reinterpret_cast< QList<Unit*>(*)>(_a[1]))); break;
        case 1: _t->enemySighted((*reinterpret_cast< QList<Unit*>(*)>(_a[1])),(*reinterpret_cast< QList<Unit*>(*)>(_a[2]))); break;
        case 2: _t->dead((*reinterpret_cast< Unit*(*)>(_a[1]))); break;
        case 3: _t->pheromoneDetected((*reinterpret_cast< QList<PheromoneItem*>(*)>(_a[1]))); break;
        case 4: _t->checkPointReached((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 5: _t->checkAll((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Unit*> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Unit*> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Unit* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<PheromoneItem*> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Unit::*_t)(QList<Unit*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Unit::enemySighted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Unit::*_t)(QList<Unit*> , QList<Unit*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Unit::enemySighted)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Unit::*_t)(Unit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Unit::dead)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Unit::*_t)(QList<PheromoneItem*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Unit::pheromoneDetected)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Unit::staticMetaObject = {
    { &MovilAgent::staticMetaObject, qt_meta_stringdata_Unit.data,
      qt_meta_data_Unit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Unit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Unit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Unit.stringdata0))
        return static_cast<void*>(const_cast< Unit*>(this));
    return MovilAgent::qt_metacast(_clname);
}

int Unit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MovilAgent::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Unit::enemySighted(QList<Unit*> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Unit::enemySighted(QList<Unit*> _t1, QList<Unit*> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Unit::dead(Unit * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Unit::pheromoneDetected(QList<PheromoneItem*> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
