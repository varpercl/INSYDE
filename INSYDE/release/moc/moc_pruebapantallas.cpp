/****************************************************************************
** Meta object code from reading C++ file 'pruebapantallas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pruebapantallas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pruebapantallas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PruebaPantalla_t {
    QByteArrayData data[16];
    char stringdata[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PruebaPantalla_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PruebaPantalla_t qt_meta_stringdata_PruebaPantalla = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PruebaPantalla"
QT_MOC_LITERAL(1, 15, 18), // "onTrainingFinished"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 17), // "onTrainingClicked"
QT_MOC_LITERAL(4, 53, 27), // "on_newProjectButton_clicked"
QT_MOC_LITERAL(5, 81, 27), // "on_mainWindowButton_clicked"
QT_MOC_LITERAL(6, 109, 27), // "on_perceptronButton_clicked"
QT_MOC_LITERAL(7, 137, 28), // "on_trainingSetButton_clicked"
QT_MOC_LITERAL(8, 166, 23), // "on_systemButton_clicked"
QT_MOC_LITERAL(9, 190, 14), // "onVisorClicked"
QT_MOC_LITERAL(10, 205, 12), // "QMouseEvent*"
QT_MOC_LITERAL(11, 218, 5), // "event"
QT_MOC_LITERAL(12, 224, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(13, 246, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(14, 270, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(15, 294, 23) // "on_pushButton_4_clicked"

    },
    "PruebaPantalla\0onTrainingFinished\0\0"
    "onTrainingClicked\0on_newProjectButton_clicked\0"
    "on_mainWindowButton_clicked\0"
    "on_perceptronButton_clicked\0"
    "on_trainingSetButton_clicked\0"
    "on_systemButton_clicked\0onVisorClicked\0"
    "QMouseEvent*\0event\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PruebaPantalla[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    1,   81,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PruebaPantalla::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PruebaPantalla *_t = static_cast<PruebaPantalla *>(_o);
        switch (_id) {
        case 0: _t->onTrainingFinished(); break;
        case 1: _t->onTrainingClicked(); break;
        case 2: _t->on_newProjectButton_clicked(); break;
        case 3: _t->on_mainWindowButton_clicked(); break;
        case 4: _t->on_perceptronButton_clicked(); break;
        case 5: _t->on_trainingSetButton_clicked(); break;
        case 6: _t->on_systemButton_clicked(); break;
        case 7: _t->onVisorClicked((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_pushButton_2_clicked(); break;
        case 10: _t->on_pushButton_3_clicked(); break;
        case 11: _t->on_pushButton_4_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject PruebaPantalla::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PruebaPantalla.data,
      qt_meta_data_PruebaPantalla,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PruebaPantalla::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PruebaPantalla::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PruebaPantalla.stringdata))
        return static_cast<void*>(const_cast< PruebaPantalla*>(this));
    return QWidget::qt_metacast(_clname);
}

int PruebaPantalla::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
