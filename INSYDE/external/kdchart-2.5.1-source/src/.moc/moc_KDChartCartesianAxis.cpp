/****************************************************************************
** Meta object code from reading C++ file 'KDChartCartesianAxis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/Cartesian/KDChartCartesianAxis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartCartesianAxis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__CartesianAxis_t {
    QByteArrayData data[6];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__CartesianAxis_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__CartesianAxis_t qt_meta_stringdata_KDChart__CartesianAxis = {
    {
QT_MOC_LITERAL(0, 0, 22), // "KDChart::CartesianAxis"
QT_MOC_LITERAL(1, 23, 18), // "setCachedSizeDirty"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 10), // "tickLength"
QT_MOC_LITERAL(4, 54, 12), // "subUnitTicks"
QT_MOC_LITERAL(5, 67, 23) // "coordinateSystemChanged"

    },
    "KDChart::CartesianAxis\0setCachedSizeDirty\0"
    "\0tickLength\0subUnitTicks\0"
    "coordinateSystemChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__CartesianAxis[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       3,    0,   38,    2, 0x2a /* Public | MethodCloned */,
       5,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Int, QMetaType::Bool,    4,
    QMetaType::Int,
    QMetaType::Void,

       0        // eod
};

void KDChart::CartesianAxis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CartesianAxis *_t = static_cast<CartesianAxis *>(_o);
        switch (_id) {
        case 0: _t->setCachedSizeDirty(); break;
        case 1: { int _r = _t->tickLength((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->tickLength();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: _t->coordinateSystemChanged(); break;
        default: ;
        }
    }
}

const QMetaObject KDChart::CartesianAxis::staticMetaObject = {
    { &AbstractAxis::staticMetaObject, qt_meta_stringdata_KDChart__CartesianAxis.data,
      qt_meta_data_KDChart__CartesianAxis,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::CartesianAxis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::CartesianAxis::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__CartesianAxis.stringdata))
        return static_cast<void*>(const_cast< CartesianAxis*>(this));
    return AbstractAxis::qt_metacast(_clname);
}

int KDChart::CartesianAxis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractAxis::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
