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
    QByteArrayData data[31];
    char stringdata0[443];
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
QT_MOC_LITERAL(5, 44, 22), // "on_btnFileSync_clicked"
QT_MOC_LITERAL(6, 67, 22), // "on_btnFileBase_clicked"
QT_MOC_LITERAL(7, 90, 27), // "on_actionBackHome_triggered"
QT_MOC_LITERAL(8, 118, 27), // "on_BtnChoseSyncPath_clicked"
QT_MOC_LITERAL(9, 146, 27), // "on_BtnChoseBasePath_clicked"
QT_MOC_LITERAL(10, 174, 28), // "on_BtnConnectToFBase_clicked"
QT_MOC_LITERAL(11, 203, 21), // "slot_DirectoryChanged"
QT_MOC_LITERAL(12, 225, 4), // "path"
QT_MOC_LITERAL(13, 230, 14), // "slot_FileAdded"
QT_MOC_LITERAL(14, 245, 4), // "file"
QT_MOC_LITERAL(15, 250, 16), // "slot_FileRemoved"
QT_MOC_LITERAL(16, 267, 16), // "slot_FileChanged"
QT_MOC_LITERAL(17, 284, 16), // "slot_FileRenamed"
QT_MOC_LITERAL(18, 301, 7), // "oldName"
QT_MOC_LITERAL(19, 309, 7), // "newName"
QT_MOC_LITERAL(20, 317, 21), // "slot_FromFileTransfer"
QT_MOC_LITERAL(21, 339, 7), // "content"
QT_MOC_LITERAL(22, 347, 9), // "slot_File"
QT_MOC_LITERAL(23, 357, 8), // "fileName"
QT_MOC_LITERAL(24, 366, 4), // "data"
QT_MOC_LITERAL(25, 371, 8), // "slot_Del"
QT_MOC_LITERAL(26, 380, 11), // "slot_Rename"
QT_MOC_LITERAL(27, 392, 7), // "fileOld"
QT_MOC_LITERAL(28, 400, 7), // "fileNew"
QT_MOC_LITERAL(29, 408, 17), // "slot_ServerListen"
QT_MOC_LITERAL(30, 426, 16) // "isServerListenOK"

    },
    "MainWindow\0signal_ConnectToFBase\0\0"
    "Host\0port\0on_btnFileSync_clicked\0"
    "on_btnFileBase_clicked\0"
    "on_actionBackHome_triggered\0"
    "on_BtnChoseSyncPath_clicked\0"
    "on_BtnChoseBasePath_clicked\0"
    "on_BtnConnectToFBase_clicked\0"
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
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  104,    2, 0x08 /* Private */,
       6,    0,  105,    2, 0x08 /* Private */,
       7,    0,  106,    2, 0x08 /* Private */,
       8,    0,  107,    2, 0x08 /* Private */,
       9,    0,  108,    2, 0x08 /* Private */,
      10,    0,  109,    2, 0x08 /* Private */,
      11,    1,  110,    2, 0x08 /* Private */,
      13,    1,  113,    2, 0x08 /* Private */,
      15,    1,  116,    2, 0x08 /* Private */,
      16,    1,  119,    2, 0x08 /* Private */,
      17,    2,  122,    2, 0x08 /* Private */,
      20,    1,  127,    2, 0x08 /* Private */,
      22,    2,  130,    2, 0x08 /* Private */,
      25,    1,  135,    2, 0x08 /* Private */,
      26,    2,  138,    2, 0x08 /* Private */,
      29,    1,  143,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   18,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,   23,   24,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   27,   28,
    QMetaType::Void, QMetaType::Bool,   30,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_ConnectToFBase((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_btnFileSync_clicked(); break;
        case 2: _t->on_btnFileBase_clicked(); break;
        case 3: _t->on_actionBackHome_triggered(); break;
        case 4: _t->on_BtnChoseSyncPath_clicked(); break;
        case 5: _t->on_BtnChoseBasePath_clicked(); break;
        case 6: _t->on_BtnConnectToFBase_clicked(); break;
        case 7: _t->slot_DirectoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->slot_FileAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->slot_FileRemoved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->slot_FileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->slot_FileRenamed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 12: _t->slot_FromFileTransfer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->slot_File((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 14: _t->slot_Del((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->slot_Rename((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 16: _t->slot_ServerListen((*reinterpret_cast< bool(*)>(_a[1]))); break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signal_ConnectToFBase(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
