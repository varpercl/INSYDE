/****************************************************************************
** Meta object code from reading C++ file 'pheromonedepositor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ECGraphicInterface/pheromonedepositor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pheromonedepositor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PheromoneDepositor_t {
    QByteArrayData data[3];
    char stringdata[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PheromoneDepositor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PheromoneDepositor_t qt_meta_stringdata_PheromoneDepositor = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 23),
QT_MOC_LITERAL(2, 43, 0)
    },
    "PheromoneDepositor\0timerCheckDistanceEvent\0"
    "\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PheromoneDepositor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x09,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void PheromoneDepositor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PheromoneDepositor *_t = static_cast<PheromoneDepositor *>(_o);
        switch (_id) {
        case 0: _t->timerCheckDistanceEvent(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PheromoneDepositor::staticMetaObject = {
    { &Actuator::staticMetaObject, qt_meta_stringdata_PheromoneDepositor.data,
      qt_meta_data_PheromoneDepositor,  qt_static_metacall, 0, 0}
};


const QMetaObject *PheromoneDepositor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PheromoneDepositor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PheromoneDepositor.stringdata))
        return static_cast<void*>(const_cast< PheromoneDepositor*>(this));
    return Actuator::qt_metacast(_clname);
}

int PheromoneDepositor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Actuator::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
