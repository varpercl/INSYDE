/****************************************************************************
** Meta object code from reading C++ file 'KDChartWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__Widget_t {
    QByteArrayData data[18];
    char stringdata[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__Widget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__Widget_t qt_meta_stringdata_KDChart__Widget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "KDChart::Widget"
QT_MOC_LITERAL(1, 16, 16), // "setGlobalLeading"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "left"
QT_MOC_LITERAL(4, 39, 3), // "top"
QT_MOC_LITERAL(5, 43, 5), // "right"
QT_MOC_LITERAL(6, 49, 6), // "bottom"
QT_MOC_LITERAL(7, 56, 20), // "setGlobalLeadingLeft"
QT_MOC_LITERAL(8, 77, 7), // "leading"
QT_MOC_LITERAL(9, 85, 19), // "setGlobalLeadingTop"
QT_MOC_LITERAL(10, 105, 21), // "setGlobalLeadingRight"
QT_MOC_LITERAL(11, 127, 22), // "setGlobalLeadingBottom"
QT_MOC_LITERAL(12, 150, 7), // "setType"
QT_MOC_LITERAL(13, 158, 9), // "ChartType"
QT_MOC_LITERAL(14, 168, 9), // "chartType"
QT_MOC_LITERAL(15, 178, 7), // "SubType"
QT_MOC_LITERAL(16, 186, 7), // "subType"
QT_MOC_LITERAL(17, 194, 10) // "setSubType"

    },
    "KDChart::Widget\0setGlobalLeading\0\0"
    "left\0top\0right\0bottom\0setGlobalLeadingLeft\0"
    "leading\0setGlobalLeadingTop\0"
    "setGlobalLeadingRight\0setGlobalLeadingBottom\0"
    "setType\0ChartType\0chartType\0SubType\0"
    "subType\0setSubType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   54,    2, 0x0a /* Public */,
       7,    1,   63,    2, 0x0a /* Public */,
       9,    1,   66,    2, 0x0a /* Public */,
      10,    1,   69,    2, 0x0a /* Public */,
      11,    1,   72,    2, 0x0a /* Public */,
      12,    2,   75,    2, 0x0a /* Public */,
      12,    1,   80,    2, 0x2a /* Public | MethodCloned */,
      17,    1,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15,   14,   16,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void KDChart::Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        switch (_id) {
        case 0: _t->setGlobalLeading((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->setGlobalLeadingLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setGlobalLeadingTop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setGlobalLeadingRight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setGlobalLeadingBottom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setType((*reinterpret_cast< ChartType(*)>(_a[1])),(*reinterpret_cast< SubType(*)>(_a[2]))); break;
        case 6: _t->setType((*reinterpret_cast< ChartType(*)>(_a[1]))); break;
        case 7: _t->setSubType((*reinterpret_cast< SubType(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject KDChart::Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_KDChart__Widget.data,
      qt_meta_data_KDChart__Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__Widget.stringdata))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int KDChart::Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
