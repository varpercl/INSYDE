/****************************************************************************
** Meta object code from reading C++ file 'KDChartCartesianCoordinatePlane.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/Cartesian/KDChartCartesianCoordinatePlane.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartCartesianCoordinatePlane.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__CartesianCoordinatePlane_t {
    QByteArrayData data[7];
    char stringdata[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__CartesianCoordinatePlane_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__CartesianCoordinatePlane_t qt_meta_stringdata_KDChart__CartesianCoordinatePlane = {
    {
QT_MOC_LITERAL(0, 0, 33), // "KDChart::CartesianCoordinateP..."
QT_MOC_LITERAL(1, 34, 18), // "adjustRangesToData"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 27), // "adjustHorizontalRangeToData"
QT_MOC_LITERAL(4, 82, 25), // "adjustVerticalRangeToData"
QT_MOC_LITERAL(5, 108, 17), // "slotLayoutChanged"
QT_MOC_LITERAL(6, 126, 16) // "AbstractDiagram*"

    },
    "KDChart::CartesianCoordinatePlane\0"
    "adjustRangesToData\0\0adjustHorizontalRangeToData\0"
    "adjustVerticalRangeToData\0slotLayoutChanged\0"
    "AbstractDiagram*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__CartesianCoordinatePlane[] = {

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
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void KDChart::CartesianCoordinatePlane::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CartesianCoordinatePlane *_t = static_cast<CartesianCoordinatePlane *>(_o);
        switch (_id) {
        case 0: _t->adjustRangesToData(); break;
        case 1: _t->adjustHorizontalRangeToData(); break;
        case 2: _t->adjustVerticalRangeToData(); break;
        case 3: _t->slotLayoutChanged((*reinterpret_cast< AbstractDiagram*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AbstractDiagram* >(); break;
            }
            break;
        }
    }
}

const QMetaObject KDChart::CartesianCoordinatePlane::staticMetaObject = {
    { &AbstractCoordinatePlane::staticMetaObject, qt_meta_stringdata_KDChart__CartesianCoordinatePlane.data,
      qt_meta_data_KDChart__CartesianCoordinatePlane,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::CartesianCoordinatePlane::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::CartesianCoordinatePlane::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__CartesianCoordinatePlane.stringdata))
        return static_cast<void*>(const_cast< CartesianCoordinatePlane*>(this));
    return AbstractCoordinatePlane::qt_metacast(_clname);
}

int KDChart::CartesianCoordinatePlane::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCoordinatePlane::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
