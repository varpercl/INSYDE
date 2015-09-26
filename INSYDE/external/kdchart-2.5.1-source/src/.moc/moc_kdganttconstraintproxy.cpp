/****************************************************************************
** Meta object code from reading C++ file 'kdganttconstraintproxy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDGantt/kdganttconstraintproxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kdganttconstraintproxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDGantt__ConstraintProxy_t {
    QByteArrayData data[8];
    char stringdata[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDGantt__ConstraintProxy_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDGantt__ConstraintProxy_t qt_meta_stringdata_KDGantt__ConstraintProxy = {
    {
QT_MOC_LITERAL(0, 0, 24), // "KDGantt::ConstraintProxy"
QT_MOC_LITERAL(1, 25, 25), // "slotSourceConstraintAdded"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 19), // "KDGantt::Constraint"
QT_MOC_LITERAL(4, 72, 27), // "slotSourceConstraintRemoved"
QT_MOC_LITERAL(5, 100, 30), // "slotDestinationConstraintAdded"
QT_MOC_LITERAL(6, 131, 32), // "slotDestinationConstraintRemoved"
QT_MOC_LITERAL(7, 164, 17) // "slotLayoutChanged"

    },
    "KDGantt::ConstraintProxy\0"
    "slotSourceConstraintAdded\0\0"
    "KDGantt::Constraint\0slotSourceConstraintRemoved\0"
    "slotDestinationConstraintAdded\0"
    "slotDestinationConstraintRemoved\0"
    "slotLayoutChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDGantt__ConstraintProxy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       5,    1,   45,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

       0        // eod
};

void KDGantt::ConstraintProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConstraintProxy *_t = static_cast<ConstraintProxy *>(_o);
        switch (_id) {
        case 0: _t->slotSourceConstraintAdded((*reinterpret_cast< const KDGantt::Constraint(*)>(_a[1]))); break;
        case 1: _t->slotSourceConstraintRemoved((*reinterpret_cast< const KDGantt::Constraint(*)>(_a[1]))); break;
        case 2: _t->slotDestinationConstraintAdded((*reinterpret_cast< const KDGantt::Constraint(*)>(_a[1]))); break;
        case 3: _t->slotDestinationConstraintRemoved((*reinterpret_cast< const KDGantt::Constraint(*)>(_a[1]))); break;
        case 4: _t->slotLayoutChanged(); break;
        default: ;
        }
    }
}

const QMetaObject KDGantt::ConstraintProxy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KDGantt__ConstraintProxy.data,
      qt_meta_data_KDGantt__ConstraintProxy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDGantt::ConstraintProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDGantt::ConstraintProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDGantt__ConstraintProxy.stringdata))
        return static_cast<void*>(const_cast< ConstraintProxy*>(this));
    return QObject::qt_metacast(_clname);
}

int KDGantt::ConstraintProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
