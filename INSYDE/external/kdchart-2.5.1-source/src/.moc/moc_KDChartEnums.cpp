/****************************************************************************
** Meta object code from reading C++ file 'KDChartEnums.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartEnums.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartEnums.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChartEnums_t {
    QByteArrayData data[7];
    char stringdata[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChartEnums_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChartEnums_t qt_meta_stringdata_KDChartEnums = {
    {
QT_MOC_LITERAL(0, 0, 12), // "KDChartEnums"
QT_MOC_LITERAL(1, 13, 16), // "TextLayoutPolicy"
QT_MOC_LITERAL(2, 30, 19), // "LayoutJustOverwrite"
QT_MOC_LITERAL(3, 50, 18), // "LayoutPolicyRotate"
QT_MOC_LITERAL(4, 69, 27), // "LayoutPolicyShiftVertically"
QT_MOC_LITERAL(5, 97, 29), // "LayoutPolicyShiftHorizontally"
QT_MOC_LITERAL(6, 127, 26) // "LayoutPolicyShrinkFontSize"

    },
    "KDChartEnums\0TextLayoutPolicy\0"
    "LayoutJustOverwrite\0LayoutPolicyRotate\0"
    "LayoutPolicyShiftVertically\0"
    "LayoutPolicyShiftHorizontally\0"
    "LayoutPolicyShrinkFontSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChartEnums[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    5,   18,

 // enum data: key, value
       2, uint(KDChartEnums::LayoutJustOverwrite),
       3, uint(KDChartEnums::LayoutPolicyRotate),
       4, uint(KDChartEnums::LayoutPolicyShiftVertically),
       5, uint(KDChartEnums::LayoutPolicyShiftHorizontally),
       6, uint(KDChartEnums::LayoutPolicyShrinkFontSize),

       0        // eod
};

void KDChartEnums::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject KDChartEnums::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KDChartEnums.data,
      qt_meta_data_KDChartEnums,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChartEnums::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChartEnums::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChartEnums.stringdata))
        return static_cast<void*>(const_cast< KDChartEnums*>(this));
    return QObject::qt_metacast(_clname);
}

int KDChartEnums::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
