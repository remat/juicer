/****************************************************************************
** Meta object code from reading C++ file 'autoupdate.h'
**
** Created: Sun Jul 26 17:09:50 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "autoupdate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'autoupdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AutoUpdate[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      29,   20,   11,   11, 0x08,
      66,   55,   11,   11, 0x08,
      99,   92,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AutoUpdate[] = {
    "AutoUpdate\0\0check()\0id,error\0"
    "requestFinished(int,bool)\0done,total\0"
    "dataReadProgress(int,int)\0button\0"
    "clicked(QAbstractButton*)\0"
};

const QMetaObject AutoUpdate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AutoUpdate,
      qt_meta_data_AutoUpdate, 0 }
};

const QMetaObject *AutoUpdate::metaObject() const
{
    return &staticMetaObject;
}

void *AutoUpdate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AutoUpdate))
        return static_cast<void*>(const_cast< AutoUpdate*>(this));
    return QObject::qt_metacast(_clname);
}

int AutoUpdate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: check(); break;
        case 1: requestFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: dataReadProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
