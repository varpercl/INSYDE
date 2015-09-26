/****************************************************************************
** Meta object code from reading C++ file 'kdganttview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDGantt/kdganttview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kdganttview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDGantt__View_t {
    QByteArrayData data[24];
    char stringdata[354];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDGantt__View_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDGantt__View_t qt_meta_stringdata_KDGantt__View = {
    {
QT_MOC_LITERAL(0, 0, 13), // "KDGantt::View"
QT_MOC_LITERAL(1, 14, 13), // "slotCollapsed"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "slotExpanded"
QT_MOC_LITERAL(4, 42, 30), // "slotVerticalScrollValueChanged"
QT_MOC_LITERAL(5, 73, 34), // "slotLeftWidgetVerticalRangeCh..."
QT_MOC_LITERAL(6, 108, 31), // "slotGfxViewVerticalRangeChanged"
QT_MOC_LITERAL(7, 140, 8), // "setModel"
QT_MOC_LITERAL(8, 149, 19), // "QAbstractItemModel*"
QT_MOC_LITERAL(9, 169, 5), // "model"
QT_MOC_LITERAL(10, 175, 12), // "setRootIndex"
QT_MOC_LITERAL(11, 188, 3), // "idx"
QT_MOC_LITERAL(12, 192, 17), // "setSelectionModel"
QT_MOC_LITERAL(13, 210, 20), // "QItemSelectionModel*"
QT_MOC_LITERAL(14, 231, 6), // "smodel"
QT_MOC_LITERAL(15, 238, 15), // "setItemDelegate"
QT_MOC_LITERAL(16, 254, 13), // "ItemDelegate*"
QT_MOC_LITERAL(17, 268, 18), // "setConstraintModel"
QT_MOC_LITERAL(18, 287, 16), // "ConstraintModel*"
QT_MOC_LITERAL(19, 304, 7), // "setGrid"
QT_MOC_LITERAL(20, 312, 13), // "AbstractGrid*"
QT_MOC_LITERAL(21, 326, 9), // "expandAll"
QT_MOC_LITERAL(22, 336, 5), // "index"
QT_MOC_LITERAL(23, 342, 11) // "collapseAll"

    },
    "KDGantt::View\0slotCollapsed\0\0slotExpanded\0"
    "slotVerticalScrollValueChanged\0"
    "slotLeftWidgetVerticalRangeChanged\0"
    "slotGfxViewVerticalRangeChanged\0"
    "setModel\0QAbstractItemModel*\0model\0"
    "setRootIndex\0idx\0setSelectionModel\0"
    "QItemSelectionModel*\0smodel\0setItemDelegate\0"
    "ItemDelegate*\0setConstraintModel\0"
    "ConstraintModel*\0setGrid\0AbstractGrid*\0"
    "expandAll\0index\0collapseAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDGantt__View[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       3,    1,   92,    2, 0x08 /* Private */,
       4,    1,   95,    2, 0x08 /* Private */,
       5,    2,   98,    2, 0x08 /* Private */,
       6,    2,  103,    2, 0x08 /* Private */,
       7,    1,  108,    2, 0x0a /* Public */,
      10,    1,  111,    2, 0x0a /* Public */,
      12,    1,  114,    2, 0x0a /* Public */,
      15,    1,  117,    2, 0x0a /* Public */,
      17,    1,  120,    2, 0x0a /* Public */,
      19,    1,  123,    2, 0x0a /* Public */,
      21,    1,  126,    2, 0x0a /* Public */,
      21,    0,  129,    2, 0x2a /* Public | MethodCloned */,
      23,    1,  130,    2, 0x0a /* Public */,
      23,    0,  133,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QModelIndex,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, QMetaType::QModelIndex,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   22,
    QMetaType::Void,

       0        // eod
};

void KDGantt::View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        View *_t = static_cast<View *>(_o);
        switch (_id) {
        case 0: _t->d->slotCollapsed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->d->slotExpanded((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->d->slotVerticalScrollValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->d->slotLeftWidgetVerticalRangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->d->slotGfxViewVerticalRangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->setModel((*reinterpret_cast< QAbstractItemModel*(*)>(_a[1]))); break;
        case 6: _t->setRootIndex((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->setSelectionModel((*reinterpret_cast< QItemSelectionModel*(*)>(_a[1]))); break;
        case 8: _t->setItemDelegate((*reinterpret_cast< ItemDelegate*(*)>(_a[1]))); break;
        case 9: _t->setConstraintModel((*reinterpret_cast< ConstraintModel*(*)>(_a[1]))); break;
        case 10: _t->setGrid((*reinterpret_cast< AbstractGrid*(*)>(_a[1]))); break;
        case 11: _t->expandAll((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 12: _t->expandAll(); break;
        case 13: _t->collapseAll((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 14: _t->collapseAll(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractItemModel* >(); break;
            }
            break;
        }
    }
}

const QMetaObject KDGantt::View::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_KDGantt__View.data,
      qt_meta_data_KDGantt__View,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDGantt::View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDGantt::View::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDGantt__View.stringdata))
        return static_cast<void*>(const_cast< View*>(this));
    return QWidget::qt_metacast(_clname);
}

int KDGantt::View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
