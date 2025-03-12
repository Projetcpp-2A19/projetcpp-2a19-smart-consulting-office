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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Projects;
    QGroupBox *groupBox;
    QPushButton *addButton;
    QDateEdit *dateDebutEdit;
    QDateEdit *dateFinEdit;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLineEdit *nomLineEdit;
    QLabel *label_7;
    QLineEdit *budgetLineEdit;
    QLabel *label_8;
    QTextEdit *descLineEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *prioriteComboBox;
    QLabel *label_pic;
    QGroupBox *groupBox_3;
    QTableView *tableView;
    QSplitter *splitter_5;
    QPushButton *modifyButton;
    QPushButton *pushButton_9;
    QPushButton *deleteButton;
    QLabel *label_14;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_5;
    QLabel *label_15;
    QLabel *label_9;
    QComboBox *comboBox_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1290, 711);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 30, 1241, 571));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 2px solid #3498db; /* Bordure autour du widget */\n"
"    background: white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: #ecf0f1; /* Fond gris clair */\n"
"    border: 2px solid #bdc3c7;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #3498db; /* Bleu pour l'onglet actif */\n"
"    color: white;\n"
"    border: 2px solid #2980b9;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: #5dade2; /* Bleu clair au survol */\n"
"}\n"
""));
        Projects = new QWidget();
        Projects->setObjectName("Projects");
        groupBox = new QGroupBox(Projects);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 30, 291, 481));
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
        addButton = new QPushButton(groupBox);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(70, 440, 121, 31));
        addButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        dateDebutEdit = new QDateEdit(groupBox);
        dateDebutEdit->setObjectName("dateDebutEdit");
        dateDebutEdit->setGeometry(QRect(138, 343, 121, 31));
        dateDebutEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
        dateFinEdit = new QDateEdit(groupBox);
        dateFinEdit->setObjectName("dateFinEdit");
        dateFinEdit->setGeometry(QRect(122, 383, 121, 31));
        dateFinEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"    background-color: #f9f9f9;\n"
"}\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"}\n"
"\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(21, 343, 111, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(21, 383, 95, 31));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(23, 41, 251, 261));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));

        verticalLayout_4->addWidget(label_6);

        nomLineEdit = new QLineEdit(layoutWidget);
        nomLineEdit->setObjectName("nomLineEdit");
        nomLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        verticalLayout_4->addWidget(nomLineEdit);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));

        verticalLayout_4->addWidget(label_7);

        budgetLineEdit = new QLineEdit(layoutWidget);
        budgetLineEdit->setObjectName("budgetLineEdit");
        budgetLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        verticalLayout_4->addWidget(budgetLineEdit);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));

        verticalLayout_4->addWidget(label_8);

        descLineEdit = new QTextEdit(layoutWidget);
        descLineEdit->setObjectName("descLineEdit");
        descLineEdit->setStyleSheet(QString::fromUtf8("QTextEdit:focus {\n"
"    border: 2px solid #3498db;\n"
"    background-color: white;\n"
"}\n"
"\n"
"\n"
"QTextEdit {\n"
"    background-color: #1e1e1e;  /* Fond noir */\n"
"    color: #ffffff;  /* Texte blanc */\n"
"    border: 1px solid #333333;  /* Bordure grise */\n"
"\n"
"    selection-background-color: #444444; /* Couleur de s\303\251lection */\n"
"}\n"
"QTextEdit {\n"
"    background-color: #ffffff;\n"
"    color: #222222;\n"
"    font-size: 14px;\n"
"    border: 2px solid #aaaaaa;\n"
"\n"
"    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3); /* Ombre */\n"
"\n"
"}\n"
""));

        verticalLayout_4->addWidget(descLineEdit);

        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(21, 310, 162, 28));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));

        horizontalLayout->addWidget(label);

        prioriteComboBox = new QComboBox(widget);
        prioriteComboBox->addItem(QString());
        prioriteComboBox->addItem(QString());
        prioriteComboBox->addItem(QString());
        prioriteComboBox->setObjectName("prioriteComboBox");

        horizontalLayout->addWidget(prioriteComboBox);

        label_pic = new QLabel(Projects);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(1130, -20, 111, 81));
        groupBox_3 = new QGroupBox(Projects);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(320, 30, 801, 481));
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
"}\n"
""));
        tableView = new QTableView(groupBox_3);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 120, 611, 231));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
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
        splitter_5 = new QSplitter(groupBox_3);
        splitter_5->setObjectName("splitter_5");
        splitter_5->setGeometry(QRect(660, 140, 133, 105));
        splitter_5->setOrientation(Qt::Orientation::Vertical);
        modifyButton = new QPushButton(splitter_5);
        modifyButton->setObjectName("modifyButton");
        modifyButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        splitter_5->addWidget(modifyButton);
        pushButton_9 = new QPushButton(splitter_5);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        splitter_5->addWidget(pushButton_9);
        deleteButton = new QPushButton(splitter_5);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        splitter_5->addWidget(deleteButton);
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(30, 360, 181, 31));
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        verticalLayoutWidget_3 = new QWidget(groupBox_3);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(210, 360, 431, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(130, 44, 114, 31));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(30, 44, 94, 31));
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 80, 71, 25));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        comboBox_4 = new QComboBox(groupBox_3);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(110, 80, 80, 26));
        comboBox_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tabWidget->addTab(Projects, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1290, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Add Project", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Start date :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "End date :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Name of the project :", nullptr));
        nomLineEdit->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Budget :", nullptr));
        budgetLineEdit->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Description :", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Priority :", nullptr));
        prioriteComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Low", nullptr));
        prioriteComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Medium", nullptr));
        prioriteComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "High", nullptr));

        label_pic->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Projects", nullptr));
        modifyButton->setText(QCoreApplication::translate("MainWindow", "modify project", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Export to PDF", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "delete project", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Statics of the project", nullptr));
        lineEdit_5->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "Search :", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Priority :", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "haute", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "moyenne", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("MainWindow", "basse", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(Projects), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
