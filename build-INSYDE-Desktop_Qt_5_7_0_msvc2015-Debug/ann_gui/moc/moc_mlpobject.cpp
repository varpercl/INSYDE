/****************************************************************************
** Meta object code from reading C++ file 'mlpobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/ann_gui/mlpobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mlpobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MLPObject_t {
    QByteArrayData data[21];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLPObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLPObject_t qt_meta_stringdata_MLPObject = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MLPObject"
QT_MOC_LITERAL(1, 10, 13), // "outputChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 41, 7), // "outputs"
QT_MOC_LITERAL(5, 49, 13), // "QVector<char>"
QT_MOC_LITERAL(6, 63, 5), // "chars"
QT_MOC_LITERAL(7, 69, 9), // "copyClick"
QT_MOC_LITERAL(8, 79, 8), // "cutClick"
QT_MOC_LITERAL(9, 88, 10), // "pasteClick"
QT_MOC_LITERAL(10, 99, 9), // "saveClick"
QT_MOC_LITERAL(11, 109, 13), // "propertyClick"
QT_MOC_LITERAL(12, 123, 17), // "openOnWindowClick"
QT_MOC_LITERAL(13, 141, 18), // "onAddToTrainingSet"
QT_MOC_LITERAL(14, 160, 24), // "onDotMatrixStatusChanged"
QT_MOC_LITERAL(15, 185, 12), // "QVector<int>"
QT_MOC_LITERAL(16, 198, 11), // "vector<int>"
QT_MOC_LITERAL(17, 210, 12), // "onTrainClick"
QT_MOC_LITERAL(18, 223, 14), // "onAnalizeClick"
QT_MOC_LITERAL(19, 238, 17), // "updateInputCursor"
QT_MOC_LITERAL(20, 256, 3) // "pos"

    },
    "MLPObject\0outputChanged\0\0QVector<double>\0"
    "outputs\0QVector<char>\0chars\0copyClick\0"
    "cutClick\0pasteClick\0saveClick\0"
    "propertyClick\0openOnWindowClick\0"
    "onAddToTrainingSet\0onDotMatrixStatusChanged\0"
    "QVector<int>\0vector<int>\0onTrainClick\0"
    "onAnalizeClick\0updateInputCursor\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLPObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       1,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   90,    2, 0x09 /* Protected */,
       8,    0,   91,    2, 0x09 /* Protected */,
       9,    0,   92,    2, 0x09 /* Protected */,
      10,    0,   93,    2, 0x09 /* Protected */,
      11,    0,   94,    2, 0x09 /* Protected */,
      12,    0,   95,    2, 0x09 /* Protected */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,
      14,    1,  100,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,
      18,    0,  104,    2, 0x08 /* Private */,
      19,    1,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    4,
    QMetaType::Void, 0x80000000 | 16,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,

       0        // eod
};

void MLPObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLPObject *_t = static_cast<MLPObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->outputChanged((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 1: _t->outputChanged((*reinterpret_cast< QVector<char>(*)>(_a[1]))); break;
        case 2: _t->copyClick(); break;
        case 3: _t->cutClick(); break;
        case 4: _t->pasteClick(); break;
        case 5: _t->saveClick(); break;
        case 6: _t->propertyClick(); break;
        case 7: _t->openOnWindowClick(); break;
        case 8: _t->onAddToTrainingSet(); break;
        case 9: _t->onDotMatrixStatusChanged((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 10: _t->onDotMatrixStatusChanged((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 11: _t->onTrainClick(); break;
        case 12: _t->onAnalizeClick(); break;
        case 13: _t->updateInputCursor((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<char> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MLPObject::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLPObject::outputChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MLPObject::*_t)(QVector<char> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MLPObject::outputChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MLPObject::staticMetaObject = {
    { &GraphicObject::staticMetaObject, qt_meta_stringdata_MLPObject.data,
      qt_meta_data_MLPObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLPObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLPObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MLPObject.stringdata0))
        return static_cast<void*>(const_cast< MLPObject*>(this));
    return GraphicObject::qt_metacast(_clname);
}

int MLPObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MLPObject::outputChanged(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MLPObject::outputChanged(QVector<char> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
