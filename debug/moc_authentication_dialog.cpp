/****************************************************************************
** Meta object code from reading C++ file 'authentication_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TraTa/authentication_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'authentication_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Authentication_dialog_t {
    const uint offsetsAndSize[12];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Authentication_dialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Authentication_dialog_t qt_meta_stringdata_Authentication_dialog = {
    {
QT_MOC_LITERAL(0, 21), // "Authentication_dialog"
QT_MOC_LITERAL(22, 27), // "on_DialogButtonBox_accepted"
QT_MOC_LITERAL(50, 0), // ""
QT_MOC_LITERAL(51, 27), // "on_DialogButtonBox_rejected"
QT_MOC_LITERAL(79, 22), // "on_remember_CB_toggled"
QT_MOC_LITERAL(102, 7) // "checked"

    },
    "Authentication_dialog\0on_DialogButtonBox_accepted\0"
    "\0on_DialogButtonBox_rejected\0"
    "on_remember_CB_toggled\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Authentication_dialog[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    0 /* Private */,
       3,    0,   33,    2, 0x08,    1 /* Private */,
       4,    1,   34,    2, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void Authentication_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Authentication_dialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_DialogButtonBox_accepted(); break;
        case 1: _t->on_DialogButtonBox_rejected(); break;
        case 2: _t->on_remember_CB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Authentication_dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Authentication_dialog.offsetsAndSize,
    qt_meta_data_Authentication_dialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Authentication_dialog_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *Authentication_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Authentication_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Authentication_dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Authentication_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
