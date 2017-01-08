/****************************************************************************
** Meta object code from reading C++ file 'imageeffect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/imageeffect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageeffect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageEffect_t {
    QByteArrayData data[10];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageEffect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageEffect_t qt_meta_stringdata_ImageEffect = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ImageEffect"
QT_MOC_LITERAL(1, 12, 9), // "copyClick"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "cutClick"
QT_MOC_LITERAL(4, 32, 10), // "pasteClick"
QT_MOC_LITERAL(5, 43, 9), // "saveClick"
QT_MOC_LITERAL(6, 53, 13), // "propertyClick"
QT_MOC_LITERAL(7, 67, 17), // "openOnWindowClick"
QT_MOC_LITERAL(8, 85, 19), // "onInputImageChanged"
QT_MOC_LITERAL(9, 105, 3) // "img"

    },
    "ImageEffect\0copyClick\0\0cutClick\0"
    "pasteClick\0saveClick\0propertyClick\0"
    "openOnWindowClick\0onInputImageChanged\0"
    "img"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageEffect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x09 /* Protected */,
       3,    0,   50,    2, 0x09 /* Protected */,
       4,    0,   51,    2, 0x09 /* Protected */,
       5,    0,   52,    2, 0x09 /* Protected */,
       6,    0,   53,    2, 0x09 /* Protected */,
       7,    0,   54,    2, 0x09 /* Protected */,
       8,    1,   55,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    9,

       0        // eod
};

void ImageEffect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageEffect *_t = static_cast<ImageEffect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->copyClick(); break;
        case 1: _t->cutClick(); break;
        case 2: _t->pasteClick(); break;
        case 3: _t->saveClick(); break;
        case 4: _t->propertyClick(); break;
        case 5: _t->openOnWindowClick(); break;
        case 6: _t->onInputImageChanged((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ImageEffect::staticMetaObject = {
    { &Cursor::staticMetaObject, qt_meta_stringdata_ImageEffect.data,
      qt_meta_data_ImageEffect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageEffect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageEffect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageEffect.stringdata0))
        return static_cast<void*>(const_cast< ImageEffect*>(this));
    return Cursor::qt_metacast(_clname);
}

int ImageEffect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Cursor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
