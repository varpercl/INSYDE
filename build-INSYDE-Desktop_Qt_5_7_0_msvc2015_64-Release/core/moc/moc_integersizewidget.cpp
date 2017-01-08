/****************************************************************************
** Meta object code from reading C++ file 'integersizewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/integersizewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'integersizewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_core__IntegerSizeWidget_t {
    QByteArrayData data[13];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_core__IntegerSizeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_core__IntegerSizeWidget_t qt_meta_stringdata_core__IntegerSizeWidget = {
    {
QT_MOC_LITERAL(0, 0, 23), // "core::IntegerSizeWidget"
QT_MOC_LITERAL(1, 24, 11), // "sizeChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 3), // "arg"
QT_MOC_LITERAL(4, 41, 12), // "unitsChanged"
QT_MOC_LITERAL(5, 54, 18), // "QPair<Units,Units>"
QT_MOC_LITERAL(6, 73, 12), // "widthChanged"
QT_MOC_LITERAL(7, 86, 2), // "nw"
QT_MOC_LITERAL(8, 89, 13), // "heightChanged"
QT_MOC_LITERAL(9, 103, 2), // "nh"
QT_MOC_LITERAL(10, 106, 15), // "onHeightChanged"
QT_MOC_LITERAL(11, 122, 3), // "val"
QT_MOC_LITERAL(12, 126, 14) // "onWidthChanged"

    },
    "core::IntegerSizeWidget\0sizeChanged\0"
    "\0arg\0unitsChanged\0QPair<Units,Units>\0"
    "widthChanged\0nw\0heightChanged\0nh\0"
    "onHeightChanged\0val\0onWidthChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_core__IntegerSizeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,
       8,    1,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   56,    2, 0x08 /* Private */,
      12,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QSize,    3,
    QMetaType::Void, 0x80000000 | 5,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void core::IntegerSizeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IntegerSizeWidget *_t = static_cast<IntegerSizeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sizeChanged((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        case 1: _t->unitsChanged((*reinterpret_cast< const QPair<Units,Units>(*)>(_a[1]))); break;
        case 2: _t->widthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->heightChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onHeightChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onWidthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IntegerSizeWidget::*_t)(QSize );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IntegerSizeWidget::sizeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (IntegerSizeWidget::*_t)(const QPair<Units,Units> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IntegerSizeWidget::unitsChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (IntegerSizeWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IntegerSizeWidget::widthChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (IntegerSizeWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IntegerSizeWidget::heightChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject core::IntegerSizeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_core__IntegerSizeWidget.data,
      qt_meta_data_core__IntegerSizeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *core::IntegerSizeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *core::IntegerSizeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_core__IntegerSizeWidget.stringdata0))
        return static_cast<void*>(const_cast< IntegerSizeWidget*>(this));
    if (!strcmp(_clname, "Resizable"))
        return static_cast< Resizable*>(const_cast< IntegerSizeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int core::IntegerSizeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void core::IntegerSizeWidget::sizeChanged(QSize _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void core::IntegerSizeWidget::unitsChanged(const QPair<Units,Units> & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void core::IntegerSizeWidget::widthChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void core::IntegerSizeWidget::heightChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
