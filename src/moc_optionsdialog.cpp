/****************************************************************************
** Meta object code from reading C++ file 'optionsdialog.h'
**
** Created: Sun Jul 26 17:46:28 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "optionsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OptionsDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x09,
      35,   14,   14,   14, 0x09,
      51,   14,   14,   14, 0x09,
      79,   14,   14,   14, 0x09,
     103,   14,   14,   14, 0x09,
     128,  120,   14,   14, 0x09,
     155,   14,   14,   14, 0x09,
     171,   14,   14,   14, 0x09,
     191,  186,   14,   14, 0x09,
     211,   14,   14,   14, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_OptionsDialog[] = {
    "OptionsDialog\0\0selectIncomingDir()\0"
    "selectTempDir()\0selectIncomingDirSpecific()\0"
    "selectTempDirSpecific()\0selectLauncher()\0"
    "checked\0specificRadioToggled(bool)\0"
    "jumpToFtpSlot()\0acceptedSlot()\0font\0"
    "setFontSizes(QFont)\0reset()\0"
};

const QMetaObject OptionsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OptionsDialog,
      qt_meta_data_OptionsDialog, 0 }
};

const QMetaObject *OptionsDialog::metaObject() const
{
    return &staticMetaObject;
}

void *OptionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsDialog))
        return static_cast<void*>(const_cast< OptionsDialog*>(this));
    if (!strcmp(_clname, "Ui::OptionsDialogBase"))
        return static_cast< Ui::OptionsDialogBase*>(const_cast< OptionsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int OptionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: selectIncomingDir(); break;
        case 1: selectTempDir(); break;
        case 2: selectIncomingDirSpecific(); break;
        case 3: selectTempDirSpecific(); break;
        case 4: selectLauncher(); break;
        case 5: specificRadioToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: jumpToFtpSlot(); break;
        case 7: acceptedSlot(); break;
        case 8: setFontSizes((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 9: reset(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
