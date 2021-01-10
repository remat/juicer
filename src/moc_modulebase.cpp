/****************************************************************************
** Meta object code from reading C++ file 'modulebase.h'
**
** Created: Sun Jul 26 17:09:49 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "modulebase.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modulebase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ModuleBase[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      34,   11,   11,   11, 0x09,
      49,   11,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ModuleBase[] = {
    "ModuleBase\0\0adjustSizeOfColumns()\0"
    "linkListSlot()\0selectionChanged()\0"
};

const QMetaObject ModuleBase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ModuleBase,
      qt_meta_data_ModuleBase, 0 }
};

const QMetaObject *ModuleBase::metaObject() const
{
    return &staticMetaObject;
}

void *ModuleBase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModuleBase))
        return static_cast<void*>(const_cast< ModuleBase*>(this));
    return QObject::qt_metacast(_clname);
}

int ModuleBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: adjustSizeOfColumns(); break;
        case 1: linkListSlot(); break;
        case 2: selectionChanged(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_DockMain[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_DockMain[] = {
    "DockMain\0"
};

const QMetaObject DockMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DockMain,
      qt_meta_data_DockMain, 0 }
};

const QMetaObject *DockMain::metaObject() const
{
    return &staticMetaObject;
}

void *DockMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DockMain))
        return static_cast<void*>(const_cast< DockMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DockMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
