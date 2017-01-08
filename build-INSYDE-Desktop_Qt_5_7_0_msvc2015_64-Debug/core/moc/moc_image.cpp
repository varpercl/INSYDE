/****************************************************************************
** Meta object code from reading C++ file 'image.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/image.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'image.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_core__Image_t {
    QByteArrayData data[12];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_core__Image_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_core__Image_t qt_meta_stringdata_core__Image = {
    {
QT_MOC_LITERAL(0, 0, 11), // "core::Image"
QT_MOC_LITERAL(1, 12, 11), // "imageChange"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 3), // "img"
QT_MOC_LITERAL(4, 29, 9), // "copyClick"
QT_MOC_LITERAL(5, 39, 14), // "copyImageClick"
QT_MOC_LITERAL(6, 54, 8), // "cutClick"
QT_MOC_LITERAL(7, 63, 10), // "pasteClick"
QT_MOC_LITERAL(8, 74, 9), // "saveClick"
QT_MOC_LITERAL(9, 84, 13), // "propertyClick"
QT_MOC_LITERAL(10, 98, 18), // "onChangeImageClick"
QT_MOC_LITERAL(11, 117, 6) // "getXML"

    },
    "core::Image\0imageChange\0\0img\0copyClick\0"
    "copyImageClick\0cutClick\0pasteClick\0"
    "saveClick\0propertyClick\0onChangeImageClick\0"
    "getXML"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_core__Image[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x09 /* Protected */,
       5,    0,   63,    2, 0x09 /* Protected */,
       6,    0,   64,    2, 0x09 /* Protected */,
       7,    0,   65,    2, 0x09 /* Protected */,
       8,    0,   66,    2, 0x09 /* Protected */,
       9,    0,   67,    2, 0x09 /* Protected */,
      10,    0,   68,    2, 0x09 /* Protected */,
      11,    0,   69,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,

       0        // eod
};

void core::Image::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Image *_t = static_cast<Image *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageChange((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->copyClick(); break;
        case 2: _t->copyImageClick(); break;
        case 3: _t->cutClick(); break;
        case 4: _t->pasteClick(); break;
        case 5: _t->saveClick(); break;
        case 6: _t->propertyClick(); break;
        case 7: _t->onChangeImageClick(); break;
        case 8: { QString _r = _t->getXML();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Image::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Image::imageChange)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject core::Image::staticMetaObject = {
    { &GraphicObject::staticMetaObject, qt_meta_stringdata_core__Image.data,
      qt_meta_data_core__Image,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *core::Image::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *core::Image::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_core__Image.stringdata0))
        return static_cast<void*>(const_cast< Image*>(this));
    return GraphicObject::qt_metacast(_clname);
}

int core::Image::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void core::Image::imageChange(const QImage & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
