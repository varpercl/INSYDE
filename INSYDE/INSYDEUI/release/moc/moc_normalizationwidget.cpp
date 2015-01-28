/****************************************************************************
** Meta object code from reading C++ file 'normalizationwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ANNGraphicInterface/normalizationwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'normalizationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NormalizationWidget_t {
    QByteArrayData data[18];
    char stringdata[316];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NormalizationWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NormalizationWidget_t qt_meta_stringdata_NormalizationWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "NormalizationWidget"
QT_MOC_LITERAL(1, 20, 20), // "normalizationChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 13), // "Normalization"
QT_MOC_LITERAL(4, 56, 3), // "nor"
QT_MOC_LITERAL(5, 60, 21), // "amplitudeValueChanged"
QT_MOC_LITERAL(6, 82, 3), // "val"
QT_MOC_LITERAL(7, 86, 22), // "elongationValueChanged"
QT_MOC_LITERAL(8, 109, 21), // "thresholdValueChanged"
QT_MOC_LITERAL(9, 131, 15), // "minValueChanged"
QT_MOC_LITERAL(10, 147, 15), // "maxValueChanged"
QT_MOC_LITERAL(11, 163, 42), // "on_cbNormalizationType_curren..."
QT_MOC_LITERAL(12, 206, 5), // "index"
QT_MOC_LITERAL(13, 212, 23), // "onAmplitudeValueChanged"
QT_MOC_LITERAL(14, 236, 24), // "onElongationValueChanged"
QT_MOC_LITERAL(15, 261, 18), // "onThresholdChanged"
QT_MOC_LITERAL(16, 280, 17), // "onMinValueChanged"
QT_MOC_LITERAL(17, 298, 17) // "onMaxValueChanged"

    },
    "NormalizationWidget\0normalizationChanged\0"
    "\0Normalization\0nor\0amplitudeValueChanged\0"
    "val\0elongationValueChanged\0"
    "thresholdValueChanged\0minValueChanged\0"
    "maxValueChanged\0"
    "on_cbNormalizationType_currentIndexChanged\0"
    "index\0onAmplitudeValueChanged\0"
    "onElongationValueChanged\0onThresholdChanged\0"
    "onMinValueChanged\0onMaxValueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NormalizationWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,
       7,    1,   80,    2, 0x06 /* Public */,
       8,    1,   83,    2, 0x06 /* Public */,
       9,    1,   86,    2, 0x06 /* Public */,
      10,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   92,    2, 0x08 /* Private */,
      13,    1,   95,    2, 0x08 /* Private */,
      14,    1,   98,    2, 0x08 /* Private */,
      15,    1,  101,    2, 0x08 /* Private */,
      16,    1,  104,    2, 0x08 /* Private */,
      17,    1,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,

       0        // eod
};

void NormalizationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NormalizationWidget *_t = static_cast<NormalizationWidget *>(_o);
        switch (_id) {
        case 0: _t->normalizationChanged((*reinterpret_cast< Normalization(*)>(_a[1]))); break;
        case 1: _t->amplitudeValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->elongationValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->thresholdValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->minValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->maxValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_cbNormalizationType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onAmplitudeValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->onElongationValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->onThresholdChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->onMinValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->onMaxValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NormalizationWidget::*_t)(Normalization );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::normalizationChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (NormalizationWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::amplitudeValueChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (NormalizationWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::elongationValueChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (NormalizationWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::thresholdValueChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (NormalizationWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::minValueChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (NormalizationWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalizationWidget::maxValueChanged)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject NormalizationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NormalizationWidget.data,
      qt_meta_data_NormalizationWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NormalizationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NormalizationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NormalizationWidget.stringdata))
        return static_cast<void*>(const_cast< NormalizationWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int NormalizationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void NormalizationWidget::normalizationChanged(Normalization _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NormalizationWidget::amplitudeValueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NormalizationWidget::elongationValueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NormalizationWidget::thresholdValueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NormalizationWidget::minValueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void NormalizationWidget::maxValueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
