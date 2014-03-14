/****************************************************************************
** Meta object code from reading C++ file 'imagerepresentationwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ANNGraphicInterface/imagerepresentationwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagerepresentationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageRepresentationWidget_t {
    QByteArrayData data[6];
    char stringdata[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ImageRepresentationWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ImageRepresentationWidget_t qt_meta_stringdata_ImageRepresentationWidget = {
    {
QT_MOC_LITERAL(0, 0, 25),
QT_MOC_LITERAL(1, 26, 18),
QT_MOC_LITERAL(2, 45, 0),
QT_MOC_LITERAL(3, 46, 4),
QT_MOC_LITERAL(4, 51, 36),
QT_MOC_LITERAL(5, 88, 5)
    },
    "ImageRepresentationWidget\0onSizeValueChanged\0"
    "\0size\0on_cbImageFormat_currentIndexChanged\0"
    "index\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageRepresentationWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x09,
       4,    1,   27,    2, 0x09,

 // slots: parameters
    QMetaType::Void, QMetaType::QSize,    3,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void ImageRepresentationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageRepresentationWidget *_t = static_cast<ImageRepresentationWidget *>(_o);
        switch (_id) {
        case 0: _t->onSizeValueChanged((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 1: _t->on_cbImageFormat_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ImageRepresentationWidget::staticMetaObject = {
    { &RepresentationWidget::staticMetaObject, qt_meta_stringdata_ImageRepresentationWidget.data,
      qt_meta_data_ImageRepresentationWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ImageRepresentationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageRepresentationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageRepresentationWidget.stringdata))
        return static_cast<void*>(const_cast< ImageRepresentationWidget*>(this));
    return RepresentationWidget::qt_metacast(_clname);
}

int ImageRepresentationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RepresentationWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
