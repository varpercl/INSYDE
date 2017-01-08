/****************************************************************************
** Meta object code from reading C++ file 'imagerepresentationwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/imagerepresentationwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagerepresentationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_core__ImageRepresentationWidget_t {
    QByteArrayData data[11];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_core__ImageRepresentationWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_core__ImageRepresentationWidget_t qt_meta_stringdata_core__ImageRepresentationWidget = {
    {
QT_MOC_LITERAL(0, 0, 31), // "core::ImageRepresentationWidget"
QT_MOC_LITERAL(1, 32, 18), // "imageFormatChanged"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 14), // "QImage::Format"
QT_MOC_LITERAL(4, 67, 6), // "format"
QT_MOC_LITERAL(5, 74, 18), // "onSizeValueChanged"
QT_MOC_LITERAL(6, 93, 4), // "size"
QT_MOC_LITERAL(7, 98, 36), // "on_cbImageFormat_currentIndex..."
QT_MOC_LITERAL(8, 135, 5), // "index"
QT_MOC_LITERAL(9, 141, 27), // "onIgnoreAlphaChannelToogled"
QT_MOC_LITERAL(10, 169, 2) // "ac"

    },
    "core::ImageRepresentationWidget\0"
    "imageFormatChanged\0\0QImage::Format\0"
    "format\0onSizeValueChanged\0size\0"
    "on_cbImageFormat_currentIndexChanged\0"
    "index\0onIgnoreAlphaChannelToogled\0ac"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_core__ImageRepresentationWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   37,    2, 0x08 /* Private */,
       7,    1,   40,    2, 0x08 /* Private */,
       9,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QSize,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void core::ImageRepresentationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageRepresentationWidget *_t = static_cast<ImageRepresentationWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageFormatChanged((*reinterpret_cast< const QImage::Format(*)>(_a[1]))); break;
        case 1: _t->onSizeValueChanged((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 2: _t->on_cbImageFormat_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onIgnoreAlphaChannelToogled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageRepresentationWidget::*_t)(const QImage::Format & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageRepresentationWidget::imageFormatChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject core::ImageRepresentationWidget::staticMetaObject = {
    { &DataRepresentationWidget::staticMetaObject, qt_meta_stringdata_core__ImageRepresentationWidget.data,
      qt_meta_data_core__ImageRepresentationWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *core::ImageRepresentationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *core::ImageRepresentationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_core__ImageRepresentationWidget.stringdata0))
        return static_cast<void*>(const_cast< ImageRepresentationWidget*>(this));
    if (!strcmp(_clname, "Resizable"))
        return static_cast< Resizable*>(const_cast< ImageRepresentationWidget*>(this));
    return DataRepresentationWidget::qt_metacast(_clname);
}

int core::ImageRepresentationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataRepresentationWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void core::ImageRepresentationWidget::imageFormatChanged(const QImage::Format & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
