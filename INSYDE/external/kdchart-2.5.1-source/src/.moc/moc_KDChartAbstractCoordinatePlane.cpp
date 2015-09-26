/****************************************************************************
** Meta object code from reading C++ file 'KDChartAbstractCoordinatePlane.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartAbstractCoordinatePlane.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartAbstractCoordinatePlane.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__AbstractCoordinatePlane_t {
    QByteArrayData data[16];
    char stringdata[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__AbstractCoordinatePlane_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__AbstractCoordinatePlane_t qt_meta_stringdata_KDChart__AbstractCoordinatePlane = {
    {
QT_MOC_LITERAL(0, 0, 32), // "KDChart::AbstractCoordinatePlane"
QT_MOC_LITERAL(1, 33, 24), // "destroyedCoordinatePlane"
QT_MOC_LITERAL(2, 58, 0), // ""
QT_MOC_LITERAL(3, 59, 24), // "AbstractCoordinatePlane*"
QT_MOC_LITERAL(4, 84, 10), // "needUpdate"
QT_MOC_LITERAL(5, 95, 12), // "needRelayout"
QT_MOC_LITERAL(6, 108, 16), // "needLayoutPlanes"
QT_MOC_LITERAL(7, 125, 17), // "propertiesChanged"
QT_MOC_LITERAL(8, 143, 17), // "boundariesChanged"
QT_MOC_LITERAL(9, 161, 15), // "geometryChanged"
QT_MOC_LITERAL(10, 177, 24), // "internal_geometryChanged"
QT_MOC_LITERAL(11, 202, 31), // "viewportCoordinateSystemChanged"
QT_MOC_LITERAL(12, 234, 6), // "update"
QT_MOC_LITERAL(13, 241, 8), // "relayout"
QT_MOC_LITERAL(14, 250, 12), // "layoutPlanes"
QT_MOC_LITERAL(15, 263, 23) // "setGridNeedsRecalculate"

    },
    "KDChart::AbstractCoordinatePlane\0"
    "destroyedCoordinatePlane\0\0"
    "AbstractCoordinatePlane*\0needUpdate\0"
    "needRelayout\0needLayoutPlanes\0"
    "propertiesChanged\0boundariesChanged\0"
    "geometryChanged\0internal_geometryChanged\0"
    "viewportCoordinateSystemChanged\0update\0"
    "relayout\0layoutPlanes\0setGridNeedsRecalculate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__AbstractCoordinatePlane[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    0,   82,    2, 0x06 /* Public */,
       5,    0,   83,    2, 0x06 /* Public */,
       6,    0,   84,    2, 0x06 /* Public */,
       7,    0,   85,    2, 0x06 /* Public */,
       8,    0,   86,    2, 0x06 /* Public */,
       9,    2,   87,    2, 0x06 /* Public */,
      10,    2,   92,    2, 0x06 /* Public */,
      11,    0,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   98,    2, 0x0a /* Public */,
      13,    0,   99,    2, 0x0a /* Public */,
      14,    0,  100,    2, 0x0a /* Public */,
      15,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRect, QMetaType::QRect,    2,    2,
    QMetaType::Void, QMetaType::QRect, QMetaType::QRect,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KDChart::AbstractCoordinatePlane::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractCoordinatePlane *_t = static_cast<AbstractCoordinatePlane *>(_o);
        switch (_id) {
        case 0: _t->destroyedCoordinatePlane((*reinterpret_cast< AbstractCoordinatePlane*(*)>(_a[1]))); break;
        case 1: _t->needUpdate(); break;
        case 2: _t->needRelayout(); break;
        case 3: _t->needLayoutPlanes(); break;
        case 4: _t->propertiesChanged(); break;
        case 5: _t->boundariesChanged(); break;
        case 6: _t->geometryChanged((*reinterpret_cast< QRect(*)>(_a[1])),(*reinterpret_cast< QRect(*)>(_a[2]))); break;
        case 7: _t->internal_geometryChanged((*reinterpret_cast< QRect(*)>(_a[1])),(*reinterpret_cast< QRect(*)>(_a[2]))); break;
        case 8: _t->viewportCoordinateSystemChanged(); break;
        case 9: _t->update(); break;
        case 10: _t->relayout(); break;
        case 11: _t->layoutPlanes(); break;
        case 12: _t->setGridNeedsRecalculate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AbstractCoordinatePlane* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AbstractCoordinatePlane::*_t)(AbstractCoordinatePlane * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractCoordinatePlane::destroyedCoordinatePlane)) {
                *result = 0;
            }
        }
        {
            typedef void (AbstractCoordinatePlane::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractCoordinatePlane::needUpdate)) {
                *result = 1;
            }
        }
        {
            typedef void (AbstractCoordinatePlane::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractCoordinatePlane::needRelayout)) {
                *result = 2;
            }
        }
        {
            typedef void (AbstractCoordinatePlane::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractCoordinatePlane::needLayoutPlanes)) {
                *result = 3;
            }
        }
        {
            typedef void (AbstractCoordinatePlane::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractCoordinatePlane::propertiesChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (AbstractCoordinatePlane::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractCoordinatePlane::boundariesChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (AbstractCoordinatePlane::*_t)(QRect , QRect );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractCoordinatePlane::geometryChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (AbstractCoordinatePlane::*_t)(QRect , QRect );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractCoordinatePlane::internal_geometryChanged)) {
                *result = 7;
            }
        }
        {
            typedef void (AbstractCoordinatePlane::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractCoordinatePlane::viewportCoordinateSystemChanged)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject KDChart::AbstractCoordinatePlane::staticMetaObject = {
    { &AbstractArea::staticMetaObject, qt_meta_stringdata_KDChart__AbstractCoordinatePlane.data,
      qt_meta_data_KDChart__AbstractCoordinatePlane,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::AbstractCoordinatePlane::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::AbstractCoordinatePlane::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__AbstractCoordinatePlane.stringdata))
        return static_cast<void*>(const_cast< AbstractCoordinatePlane*>(this));
    return AbstractArea::qt_metacast(_clname);
}

int KDChart::AbstractCoordinatePlane::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void KDChart::AbstractCoordinatePlane::destroyedCoordinatePlane(AbstractCoordinatePlane * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KDChart::AbstractCoordinatePlane::needUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void KDChart::AbstractCoordinatePlane::needRelayout()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void KDChart::AbstractCoordinatePlane::needLayoutPlanes()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void KDChart::AbstractCoordinatePlane::propertiesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void KDChart::AbstractCoordinatePlane::boundariesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void KDChart::AbstractCoordinatePlane::geometryChanged(QRect _t1, QRect _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void KDChart::AbstractCoordinatePlane::internal_geometryChanged(QRect _t1, QRect _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void KDChart::AbstractCoordinatePlane::viewportCoordinateSystemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
