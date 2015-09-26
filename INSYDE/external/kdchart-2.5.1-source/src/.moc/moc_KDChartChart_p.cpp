/****************************************************************************
** Meta object code from reading C++ file 'KDChartChart_p.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartChart_p.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartChart_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__Chart__Private_t {
    QByteArrayData data[17];
    char stringdata[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__Chart__Private_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__Chart__Private_t qt_meta_stringdata_KDChart__Chart__Private = {
    {
QT_MOC_LITERAL(0, 0, 23), // "KDChart::Chart::Private"
QT_MOC_LITERAL(1, 24, 16), // "slotLayoutPlanes"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 16), // "slotResizePlanes"
QT_MOC_LITERAL(4, 59, 25), // "slotLegendPositionChanged"
QT_MOC_LITERAL(5, 85, 19), // "AbstractAreaWidget*"
QT_MOC_LITERAL(6, 105, 6), // "legend"
QT_MOC_LITERAL(7, 112, 31), // "slotHeaderFooterPositionChanged"
QT_MOC_LITERAL(8, 144, 13), // "HeaderFooter*"
QT_MOC_LITERAL(9, 158, 2), // "hf"
QT_MOC_LITERAL(10, 161, 29), // "slotUnregisterDestroyedLegend"
QT_MOC_LITERAL(11, 191, 7), // "Legend*"
QT_MOC_LITERAL(12, 199, 35), // "slotUnregisterDestroyedHeader..."
QT_MOC_LITERAL(13, 235, 12), // "headerFooter"
QT_MOC_LITERAL(14, 248, 28), // "slotUnregisterDestroyedPlane"
QT_MOC_LITERAL(15, 277, 24), // "AbstractCoordinatePlane*"
QT_MOC_LITERAL(16, 302, 5) // "plane"

    },
    "KDChart::Chart::Private\0slotLayoutPlanes\0"
    "\0slotResizePlanes\0slotLegendPositionChanged\0"
    "AbstractAreaWidget*\0legend\0"
    "slotHeaderFooterPositionChanged\0"
    "HeaderFooter*\0hf\0slotUnregisterDestroyedLegend\0"
    "Legend*\0slotUnregisterDestroyedHeaderFooter\0"
    "headerFooter\0slotUnregisterDestroyedPlane\0"
    "AbstractCoordinatePlane*\0plane"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__Chart__Private[] = {

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
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    1,   51,    2, 0x0a /* Public */,
       7,    1,   54,    2, 0x0a /* Public */,
      10,    1,   57,    2, 0x0a /* Public */,
      12,    1,   60,    2, 0x0a /* Public */,
      14,    1,   63,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    6,
    QMetaType::Void, 0x80000000 | 8,   13,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void KDChart::Chart::Private::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Private *_t = static_cast<Private *>(_o);
        switch (_id) {
        case 0: _t->slotLayoutPlanes(); break;
        case 1: _t->slotResizePlanes(); break;
        case 2: _t->slotLegendPositionChanged((*reinterpret_cast< AbstractAreaWidget*(*)>(_a[1]))); break;
        case 3: _t->slotHeaderFooterPositionChanged((*reinterpret_cast< HeaderFooter*(*)>(_a[1]))); break;
        case 4: _t->slotUnregisterDestroyedLegend((*reinterpret_cast< Legend*(*)>(_a[1]))); break;
        case 5: _t->slotUnregisterDestroyedHeaderFooter((*reinterpret_cast< HeaderFooter*(*)>(_a[1]))); break;
        case 6: _t->slotUnregisterDestroyedPlane((*reinterpret_cast< AbstractCoordinatePlane*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject KDChart::Chart::Private::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KDChart__Chart__Private.data,
      qt_meta_data_KDChart__Chart__Private,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::Chart::Private::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::Chart::Private::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__Chart__Private.stringdata))
        return static_cast<void*>(const_cast< Private*>(this));
    return QObject::qt_metacast(_clname);
}

int KDChart::Chart::Private::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
