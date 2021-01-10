/****************************************************************************
** Meta object code from reading C++ file 'dirselectiondialog.h'
**
** Created: Sun Jul 26 15:42:59 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dirselectiondialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dirselectiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DirSelectionDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      25,   20,   19,   19, 0x09,
      77,   68,   19,   19, 0x09,
     103,   19,   19,   19, 0x09,
     112,   19,   19,   19, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_DirSelectionDialog[] = {
    "DirSelectionDialog\0\0item\0"
    "updateSubDirectoriesSlot(QTreeWidgetItem*)\0"
    "id,error\0requestFinished(int,bool)\0"
    "reject()\0accept()\0"
};

const QMetaObject DirSelectionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DirSelectionDialog,
      qt_meta_data_DirSelectionDialog, 0 }
};

const QMetaObject *DirSelectionDialog::metaObject() const
{
    return &staticMetaObject;
}

void *DirSelectionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DirSelectionDialog))
        return static_cast<void*>(const_cast< DirSelectionDialog*>(this));
    if (!strcmp(_clname, "Ui::DirSelectionDialogBase"))
        return static_cast< Ui::DirSelectionDialogBase*>(const_cast< DirSelectionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int DirSelectionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateSubDirectoriesSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 1: requestFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: reject(); break;
        case 3: accept(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
