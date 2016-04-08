/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      23,   11,   11,   11, 0x0a,
      40,   11,   11,   11, 0x0a,
      58,   11,   11,   11, 0x0a,
     101,   81,   11,   11, 0x0a,
     145,   11,   11,   11, 0x0a,
     176,  170,   11,   11, 0x0a,
     203,   11,   11,   11, 0x08,
     221,   11,   11,   11, 0x08,
     251,  245,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0saveData()\0clearSelection()\0"
    "deleteSelection()\0handleImageSelection()\0"
    "old_index,new_index\0"
    "objUpdateSelection(QModelIndex,QModelIndex)\0"
    "handleSessionSelection()\0state\0"
    "handleMissingCheckBox(int)\0handleAdminPass()\0"
    "handleServerSelection()\0index\0"
    "handleHeaderFilter(int)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->saveData(); break;
        case 1: _t->clearSelection(); break;
        case 2: _t->deleteSelection(); break;
        case 3: _t->handleImageSelection(); break;
        case 4: _t->objUpdateSelection((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 5: _t->handleSessionSelection(); break;
        case 6: _t->handleMissingCheckBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->handleAdminPass(); break;
        case 8: _t->handleServerSelection(); break;
        case 9: _t->handleHeaderFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
