/****************************************************************************
** Meta object code from reading C++ file 'mlp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/ann_base/mlp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mlp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ann_base__MultilayerPerceptron_t {
    QByteArrayData data[26];
    char stringdata0[305];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ann_base__MultilayerPerceptron_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ann_base__MultilayerPerceptron_t qt_meta_stringdata_ann_base__MultilayerPerceptron = {
    {
QT_MOC_LITERAL(0, 0, 30), // "ann_base::MultilayerPerceptron"
QT_MOC_LITERAL(1, 31, 18), // "trainingAboutStart"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 16), // "trainingFinished"
QT_MOC_LITERAL(4, 68, 17), // "MLPTrainingResult"
QT_MOC_LITERAL(5, 86, 4), // "tres"
QT_MOC_LITERAL(6, 91, 13), // "elapsedEpochs"
QT_MOC_LITERAL(7, 105, 11), // "elapsedTime"
QT_MOC_LITERAL(8, 117, 12), // "appendRecord"
QT_MOC_LITERAL(9, 130, 3), // "mse"
QT_MOC_LITERAL(10, 134, 4), // "rmse"
QT_MOC_LITERAL(11, 139, 2), // "ce"
QT_MOC_LITERAL(12, 142, 14), // "weightsChanged"
QT_MOC_LITERAL(13, 157, 17), // "layerCountChanged"
QT_MOC_LITERAL(14, 175, 4), // "last"
QT_MOC_LITERAL(15, 180, 8), // "newCount"
QT_MOC_LITERAL(16, 189, 17), // "outputSizeChanged"
QT_MOC_LITERAL(17, 207, 8), // "lastSize"
QT_MOC_LITERAL(18, 216, 7), // "newSize"
QT_MOC_LITERAL(19, 224, 12), // "layerRemoved"
QT_MOC_LITERAL(20, 237, 5), // "index"
QT_MOC_LITERAL(21, 243, 16), // "layerSizeChanged"
QT_MOC_LITERAL(22, 260, 5), // "layer"
QT_MOC_LITERAL(23, 266, 8), // "finished"
QT_MOC_LITERAL(24, 275, 13), // "onTimeTrigger"
QT_MOC_LITERAL(25, 289, 15) // "onRecordAppened"

    },
    "ann_base::MultilayerPerceptron\0"
    "trainingAboutStart\0\0trainingFinished\0"
    "MLPTrainingResult\0tres\0elapsedEpochs\0"
    "elapsedTime\0appendRecord\0mse\0rmse\0ce\0"
    "weightsChanged\0layerCountChanged\0last\0"
    "newCount\0outputSizeChanged\0lastSize\0"
    "newSize\0layerRemoved\0index\0layerSizeChanged\0"
    "layer\0finished\0onTimeTrigger\0"
    "onRecordAppened"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ann_base__MultilayerPerceptron[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       3,    1,  101,    2, 0x06 /* Public */,
       6,    1,  104,    2, 0x06 /* Public */,
       7,    1,  107,    2, 0x06 /* Public */,
       8,    3,  110,    2, 0x06 /* Public */,
      12,    0,  117,    2, 0x06 /* Public */,
      13,    2,  118,    2, 0x06 /* Public */,
      13,    0,  123,    2, 0x06 /* Public */,
      16,    0,  124,    2, 0x06 /* Public */,
      16,    2,  125,    2, 0x06 /* Public */,
      19,    1,  130,    2, 0x06 /* Public */,
      21,    3,  133,    2, 0x06 /* Public */,
      21,    1,  140,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    0,  143,    2, 0x08 /* Private */,
      24,    0,  144,    2, 0x08 /* Private */,
      25,    3,  145,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    9,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   22,   17,   18,
    QMetaType::Void, QMetaType::Int,   22,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    9,   10,   11,

       0        // eod
};

void ann_base::MultilayerPerceptron::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MultilayerPerceptron *_t = static_cast<MultilayerPerceptron *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->trainingAboutStart(); break;
        case 1: _t->trainingFinished(); break;
        case 2: _t->trainingFinished((*reinterpret_cast< const MLPTrainingResult(*)>(_a[1]))); break;
        case 3: _t->elapsedEpochs((*reinterpret_cast< const MLPTrainingResult(*)>(_a[1]))); break;
        case 4: _t->elapsedTime((*reinterpret_cast< const MLPTrainingResult(*)>(_a[1]))); break;
        case 5: _t->appendRecord((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 6: _t->weightsChanged(); break;
        case 7: _t->layerCountChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->layerCountChanged(); break;
        case 9: _t->outputSizeChanged(); break;
        case 10: _t->outputSizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->layerRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->layerSizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->layerSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->finished(); break;
        case 15: _t->onTimeTrigger(); break;
        case 16: _t->onRecordAppened((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MultilayerPerceptron::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::trainingAboutStart)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::trainingFinished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(const MLPTrainingResult );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::trainingFinished)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(const MLPTrainingResult );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::elapsedEpochs)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(const MLPTrainingResult );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::elapsedTime)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::appendRecord)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::weightsChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::layerCountChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::layerCountChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::outputSizeChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::outputSizeChanged)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::layerRemoved)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::layerSizeChanged)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::layerSizeChanged)) {
                *result = 13;
                return;
            }
        }
    }
}

const QMetaObject ann_base::MultilayerPerceptron::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ann_base__MultilayerPerceptron.data,
      qt_meta_data_ann_base__MultilayerPerceptron,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ann_base::MultilayerPerceptron::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ann_base::MultilayerPerceptron::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ann_base__MultilayerPerceptron.stringdata0))
        return static_cast<void*>(const_cast< MultilayerPerceptron*>(this));
    if (!strcmp(_clname, "ArtificialNeuralNetwork"))
        return static_cast< ArtificialNeuralNetwork*>(const_cast< MultilayerPerceptron*>(this));
    return QThread::qt_metacast(_clname);
}

int ann_base::MultilayerPerceptron::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void ann_base::MultilayerPerceptron::trainingAboutStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ann_base::MultilayerPerceptron::trainingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ann_base::MultilayerPerceptron::trainingFinished(const MLPTrainingResult _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ann_base::MultilayerPerceptron::elapsedEpochs(const MLPTrainingResult _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ann_base::MultilayerPerceptron::elapsedTime(const MLPTrainingResult _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ann_base::MultilayerPerceptron::appendRecord(double _t1, double _t2, double _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ann_base::MultilayerPerceptron::weightsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void ann_base::MultilayerPerceptron::layerCountChanged(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ann_base::MultilayerPerceptron::layerCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void ann_base::MultilayerPerceptron::outputSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void ann_base::MultilayerPerceptron::outputSizeChanged(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void ann_base::MultilayerPerceptron::layerRemoved(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ann_base::MultilayerPerceptron::layerSizeChanged(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void ann_base::MultilayerPerceptron::layerSizeChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_END_MOC_NAMESPACE
