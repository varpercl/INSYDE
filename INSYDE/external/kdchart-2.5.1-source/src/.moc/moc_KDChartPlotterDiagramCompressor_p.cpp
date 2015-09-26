/****************************************************************************
** Meta object code from reading C++ file 'KDChartPlotterDiagramCompressor_p.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/Cartesian/KDChartPlotterDiagramCompressor_p.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartPlotterDiagramCompressor_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__PlotterDiagramCompressor__Private_t {
    QByteArrayData data[8];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__PlotterDiagramCompressor__Private_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__PlotterDiagramCompressor__Private_t qt_meta_stringdata_KDChart__PlotterDiagramCompressor__Private = {
    {
QT_MOC_LITERAL(0, 0, 42), // "KDChart::PlotterDiagramCompre..."
QT_MOC_LITERAL(1, 43, 12), // "rowsInserted"
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 6), // "parent"
QT_MOC_LITERAL(4, 64, 5), // "start"
QT_MOC_LITERAL(5, 70, 3), // "end"
QT_MOC_LITERAL(6, 74, 11), // "clearBuffer"
QT_MOC_LITERAL(7, 86, 14) // "setModelToZero"

    },
    "KDChart::PlotterDiagramCompressor::Private\0"
    "rowsInserted\0\0parent\0start\0end\0"
    "clearBuffer\0setModelToZero"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__PlotterDiagramCompressor__Private[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x0a /* Public */,
       6,    0,   36,    2, 0x0a /* Public */,
       7,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KDChart::PlotterDiagramCompressor::Private::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Private *_t = static_cast<Private *>(_o);
        switch (_id) {
        case 0: _t->rowsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->clearBuffer(); break;
        case 2: _t->setModelToZero(); break;
        default: ;
        }
    }
}

const QMetaObject KDChart::PlotterDiagramCompressor::Private::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KDChart__PlotterDiagramCompressor__Private.data,
      qt_meta_data_KDChart__PlotterDiagramCompressor__Private,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::PlotterDiagramCompressor::Private::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::PlotterDiagramCompressor::Private::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__PlotterDiagramCompressor__Private.stringdata))
        return static_cast<void*>(const_cast< Private*>(this));
    return QObject::qt_metacast(_clname);
}

int KDChart::PlotterDiagramCompressor::Private::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
