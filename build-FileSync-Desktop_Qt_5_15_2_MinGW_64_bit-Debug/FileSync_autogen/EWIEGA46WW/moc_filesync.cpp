/****************************************************************************
** Meta object code from reading C++ file 'filesync.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../FileSync/filesync.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filesync.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileSync_t {
    QByteArrayData data[11];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileSync_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileSync_t qt_meta_stringdata_FileSync = {
    {
QT_MOC_LITERAL(0, 0, 8), // "FileSync"
QT_MOC_LITERAL(1, 9, 21), // "slot_DirectoryChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "path"
QT_MOC_LITERAL(4, 37, 14), // "slot_FileAdded"
QT_MOC_LITERAL(5, 52, 4), // "file"
QT_MOC_LITERAL(6, 57, 16), // "slot_FileRemoved"
QT_MOC_LITERAL(7, 74, 16), // "slot_FileChanged"
QT_MOC_LITERAL(8, 91, 16), // "slot_FileRenamed"
QT_MOC_LITERAL(9, 108, 7), // "oldName"
QT_MOC_LITERAL(10, 116, 7) // "newName"

    },
    "FileSync\0slot_DirectoryChanged\0\0path\0"
    "slot_FileAdded\0file\0slot_FileRemoved\0"
    "slot_FileChanged\0slot_FileRenamed\0"
    "oldName\0newName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileSync[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       6,    1,   45,    2, 0x08 /* Private */,
       7,    1,   48,    2, 0x08 /* Private */,
       8,    2,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,

       0        // eod
};

void FileSync::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileSync *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_DirectoryChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->slot_FileAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->slot_FileRemoved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->slot_FileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->slot_FileRenamed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileSync::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FileSync.data,
    qt_meta_data_FileSync,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileSync::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileSync::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileSync.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FileSync::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
