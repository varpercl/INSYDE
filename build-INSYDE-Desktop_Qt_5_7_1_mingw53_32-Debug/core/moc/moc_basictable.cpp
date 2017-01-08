/****************************************************************************
** Meta object code from reading C++ file 'basictable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/basictable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basictable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BasicTable_t {
    QByteArrayData data[18];
    char stringdata0[309];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BasicTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BasicTable_t qt_meta_stringdata_BasicTable = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BasicTable"
QT_MOC_LITERAL(1, 11, 20), // "selectedItemsChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "QItemSelection"
QT_MOC_LITERAL(4, 48, 8), // "selected"
QT_MOC_LITERAL(5, 57, 10), // "deselected"
QT_MOC_LITERAL(6, 68, 9), // "copyClick"
QT_MOC_LITERAL(7, 78, 8), // "cutClick"
QT_MOC_LITERAL(8, 87, 10), // "pasteClick"
QT_MOC_LITERAL(9, 98, 28), // "onInsertRightColumnTriggered"
QT_MOC_LITERAL(10, 127, 27), // "onInsertLeftColumnTriggered"
QT_MOC_LITERAL(11, 155, 23), // "onRemoveColumnTriggered"
QT_MOC_LITERAL(12, 179, 22), // "onInsertUpRowTriggered"
QT_MOC_LITERAL(13, 202, 24), // "onInsertDownRowTriggered"
QT_MOC_LITERAL(14, 227, 20), // "onRemoveRowTriggered"
QT_MOC_LITERAL(15, 248, 29), // "onHorizontalHeaderContextMenu"
QT_MOC_LITERAL(16, 278, 2), // "pt"
QT_MOC_LITERAL(17, 281, 27) // "onVerticalHeaderContextMenu"

    },
    "BasicTable\0selectedItemsChanged\0\0"
    "QItemSelection\0selected\0deselected\0"
    "copyClick\0cutClick\0pasteClick\0"
    "onInsertRightColumnTriggered\0"
    "onInsertLeftColumnTriggered\0"
    "onRemoveColumnTriggered\0onInsertUpRowTriggered\0"
    "onInsertDownRowTriggered\0onRemoveRowTriggered\0"
    "onHorizontalHeaderContextMenu\0pt\0"
    "onVerticalHeaderContextMenu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BasicTable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   79,    2, 0x0a /* Public */,
       7,    0,   80,    2, 0x0a /* Public */,
       8,    0,   81,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x09 /* Protected */,
      10,    0,   83,    2, 0x09 /* Protected */,
      11,    0,   84,    2, 0x09 /* Protected */,
      12,    0,   85,    2, 0x09 /* Protected */,
      13,    0,   86,    2, 0x09 /* Protected */,
      14,    0,   87,    2, 0x09 /* Protected */,
      15,    1,   88,    2, 0x08 /* Private */,
      17,    1,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   16,
    QMetaType::Void, QMetaType::QPoint,   16,

       0        // eod
};

void BasicTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BasicTable *_t = static_cast<BasicTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectedItemsChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 1: _t->copyClick(); break;
        case 2: _t->cutClick(); break;
        case 3: _t->pasteClick(); break;
        case 4: _t->onInsertRightColumnTriggered(); break;
        case 5: _t->onInsertLeftColumnTriggered(); break;
        case 6: _t->onRemoveColumnTriggered(); break;
        case 7: _t->onInsertUpRowTriggered(); break;
        case 8: _t->onInsertDownRowTriggered(); break;
        case 9: _t->onRemoveRowTriggered(); break;
        case 10: _t->onHorizontalHeaderContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 11: _t->onVerticalHeaderContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BasicTable::*_t)(const QItemSelection & , const QItemSelection & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BasicTable::selectedItemsChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject BasicTable::staticMetaObject = {
    { &QTableView::staticMetaObject, qt_meta_stringdata_BasicTable.data,
      qt_meta_data_BasicTable,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BasicTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BasicTable::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BasicTable.stringdata0))
        return static_cast<void*>(const_cast< BasicTable*>(this));
    if (!strcmp(_clname, "ClipboardInterface"))
        return static_cast< ClipboardInterface*>(const_cast< BasicTable*>(this));
    return QTableView::qt_metacast(_clname);
}

int BasicTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void BasicTable::selectedItemsChanged(const QItemSelection & _t1, const QItemSelection & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
