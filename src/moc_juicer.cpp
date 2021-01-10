/****************************************************************************
** Meta object code from reading C++ file 'juicer.h'
**
** Created: Sun Jul 26 18:02:45 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "juicer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'juicer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Juicer[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      27,   13,    8,    7, 0x08,
      55,   47,    8,    7, 0x28,
      70,    7,    8,    7, 0x28,
      78,    7,    7,    7, 0x08,
      88,    7,    7,    7, 0x08,
      96,    7,    7,    7, 0x08,
     106,    7,    7,    7, 0x08,
     118,    7,    7,    7, 0x08,
     141,  132,    7,    7, 0x08,
     174,  167,    7,    7, 0x08,
     192,    7,    7,    7, 0x08,
     210,  205,    7,    7, 0x08,
     231,    7,    7,    7, 0x08,
     245,    7,    7,    7, 0x08,
     270,  264,    7,    7, 0x08,
     286,    7,    7,    7, 0x08,
     293,    7,    7,    7, 0x08,
     304,    7,    7,    7, 0x08,
     320,    7,    7,    7, 0x08,
     336,  167,    7,    7, 0x08,
     390,  385,    7,    7, 0x08,
     435,  430,    7,    7, 0x08,
     459,    7,    7,    7, 0x08,
     477,  472,    7,    7, 0x08,
     512,    7,    7,    7, 0x08,
     538,  529,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Juicer[] = {
    "Juicer\0\0bool\0message,error\0"
    "login(QString,bool)\0message\0login(QString)\0"
    "login()\0openAjL()\0about()\0aboutQt()\0"
    "timerSlot()\0showOptions()\0settings\0"
    "settingsReady(AjSettings)\0reason\0"
    "xmlError(QString)\0gotSession()\0link\0"
    "processLink(QString)\0processLink()\0"
    "processClipboard()\0index\0tabChanged(int)\0"
    "quit()\0exitCore()\0firstModified()\0"
    "adjustColumns()\0"
    "trayActivated(QSystemTrayIcon::ActivationReason)\0"
    "list\0downloadsFinished(QList<DownloadItem*>)\0"
    "host\0hostLookedUp(QHostInfo)\0showManual()\0"
    "mode\0clipboardChanged(QClipboard::Mode)\0"
    "getNetworkInfo()\0id,error\0"
    "requestFinished(int,bool)\0"
};

const QMetaObject Juicer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Juicer,
      qt_meta_data_Juicer, 0 }
};

const QMetaObject *Juicer::metaObject() const
{
    return &staticMetaObject;
}

void *Juicer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Juicer))
        return static_cast<void*>(const_cast< Juicer*>(this));
    if (!strcmp(_clname, "Ui::MainWindowBase"))
        return static_cast< Ui::MainWindowBase*>(const_cast< Juicer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Juicer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = login((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = login((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = login();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: openAjL(); break;
        case 4: about(); break;
        case 5: aboutQt(); break;
        case 6: timerSlot(); break;
        case 7: showOptions(); break;
        case 8: settingsReady((*reinterpret_cast< const AjSettings(*)>(_a[1]))); break;
        case 9: xmlError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: gotSession(); break;
        case 11: processLink((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: processLink(); break;
        case 13: processClipboard(); break;
        case 14: tabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: quit(); break;
        case 16: exitCore(); break;
        case 17: firstModified(); break;
        case 18: adjustColumns(); break;
        case 19: trayActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 20: downloadsFinished((*reinterpret_cast< const QList<DownloadItem*>(*)>(_a[1]))); break;
        case 21: hostLookedUp((*reinterpret_cast< const QHostInfo(*)>(_a[1]))); break;
        case 22: showManual(); break;
        case 23: clipboardChanged((*reinterpret_cast< QClipboard::Mode(*)>(_a[1]))); break;
        case 24: getNetworkInfo(); break;
        case 25: requestFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
