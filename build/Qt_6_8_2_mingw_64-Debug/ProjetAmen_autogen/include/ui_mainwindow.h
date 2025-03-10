/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_nomCliet;
    QLineEdit *lineEdit_prenomClient;
    QLineEdit *lineEdit_numClient;
    QLabel *label_nomClient;
    QLabel *label_prenomClient;
    QLabel *label_typeClient;
    QLabel *label_6;
    QComboBox *comboBox_typeClient;
    QPushButton *pushButton_addClient;
    QPushButton *pushButton_cancel;
    QLabel *label_adresseClient;
    QLineEdit *lineEdit_adresseClient;
    QLineEdit *lineEdit_emailClient;
    QLineEdit *lineEdit_cinClient;
    QLabel *label_emailClient;
    QLabel *label_cinClient;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_searchEmail;
    QPushButton *pushButton;
    QTableView *tableViewClients;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_notify;
    QPushButton *pushButton_actualiser;
    QPushButton *pushButton_pdf;
    QRadioButton *pushButton_sortByName;
    QRadioButton *pushButton_sortByCin;
    QPushButton *pushButton_deleteClient;
    QPushButton *pushButton_updateClient;
    QPushButton *pushButton_statistique;
    QPushButton *pushButton_backup;
    QWidget *tab_3;
    QGroupBox *groupBox_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1073, 762);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 1071, 711));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(20, 31, 1021, 611));
        groupBox_3->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px; margin-top: 1ex;\n"
"color:#00aaff;\n"
"border-color:#00aaff;"));
        lineEdit_nomCliet = new QLineEdit(groupBox_3);
        lineEdit_nomCliet->setObjectName("lineEdit_nomCliet");
        lineEdit_nomCliet->setGeometry(QRect(230, 50, 211, 51));
        lineEdit_prenomClient = new QLineEdit(groupBox_3);
        lineEdit_prenomClient->setObjectName("lineEdit_prenomClient");
        lineEdit_prenomClient->setGeometry(QRect(230, 160, 211, 51));
        lineEdit_numClient = new QLineEdit(groupBox_3);
        lineEdit_numClient->setObjectName("lineEdit_numClient");
        lineEdit_numClient->setGeometry(QRect(710, 160, 211, 51));
        label_nomClient = new QLabel(groupBox_3);
        label_nomClient->setObjectName("label_nomClient");
        label_nomClient->setGeometry(QRect(40, 60, 131, 31));
        label_nomClient->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        label_prenomClient = new QLabel(groupBox_3);
        label_prenomClient->setObjectName("label_prenomClient");
        label_prenomClient->setGeometry(QRect(40, 167, 131, 31));
        label_prenomClient->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        label_typeClient = new QLabel(groupBox_3);
        label_typeClient->setObjectName("label_typeClient");
        label_typeClient->setGeometry(QRect(530, 60, 131, 31));
        label_typeClient->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(530, 170, 151, 31));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        comboBox_typeClient = new QComboBox(groupBox_3);
        comboBox_typeClient->setObjectName("comboBox_typeClient");
        comboBox_typeClient->setGeometry(QRect(710, 50, 211, 51));
        pushButton_addClient = new QPushButton(groupBox_3);
        pushButton_addClient->setObjectName("pushButton_addClient");
        pushButton_addClient->setGeometry(QRect(538, 378, 171, 51));
        pushButton_addClient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: skyblue;\n"
"    color: white;\n"
"    border: 1px solid skyblue;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00aaff;\n"
"}"));
        pushButton_cancel = new QPushButton(groupBox_3);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(748, 378, 171, 51));
        pushButton_cancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: skyblue;\n"
"    color: white;\n"
"    border: 1px solid skyblue;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00aaff;\n"
"}"));
        label_adresseClient = new QLabel(groupBox_3);
        label_adresseClient->setObjectName("label_adresseClient");
        label_adresseClient->setGeometry(QRect(531, 280, 131, 31));
        label_adresseClient->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        lineEdit_adresseClient = new QLineEdit(groupBox_3);
        lineEdit_adresseClient->setObjectName("lineEdit_adresseClient");
        lineEdit_adresseClient->setGeometry(QRect(710, 268, 211, 51));
        lineEdit_emailClient = new QLineEdit(groupBox_3);
        lineEdit_emailClient->setObjectName("lineEdit_emailClient");
        lineEdit_emailClient->setGeometry(QRect(230, 267, 211, 51));
        lineEdit_cinClient = new QLineEdit(groupBox_3);
        lineEdit_cinClient->setObjectName("lineEdit_cinClient");
        lineEdit_cinClient->setGeometry(QRect(231, 378, 211, 51));
        label_emailClient = new QLabel(groupBox_3);
        label_emailClient->setObjectName("label_emailClient");
        label_emailClient->setGeometry(QRect(39, 273, 131, 31));
        label_emailClient->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        label_cinClient = new QLabel(groupBox_3);
        label_cinClient->setObjectName("label_cinClient");
        label_cinClient->setGeometry(QRect(39, 386, 131, 31));
        label_cinClient->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 50, 671, 491));
        groupBox->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px; margin-top: 1ex;\n"
"color:#00aaff;\n"
"border-color:#00aaff;"));
        lineEdit_searchEmail = new QLineEdit(groupBox);
        lineEdit_searchEmail->setObjectName("lineEdit_searchEmail");
        lineEdit_searchEmail->setGeometry(QRect(360, 410, 211, 51));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 408, 93, 51));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: skyblue;\n"
"    color: white;\n"
"    border: 1px solid skyblue;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00aaff;\n"
"}"));
        tableViewClients = new QTableView(groupBox);
        tableViewClients->setObjectName("tableViewClients");
        tableViewClients->setGeometry(QRect(10, 30, 631, 361));
        tableViewClients->setStyleSheet(QString::fromUtf8(""));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(700, 50, 331, 491));
        groupBox_2->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px; margin-top: 1ex;\n"
"color: #00aaff;\n"
"border-color:#00aaff;"));
        pushButton_notify = new QPushButton(groupBox_2);
        pushButton_notify->setObjectName("pushButton_notify");
        pushButton_notify->setGeometry(QRect(90, 117, 171, 51));
        pushButton_notify->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: skyblue;\n"
"    color: white;\n"
"    border: 1px solid skyblue;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00aaff;\n"
"}"));
        pushButton_actualiser = new QPushButton(groupBox_2);
        pushButton_actualiser->setObjectName("pushButton_actualiser");
        pushButton_actualiser->setGeometry(QRect(90, 166, 171, 51));
        pushButton_actualiser->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: skyblue;\n"
"    color: white;\n"
"    border: 1px solid skyblue;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00aaff;\n"
"}"));
        pushButton_pdf = new QPushButton(groupBox_2);
        pushButton_pdf->setObjectName("pushButton_pdf");
        pushButton_pdf->setGeometry(QRect(90, 216, 171, 51));
        pushButton_pdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: skyblue;\n"
"    color: white;\n"
"    border: 1px solid skyblue;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00aaff;\n"
"}"));
        pushButton_sortByName = new QRadioButton(groupBox_2);
        pushButton_sortByName->setObjectName("pushButton_sortByName");
        pushButton_sortByName->setGeometry(QRect(110, 373, 110, 41));
        pushButton_sortByCin = new QRadioButton(groupBox_2);
        pushButton_sortByCin->setObjectName("pushButton_sortByCin");
        pushButton_sortByCin->setGeometry(QRect(110, 420, 110, 41));
        pushButton_deleteClient = new QPushButton(groupBox_2);
        pushButton_deleteClient->setObjectName("pushButton_deleteClient");
        pushButton_deleteClient->setGeometry(QRect(90, 69, 171, 51));
        pushButton_deleteClient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: skyblue;\n"
"    color: white;\n"
"    border: 1px solid skyblue;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00aaff;\n"
"}"));
        pushButton_updateClient = new QPushButton(groupBox_2);
        pushButton_updateClient->setObjectName("pushButton_updateClient");
        pushButton_updateClient->setGeometry(QRect(90, 20, 171, 51));
        pushButton_updateClient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: skyblue;\n"
"    color: white;\n"
"    border: 1px solid skyblue;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00aaff;\n"
"}"));
        pushButton_statistique = new QPushButton(groupBox_2);
        pushButton_statistique->setObjectName("pushButton_statistique");
        pushButton_statistique->setGeometry(QRect(90, 265, 171, 51));
        pushButton_statistique->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: skyblue;\n"
"    color: white;\n"
"    border: 1px solid skyblue;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00aaff;\n"
"}"));
        pushButton_backup = new QPushButton(groupBox_2);
        pushButton_backup->setObjectName("pushButton_backup");
        pushButton_backup->setGeometry(QRect(89, 314, 171, 51));
        pushButton_backup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: skyblue;\n"
"    color: white;\n"
"    border: 1px solid skyblue;\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00aaff;\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(0, 0, 1061, 671));
        groupBox_4->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px; margin-top: 1ex;\n"
"color:#00aaff;\n"
"border-color:#00aaff;"));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1073, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Ajouter un client ", nullptr));
        label_nomClient->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_prenomClient->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_typeClient->setText(QCoreApplication::translate("MainWindow", "Type Client", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Num De T\303\251l\303\251phione", nullptr));
        pushButton_addClient->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_adresseClient->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_emailClient->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_cinClient->setText(QCoreApplication::translate("MainWindow", "Cin", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Ajouter Client", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Liste Des Clients ", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        pushButton_notify->setText(QCoreApplication::translate("MainWindow", "Notifier Client", nullptr));
        pushButton_actualiser->setText(QCoreApplication::translate("MainWindow", "Actualiser", nullptr));
        pushButton_pdf->setText(QCoreApplication::translate("MainWindow", "List PDF", nullptr));
        pushButton_sortByName->setText(QCoreApplication::translate("MainWindow", "Tri par nom", nullptr));
        pushButton_sortByCin->setText(QCoreApplication::translate("MainWindow", "Tri par CIN", nullptr));
        pushButton_deleteClient->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_updateClient->setText(QCoreApplication::translate("MainWindow", "Modifier client", nullptr));
        pushButton_statistique->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        pushButton_backup->setText(QCoreApplication::translate("MainWindow", "BackUp", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Affichier Client", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Statistique ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
