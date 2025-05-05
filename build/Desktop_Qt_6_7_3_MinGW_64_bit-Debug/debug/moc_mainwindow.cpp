/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_addButton_clicked",
    "",
    "on_tableView_clicked",
    "QModelIndex",
    "index",
    "on_modifyButton_clicked",
    "on_deleteButton_clicked",
    "on_searchLineEdit_textChanged",
    "text",
    "on_sortComboBox_currentIndexChanged",
    "on_exportButton_clicked",
    "showTrackingContextMenu",
    "pos",
    "markProjectCompleted",
    "changeProjectPriority",
    "updateGanttChart",
    "changeProjectStatus",
    "newStatus",
    "on_connectArduino_clicked",
    "on_setThreshold_clicked",
    "updateTemperature",
    "on_add_button_4_clicked",
    "on_modifStadeButton_4_clicked",
    "on_DeleteStadeButton_4_clicked",
    "on_trier_Button_4_clicked",
    "on_lineEdit_9_textChanged",
    "arg1",
    "on_tableViewEmploye_4_doubleClicked",
    "on_pushButton_10_clicked",
    "on_pushButton_11_clicked",
    "on_pushButton_12_clicked",
    "initializeSpecialityComboBox",
    "displaySpecialiteStats",
    "on_menu_employe_clicked",
    "on_employe_go_to_menu_clicked",
    "on_pushButton_addClient_clicked",
    "on_pushButton_deleteClient_clicked",
    "on_pushButton_updateClient_clicked",
    "on_pushButton_cancel_clicked",
    "on_pushButton_pdf_clicked",
    "on_pushButton_notify_clicked",
    "on_lineEdit_searchEmail_textChanged",
    "on_pushButton_sortByName_clicked",
    "on_pushButton_sortByCin_clicked",
    "on_pushButton_actualiser_clicked",
    "on_pushButton_statistique_clicked",
    "on_pushButton_backup_clicked",
    "on_projet_go_to_menu_clicked",
    "on_menu_client_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  266,    2, 0x08,    1 /* Private */,
       3,    1,  267,    2, 0x08,    2 /* Private */,
       6,    0,  270,    2, 0x08,    4 /* Private */,
       7,    0,  271,    2, 0x08,    5 /* Private */,
       8,    1,  272,    2, 0x08,    6 /* Private */,
      10,    1,  275,    2, 0x08,    8 /* Private */,
      11,    0,  278,    2, 0x08,   10 /* Private */,
      12,    1,  279,    2, 0x08,   11 /* Private */,
      14,    0,  282,    2, 0x08,   13 /* Private */,
      15,    0,  283,    2, 0x08,   14 /* Private */,
      16,    0,  284,    2, 0x08,   15 /* Private */,
      17,    1,  285,    2, 0x08,   16 /* Private */,
      19,    0,  288,    2, 0x08,   18 /* Private */,
      20,    0,  289,    2, 0x08,   19 /* Private */,
      21,    0,  290,    2, 0x08,   20 /* Private */,
      22,    0,  291,    2, 0x08,   21 /* Private */,
      23,    0,  292,    2, 0x08,   22 /* Private */,
      24,    0,  293,    2, 0x08,   23 /* Private */,
      25,    0,  294,    2, 0x08,   24 /* Private */,
      26,    1,  295,    2, 0x08,   25 /* Private */,
      28,    1,  298,    2, 0x08,   27 /* Private */,
      29,    0,  301,    2, 0x08,   29 /* Private */,
      30,    0,  302,    2, 0x08,   30 /* Private */,
      31,    0,  303,    2, 0x08,   31 /* Private */,
      32,    0,  304,    2, 0x08,   32 /* Private */,
      33,    0,  305,    2, 0x08,   33 /* Private */,
      34,    0,  306,    2, 0x08,   34 /* Private */,
      35,    0,  307,    2, 0x08,   35 /* Private */,
      36,    0,  308,    2, 0x08,   36 /* Private */,
      37,    0,  309,    2, 0x08,   37 /* Private */,
      38,    0,  310,    2, 0x08,   38 /* Private */,
      39,    0,  311,    2, 0x08,   39 /* Private */,
      40,    0,  312,    2, 0x08,   40 /* Private */,
      41,    0,  313,    2, 0x08,   41 /* Private */,
      42,    1,  314,    2, 0x08,   42 /* Private */,
      43,    0,  317,    2, 0x08,   44 /* Private */,
      44,    0,  318,    2, 0x08,   45 /* Private */,
      45,    0,  319,    2, 0x08,   46 /* Private */,
      46,    0,  320,    2, 0x08,   47 /* Private */,
      47,    0,  321,    2, 0x08,   48 /* Private */,
      48,    0,  322,    2, 0x08,   49 /* Private */,
      49,    0,  323,    2, 0x08,   50 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, 0x80000000 | 4,    5,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_addButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_modifyButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deleteButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_searchLineEdit_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_sortComboBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_exportButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showTrackingContextMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'markProjectCompleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeProjectPriority'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateGanttChart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeProjectStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_connectArduino_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_setThreshold_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateTemperature'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_add_button_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_modifStadeButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_DeleteStadeButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_trier_Button_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineEdit_9_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_tableViewEmploye_4_doubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_pushButton_10_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_11_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_12_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initializeSpecialityComboBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'displaySpecialiteStats'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_menu_employe_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_employe_go_to_menu_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_addClient_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_deleteClient_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_updateClient_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_cancel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_pdf_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_notify_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineEdit_searchEmail_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_sortByName_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_sortByCin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_actualiser_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_statistique_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_backup_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_projet_go_to_menu_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_menu_client_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_addButton_clicked(); break;
        case 1: _t->on_tableView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->on_modifyButton_clicked(); break;
        case 3: _t->on_deleteButton_clicked(); break;
        case 4: _t->on_searchLineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_sortComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_exportButton_clicked(); break;
        case 7: _t->showTrackingContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 8: _t->markProjectCompleted(); break;
        case 9: _t->changeProjectPriority(); break;
        case 10: _t->updateGanttChart(); break;
        case 11: _t->changeProjectStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->on_connectArduino_clicked(); break;
        case 13: _t->on_setThreshold_clicked(); break;
        case 14: _t->updateTemperature(); break;
        case 15: _t->on_add_button_4_clicked(); break;
        case 16: _t->on_modifStadeButton_4_clicked(); break;
        case 17: _t->on_DeleteStadeButton_4_clicked(); break;
        case 18: _t->on_trier_Button_4_clicked(); break;
        case 19: _t->on_lineEdit_9_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->on_tableViewEmploye_4_doubleClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 21: _t->on_pushButton_10_clicked(); break;
        case 22: _t->on_pushButton_11_clicked(); break;
        case 23: _t->on_pushButton_12_clicked(); break;
        case 24: _t->initializeSpecialityComboBox(); break;
        case 25: _t->displaySpecialiteStats(); break;
        case 26: _t->on_menu_employe_clicked(); break;
        case 27: _t->on_employe_go_to_menu_clicked(); break;
        case 28: _t->on_pushButton_addClient_clicked(); break;
        case 29: _t->on_pushButton_deleteClient_clicked(); break;
        case 30: _t->on_pushButton_updateClient_clicked(); break;
        case 31: _t->on_pushButton_cancel_clicked(); break;
        case 32: _t->on_pushButton_pdf_clicked(); break;
        case 33: _t->on_pushButton_notify_clicked(); break;
        case 34: _t->on_lineEdit_searchEmail_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: _t->on_pushButton_sortByName_clicked(); break;
        case 36: _t->on_pushButton_sortByCin_clicked(); break;
        case 37: _t->on_pushButton_actualiser_clicked(); break;
        case 38: _t->on_pushButton_statistique_clicked(); break;
        case 39: _t->on_pushButton_backup_clicked(); break;
        case 40: _t->on_projet_go_to_menu_clicked(); break;
        case 41: _t->on_menu_client_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 42;
    }
    return _id;
}
QT_WARNING_POP
