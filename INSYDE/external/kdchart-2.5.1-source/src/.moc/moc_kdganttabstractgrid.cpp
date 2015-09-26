/****************************************************************************
** Meta object code from reading C++ file 'kdganttabstractgrid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDGantt/kdganttabstractgrid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kdganttabstractgrid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDGantt__AbstractGrid_t {
    QByteArrayData data[8];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDGantt__AbstractGrid_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDGantt__AbstractGrid_t qt_meta_stringdata_KDGantt__AbstractGrid = {
    {
QT_MOC_LITERAL(0, 0, 21), // "KDGantt::AbstractGrid"
QT_MOC_LITERAL(1, 22, 11), // "gridChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "setModel"
QT_MOC_LITERAL(4, 44, 19), // "QAbstractItemModel*"
QT_MOC_LITERAL(5, 64, 5), // "model"
QT_MOC_LITERAL(6, 70, 12), // "setRootIndex"
QT_MOC_LITERAL(7, 83, 3) // "idx"

    },
    "KDGantt::AbstractGrid\0gridChanged\0\0"
    "setModel\0QAbstractItemModel*\0model\0"
    "setRootIndex\0idx"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDGantt__AbstractGrid[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x0a /* Public */,
       6,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QModelIndex,    7,

       0        // eod
};

void KDGantt::AbstractGrid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractGrid *_t = static_cast<AbstractGrid *>(_o);
        switch (_id) {
        case 0: _t->gridChanged(); break;
        case 1: _t->setModel((*reinterpret_cast< QAbstractItemModel*(*)>(_a[1]))); break;
        case 2: _t->setRootIndex((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractItemModel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AbstractGrid::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractGrid::gridChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject KDGantt::AbstractGrid::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KDGantt__AbstractGrid.data,
      qt_meta_data_KDGantt__AbstractGrid,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDGantt::AbstractGrid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDGantt::AbstractGrid::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDGantt__AbstractGrid.stringdata))
        return static_cast<void*>(const_cast< AbstractGrid*>(this));
    return QObject::qt_metacast(_clname);
}

int KDGantt::AbstractGrid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void KDGantt::AbstractGrid::gridChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
