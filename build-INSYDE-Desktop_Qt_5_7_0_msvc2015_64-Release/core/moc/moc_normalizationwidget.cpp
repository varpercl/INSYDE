/****************************************************************************
** Meta object code from reading C++ file 'normalizationwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/normalizationwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'normalizationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_core__NormalizationWidget_t {
    QByteArrayData data[26];
    char stringdata0[446];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_core__NormalizationWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_core__NormalizationWidget_t qt_meta_stringdata_core__NormalizationWidget = {
    {
QT_MOC_LITERAL(0, 0, 25), // "core::NormalizationWidget"
QT_MOC_LITERAL(1, 26, 20), // "normalizationChanged"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 14), // "Normalization*"
QT_MOC_LITERAL(4, 63, 20), // "currentNormalization"
QT_MOC_LITERAL(5, 84, 11), // "typeChanged"
QT_MOC_LITERAL(6, 96, 19), // "Normalization::Type"
QT_MOC_LITERAL(7, 116, 4), // "type"
QT_MOC_LITERAL(8, 121, 21), // "amplitudeValueChanged"
QT_MOC_LITERAL(9, 143, 3), // "val"
QT_MOC_LITERAL(10, 147, 22), // "elongationValueChanged"
QT_MOC_LITERAL(11, 170, 21), // "thresholdValueChanged"
QT_MOC_LITERAL(12, 192, 15), // "minValueChanged"
QT_MOC_LITERAL(13, 208, 15), // "maxValueChanged"
QT_MOC_LITERAL(14, 224, 16), // "amplitudeTimeout"
QT_MOC_LITERAL(15, 241, 17), // "elongationTimeout"
QT_MOC_LITERAL(16, 259, 15), // "maxValueTimeout"
QT_MOC_LITERAL(17, 275, 15), // "minValueTimeout"
QT_MOC_LITERAL(18, 291, 16), // "thresholdTimeout"
QT_MOC_LITERAL(19, 308, 27), // "cbNormalizationIndexChanged"
QT_MOC_LITERAL(20, 336, 5), // "index"
QT_MOC_LITERAL(21, 342, 23), // "onAmplitudeValueChanged"
QT_MOC_LITERAL(22, 366, 24), // "onElongationValueChanged"
QT_MOC_LITERAL(23, 391, 18), // "onThresholdChanged"
QT_MOC_LITERAL(24, 410, 17), // "onMinValueChanged"
QT_MOC_LITERAL(25, 428, 17) // "onMaxValueChanged"

    },
    "core::NormalizationWidget\0"
    "normalizationChanged\0\0Normalization*\0"
    "currentNormalization\0typeChanged\0"
    "Normalization::Type\0type\0amplitudeValueChanged\0"
    "val\0elongationValueChanged\0"
    "thresholdValueChanged\0minValueChanged\0"
    "maxValueChanged\0amplitudeTimeout\0"
    "elongationTimeout\0maxValueTimeout\0"
    "minValueTimeout\0thresholdTimeout\0"
    "cbNormalizationIndexChanged\0index\0"
    "onAmplitudeValueChanged\0"
    "onElongationValueChanged\0onThresholdChanged\0"
    "onMinValueChanged\0onMaxValueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_core__NormalizationWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       5,    1,  107,    2, 0x06 /* Public */,
       8,    1,  110,    2, 0x06 /* Public */,
      10,    1,  113,    2, 0x06 /* Public */,
      11,    1,  116,    2, 0x06 /* Public */,
      12,    1,  119,    2, 0x06 /* Public */,
      13,    1,  122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  125,    2, 0x08 /* Private */,
      15,    0,  126,    2, 0x08 /* Private */,
      16,    0,  127,    2, 0x08 /* Private */,
      17,    0,  128,    2, 0x08 /* Private */,
      18,    0,  129,    2, 0x08 /* Private */,
      19,    1,  130,    2, 0x08 /* Private */,
      21,    1,  133,    2, 0x08 /* Private */,
      22,    1,  136,    2, 0x08 /* Private */,
      23,    1,  139,    2, 0x08 /* Private */,
      24,    1,  142,    2, 0x08 /* Private */,
      25,    1,  145,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,

       0        // eod
};

void core::NormalizationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NormalizationWidget *_t = static_cast<NormalizationWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->normalizationChanged((*reinterpret_cast< Normalization*(*)>(_a[1]))); break;
        case 1: _t->typeChanged((*reinterpret_cast< const Normalization::Type(*)>(_a[1]))); break;
        case 2: _t->amplitudeValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->elongationValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->thresholdValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->minValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->maxValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->amplitudeTimeout(); break;
        case 8: _t->elongationTimeout(); break;
        case 9: _t->maxValueTimeout(); break;
        case 10: _t->minValueTimeout(); break;
        case 11: _t->thresholdTimeout(); break;
        case 12: _t->cbNormalizationIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->onAmplitudeValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->onElongationValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->onThresholdChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->onMinValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->onMaxValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Normalization* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NormalizationWidget::*_t)(Normalization * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::normalizationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NormalizationWidget::*_t)(const Normalization::Type & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::typeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NormalizationWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::amplitudeValueChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NormalizationWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::elongationValueChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (NormalizationWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::thresholdValueChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (NormalizationWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::minValueChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (NormalizationWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::maxValueChanged)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject core::NormalizationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_core__NormalizationWidget.data,
      qt_meta_data_core__NormalizationWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *core::NormalizationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *core::NormalizationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_core__NormalizationWidget.stringdata0))
        return static_cast<void*>(const_cast< NormalizationWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int core::NormalizationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void core::NormalizationWidget::normalizationChanged(Normalization * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void core::NormalizationWidget::typeChanged(const Normalization::Type & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void core::NormalizationWidget::amplitudeValueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void core::NormalizationWidget::elongationValueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void core::NormalizationWidget::thresholdValueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void core::NormalizationWidget::minValueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void core::NormalizationWidget::maxValueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE