/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_Nom;
    QLineEdit *lineEdit_Prenom;
    QLineEdit *lineEdit_Telephone;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *QJOUTERCONSULTQNTBUTTON;
    QPushButton *pushButton_3;
    QLabel *label_8;
    QDateEdit *dateAjoutLineEdit;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_2;
    QLabel *label_10;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QTableView *consultantTable;
    QLabel *label_6;
    QLineEdit *chercherconsultqntlineedit;
    QLabel *label_7;
    QRadioButton *tricroiradiobutton;
    QRadioButton *tridecroiradiobutton;
    QPushButton *supprierconsultqntpushbutton;
    QPushButton *odifyconsultant;
    QPushButton *exportpdfbutton;
    QPushButton *statistiquepushbutton;
    QWidget *staticWidget;
    QPushButton *hidepushbutton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1400, 784);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(80, 60, 491, 371));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #3498db;\n"
"    border-radius: 10px;\n"
"    margin-top: 10px;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    padding: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 5px 10px;\n"
"    color: #3498db;\n"
"}"));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 121, 16));
        lineEdit_ID = new QLineEdit(groupBox);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(30, 50, 181, 31));
        lineEdit_Nom = new QLineEdit(groupBox);
        lineEdit_Nom->setObjectName("lineEdit_Nom");
        lineEdit_Nom->setGeometry(QRect(30, 130, 181, 31));
        lineEdit_Prenom = new QLineEdit(groupBox);
        lineEdit_Prenom->setObjectName("lineEdit_Prenom");
        lineEdit_Prenom->setGeometry(QRect(280, 130, 191, 31));
        lineEdit_Telephone = new QLineEdit(groupBox);
        lineEdit_Telephone->setObjectName("lineEdit_Telephone");
        lineEdit_Telephone->setGeometry(QRect(30, 220, 191, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 100, 201, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(280, 100, 63, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 190, 191, 20));
        QJOUTERCONSULTQNTBUTTON = new QPushButton(groupBox);
        QJOUTERCONSULTQNTBUTTON->setObjectName("QJOUTERCONSULTQNTBUTTON");
        QJOUTERCONSULTQNTBUTTON->setGeometry(QRect(270, 330, 93, 29));
        QJOUTERCONSULTQNTBUTTON->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1c5985;\n"
"}"));
        QJOUTERCONSULTQNTBUTTON->setAutoDefault(false);
        QJOUTERCONSULTQNTBUTTON->setFlat(false);
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(90, 330, 93, 29));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1c5985;\n"
"}"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(280, 190, 63, 20));
        dateAjoutLineEdit = new QDateEdit(groupBox);
        dateAjoutLineEdit->setObjectName("dateAjoutLineEdit");
        dateAjoutLineEdit->setGeometry(QRect(280, 230, 161, 26));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(120, 470, 161, 20));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(310, 470, 113, 26));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(360, 640, 93, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1c5985;\n"
"}\n"
""));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(120, 510, 361, 161));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(89, 449, 481, 241));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #3498db;\n"
"    border-radius: 10px;\n"
"    margin-top: 10px;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    padding: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 5px 10px;\n"
"    color: #3498db;\n"
"}"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(60, 30, 1331, 691));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #3498db;\n"
"    border-radius: 10px;\n"
"    margin-top: 10px;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    padding: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 5px 10px;\n"
"    color: #3498db;\n"
"}"));
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setEnabled(true);
        groupBox_2->setGeometry(QRect(520, 20, 741, 641));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #3498db;\n"
"    border-radius: 10px;\n"
"    margin-top: 10px;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    padding: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 5px 10px;\n"
"    color: #3498db;\n"
"}"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 40, 151, 20));
        consultantTable = new QTableView(groupBox_2);
        consultantTable->setObjectName("consultantTable");
        consultantTable->setGeometry(QRect(200, 90, 521, 211));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(180, 40, 101, 20));
        chercherconsultqntlineedit = new QLineEdit(groupBox_2);
        chercherconsultqntlineedit->setObjectName("chercherconsultqntlineedit");
        chercherconsultqntlineedit->setGeometry(QRect(270, 40, 113, 26));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(420, 40, 81, 20));
        tricroiradiobutton = new QRadioButton(groupBox_2);
        tricroiradiobutton->setObjectName("tricroiradiobutton");
        tricroiradiobutton->setGeometry(QRect(520, 20, 110, 24));
        tridecroiradiobutton = new QRadioButton(groupBox_2);
        tridecroiradiobutton->setObjectName("tridecroiradiobutton");
        tridecroiradiobutton->setGeometry(QRect(520, 60, 110, 24));
        supprierconsultqntpushbutton = new QPushButton(groupBox_2);
        supprierconsultqntpushbutton->setObjectName("supprierconsultqntpushbutton");
        supprierconsultqntpushbutton->setGeometry(QRect(30, 100, 93, 29));
        supprierconsultqntpushbutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1c5985;\n"
"}"));
        odifyconsultant = new QPushButton(groupBox_2);
        odifyconsultant->setObjectName("odifyconsultant");
        odifyconsultant->setGeometry(QRect(30, 150, 93, 29));
        odifyconsultant->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1c5985;\n"
"}\n"
""));
        exportpdfbutton = new QPushButton(groupBox_2);
        exportpdfbutton->setObjectName("exportpdfbutton");
        exportpdfbutton->setGeometry(QRect(30, 200, 141, 29));
        exportpdfbutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1c5985;\n"
"}"));
        statistiquepushbutton = new QPushButton(groupBox_2);
        statistiquepushbutton->setObjectName("statistiquepushbutton");
        statistiquepushbutton->setGeometry(QRect(30, 260, 141, 29));
        statistiquepushbutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1c5985;\n"
"}"));
        staticWidget = new QWidget(groupBox_2);
        staticWidget->setObjectName("staticWidget");
        staticWidget->setGeometry(QRect(30, 320, 701, 271));
        hidepushbutton = new QPushButton(groupBox_2);
        hidepushbutton->setObjectName("hidepushbutton");
        hidepushbutton->setGeometry(QRect(640, 600, 93, 31));
        hidepushbutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1c5985;\n"
"}"));
        label_5->raise();
        label_6->raise();
        chercherconsultqntlineedit->raise();
        label_7->raise();
        tricroiradiobutton->raise();
        tridecroiradiobutton->raise();
        supprierconsultqntpushbutton->raise();
        odifyconsultant->raise();
        exportpdfbutton->raise();
        consultantTable->raise();
        statistiquepushbutton->raise();
        staticWidget->raise();
        hidepushbutton->raise();
        MainWindow->setCentralWidget(centralwidget);
        groupBox_3->raise();
        groupBox->raise();
        label_9->raise();
        lineEdit_6->raise();
        pushButton_2->raise();
        label_10->raise();
        groupBox_4->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1400, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QJOUTERCONSULTQNTBUTTON->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "ajouter un consultant", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "id du consultant: ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "donner le nom du consultant:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "prenom:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "numero de telephone :", nullptr));
        QJOUTERCONSULTQNTBUTTON->setText(QCoreApplication::translate("MainWindow", "ajouter ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "prenom:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "numero de telephone :", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "envoyer", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Bonjour,\n"
"Ceci est un rappel concernant votre rendez-vous pr\303\251vu\n"
" avec le responsable des consultants.\n"
" Merci d\342\200\231\303\252tre ponctuel et de confirmer votre disponibilit\303\251 \n"
"si n\303\251cessaire.\n"
"\n"
"Bonne journ\303\251e,\n"
"Chef des Consultants", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "alertes par sms ", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "gestion des consultants:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "gestion de liste des consultants :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "liste des consultants:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "rechercher:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "trier par id :", nullptr));
        tricroiradiobutton->setText(QCoreApplication::translate("MainWindow", "croissant", nullptr));
        tridecroiradiobutton->setText(QCoreApplication::translate("MainWindow", "decroissant", nullptr));
        supprierconsultqntpushbutton->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        odifyconsultant->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        exportpdfbutton->setText(QCoreApplication::translate("MainWindow", "exporter en pdf", nullptr));
        statistiquepushbutton->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        hidepushbutton->setText(QCoreApplication::translate("MainWindow", "hide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
