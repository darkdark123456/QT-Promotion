/****************************************************************************
** Meta object code from reading C++ file 'questionyeardialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "questionyeardialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'questionyeardialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_questionYearDialog_t {
    QByteArrayData data[14];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_questionYearDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_questionYearDialog_t qt_meta_stringdata_questionYearDialog = {
    {
QT_MOC_LITERAL(0, 0, 18), // "questionYearDialog"
QT_MOC_LITERAL(1, 19, 18), // "on_btn2010_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18), // "on_btn2020_clicked"
QT_MOC_LITERAL(4, 58, 18), // "on_btn2021_clicked"
QT_MOC_LITERAL(5, 77, 18), // "on_btn2019_clicked"
QT_MOC_LITERAL(6, 96, 18), // "on_btn2018_clicked"
QT_MOC_LITERAL(7, 115, 18), // "on_btn2017_clicked"
QT_MOC_LITERAL(8, 134, 18), // "on_btn2016_clicked"
QT_MOC_LITERAL(9, 153, 18), // "on_btn2015_clicked"
QT_MOC_LITERAL(10, 172, 18), // "on_btn2014_clicked"
QT_MOC_LITERAL(11, 191, 18), // "on_btn2013_clicked"
QT_MOC_LITERAL(12, 210, 18), // "on_btn2012_clicked"
QT_MOC_LITERAL(13, 229, 18) // "on_btn2011_clicked"

    },
    "questionYearDialog\0on_btn2010_clicked\0"
    "\0on_btn2020_clicked\0on_btn2021_clicked\0"
    "on_btn2019_clicked\0on_btn2018_clicked\0"
    "on_btn2017_clicked\0on_btn2016_clicked\0"
    "on_btn2015_clicked\0on_btn2014_clicked\0"
    "on_btn2013_clicked\0on_btn2012_clicked\0"
    "on_btn2011_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_questionYearDialog[] = {

 // content:
       8,       // revision
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
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void questionYearDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<questionYearDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn2010_clicked(); break;
        case 1: _t->on_btn2020_clicked(); break;
        case 2: _t->on_btn2021_clicked(); break;
        case 3: _t->on_btn2019_clicked(); break;
        case 4: _t->on_btn2018_clicked(); break;
        case 5: _t->on_btn2017_clicked(); break;
        case 6: _t->on_btn2016_clicked(); break;
        case 7: _t->on_btn2015_clicked(); break;
        case 8: _t->on_btn2014_clicked(); break;
        case 9: _t->on_btn2013_clicked(); break;
        case 10: _t->on_btn2012_clicked(); break;
        case 11: _t->on_btn2011_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject questionYearDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_questionYearDialog.data,
    qt_meta_data_questionYearDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *questionYearDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *questionYearDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_questionYearDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int questionYearDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
