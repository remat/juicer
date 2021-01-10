/****************************************************************************
** Meta object code from reading C++ file 'servermodule.h'
**
** Created: Sun Jul 26 17:46:29 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "servermodule.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servermodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerModule[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      28,   13,   13,   13, 0x0a,
      41,   13,   13,   13, 0x0a,
      63,   54,   13,   13, 0x0a,
      83,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ServerModule[] = {
    "ServerModule\0\0connectSlot()\0removeSlot()\0"
    "searchSlot()\0id,error\0gotServer(int,bool)\0"
    "selectionChanged()\0"
};

const QMetaObject ServerModule::staticMetaObject = {
    { &ModuleBase::staticMetaObject, qt_meta_stringdata_ServerModule,
      qt_meta_data_ServerModule, 0 }
};

const QMetaObject *ServerModule::metaObject() const
{
    return &staticMetaObject;
}

void *ServerModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerModule))
        return static_cast<void*>(const_cast< ServerModule*>(this));
    return ModuleBase::qt_metacast(_clname);
}

int ServerModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModuleBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: connectSlot(); break;
        case 1: removeSlot(); break;
        case 2: searchSlot(); break;
        case 3: gotServer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: selectionChanged(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
