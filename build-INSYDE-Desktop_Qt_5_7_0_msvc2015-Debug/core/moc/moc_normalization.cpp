/****************************************************************************
** Meta object code from reading C++ file 'normalization.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/normalization.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'normalization.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Normalization_t {
    QByteArrayData data[10];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Normalization_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Normalization_t qt_meta_stringdata_Normalization = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Normalization"
QT_MOC_LITERAL(1, 14, 16), // "amplitudeChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "val"
QT_MOC_LITERAL(4, 36, 17), // "elongationChanged"
QT_MOC_LITERAL(5, 54, 16), // "thresholdChanged"
QT_MOC_LITERAL(6, 71, 15), // "maxValueChanged"
QT_MOC_LITERAL(7, 87, 15), // "minValueChanged"
QT_MOC_LITERAL(8, 103, 11), // "typeChanged"
QT_MOC_LITERAL(9, 115, 4) // "type"

    },
    "Normalization\0amplitudeChanged\0\0val\0"
    "elongationChanged\0thresholdChanged\0"
    "maxValueChanged\0minValueChanged\0"
    "typeChanged\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Normalization[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    1,   50,    2, 0x06 /* Public */,
       6,    1,   53,    2, 0x06 /* Public */,
       7,    1,   56,    2, 0x06 /* Public */,
       8,    1,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void Normalization::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Normalization *_t = static_cast<Normalization *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->amplitudeChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->elongationChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->thresholdChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->maxValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->minValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->typeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Normalization::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Normalization::amplitudeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Normalization::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Normalization::elongationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Normalization::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Normalization::thresholdChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Normalization::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Normalization::maxValueChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Normalization::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Normalization::minValueChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Normalization::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Normalization::typeChanged)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Normalization::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Normalization.data,
      qt_meta_data_Normalization,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Normalization::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Normalization::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Normalization.stringdata0))
        return static_cast<void*>(const_cast< Normalization*>(this));
    return QObject::qt_metacast(_clname);
}

int Normalization::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Normalization::amplitudeChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Normalization::elongationChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Normalization::thresholdChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Normalization::maxValueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Normalization::minValueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Normalization::typeChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
