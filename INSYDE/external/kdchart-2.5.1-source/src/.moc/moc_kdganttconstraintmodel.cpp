/****************************************************************************
** Meta object code from reading C++ file 'kdganttconstraintmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDGantt/kdganttconstraintmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kdganttconstraintmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDGantt__ConstraintModel_t {
    QByteArrayData data[5];
    char stringdata[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDGantt__ConstraintModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDGantt__ConstraintModel_t qt_meta_stringdata_KDGantt__ConstraintModel = {
    {
QT_MOC_LITERAL(0, 0, 24), // "KDGantt::ConstraintModel"
QT_MOC_LITERAL(1, 25, 15), // "constraintAdded"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 19), // "KDGantt::Constraint"
QT_MOC_LITERAL(4, 62, 17) // "constraintRemoved"

    },
    "KDGantt::ConstraintModel\0constraintAdded\0"
    "\0KDGantt::Constraint\0constraintRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDGantt__ConstraintModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void KDGantt::ConstraintModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConstraintModel *_t = static_cast<ConstraintModel *>(_o);
        switch (_id) {
        case 0: _t->constraintAdded((*reinterpret_cast< const KDGantt::Constraint(*)>(_a[1]))); break;
        case 1: _t->constraintRemoved((*reinterpret_cast< const KDGantt::Constraint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ConstraintModel::*_t)(const KDGantt::Constraint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConstraintModel::constraintAdded)) {
                *result = 0;
            }
        }
        {
            typedef void (ConstraintModel::*_t)(const KDGantt::Constraint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConstraintModel::constraintRemoved)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject KDGantt::ConstraintModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KDGantt__ConstraintModel.data,
      qt_meta_data_KDGantt__ConstraintModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDGantt::ConstraintModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDGantt::ConstraintModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDGantt__ConstraintModel.stringdata))
        return static_cast<void*>(const_cast< ConstraintModel*>(this));
    return QObject::qt_metacast(_clname);
}

int KDGantt::ConstraintModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void KDGantt::ConstraintModel::constraintAdded(const KDGantt::Constraint & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KDGantt::ConstraintModel::constraintRemoved(const KDGantt::Constraint & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
