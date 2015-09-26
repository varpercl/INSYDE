/****************************************************************************
** Meta object code from reading C++ file 'KDChartPlotter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/Cartesian/KDChartPlotter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartPlotter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__Plotter_t {
    QByteArrayData data[11];
    char stringdata[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__Plotter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__Plotter_t qt_meta_stringdata_KDChart__Plotter = {
    {
QT_MOC_LITERAL(0, 0, 16), // "KDChart::Plotter"
QT_MOC_LITERAL(1, 17, 22), // "setDataBoundariesDirty"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 15), // "calcMergeRadius"
QT_MOC_LITERAL(4, 57, 18), // "useDataCompression"
QT_MOC_LITERAL(5, 76, 15), // "CompressionMode"
QT_MOC_LITERAL(6, 92, 21), // "mergeRadiusPercentage"
QT_MOC_LITERAL(7, 114, 5), // "SLOPE"
QT_MOC_LITERAL(8, 120, 8), // "DISTANCE"
QT_MOC_LITERAL(9, 129, 4), // "BOTH"
QT_MOC_LITERAL(10, 134, 4) // "NONE"

    },
    "KDChart::Plotter\0setDataBoundariesDirty\0"
    "\0calcMergeRadius\0useDataCompression\0"
    "CompressionMode\0mergeRadiusPercentage\0"
    "SLOPE\0DISTANCE\0BOTH\0NONE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__Plotter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   26, // properties
       1,   32, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x09 /* Protected */,
       3,    0,   25,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       4, 0x80000000 | 5, 0x0009510b,
       6, QMetaType::QReal, 0x00095103,

 // enums: name, flags, count, data
       5, 0x0,    4,   36,

 // enum data: key, value
       7, uint(KDChart::Plotter::SLOPE),
       8, uint(KDChart::Plotter::DISTANCE),
       9, uint(KDChart::Plotter::BOTH),
      10, uint(KDChart::Plotter::NONE),

       0        // eod
};

void KDChart::Plotter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Plotter *_t = static_cast<Plotter *>(_o);
        switch (_id) {
        case 0: _t->setDataBoundariesDirty(); break;
        case 1: _t->calcMergeRadius(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject KDChart::Plotter::staticMetaObject = {
    { &AbstractCartesianDiagram::staticMetaObject, qt_meta_stringdata_KDChart__Plotter.data,
      qt_meta_data_KDChart__Plotter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::Plotter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::Plotter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__Plotter.stringdata))
        return static_cast<void*>(const_cast< Plotter*>(this));
    return AbstractCartesianDiagram::qt_metacast(_clname);
}

int KDChart::Plotter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCartesianDiagram::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< CompressionMode*>(_v) = useDataCompression(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = mergeRadiusPercentage(); break;
        default: break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setUseDataCompression(*reinterpret_cast< CompressionMode*>(_v)); break;
        case 1: setMergeRadiusPercentage(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
