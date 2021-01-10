/****************************************************************************
** Meta object code from reading C++ file 'incomingmodule.h'
**
** Created: Sun Jul 26 17:46:29 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "incomingmodule.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'incomingmodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IncomingModule[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      25,   15,   15,   15, 0x0a,
      32,   15,   15,   15, 0x0a,
      39,   15,   15,   15, 0x0a,
      53,   48,   15,   15, 0x0a,
      70,   15,   15,   15, 0x0a,
     101,   89,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_IncomingModule[] = {
    "IncomingModule\0\0reload()\0open()\0copy()\0"
    "remove()\0info\0insert(QUrlInfo)\0"
    "selectionChanged()\0dstFile,ftp\0"
    "ftpReadyRead(QFile*,FTP*)\0"
};

const QMetaObject IncomingModule::staticMetaObject = {
    { &ModuleBase::staticMetaObject, qt_meta_stringdata_IncomingModule,
      qt_meta_data_IncomingModule, 0 }
};

const QMetaObject *IncomingModule::metaObject() const
{
    return &staticMetaObject;
}

void *IncomingModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IncomingModule))
        return static_cast<void*>(const_cast< IncomingModule*>(this));
    return ModuleBase::qt_metacast(_clname);
}

int IncomingModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModuleBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: reload(); break;
        case 1: open(); break;
        case 2: copy(); break;
        case 3: remove(); break;
        case 4: insert((*reinterpret_cast< QUrlInfo(*)>(_a[1]))); break;
        case 5: selectionChanged(); break;
        case 6: ftpReadyRead((*reinterpret_cast< QFile*(*)>(_a[1])),(*reinterpret_cast< FTP*(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
