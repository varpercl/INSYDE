/****************************************************************************
** Meta object code from reading C++ file 'KDChartAbstractAxis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartAbstractAxis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartAbstractAxis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__AbstractAxis_t {
    QByteArrayData data[5];
    char stringdata[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__AbstractAxis_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__AbstractAxis_t qt_meta_stringdata_KDChart__AbstractAxis = {
    {
QT_MOC_LITERAL(0, 0, 21), // "KDChart::AbstractAxis"
QT_MOC_LITERAL(1, 22, 23), // "coordinateSystemChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 11), // "delayedInit"
QT_MOC_LITERAL(4, 59, 6) // "update"

    },
    "KDChart::AbstractAxis\0coordinateSystemChanged\0"
    "\0delayedInit\0update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__AbstractAxis[] = {

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
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    0,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KDChart::AbstractAxis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractAxis *_t = static_cast<AbstractAxis *>(_o);
        switch (_id) {
        case 0: _t->coordinateSystemChanged(); break;
        case 1: _t->delayedInit(); break;
        case 2: _t->update(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AbstractAxis::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractAxis::coordinateSystemChanged)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject KDChart::AbstractAxis::staticMetaObject = {
    { &AbstractArea::staticMetaObject, qt_meta_stringdata_KDChart__AbstractAxis.data,
      qt_meta_data_KDChart__AbstractAxis,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::AbstractAxis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::AbstractAxis::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__AbstractAxis.stringdata))
        return static_cast<void*>(const_cast< AbstractAxis*>(this));
    return AbstractArea::qt_metacast(_clname);
}

int KDChart::AbstractAxis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractArea::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void KDChart::AbstractAxis::coordinateSystemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
