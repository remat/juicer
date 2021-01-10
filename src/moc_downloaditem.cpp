/****************************************************************************
** Meta object code from reading C++ file 'downloaditem.h'
**
** Created: Sun Jul 26 17:46:28 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "downloaditem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloaditem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DownloadItem[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DownloadItem[] = {
    "DownloadItem\0\0initPowerSpin()\0"
};

const QMetaObject DownloadItem::staticMetaObject = {
    { &Item::staticMetaObject, qt_meta_stringdata_DownloadItem,
      qt_meta_data_DownloadItem, 0 }
};

const QMetaObject *DownloadItem::metaObject() const
{
    return &staticMetaObject;
}

void *DownloadItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadItem))
        return static_cast<void*>(const_cast< DownloadItem*>(this));
    return Item::qt_metacast(_clname);
}

int DownloadItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Item::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initPowerSpin(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
