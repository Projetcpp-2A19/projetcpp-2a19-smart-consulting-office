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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
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
    QLabel *label_12;
    QGroupBox *gestion_projet;
    QTabWidget *tabWidget;
    QWidget *Projects;
    QGroupBox *groupBox;
    QPushButton *addButton;
    QDateEdit *dateDebutEdit;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLineEdit *nomLineEdit;
    QLabel *label_7;
    QLineEdit *budgetLineEdit;
    QLabel *label_8;
    QTextEdit *descLineEdit;
    QDateEdit *dateFinEdit;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *prioriteComboBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *statusComboBox;
    QComboBox *employeComboBox;
    QComboBox *clientComboBox;
    QLabel *label_5;
    QLabel *label_pic;
    QGroupBox *groupBox_3;
    QTableView *tableView;
    QSplitter *splitter_5;
    QPushButton *modifyButton;
    QPushButton *exportButton;
    QPushButton *deleteButton;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *searchLineEdit;
    QLabel *label_15;
    QLabel *label_9;
    QComboBox *sortComboBox;
    QLabel *temperatureLabel;
    QDoubleSpinBox *thresholdSpinBox;
    QPushButton *connectArduino;
    QPushButton *setThreshold;
    QLabel *arduinoStatusLabel;
    QWidget *tab;
    QGroupBox *groupBox_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutCharts;
    QGroupBox *groupBox_5;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayoutTracking;
    QLabel *label_10;
    QWidget *tab_2;
    QLabel *label_11;
    QGroupBox *groupBox_6;
    QGraphicsView *ganttGraphicsView_2;
    QLabel *bg_projet;
    QGroupBox *gestion_employe;
    QStackedWidget *stackedWidget_4;
    QWidget *page_7;
    QPushButton *modifStadeButton_4;
    QPushButton *DeleteStadeButton_4;
    QComboBox *comboBoxsortchamp_4;
    QLineEdit *lineEdit_9;
    QLabel *label_49;
    QTableView *tableViewEmploye_4;
    QComboBox *comboBox_order_4;
    QPushButton *trier_Button_4;
    QGroupBox *groupBox_9;
    QLineEdit *idEmploye_4;
    QLabel *label_50;
    QLineEdit *lineEdit_nom_4;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_53;
    QPushButton *add_button_4;
    QLineEdit *lineEdit_prenom_4;
    QLabel *label_54;
    QLineEdit *lineEdit_email_7;
    QDateEdit *dateEdit_embauche_4;
    QLabel *label_55;
    QLineEdit *lineEdit_mdp_4;
    QLabel *label_56;
    QLabel *label_57;
    QLineEdit *lineEdit_Adresse_4;
    QLineEdit *lineEdit_statut_4;
    QLabel *label_58;
    QComboBox *comboBox_specialite_4;
    QPushButton *pushButton_10;
    QFrame *frame_4;
    QPushButton *employe_go_to_menu;
    QWidget *page_8;
    QLineEdit *lineEdit_password_4;
    QLineEdit *lineEdit_email_8;
    QLabel *label_59;
    QLabel *label_60;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QGroupBox *menu;
    QPushButton *menu_employe;
    QPushButton *menu_projet;
    QPushButton *menu_client;
    QPushButton *menu_consultant;
    QPushButton *menu_reclamation;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(2070, 1396);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(32, 10, 211, 21));
        gestion_projet = new QGroupBox(centralWidget);
        gestion_projet->setObjectName("gestion_projet");
        gestion_projet->setGeometry(QRect(0, 0, 1920, 1080));
        tabWidget = new QTabWidget(gestion_projet);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(30, 30, 1400, 681));
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
        groupBox->setGeometry(QRect(10, 10, 331, 551));
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
        addButton->setGeometry(QRect(80, 500, 121, 31));
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
        dateDebutEdit->setGeometry(QRect(100, 420, 111, 31));
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
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 420, 88, 25));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 30, 251, 259));
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

        dateFinEdit = new QDateEdit(groupBox);
        dateFinEdit->setObjectName("dateFinEdit");
        dateFinEdit->setGeometry(QRect(100, 450, 111, 31));
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
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 450, 81, 25));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 320, 162, 28));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));

        horizontalLayout->addWidget(label);

        prioriteComboBox = new QComboBox(layoutWidget1);
        prioriteComboBox->addItem(QString());
        prioriteComboBox->addItem(QString());
        prioriteComboBox->addItem(QString());
        prioriteComboBox->setObjectName("prioriteComboBox");

        horizontalLayout->addWidget(prioriteComboBox);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(30, 290, 159, 28));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));

        horizontalLayout_4->addWidget(label_4);

        statusComboBox = new QComboBox(layoutWidget2);
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->setObjectName("statusComboBox");

        horizontalLayout_4->addWidget(statusComboBox);

        employeComboBox = new QComboBox(groupBox);
        employeComboBox->setObjectName("employeComboBox");
        employeComboBox->setGeometry(QRect(30, 380, 91, 26));
        clientComboBox = new QComboBox(groupBox);
        clientComboBox->setObjectName("clientComboBox");
        clientComboBox->setGeometry(QRect(140, 380, 91, 26));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 350, 211, 25));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        label_pic = new QLabel(Projects);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(1130, -20, 111, 81));
        groupBox_3 = new QGroupBox(Projects);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(350, 10, 881, 551));
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
        tableView->setGeometry(QRect(40, 120, 671, 261));
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
        splitter_5->setGeometry(QRect(740, 190, 121, 105));
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
        exportButton = new QPushButton(splitter_5);
        exportButton->setObjectName("exportButton");
        exportButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        splitter_5->addWidget(exportButton);
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
        verticalLayoutWidget_3 = new QWidget(groupBox_3);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(20, 400, 481, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        searchLineEdit = new QLineEdit(groupBox_3);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(130, 44, 114, 31));
        searchLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        sortComboBox = new QComboBox(groupBox_3);
        sortComboBox->setObjectName("sortComboBox");
        sortComboBox->setGeometry(QRect(110, 80, 161, 26));
        sortComboBox->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        temperatureLabel = new QLabel(groupBox_3);
        temperatureLabel->setObjectName("temperatureLabel");
        temperatureLabel->setGeometry(QRect(590, 400, 63, 20));
        thresholdSpinBox = new QDoubleSpinBox(groupBox_3);
        thresholdSpinBox->setObjectName("thresholdSpinBox");
        thresholdSpinBox->setGeometry(QRect(550, 440, 62, 26));
        connectArduino = new QPushButton(groupBox_3);
        connectArduino->setObjectName("connectArduino");
        connectArduino->setGeometry(QRect(540, 490, 93, 29));
        connectArduino->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        setThreshold = new QPushButton(groupBox_3);
        setThreshold->setObjectName("setThreshold");
        setThreshold->setGeometry(QRect(650, 440, 93, 29));
        setThreshold->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        arduinoStatusLabel = new QLabel(groupBox_3);
        arduinoStatusLabel->setObjectName("arduinoStatusLabel");
        arduinoStatusLabel->setGeometry(QRect(660, 490, 121, 21));
        tabWidget->addTab(Projects, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(810, 0, 411, 601));
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
"}\n"
""));
        verticalLayoutWidget = new QWidget(groupBox_4);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 20, 391, 571));
        verticalLayoutCharts = new QVBoxLayout(verticalLayoutWidget);
        verticalLayoutCharts->setSpacing(6);
        verticalLayoutCharts->setContentsMargins(11, 11, 11, 11);
        verticalLayoutCharts->setObjectName("verticalLayoutCharts");
        verticalLayoutCharts->setContentsMargins(0, 0, 0, 0);
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(10, 160, 791, 391));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        verticalLayoutWidget_4 = new QWidget(groupBox_5);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(10, 30, 771, 341));
        verticalLayoutTracking = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayoutTracking->setSpacing(6);
        verticalLayoutTracking->setContentsMargins(11, 11, 11, 11);
        verticalLayoutTracking->setObjectName("verticalLayoutTracking");
        verticalLayoutTracking->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(tab);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(80, 50, 261, 51));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_11 = new QLabel(tab_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(90, 20, 311, 51));
        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(30, 70, 1181, 551));
        groupBox_6->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        ganttGraphicsView_2 = new QGraphicsView(groupBox_6);
        ganttGraphicsView_2->setObjectName("ganttGraphicsView_2");
        ganttGraphicsView_2->setGeometry(QRect(30, 30, 1131, 511));
        ganttGraphicsView_2->setMinimumSize(QSize(400, 300));
        tabWidget->addTab(tab_2, QString());
        bg_projet = new QLabel(gestion_projet);
        bg_projet->setObjectName("bg_projet");
        bg_projet->setGeometry(QRect(0, 0, 1920, 1080));
        bg_projet->setStyleSheet(QString::fromUtf8("background-color:white;"));
        bg_projet->raise();
        tabWidget->raise();
        gestion_employe = new QGroupBox(centralWidget);
        gestion_employe->setObjectName("gestion_employe");
        gestion_employe->setGeometry(QRect(0, 0, 1920, 1080));
        gestion_employe->setStyleSheet(QString::fromUtf8("background-color:white;"));
        stackedWidget_4 = new QStackedWidget(gestion_employe);
        stackedWidget_4->setObjectName("stackedWidget_4");
        stackedWidget_4->setGeometry(QRect(0, 0, 1551, 921));
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        modifStadeButton_4 = new QPushButton(page_7);
        modifStadeButton_4->setObjectName("modifStadeButton_4");
        modifStadeButton_4->setGeometry(QRect(890, 400, 121, 41));
        modifStadeButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        DeleteStadeButton_4 = new QPushButton(page_7);
        DeleteStadeButton_4->setObjectName("DeleteStadeButton_4");
        DeleteStadeButton_4->setGeometry(QRect(1040, 400, 101, 41));
        DeleteStadeButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBoxsortchamp_4 = new QComboBox(page_7);
        comboBoxsortchamp_4->addItem(QString());
        comboBoxsortchamp_4->addItem(QString());
        comboBoxsortchamp_4->setObjectName("comboBoxsortchamp_4");
        comboBoxsortchamp_4->setGeometry(QRect(1220, 120, 101, 41));
        lineEdit_9 = new QLineEdit(page_7);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(440, 40, 181, 41));
        lineEdit_9->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_49 = new QLabel(page_7);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(1230, 90, 63, 20));
        label_49->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        tableViewEmploye_4 = new QTableView(page_7);
        tableViewEmploye_4->setObjectName("tableViewEmploye_4");
        tableViewEmploye_4->setGeometry(QRect(460, 100, 691, 281));
        tableViewEmploye_4->setStyleSheet(QString::fromUtf8("QTableView {\n"
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
        comboBox_order_4 = new QComboBox(page_7);
        comboBox_order_4->addItem(QString());
        comboBox_order_4->addItem(QString());
        comboBox_order_4->setObjectName("comboBox_order_4");
        comboBox_order_4->setGeometry(QRect(1220, 180, 101, 41));
        trier_Button_4 = new QPushButton(page_7);
        trier_Button_4->setObjectName("trier_Button_4");
        trier_Button_4->setGeometry(QRect(1220, 240, 101, 41));
        groupBox_9 = new QGroupBox(page_7);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(20, 10, 381, 651));
        groupBox_9->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        idEmploye_4 = new QLineEdit(groupBox_9);
        idEmploye_4->setObjectName("idEmploye_4");
        idEmploye_4->setGeometry(QRect(160, 40, 161, 41));
        idEmploye_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_50 = new QLabel(groupBox_9);
        label_50->setObjectName("label_50");
        label_50->setGeometry(QRect(30, 230, 101, 17));
        label_50->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        lineEdit_nom_4 = new QLineEdit(groupBox_9);
        lineEdit_nom_4->setObjectName("lineEdit_nom_4");
        lineEdit_nom_4->setGeometry(QRect(160, 100, 161, 41));
        lineEdit_nom_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_51 = new QLabel(groupBox_9);
        label_51->setObjectName("label_51");
        label_51->setGeometry(QRect(30, 170, 71, 17));
        label_51->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        label_52 = new QLabel(groupBox_9);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(30, 370, 101, 17));
        label_52->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        label_53 = new QLabel(groupBox_9);
        label_53->setObjectName("label_53");
        label_53->setGeometry(QRect(30, 50, 111, 20));
        label_53->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        add_button_4 = new QPushButton(groupBox_9);
        add_button_4->setObjectName("add_button_4");
        add_button_4->setGeometry(QRect(20, 590, 141, 41));
        add_button_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_prenom_4 = new QLineEdit(groupBox_9);
        lineEdit_prenom_4->setObjectName("lineEdit_prenom_4");
        lineEdit_prenom_4->setGeometry(QRect(160, 160, 161, 41));
        lineEdit_prenom_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_54 = new QLabel(groupBox_9);
        label_54->setObjectName("label_54");
        label_54->setGeometry(QRect(30, 420, 101, 17));
        label_54->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        lineEdit_email_7 = new QLineEdit(groupBox_9);
        lineEdit_email_7->setObjectName("lineEdit_email_7");
        lineEdit_email_7->setGeometry(QRect(160, 290, 161, 41));
        lineEdit_email_7->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        dateEdit_embauche_4 = new QDateEdit(groupBox_9);
        dateEdit_embauche_4->setObjectName("dateEdit_embauche_4");
        dateEdit_embauche_4->setGeometry(QRect(160, 525, 161, 41));
        dateEdit_embauche_4->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
        label_55 = new QLabel(groupBox_9);
        label_55->setObjectName("label_55");
        label_55->setGeometry(QRect(30, 300, 101, 17));
        label_55->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        lineEdit_mdp_4 = new QLineEdit(groupBox_9);
        lineEdit_mdp_4->setObjectName("lineEdit_mdp_4");
        lineEdit_mdp_4->setGeometry(QRect(160, 350, 161, 41));
        lineEdit_mdp_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_56 = new QLabel(groupBox_9);
        label_56->setObjectName("label_56");
        label_56->setGeometry(QRect(10, 550, 121, 20));
        label_56->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        label_57 = new QLabel(groupBox_9);
        label_57->setObjectName("label_57");
        label_57->setGeometry(QRect(30, 480, 101, 17));
        label_57->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        lineEdit_Adresse_4 = new QLineEdit(groupBox_9);
        lineEdit_Adresse_4->setObjectName("lineEdit_Adresse_4");
        lineEdit_Adresse_4->setGeometry(QRect(160, 220, 161, 41));
        lineEdit_Adresse_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_statut_4 = new QLineEdit(groupBox_9);
        lineEdit_statut_4->setObjectName("lineEdit_statut_4");
        lineEdit_statut_4->setGeometry(QRect(160, 470, 161, 41));
        lineEdit_statut_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_58 = new QLabel(groupBox_9);
        label_58->setObjectName("label_58");
        label_58->setGeometry(QRect(30, 110, 111, 20));
        label_58->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        comboBox_specialite_4 = new QComboBox(groupBox_9);
        comboBox_specialite_4->setObjectName("comboBox_specialite_4");
        comboBox_specialite_4->setGeometry(QRect(170, 420, 141, 31));
        pushButton_10 = new QPushButton(page_7);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(1040, 30, 75, 31));
        frame_4 = new QFrame(page_7);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(470, 470, 621, 211));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        employe_go_to_menu = new QPushButton(page_7);
        employe_go_to_menu->setObjectName("employe_go_to_menu");
        employe_go_to_menu->setGeometry(QRect(20, 780, 141, 41));
        employe_go_to_menu->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        stackedWidget_4->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        lineEdit_password_4 = new QLineEdit(page_8);
        lineEdit_password_4->setObjectName("lineEdit_password_4");
        lineEdit_password_4->setGeometry(QRect(470, 310, 211, 41));
        lineEdit_email_8 = new QLineEdit(page_8);
        lineEdit_email_8->setObjectName("lineEdit_email_8");
        lineEdit_email_8->setGeometry(QRect(470, 240, 211, 41));
        label_59 = new QLabel(page_8);
        label_59->setObjectName("label_59");
        label_59->setGeometry(QRect(338, 250, 71, 20));
        label_60 = new QLabel(page_8);
        label_60->setObjectName("label_60");
        label_60->setGeometry(QRect(338, 320, 81, 20));
        pushButton_11 = new QPushButton(page_8);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(660, 390, 111, 31));
        pushButton_12 = new QPushButton(page_8);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(450, 380, 75, 24));
        stackedWidget_4->addWidget(page_8);
        menu = new QGroupBox(centralWidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(0, 0, 1920, 1080));
        menu->setStyleSheet(QString::fromUtf8("background-color:white;"));
        menu_employe = new QPushButton(menu);
        menu_employe->setObjectName("menu_employe");
        menu_employe->setGeometry(QRect(520, 370, 191, 71));
        menu_projet = new QPushButton(menu);
        menu_projet->setObjectName("menu_projet");
        menu_projet->setGeometry(QRect(520, 460, 191, 71));
        menu_client = new QPushButton(menu);
        menu_client->setObjectName("menu_client");
        menu_client->setGeometry(QRect(520, 550, 191, 71));
        menu_consultant = new QPushButton(menu);
        menu_consultant->setObjectName("menu_consultant");
        menu_consultant->setGeometry(QRect(520, 640, 191, 71));
        menu_reclamation = new QPushButton(menu);
        menu_reclamation->setObjectName("menu_reclamation");
        menu_reclamation->setGeometry(QRect(520, 740, 191, 71));
        MainWindow->setCentralWidget(centralWidget);
        label_12->raise();
        gestion_projet->raise();
        menu->raise();
        gestion_employe->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 2070, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        stackedWidget_4->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        label_12->setText(QString());
        gestion_projet->setTitle(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Add Project", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Start date :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Name of the project :", nullptr));
        nomLineEdit->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Budget :", nullptr));
        budgetLineEdit->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Description :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "End date :", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Priority :", nullptr));
        prioriteComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Low", nullptr));
        prioriteComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Medium", nullptr));
        prioriteComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "High", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "statut", nullptr));
        statusComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Planned", nullptr));
        statusComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "In Progress", nullptr));
        statusComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Completed", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "choose employe and client:", nullptr));
        label_pic->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Projects", nullptr));
        modifyButton->setText(QCoreApplication::translate("MainWindow", "modify project", nullptr));
        exportButton->setText(QCoreApplication::translate("MainWindow", "Export to PDF", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "delete project", nullptr));
        searchLineEdit->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "Search :", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Priority :", nullptr));
        temperatureLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        connectArduino->setText(QCoreApplication::translate("MainWindow", "connect", nullptr));
        setThreshold->setText(QCoreApplication::translate("MainWindow", "set", nullptr));
        arduinoStatusLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Projects), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        groupBox_4->setTitle(QString());
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Projects", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700; font-style:italic; color:#00aaff;\">Project Tracker :</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Page", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700; font-style:italic; color:#00aaff;\">Projects Calendar :</span></p></body></html>", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Calendar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Page", nullptr));
        bg_projet->setText(QString());
        gestion_employe->setTitle(QString());
        modifStadeButton_4->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        DeleteStadeButton_4->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        comboBoxsortchamp_4->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBoxsortchamp_4->setItemText(1, QCoreApplication::translate("MainWindow", "Date d'embauche", nullptr));

        lineEdit_9->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter un employe", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "Trier par:", nullptr));
        comboBox_order_4->setItemText(0, QCoreApplication::translate("MainWindow", "Ascendant", nullptr));
        comboBox_order_4->setItemText(1, QCoreApplication::translate("MainWindow", "Descendant", nullptr));

        trier_Button_4->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "Ajouter employe", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_52->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        label_53->setText(QCoreApplication::translate("MainWindow", "idEmplye", nullptr));
        add_button_4->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_54->setText(QCoreApplication::translate("MainWindow", "Specialite", nullptr));
        label_55->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_56->setText(QCoreApplication::translate("MainWindow", "Date embauche", nullptr));
        label_57->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        label_58->setText(QCoreApplication::translate("MainWindow", "Nom ", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        employe_go_to_menu->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", "password", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "forget", nullptr));
        menu->setTitle(QString());
        menu_employe->setText(QCoreApplication::translate("MainWindow", "EMPLOYE", nullptr));
        menu_projet->setText(QCoreApplication::translate("MainWindow", "PROJET", nullptr));
        menu_client->setText(QCoreApplication::translate("MainWindow", "CLIENT", nullptr));
        menu_consultant->setText(QCoreApplication::translate("MainWindow", "CONSULTANT", nullptr));
        menu_reclamation->setText(QCoreApplication::translate("MainWindow", "RECLAMATION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
