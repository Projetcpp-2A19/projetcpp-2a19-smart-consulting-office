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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *modifStadeButton;
    QPushButton *DeleteStadeButton;
    QComboBox *comboBoxsortchamp;
    QLineEdit *lineEdit_6;
    QLabel *label_8;
    QTableView *tableViewEmploye;
    QComboBox *comboBox_order;
    QPushButton *trier_Button;
    QGroupBox *groupBox;
    QLineEdit *idEmploye;
    QLabel *label_4;
    QLineEdit *lineEdit_nom;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label;
    QPushButton *add_button;
    QLineEdit *lineEdit_prenom;
    QLabel *label_9;
    QLineEdit *lineEdit_email;
    QDateEdit *dateEdit_embauche;
    QLabel *label_7;
    QLineEdit *lineEdit_mdp;
    QLabel *label_11;
    QLabel *label_10;
    QLineEdit *lineEdit_Adresse;
    QLineEdit *lineEdit_statut;
    QLabel *label_2;
    QComboBox *comboBox_specialite;
    QPushButton *pushButton;
    QFrame *frame;
    QWidget *page_2;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_email_2;
    QLabel *label_3;
    QLabel *label_12;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1601, 987);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(120, 30, 1551, 921));
        page = new QWidget();
        page->setObjectName("page");
        modifStadeButton = new QPushButton(page);
        modifStadeButton->setObjectName("modifStadeButton");
        modifStadeButton->setGeometry(QRect(890, 400, 121, 41));
        modifStadeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        DeleteStadeButton = new QPushButton(page);
        DeleteStadeButton->setObjectName("DeleteStadeButton");
        DeleteStadeButton->setGeometry(QRect(1040, 400, 101, 41));
        DeleteStadeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBoxsortchamp = new QComboBox(page);
        comboBoxsortchamp->addItem(QString());
        comboBoxsortchamp->addItem(QString());
        comboBoxsortchamp->setObjectName("comboBoxsortchamp");
        comboBoxsortchamp->setGeometry(QRect(1220, 120, 101, 41));
        lineEdit_6 = new QLineEdit(page);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(440, 40, 181, 41));
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"    background-color: #f9f9f9;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db;\n"
"    background-color: white;\n"
"}\n"
""));
        label_8 = new QLabel(page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(1230, 90, 63, 20));
        label_8->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        tableViewEmploye = new QTableView(page);
        tableViewEmploye->setObjectName("tableViewEmploye");
        tableViewEmploye->setGeometry(QRect(460, 100, 691, 281));
        tableViewEmploye->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #dcdcdc;\n"
"    font-size: 12px;\n"
"    color: #333;\n"
"    selection-background-color: #A3C1D1;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"    border-bottom: 1px solid #ddd;\n"
"}\n"
"\n"
"QTableView::header {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
""));
        comboBox_order = new QComboBox(page);
        comboBox_order->addItem(QString());
        comboBox_order->addItem(QString());
        comboBox_order->setObjectName("comboBox_order");
        comboBox_order->setGeometry(QRect(1220, 180, 101, 41));
        trier_Button = new QPushButton(page);
        trier_Button->setObjectName("trier_Button");
        trier_Button->setGeometry(QRect(1220, 240, 101, 41));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 10, 381, 651));
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
"}\n"
""));
        idEmploye = new QLineEdit(groupBox);
        idEmploye->setObjectName("idEmploye");
        idEmploye->setGeometry(QRect(160, 40, 161, 41));
        idEmploye->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"    background-color: #f9f9f9;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db;\n"
"    background-color: white;\n"
"}\n"
""));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 230, 101, 17));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(160, 100, 161, 41));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"    background-color: #f9f9f9;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db;\n"
"    background-color: white;\n"
"}\n"
""));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 170, 71, 17));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 370, 101, 17));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 50, 111, 20));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        add_button = new QPushButton(groupBox);
        add_button->setObjectName("add_button");
        add_button->setGeometry(QRect(20, 590, 141, 41));
        add_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_prenom = new QLineEdit(groupBox);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(160, 160, 161, 41));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"    background-color: #f9f9f9;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db;\n"
"    background-color: white;\n"
"}\n"
""));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 420, 101, 17));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        lineEdit_email = new QLineEdit(groupBox);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(160, 290, 161, 41));
        lineEdit_email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"    background-color: #f9f9f9;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db;\n"
"    background-color: white;\n"
"}\n"
""));
        dateEdit_embauche = new QDateEdit(groupBox);
        dateEdit_embauche->setObjectName("dateEdit_embauche");
        dateEdit_embauche->setGeometry(QRect(160, 525, 161, 41));
        dateEdit_embauche->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"    background-color: #f9f9f9;\n"
"}\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"}\n"
""));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 300, 101, 17));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        lineEdit_mdp = new QLineEdit(groupBox);
        lineEdit_mdp->setObjectName("lineEdit_mdp");
        lineEdit_mdp->setGeometry(QRect(160, 350, 161, 41));
        lineEdit_mdp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"    background-color: #f9f9f9;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db;\n"
"    background-color: white;\n"
"}\n"
""));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 550, 121, 20));
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 480, 101, 17));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        lineEdit_Adresse = new QLineEdit(groupBox);
        lineEdit_Adresse->setObjectName("lineEdit_Adresse");
        lineEdit_Adresse->setGeometry(QRect(160, 220, 161, 41));
        lineEdit_Adresse->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"    background-color: #f9f9f9;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db;\n"
"    background-color: white;\n"
"}\n"
""));
        lineEdit_statut = new QLineEdit(groupBox);
        lineEdit_statut->setObjectName("lineEdit_statut");
        lineEdit_statut->setGeometry(QRect(160, 470, 161, 41));
        lineEdit_statut->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"    background-color: #f9f9f9;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db;\n"
"    background-color: white;\n"
"}\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 110, 111, 20));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        comboBox_specialite = new QComboBox(groupBox);
        comboBox_specialite->setObjectName("comboBox_specialite");
        comboBox_specialite->setGeometry(QRect(170, 420, 141, 31));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1040, 30, 75, 31));
        frame = new QFrame(page);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(470, 470, 621, 211));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        lineEdit_password = new QLineEdit(page_2);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(470, 310, 211, 41));
        lineEdit_email_2 = new QLineEdit(page_2);
        lineEdit_email_2->setObjectName("lineEdit_email_2");
        lineEdit_email_2->setGeometry(QRect(470, 240, 211, 41));
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(338, 250, 71, 20));
        label_12 = new QLabel(page_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(338, 320, 81, 20));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(660, 390, 111, 31));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(450, 380, 75, 24));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1601, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        modifStadeButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        DeleteStadeButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        comboBoxsortchamp->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBoxsortchamp->setItemText(1, QCoreApplication::translate("MainWindow", "Date d'embauche", nullptr));

        lineEdit_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter un employe", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Trier par:", nullptr));
        comboBox_order->setItemText(0, QCoreApplication::translate("MainWindow", "Ascendant", nullptr));
        comboBox_order->setItemText(1, QCoreApplication::translate("MainWindow", "Descendant", nullptr));

        trier_Button->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Ajouter employe", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "idEmplye", nullptr));
        add_button->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Specialite", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Date embauche", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom ", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "password", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "forget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
