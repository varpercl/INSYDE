/****************************************************************************
** Meta object code from reading C++ file 'datarepresentationbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/datarepresentationbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datarepresentationbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_core__DataRepresentationBox_t {
    QByteArrayData data[9];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_core__DataRepresentationBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_core__DataRepresentationBox_t qt_meta_stringdata_core__DataRepresentationBox = {
    {
QT_MOC_LITERAL(0, 0, 27), // "core::DataRepresentationBox"
QT_MOC_LITERAL(1, 28, 24), // "changeDataRepresentation"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 5), // "index"
QT_MOC_LITERAL(4, 60, 13), // "onSizeChanged"
QT_MOC_LITERAL(5, 74, 4), // "size"
QT_MOC_LITERAL(6, 79, 20), // "onImageFormatChanged"
QT_MOC_LITERAL(7, 100, 14), // "QImage::Format"
QT_MOC_LITERAL(8, 115, 6) // "format"

    },
    "core::DataRepresentationBox\0"
    "changeDataRepresentation\0\0index\0"
    "onSizeChanged\0size\0onImageFormatChanged\0"
    "QImage::Format\0format"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_core__DataRepresentationBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    1,   32,    2, 0x08 /* Private */,
       6,    1,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QSize,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void core::DataRepresentationBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataRepresentationBox *_t = static_cast<DataRepresentationBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeDataRepresentation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onSizeChanged((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 2: _t->onImageFormatChanged((*reinterpret_cast< const QImage::Format(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject core::DataRepresentationBox::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_core__DataRepresentationBox.data,
      qt_meta_data_core__DataRepresentationBox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *core::DataRepresentationBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *core::DataRepresentationBox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_core__DataRepresentationBox.stringdata0))
        return static_cast<void*>(const_cast< DataRepresentationBox*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int core::DataRepresentationBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
