/****************************************************************************
** Meta object code from reading C++ file 'kdganttgraphicsscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDGantt/kdganttgraphicsscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kdganttgraphicsscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDGantt__GraphicsScene_t {
    QByteArrayData data[24];
    char stringdata[350];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDGantt__GraphicsScene_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDGantt__GraphicsScene_t qt_meta_stringdata_KDGantt__GraphicsScene = {
    {
QT_MOC_LITERAL(0, 0, 22), // "KDGantt::GraphicsScene"
QT_MOC_LITERAL(1, 23, 11), // "gridChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "clicked"
QT_MOC_LITERAL(4, 44, 5), // "index"
QT_MOC_LITERAL(5, 50, 12), // "qrealClicked"
QT_MOC_LITERAL(6, 63, 7), // "entered"
QT_MOC_LITERAL(7, 71, 7), // "pressed"
QT_MOC_LITERAL(8, 79, 8), // "setModel"
QT_MOC_LITERAL(9, 88, 19), // "QAbstractItemModel*"
QT_MOC_LITERAL(10, 108, 23), // "setSummaryHandlingModel"
QT_MOC_LITERAL(11, 132, 20), // "QAbstractProxyModel*"
QT_MOC_LITERAL(12, 153, 18), // "setConstraintModel"
QT_MOC_LITERAL(13, 172, 16), // "ConstraintModel*"
QT_MOC_LITERAL(14, 189, 12), // "setRootIndex"
QT_MOC_LITERAL(15, 202, 3), // "idx"
QT_MOC_LITERAL(16, 206, 17), // "setSelectionModel"
QT_MOC_LITERAL(17, 224, 20), // "QItemSelectionModel*"
QT_MOC_LITERAL(18, 245, 14), // "selectionmodel"
QT_MOC_LITERAL(19, 260, 11), // "setReadOnly"
QT_MOC_LITERAL(20, 272, 19), // "slotConstraintAdded"
QT_MOC_LITERAL(21, 292, 19), // "KDGantt::Constraint"
QT_MOC_LITERAL(22, 312, 21), // "slotConstraintRemoved"
QT_MOC_LITERAL(23, 334, 15) // "slotGridChanged"

    },
    "KDGantt::GraphicsScene\0gridChanged\0\0"
    "clicked\0index\0qrealClicked\0entered\0"
    "pressed\0setModel\0QAbstractItemModel*\0"
    "setSummaryHandlingModel\0QAbstractProxyModel*\0"
    "setConstraintModel\0ConstraintModel*\0"
    "setRootIndex\0idx\0setSelectionModel\0"
    "QItemSelectionModel*\0selectionmodel\0"
    "setReadOnly\0slotConstraintAdded\0"
    "KDGantt::Constraint\0slotConstraintRemoved\0"
    "slotGridChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDGantt__GraphicsScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    1,   85,    2, 0x06 /* Public */,
       5,    1,   88,    2, 0x06 /* Public */,
       6,    1,   91,    2, 0x06 /* Public */,
       7,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   97,    2, 0x0a /* Public */,
      10,    1,  100,    2, 0x0a /* Public */,
      12,    1,  103,    2, 0x0a /* Public */,
      14,    1,  106,    2, 0x0a /* Public */,
      16,    1,  109,    2, 0x0a /* Public */,
      19,    1,  112,    2, 0x0a /* Public */,
      20,    1,  115,    2, 0x08 /* Private */,
      22,    1,  118,    2, 0x08 /* Private */,
      23,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void, QMetaType::QModelIndex,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::QModelIndex,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void,

       0        // eod
};

void KDGantt::GraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicsScene *_t = static_cast<GraphicsScene *>(_o);
        switch (_id) {
        case 0: _t->gridChanged(); break;
        case 1: _t->clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->qrealClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->entered((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->pressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->setModel((*reinterpret_cast< QAbstractItemModel*(*)>(_a[1]))); break;
        case 6: _t->setSummaryHandlingModel((*reinterpret_cast< QAbstractProxyModel*(*)>(_a[1]))); break;
        case 7: _t->setConstraintModel((*reinterpret_cast< ConstraintModel*(*)>(_a[1]))); break;
        case 8: _t->setRootIndex((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->setSelectionModel((*reinterpret_cast< QItemSelectionModel*(*)>(_a[1]))); break;
        case 10: _t->setReadOnly((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->slotConstraintAdded((*reinterpret_cast< const KDGantt::Constraint(*)>(_a[1]))); break;
        case 12: _t->slotConstraintRemoved((*reinterpret_cast< const KDGantt::Constraint(*)>(_a[1]))); break;
        case 13: _t->slotGridChanged(); break;
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphicsScene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsScene::gridChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (GraphicsScene::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsScene::clicked)) {
                *result = 1;
            }
        }
        {
            typedef void (GraphicsScene::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsScene::qrealClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (GraphicsScene::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsScene::entered)) {
                *result = 3;
            }
        }
        {
            typedef void (GraphicsScene::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsScene::pressed)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject KDGantt::GraphicsScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_KDGantt__GraphicsScene.data,
      qt_meta_data_KDGantt__GraphicsScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDGantt::GraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDGantt::GraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDGantt__GraphicsScene.stringdata))
        return static_cast<void*>(const_cast< GraphicsScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int KDGantt::GraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void KDGantt::GraphicsScene::gridChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void KDGantt::GraphicsScene::clicked(const QModelIndex & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KDGantt::GraphicsScene::qrealClicked(const QModelIndex & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KDGantt::GraphicsScene::entered(const QModelIndex & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KDGantt::GraphicsScene::pressed(const QModelIndex & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
