/****************************************************************************
** Meta object code from reading C++ file 'KDChartChart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartChart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartChart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__Chart_t {
    QByteArrayData data[9];
    char stringdata[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__Chart_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__Chart_t qt_meta_stringdata_KDChart__Chart = {
    {
QT_MOC_LITERAL(0, 0, 14), // "KDChart::Chart"
QT_MOC_LITERAL(1, 15, 17), // "propertiesChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "finishedDrawing"
QT_MOC_LITERAL(4, 50, 16), // "globalLeadingTop"
QT_MOC_LITERAL(5, 67, 19), // "globalLeadingBottom"
QT_MOC_LITERAL(6, 87, 17), // "globalLeadingLeft"
QT_MOC_LITERAL(7, 105, 18), // "globalLeadingRight"
QT_MOC_LITERAL(8, 124, 18) // "useNewLayoutSystem"

    },
    "KDChart::Chart\0propertiesChanged\0\0"
    "finishedDrawing\0globalLeadingTop\0"
    "globalLeadingBottom\0globalLeadingLeft\0"
    "globalLeadingRight\0useNewLayoutSystem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__Chart[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       5,   26, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::Int, 0x00095103,
       5, QMetaType::Int, 0x00095103,
       6, QMetaType::Int, 0x00095103,
       7, QMetaType::Int, 0x00095103,
       8, QMetaType::Bool, 0x00095103,

       0        // eod
};

void KDChart::Chart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Chart *_t = static_cast<Chart *>(_o);
        switch (_id) {
        case 0: _t->propertiesChanged(); break;
        case 1: _t->finishedDrawing(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Chart::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Chart::propertiesChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Chart::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Chart::finishedDrawing)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject KDChart::Chart::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_KDChart__Chart.data,
      qt_meta_data_KDChart__Chart,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::Chart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::Chart::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__Chart.stringdata))
        return static_cast<void*>(const_cast< Chart*>(this));
    return QWidget::qt_metacast(_clname);
}

int KDChart::Chart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
        case 0: *reinterpret_cast< int*>(_v) = globalLeadingTop(); break;
        case 1: *reinterpret_cast< int*>(_v) = globalLeadingBottom(); break;
        case 2: *reinterpret_cast< int*>(_v) = globalLeadingLeft(); break;
        case 3: *reinterpret_cast< int*>(_v) = globalLeadingRight(); break;
        case 4: *reinterpret_cast< bool*>(_v) = useNewLayoutSystem(); break;
        default: break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setGlobalLeadingTop(*reinterpret_cast< int*>(_v)); break;
        case 1: setGlobalLeadingBottom(*reinterpret_cast< int*>(_v)); break;
        case 2: setGlobalLeadingLeft(*reinterpret_cast< int*>(_v)); break;
        case 3: setGlobalLeadingRight(*reinterpret_cast< int*>(_v)); break;
        case 4: setUseNewLayoutSystem(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void KDChart::Chart::propertiesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void KDChart::Chart::finishedDrawing()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
