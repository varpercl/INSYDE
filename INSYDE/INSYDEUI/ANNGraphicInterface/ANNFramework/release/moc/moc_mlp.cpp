/****************************************************************************
** Meta object code from reading C++ file 'mlp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mlp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mlp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MultilayerPerceptron_t {
    QByteArrayData data[14];
    char stringdata[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MultilayerPerceptron_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MultilayerPerceptron_t qt_meta_stringdata_MultilayerPerceptron = {
    {
QT_MOC_LITERAL(0, 0, 20), // "MultilayerPerceptron"
QT_MOC_LITERAL(1, 21, 16), // "trainingFinished"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 17), // "MLPTrainingResult"
QT_MOC_LITERAL(4, 57, 4), // "tres"
QT_MOC_LITERAL(5, 62, 13), // "elapsedEpochs"
QT_MOC_LITERAL(6, 76, 11), // "elapsedTime"
QT_MOC_LITERAL(7, 88, 12), // "appendRecord"
QT_MOC_LITERAL(8, 101, 3), // "mse"
QT_MOC_LITERAL(9, 105, 4), // "rmse"
QT_MOC_LITERAL(10, 110, 2), // "ce"
QT_MOC_LITERAL(11, 113, 8), // "finished"
QT_MOC_LITERAL(12, 122, 13), // "onTimeTrigger"
QT_MOC_LITERAL(13, 136, 15) // "onRecordAppened"

    },
    "MultilayerPerceptron\0trainingFinished\0"
    "\0MLPTrainingResult\0tres\0elapsedEpochs\0"
    "elapsedTime\0appendRecord\0mse\0rmse\0ce\0"
    "finished\0onTimeTrigger\0onRecordAppened"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MultilayerPerceptron[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       1,    1,   55,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,
       6,    1,   61,    2, 0x06 /* Public */,
       7,    3,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   71,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    3,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    8,    9,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    8,    9,   10,

       0        // eod
};

void MultilayerPerceptron::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MultilayerPerceptron *_t = static_cast<MultilayerPerceptron *>(_o);
        switch (_id) {
        case 0: _t->trainingFinished(); break;
        case 1: _t->trainingFinished((*reinterpret_cast< const MLPTrainingResult(*)>(_a[1]))); break;
        case 2: _t->elapsedEpochs((*reinterpret_cast< const MLPTrainingResult(*)>(_a[1]))); break;
        case 3: _t->elapsedTime((*reinterpret_cast< const MLPTrainingResult(*)>(_a[1]))); break;
        case 4: _t->appendRecord((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 5: _t->finished(); break;
        case 6: _t->onTimeTrigger(); break;
        case 7: _t->onRecordAppened((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MultilayerPerceptron::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::trainingFinished)) {
                *result = 0;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(const MLPTrainingResult );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::trainingFinished)) {
                *result = 1;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(const MLPTrainingResult );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::elapsedEpochs)) {
                *result = 2;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(const MLPTrainingResult );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::elapsedTime)) {
                *result = 3;
            }
        }
        {
            typedef void (MultilayerPerceptron::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MultilayerPerceptron::appendRecord)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject MultilayerPerceptron::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MultilayerPerceptron.data,
      qt_meta_data_MultilayerPerceptron,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MultilayerPerceptron::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultilayerPerceptron::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MultilayerPerceptron.stringdata))
        return static_cast<void*>(const_cast< MultilayerPerceptron*>(this));
    return QThread::qt_metacast(_clname);
}

int MultilayerPerceptron::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MultilayerPerceptron::trainingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MultilayerPerceptron::trainingFinished(const MLPTrainingResult _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MultilayerPerceptron::elapsedEpochs(const MLPTrainingResult _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MultilayerPerceptron::elapsedTime(const MLPTrainingResult _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MultilayerPerceptron::appendRecord(double _t1, double _t2, double _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
