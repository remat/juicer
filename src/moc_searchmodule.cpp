/****************************************************************************
** Meta object code from reading C++ file 'searchmodule.h'
**
** Created: Sun Jul 26 17:09:49 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "searchmodule.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchmodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SearchModule[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      27,   13,   13,   13, 0x08,
      42,   13,   13,   13, 0x08,
      55,   13,   13,   13, 0x08,
      66,   13,   13,   13, 0x08,
      85,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SearchModule[] = {
    "SearchModule\0\0removeSlot()\0downloadSlot()\0"
    "searchSlot()\0linkSlot()\0selectionChanged()\0"
    "filterResults()\0"
};

const QMetaObject SearchModule::staticMetaObject = {
    { &ModuleBase::staticMetaObject, qt_meta_stringdata_SearchModule,
      qt_meta_data_SearchModule, 0 }
};

const QMetaObject *SearchModule::metaObject() const
{
    return &staticMetaObject;
}

void *SearchModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SearchModule))
        return static_cast<void*>(const_cast< SearchModule*>(this));
    return ModuleBase::qt_metacast(_clname);
}

int SearchModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModuleBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: removeSlot(); break;
        case 1: downloadSlot(); break;
        case 2: searchSlot(); break;
        case 3: linkSlot(); break;
        case 4: selectionChanged(); break;
        case 5: filterResults(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE