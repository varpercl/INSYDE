/****************************************************************************
** Meta object code from reading C++ file 'dotmatrix.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/dotmatrix.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dotmatrix.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DotMatrix_t {
    QByteArrayData data[28];
    char stringdata0[331];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DotMatrix_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DotMatrix_t qt_meta_stringdata_DotMatrix = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DotMatrix"
QT_MOC_LITERAL(1, 10, 13), // "statusChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 22), // "QVector<QVector<int> >"
QT_MOC_LITERAL(4, 48, 6), // "matrix"
QT_MOC_LITERAL(5, 55, 12), // "QVector<int>"
QT_MOC_LITERAL(6, 68, 6), // "inputs"
QT_MOC_LITERAL(7, 75, 15), // "rowCountChanged"
QT_MOC_LITERAL(8, 91, 5), // "value"
QT_MOC_LITERAL(9, 97, 15), // "colCountChanged"
QT_MOC_LITERAL(10, 113, 14), // "dotSizeChanged"
QT_MOC_LITERAL(11, 128, 17), // "matrixSizeChanged"
QT_MOC_LITERAL(12, 146, 4), // "size"
QT_MOC_LITERAL(13, 151, 26), // "setEnableContinuousDrawing"
QT_MOC_LITERAL(14, 178, 1), // "b"
QT_MOC_LITERAL(15, 180, 18), // "setEnableEraserPen"
QT_MOC_LITERAL(16, 199, 7), // "setRows"
QT_MOC_LITERAL(17, 207, 7), // "setCols"
QT_MOC_LITERAL(18, 215, 10), // "setDotSize"
QT_MOC_LITERAL(19, 226, 13), // "setMatrixSize"
QT_MOC_LITERAL(20, 240, 9), // "copyClick"
QT_MOC_LITERAL(21, 250, 8), // "cutClick"
QT_MOC_LITERAL(22, 259, 10), // "pasteClick"
QT_MOC_LITERAL(23, 270, 9), // "saveClick"
QT_MOC_LITERAL(24, 280, 13), // "propertyClick"
QT_MOC_LITERAL(25, 294, 14), // "onClearClicked"
QT_MOC_LITERAL(26, 309, 7), // "checked"
QT_MOC_LITERAL(27, 317, 13) // "onFillClicked"

    },
    "DotMatrix\0statusChanged\0\0"
    "QVector<QVector<int> >\0matrix\0"
    "QVector<int>\0inputs\0rowCountChanged\0"
    "value\0colCountChanged\0dotSizeChanged\0"
    "matrixSizeChanged\0size\0"
    "setEnableContinuousDrawing\0b\0"
    "setEnableEraserPen\0setRows\0setCols\0"
    "setDotSize\0setMatrixSize\0copyClick\0"
    "cutClick\0pasteClick\0saveClick\0"
    "propertyClick\0onClearClicked\0checked\0"
    "onFillClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DotMatrix[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       1,    1,  112,    2, 0x06 /* Public */,
       7,    1,  115,    2, 0x06 /* Public */,
       9,    1,  118,    2, 0x06 /* Public */,
      10,    1,  121,    2, 0x06 /* Public */,
      11,    1,  124,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  127,    2, 0x0a /* Public */,
      15,    1,  130,    2, 0x0a /* Public */,
      16,    1,  133,    2, 0x0a /* Public */,
      17,    1,  136,    2, 0x0a /* Public */,
      18,    1,  139,    2, 0x0a /* Public */,
      19,    1,  142,    2, 0x0a /* Public */,
      20,    0,  145,    2, 0x09 /* Protected */,
      21,    0,  146,    2, 0x09 /* Protected */,
      22,    0,  147,    2, 0x09 /* Protected */,
      23,    0,  148,    2, 0x09 /* Protected */,
      24,    0,  149,    2, 0x09 /* Protected */,
      25,    1,  150,    2, 0x08 /* Private */,
      27,    1,  153,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QSize,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QSize,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,

       0        // eod
};

void DotMatrix::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DotMatrix *_t = static_cast<DotMatrix *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->statusChanged((*reinterpret_cast< const QVector<QVector<int> >(*)>(_a[1]))); break;
        case 1: _t->statusChanged((*reinterpret_cast< const QVector<int>(*)>(_a[1]))); break;
        case 2: _t->rowCountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->colCountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->dotSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->matrixSizeChanged((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 6: _t->setEnableContinuousDrawing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setEnableEraserPen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setRows((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setCols((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setDotSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setMatrixSize((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 12: _t->copyClick(); break;
        case 13: _t->cutClick(); break;
        case 14: _t->pasteClick(); break;
        case 15: _t->saveClick(); break;
        case 16: _t->propertyClick(); break;
        case 17: _t->onClearClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->onFillClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<int> > >(); break;
            }
            break;
        case 1:
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
            typedef void (DotMatrix::*_t)(const QVector<QVector<int> > & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DotMatrix::statusChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DotMatrix::*_t)(const QVector<int> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DotMatrix::statusChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DotMatrix::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DotMatrix::rowCountChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DotMatrix::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DotMatrix::colCountChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (DotMatrix::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DotMatrix::dotSizeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (DotMatrix::*_t)(const QSize & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DotMatrix::matrixSizeChanged)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject DotMatrix::staticMetaObject = {
    { &GraphicObject::staticMetaObject, qt_meta_stringdata_DotMatrix.data,
      qt_meta_data_DotMatrix,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DotMatrix::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DotMatrix::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DotMatrix.stringdata0))
        return static_cast<void*>(const_cast< DotMatrix*>(this));
    return GraphicObject::qt_metacast(_clname);
}

int DotMatrix::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void DotMatrix::statusChanged(const QVector<QVector<int> > & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DotMatrix::statusChanged(const QVector<int> & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DotMatrix::rowCountChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DotMatrix::colCountChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DotMatrix::dotSizeChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DotMatrix::matrixSizeChanged(const QSize & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
