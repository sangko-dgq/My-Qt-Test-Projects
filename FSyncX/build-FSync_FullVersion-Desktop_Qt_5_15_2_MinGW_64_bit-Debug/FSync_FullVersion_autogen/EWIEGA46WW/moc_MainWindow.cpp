/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../FSync_FullVersion/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[40];
    char stringdata0[638];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "signal_ConnectToFBase"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "Host"
QT_MOC_LITERAL(4, 39, 4), // "port"
QT_MOC_LITERAL(5, 44, 33), // "signal_Reject_or_Break_Connec..."
QT_MOC_LITERAL(6, 78, 4), // "Type"
QT_MOC_LITERAL(7, 83, 25), // "signal_ONOFF_ServerListen"
QT_MOC_LITERAL(8, 109, 5), // "ONOFF"
QT_MOC_LITERAL(9, 115, 22), // "on_btnFileSync_clicked"
QT_MOC_LITERAL(10, 138, 22), // "on_btnFileBase_clicked"
QT_MOC_LITERAL(11, 161, 27), // "on_actionBackHome_triggered"
QT_MOC_LITERAL(12, 189, 27), // "on_BtnChoseSyncPath_clicked"
QT_MOC_LITERAL(13, 217, 27), // "on_BtnChoseBasePath_clicked"
QT_MOC_LITERAL(14, 245, 28), // "on_BtnConnectToFBase_clicked"
QT_MOC_LITERAL(15, 274, 23), // "on_BtnStartSync_clicked"
QT_MOC_LITERAL(16, 298, 26), // "on_BtnOpenSyncPath_clicked"
QT_MOC_LITERAL(17, 325, 26), // "on_BtnOpenBasePath_clicked"
QT_MOC_LITERAL(18, 352, 25), // "on_BtnStartListen_clicked"
QT_MOC_LITERAL(19, 378, 19), // "on_BtnGetIP_clicked"
QT_MOC_LITERAL(20, 398, 21), // "slot_DirectoryChanged"
QT_MOC_LITERAL(21, 420, 4), // "path"
QT_MOC_LITERAL(22, 425, 14), // "slot_FileAdded"
QT_MOC_LITERAL(23, 440, 4), // "file"
QT_MOC_LITERAL(24, 445, 16), // "slot_FileRemoved"
QT_MOC_LITERAL(25, 462, 16), // "slot_FileChanged"
QT_MOC_LITERAL(26, 479, 16), // "slot_FileRenamed"
QT_MOC_LITERAL(27, 496, 7), // "oldName"
QT_MOC_LITERAL(28, 504, 7), // "newName"
QT_MOC_LITERAL(29, 512, 21), // "slot_FromFileTransfer"
QT_MOC_LITERAL(30, 534, 7), // "content"
QT_MOC_LITERAL(31, 542, 9), // "slot_File"
QT_MOC_LITERAL(32, 552, 8), // "fileName"
QT_MOC_LITERAL(33, 561, 4), // "data"
QT_MOC_LITERAL(34, 566, 8), // "slot_Del"
QT_MOC_LITERAL(35, 575, 11), // "slot_Rename"
QT_MOC_LITERAL(36, 587, 7), // "fileOld"
QT_MOC_LITERAL(37, 595, 7), // "fileNew"
QT_MOC_LITERAL(38, 603, 17), // "slot_ServerListen"
QT_MOC_LITERAL(39, 621, 16) // "isServerListenOK"

    },
    "MainWindow\0signal_ConnectToFBase\0\0"
    "Host\0port\0signal_Reject_or_Break_Connection\0"
    "Type\0signal_ONOFF_ServerListen\0ONOFF\0"
    "on_btnFileSync_clicked\0on_btnFileBase_clicked\0"
    "on_actionBackHome_triggered\0"
    "on_BtnChoseSyncPath_clicked\0"
    "on_BtnChoseBasePath_clicked\0"
    "on_BtnConnectToFBase_clicked\0"
    "on_BtnStartSync_clicked\0"
    "on_BtnOpenSyncPath_clicked\0"
    "on_BtnOpenBasePath_clicked\0"
    "on_BtnStartListen_clicked\0on_BtnGetIP_clicked\0"
    "slot_DirectoryChanged\0path\0slot_FileAdded\0"
    "file\0slot_FileRemoved\0slot_FileChanged\0"
    "slot_FileRenamed\0oldName\0newName\0"
    "slot_FromFileTransfer\0content\0slot_File\0"
    "fileName\0data\0slot_Del\0slot_Rename\0"
    "fileOld\0fileNew\0slot_ServerListen\0"
    "isServerListenOK"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  134,    2, 0x06 /* Public */,
       5,    3,  139,    2, 0x06 /* Public */,
       7,    3,  146,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  153,    2, 0x08 /* Private */,
      10,    0,  154,    2, 0x08 /* Private */,
      11,    0,  155,    2, 0x08 /* Private */,
      12,    0,  156,    2, 0x08 /* Private */,
      13,    0,  157,    2, 0x08 /* Private */,
      14,    0,  158,    2, 0x08 /* Private */,
      15,    0,  159,    2, 0x08 /* Private */,
      16,    0,  160,    2, 0x08 /* Private */,
      17,    0,  161,    2, 0x08 /* Private */,
      18,    0,  162,    2, 0x08 /* Private */,
      19,    0,  163,    2, 0x08 /* Private */,
      20,    1,  164,    2, 0x08 /* Private */,
      22,    1,  167,    2, 0x08 /* Private */,
      24,    1,  170,    2, 0x08 /* Private */,
      25,    1,  173,    2, 0x08 /* Private */,
      26,    2,  176,    2, 0x08 /* Private */,
      29,    1,  181,    2, 0x08 /* Private */,
      31,    2,  184,    2, 0x08 /* Private */,
      34,    1,  189,    2, 0x08 /* Private */,
      35,    2,  192,    2, 0x08 /* Private */,
      38,    1,  197,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    8,

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
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   27,   28,
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,   32,   33,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   36,   37,
    QMetaType::Void, QMetaType::Bool,   39,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_ConnectToFBase((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->signal_Reject_or_Break_Connection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->signal_ONOFF_ServerListen((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->on_btnFileSync_clicked(); break;
        case 4: _t->on_btnFileBase_clicked(); break;
        case 5: _t->on_actionBackHome_triggered(); break;
        case 6: _t->on_BtnChoseSyncPath_clicked(); break;
        case 7: _t->on_BtnChoseBasePath_clicked(); break;
        case 8: _t->on_BtnConnectToFBase_clicked(); break;
        case 9: _t->on_BtnStartSync_clicked(); break;
        case 10: _t->on_BtnOpenSyncPath_clicked(); break;
        case 11: _t->on_BtnOpenBasePath_clicked(); break;
        case 12: _t->on_BtnStartListen_clicked(); break;
        case 13: _t->on_BtnGetIP_clicked(); break;
        case 14: _t->slot_DirectoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->slot_FileAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->slot_FileRemoved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->slot_FileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->slot_FileRenamed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 19: _t->slot_FromFileTransfer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->slot_File((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 21: _t->slot_Del((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->slot_Rename((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 23: _t->slot_ServerListen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_ConnectToFBase)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_Reject_or_Break_Connection)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_ONOFF_ServerListen)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signal_ConnectToFBase(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::signal_Reject_or_Break_Connection(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::signal_ONOFF_ServerListen(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
