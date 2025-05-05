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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
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
    QGroupBox *gestion_client;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QGroupBox *groupBox_10;
    QLineEdit *lineEdit_nomCliet;
    QLineEdit *lineEdit_prenomClient;
    QLineEdit *lineEdit_numClient;
    QLabel *label_nomClient;
    QLabel *label_prenomClient;
    QLabel *label_typeClient;
    QLabel *label_61;
    QComboBox *comboBox_typeClient;
    QPushButton *pushButton_addClient;
    QPushButton *pushButton_cancel;
    QLabel *label_adresseClient;
    QLineEdit *lineEdit_adresseClient;
    QLineEdit *lineEdit_emailClient;
    QLineEdit *lineEdit_cinClient;
    QLabel *label_emailClient;
    QLabel *label_cinClient;
    QWidget *tab_4;
    QGroupBox *groupBox_11;
    QLineEdit *lineEdit_searchEmail;
    QPushButton *pushButton_13;
    QTableView *tableViewClients;
    QGroupBox *groupBox_12;
    QPushButton *pushButton_notify;
    QPushButton *pushButton_actualiser;
    QPushButton *pushButton_pdf;
    QRadioButton *pushButton_sortByName;
    QRadioButton *pushButton_sortByCin;
    QPushButton *pushButton_deleteClient;
    QPushButton *pushButton_updateClient;
    QPushButton *pushButton_statistique;
    QPushButton *pushButton_backup;
    QPushButton *projet_go_to_menu;
    QWidget *tab_5;
    QGroupBox *groupBox_13;
    QLabel *bg_client;
    QGroupBox *gestion_consultant;
    QLabel *bg_projet_2;
    QGroupBox *groupBox_19;
    QGroupBox *groupBox_20;
    QLabel *label_74;
    QTableView *consultantTable;
    QLabel *label_75;
    QLineEdit *chercherconsultqntlineedit;
    QLabel *label_76;
    QRadioButton *tricroiradiobutton;
    QRadioButton *tridecroiradiobutton;
    QPushButton *supprierconsultqntpushbutton;
    QPushButton *odifyconsultant;
    QPushButton *exportpdfbutton;
    QPushButton *statistiquepushbutton;
    QWidget *staticWidget;
    QPushButton *hidepushbutton;
    QPushButton *sendsms;
    QLineEdit *numerolineedit;
    QLineEdit *textsms;
    QLabel *label_77;
    QLabel *label_78;
    QPushButton *fanOnButton;
    QPushButton *fanOffButton;
    QLabel *fanStatusLabel;
    QLineEdit *temperatureLineEdit;
    QPushButton *tempButton;
    QPushButton *consultant_go_to_menu;
    QGroupBox *groupBox_21;
    QLabel *label_79;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_Nom;
    QLineEdit *lineEdit_Prenom;
    QLineEdit *lineEdit_Telephone;
    QLabel *label_80;
    QLabel *label_81;
    QLabel *label_82;
    QPushButton *QJOUTERCONSULTQNTBUTTON;
    QPushButton *pushButton_14;
    QLabel *label_83;
    QDateEdit *dateAjoutLineEdit;
    QGroupBox *gestion_reclamation;
    QTabWidget *tabWidget_3;
    QWidget *Projects_2;
    QGroupBox *groupBox_2;
    QComboBox *priorite_reclamation;
    QLabel *label_12;
    QPushButton *bt_ajouter_reclamation;
    QDateEdit *date_reclamation;
    QLabel *label_13;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_14;
    QLineEdit *id_reclamation;
    QLabel *label_16;
    QLineEdit *description_reclamation;
    QLabel *label_17;
    QLineEdit *resolution_reclamation;
    QPushButton *bt_modifier_reclamation;
    QLabel *label_18;
    QComboBox *etat_reclamation;
    QLabel *label_19;
    QComboBox *nom_client_reclamation;
    QLabel *label_pic_2;
    QGroupBox *groupBox_7;
    QTableView *tableView_reclamation;
    QSplitter *splitter_6;
    QPushButton *pushButton_9;
    QPushButton *bt_supprimier_reclamation;
    QLabel *label_20;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLineEdit *lineEdit_envoyer_chatbot;
    QPushButton *bt_generate;
    QTextEdit *textEdit_text_chat;
    QLineEdit *chercher_text;
    QLabel *label_21;
    QComboBox *id_supprimer_reclamation;
    QPushButton *bt_trier;
    QComboBox *comboBox_ordre;
    QComboBox *comboBox_choix;
    QPushButton *reclamation_go_to_menu;
    QWidget *tab_6;
    QLabel *label_stat;
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
        gestion_client = new QGroupBox(centralWidget);
        gestion_client->setObjectName("gestion_client");
        gestion_client->setGeometry(QRect(0, 0, 1920, 1080));
        tabWidget_2 = new QTabWidget(gestion_client);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(20, 40, 1261, 691));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        groupBox_10 = new QGroupBox(tab_3);
        groupBox_10->setObjectName("groupBox_10");
        groupBox_10->setGeometry(QRect(20, 31, 1021, 611));
        groupBox_10->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px; margin-top: 1ex;\n"
"color:#00aaff;\n"
"border-color:#00aaff;"));
        lineEdit_nomCliet = new QLineEdit(groupBox_10);
        lineEdit_nomCliet->setObjectName("lineEdit_nomCliet");
        lineEdit_nomCliet->setGeometry(QRect(230, 50, 211, 51));
        lineEdit_prenomClient = new QLineEdit(groupBox_10);
        lineEdit_prenomClient->setObjectName("lineEdit_prenomClient");
        lineEdit_prenomClient->setGeometry(QRect(230, 160, 211, 51));
        lineEdit_numClient = new QLineEdit(groupBox_10);
        lineEdit_numClient->setObjectName("lineEdit_numClient");
        lineEdit_numClient->setGeometry(QRect(710, 160, 211, 51));
        label_nomClient = new QLabel(groupBox_10);
        label_nomClient->setObjectName("label_nomClient");
        label_nomClient->setGeometry(QRect(40, 60, 131, 31));
        label_nomClient->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        label_prenomClient = new QLabel(groupBox_10);
        label_prenomClient->setObjectName("label_prenomClient");
        label_prenomClient->setGeometry(QRect(40, 167, 131, 31));
        label_prenomClient->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        label_typeClient = new QLabel(groupBox_10);
        label_typeClient->setObjectName("label_typeClient");
        label_typeClient->setGeometry(QRect(530, 60, 131, 31));
        label_typeClient->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        label_61 = new QLabel(groupBox_10);
        label_61->setObjectName("label_61");
        label_61->setGeometry(QRect(530, 170, 151, 31));
        label_61->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        comboBox_typeClient = new QComboBox(groupBox_10);
        comboBox_typeClient->setObjectName("comboBox_typeClient");
        comboBox_typeClient->setGeometry(QRect(710, 50, 211, 51));
        pushButton_addClient = new QPushButton(groupBox_10);
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
        pushButton_cancel = new QPushButton(groupBox_10);
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
        label_adresseClient = new QLabel(groupBox_10);
        label_adresseClient->setObjectName("label_adresseClient");
        label_adresseClient->setGeometry(QRect(531, 280, 131, 31));
        label_adresseClient->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        lineEdit_adresseClient = new QLineEdit(groupBox_10);
        lineEdit_adresseClient->setObjectName("lineEdit_adresseClient");
        lineEdit_adresseClient->setGeometry(QRect(710, 268, 211, 51));
        lineEdit_emailClient = new QLineEdit(groupBox_10);
        lineEdit_emailClient->setObjectName("lineEdit_emailClient");
        lineEdit_emailClient->setGeometry(QRect(230, 267, 211, 51));
        lineEdit_cinClient = new QLineEdit(groupBox_10);
        lineEdit_cinClient->setObjectName("lineEdit_cinClient");
        lineEdit_cinClient->setGeometry(QRect(231, 378, 211, 51));
        label_emailClient = new QLabel(groupBox_10);
        label_emailClient->setObjectName("label_emailClient");
        label_emailClient->setGeometry(QRect(39, 273, 131, 31));
        label_emailClient->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        label_cinClient = new QLabel(groupBox_10);
        label_cinClient->setObjectName("label_cinClient");
        label_cinClient->setGeometry(QRect(39, 386, 131, 31));
        label_cinClient->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    border: 1px solid transparent;\n"
"    font-weight: bold;\n"
"}"));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        groupBox_11 = new QGroupBox(tab_4);
        groupBox_11->setObjectName("groupBox_11");
        groupBox_11->setGeometry(QRect(10, 50, 671, 491));
        groupBox_11->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px; margin-top: 1ex;\n"
"color:#00aaff;\n"
"border-color:#00aaff;"));
        lineEdit_searchEmail = new QLineEdit(groupBox_11);
        lineEdit_searchEmail->setObjectName("lineEdit_searchEmail");
        lineEdit_searchEmail->setGeometry(QRect(360, 410, 211, 51));
        pushButton_13 = new QPushButton(groupBox_11);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(230, 408, 93, 51));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tableViewClients = new QTableView(groupBox_11);
        tableViewClients->setObjectName("tableViewClients");
        tableViewClients->setGeometry(QRect(10, 30, 631, 361));
        tableViewClients->setStyleSheet(QString::fromUtf8(""));
        groupBox_12 = new QGroupBox(tab_4);
        groupBox_12->setObjectName("groupBox_12");
        groupBox_12->setGeometry(QRect(700, 50, 331, 491));
        groupBox_12->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px; margin-top: 1ex;\n"
"color: #00aaff;\n"
"border-color:#00aaff;"));
        pushButton_notify = new QPushButton(groupBox_12);
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
        pushButton_actualiser = new QPushButton(groupBox_12);
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
        pushButton_pdf = new QPushButton(groupBox_12);
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
        pushButton_sortByName = new QRadioButton(groupBox_12);
        pushButton_sortByName->setObjectName("pushButton_sortByName");
        pushButton_sortByName->setGeometry(QRect(110, 373, 110, 41));
        pushButton_sortByCin = new QRadioButton(groupBox_12);
        pushButton_sortByCin->setObjectName("pushButton_sortByCin");
        pushButton_sortByCin->setGeometry(QRect(110, 420, 110, 41));
        pushButton_deleteClient = new QPushButton(groupBox_12);
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
        pushButton_updateClient = new QPushButton(groupBox_12);
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
        pushButton_statistique = new QPushButton(groupBox_12);
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
        pushButton_backup = new QPushButton(groupBox_12);
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
        projet_go_to_menu = new QPushButton(tab_4);
        projet_go_to_menu->setObjectName("projet_go_to_menu");
        projet_go_to_menu->setGeometry(QRect(10, 10, 81, 31));
        projet_go_to_menu->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        groupBox_13 = new QGroupBox(tab_5);
        groupBox_13->setObjectName("groupBox_13");
        groupBox_13->setGeometry(QRect(0, 0, 1061, 671));
        groupBox_13->setStyleSheet(QString::fromUtf8("border: 2px solid blue; border-radius: 5px; margin-top: 1ex;\n"
"color:#00aaff;\n"
"border-color:#00aaff;"));
        tabWidget_2->addTab(tab_5, QString());
        bg_client = new QLabel(gestion_client);
        bg_client->setObjectName("bg_client");
        bg_client->setGeometry(QRect(0, 0, 1920, 1080));
        bg_client->setStyleSheet(QString::fromUtf8("background-color:white;"));
        bg_client->raise();
        tabWidget_2->raise();
        gestion_consultant = new QGroupBox(centralWidget);
        gestion_consultant->setObjectName("gestion_consultant");
        gestion_consultant->setGeometry(QRect(0, 0, 1920, 1080));
        bg_projet_2 = new QLabel(gestion_consultant);
        bg_projet_2->setObjectName("bg_projet_2");
        bg_projet_2->setGeometry(QRect(0, 0, 1920, 1080));
        bg_projet_2->setStyleSheet(QString::fromUtf8("background-color:white;"));
        groupBox_19 = new QGroupBox(gestion_consultant);
        groupBox_19->setObjectName("groupBox_19");
        groupBox_19->setGeometry(QRect(10, 30, 1331, 691));
        groupBox_19->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #3498db;\n"
"    border-radius: 10px;\n"
"    margin-top: 10px;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    padding: 10px;\n"
"background-color:white;\n"
"\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 5px 10px;\n"
"    color: #3498db;\n"
"}"));
        groupBox_20 = new QGroupBox(groupBox_19);
        groupBox_20->setObjectName("groupBox_20");
        groupBox_20->setEnabled(true);
        groupBox_20->setGeometry(QRect(580, 20, 741, 641));
        groupBox_20->setStyleSheet(QString::fromUtf8("\n"
"QGroupBox {\n"
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
        label_74 = new QLabel(groupBox_20);
        label_74->setObjectName("label_74");
        label_74->setGeometry(QRect(20, 40, 151, 20));
        consultantTable = new QTableView(groupBox_20);
        consultantTable->setObjectName("consultantTable");
        consultantTable->setGeometry(QRect(200, 90, 521, 211));
        label_75 = new QLabel(groupBox_20);
        label_75->setObjectName("label_75");
        label_75->setGeometry(QRect(180, 40, 101, 20));
        chercherconsultqntlineedit = new QLineEdit(groupBox_20);
        chercherconsultqntlineedit->setObjectName("chercherconsultqntlineedit");
        chercherconsultqntlineedit->setGeometry(QRect(270, 40, 113, 26));
        label_76 = new QLabel(groupBox_20);
        label_76->setObjectName("label_76");
        label_76->setGeometry(QRect(420, 40, 81, 20));
        tricroiradiobutton = new QRadioButton(groupBox_20);
        tricroiradiobutton->setObjectName("tricroiradiobutton");
        tricroiradiobutton->setGeometry(QRect(520, 20, 110, 24));
        tridecroiradiobutton = new QRadioButton(groupBox_20);
        tridecroiradiobutton->setObjectName("tridecroiradiobutton");
        tridecroiradiobutton->setGeometry(QRect(520, 60, 110, 24));
        supprierconsultqntpushbutton = new QPushButton(groupBox_20);
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
        odifyconsultant = new QPushButton(groupBox_20);
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
        exportpdfbutton = new QPushButton(groupBox_20);
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
        statistiquepushbutton = new QPushButton(groupBox_20);
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
        staticWidget = new QWidget(groupBox_20);
        staticWidget->setObjectName("staticWidget");
        staticWidget->setGeometry(QRect(20, 310, 701, 271));
        hidepushbutton = new QPushButton(groupBox_20);
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
        label_74->raise();
        label_75->raise();
        label_76->raise();
        staticWidget->raise();
        chercherconsultqntlineedit->raise();
        tricroiradiobutton->raise();
        tridecroiradiobutton->raise();
        supprierconsultqntpushbutton->raise();
        odifyconsultant->raise();
        exportpdfbutton->raise();
        consultantTable->raise();
        statistiquepushbutton->raise();
        hidepushbutton->raise();
        sendsms = new QPushButton(groupBox_19);
        sendsms->setObjectName("sendsms");
        sendsms->setGeometry(QRect(200, 620, 93, 29));
        sendsms->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        numerolineedit = new QLineEdit(groupBox_19);
        numerolineedit->setObjectName("numerolineedit");
        numerolineedit->setGeometry(QRect(200, 580, 113, 26));
        textsms = new QLineEdit(groupBox_19);
        textsms->setObjectName("textsms");
        textsms->setGeometry(QRect(90, 470, 251, 91));
        label_77 = new QLabel(groupBox_19);
        label_77->setObjectName("label_77");
        label_77->setGeometry(QRect(20, 580, 191, 20));
        label_78 = new QLabel(groupBox_19);
        label_78->setObjectName("label_78");
        label_78->setGeometry(QRect(20, 490, 191, 20));
        fanOnButton = new QPushButton(groupBox_19);
        fanOnButton->setObjectName("fanOnButton");
        fanOnButton->setGeometry(QRect(400, 380, 151, 29));
        fanOffButton = new QPushButton(groupBox_19);
        fanOffButton->setObjectName("fanOffButton");
        fanOffButton->setGeometry(QRect(410, 420, 141, 29));
        fanStatusLabel = new QLabel(groupBox_19);
        fanStatusLabel->setObjectName("fanStatusLabel");
        fanStatusLabel->setGeometry(QRect(410, 500, 141, 31));
        temperatureLineEdit = new QLineEdit(groupBox_19);
        temperatureLineEdit->setObjectName("temperatureLineEdit");
        temperatureLineEdit->setGeometry(QRect(420, 460, 113, 26));
        tempButton = new QPushButton(groupBox_19);
        tempButton->setObjectName("tempButton");
        tempButton->setGeometry(QRect(450, 540, 93, 29));
        consultant_go_to_menu = new QPushButton(groupBox_19);
        consultant_go_to_menu->setObjectName("consultant_go_to_menu");
        consultant_go_to_menu->setGeometry(QRect(10, 650, 93, 29));
        consultant_go_to_menu->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        groupBox_21 = new QGroupBox(gestion_consultant);
        groupBox_21->setObjectName("groupBox_21");
        groupBox_21->setGeometry(QRect(90, 20, 491, 371));
        groupBox_21->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        label_79 = new QLabel(groupBox_21);
        label_79->setObjectName("label_79");
        label_79->setGeometry(QRect(40, 30, 121, 16));
        lineEdit_ID = new QLineEdit(groupBox_21);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(30, 50, 181, 31));
        lineEdit_Nom = new QLineEdit(groupBox_21);
        lineEdit_Nom->setObjectName("lineEdit_Nom");
        lineEdit_Nom->setGeometry(QRect(30, 130, 181, 31));
        lineEdit_Prenom = new QLineEdit(groupBox_21);
        lineEdit_Prenom->setObjectName("lineEdit_Prenom");
        lineEdit_Prenom->setGeometry(QRect(280, 130, 191, 31));
        lineEdit_Telephone = new QLineEdit(groupBox_21);
        lineEdit_Telephone->setObjectName("lineEdit_Telephone");
        lineEdit_Telephone->setGeometry(QRect(30, 220, 191, 31));
        label_80 = new QLabel(groupBox_21);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(30, 100, 201, 20));
        label_81 = new QLabel(groupBox_21);
        label_81->setObjectName("label_81");
        label_81->setGeometry(QRect(280, 100, 63, 20));
        label_82 = new QLabel(groupBox_21);
        label_82->setObjectName("label_82");
        label_82->setGeometry(QRect(30, 190, 191, 20));
        QJOUTERCONSULTQNTBUTTON = new QPushButton(groupBox_21);
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
        pushButton_14 = new QPushButton(groupBox_21);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(90, 330, 93, 29));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_83 = new QLabel(groupBox_21);
        label_83->setObjectName("label_83");
        label_83->setGeometry(QRect(280, 190, 63, 20));
        dateAjoutLineEdit = new QDateEdit(groupBox_21);
        dateAjoutLineEdit->setObjectName("dateAjoutLineEdit");
        dateAjoutLineEdit->setGeometry(QRect(280, 230, 161, 26));
        gestion_reclamation = new QGroupBox(centralWidget);
        gestion_reclamation->setObjectName("gestion_reclamation");
        gestion_reclamation->setGeometry(QRect(0, 0, 1920, 1080));
        gestion_reclamation->setStyleSheet(QString::fromUtf8("background-color:white;"));
        tabWidget_3 = new QTabWidget(gestion_reclamation);
        tabWidget_3->setObjectName("tabWidget_3");
        tabWidget_3->setGeometry(QRect(30, 20, 1241, 661));
        tabWidget_3->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
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
        Projects_2 = new QWidget();
        Projects_2->setObjectName("Projects_2");
        groupBox_2 = new QGroupBox(Projects_2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 30, 291, 581));
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
"}\n"
""));
        priorite_reclamation = new QComboBox(groupBox_2);
        priorite_reclamation->addItem(QString());
        priorite_reclamation->addItem(QString());
        priorite_reclamation->addItem(QString());
        priorite_reclamation->setObjectName("priorite_reclamation");
        priorite_reclamation->setGeometry(QRect(140, 320, 86, 26));
        priorite_reclamation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 320, 73, 25));
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        bt_ajouter_reclamation = new QPushButton(groupBox_2);
        bt_ajouter_reclamation->setObjectName("bt_ajouter_reclamation");
        bt_ajouter_reclamation->setGeometry(QRect(30, 530, 91, 31));
        bt_ajouter_reclamation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        date_reclamation = new QDateEdit(groupBox_2);
        date_reclamation->setObjectName("date_reclamation");
        date_reclamation->setGeometry(QRect(130, 360, 121, 31));
        date_reclamation->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 360, 95, 31));
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(23, 41, 251, 269));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName("label_14");
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));

        verticalLayout_5->addWidget(label_14);

        id_reclamation = new QLineEdit(layoutWidget_2);
        id_reclamation->setObjectName("id_reclamation");
        id_reclamation->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        verticalLayout_5->addWidget(id_reclamation);

        label_16 = new QLabel(layoutWidget_2);
        label_16->setObjectName("label_16");
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));

        verticalLayout_5->addWidget(label_16);

        description_reclamation = new QLineEdit(layoutWidget_2);
        description_reclamation->setObjectName("description_reclamation");
        description_reclamation->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        verticalLayout_5->addWidget(description_reclamation);

        label_17 = new QLabel(layoutWidget_2);
        label_17->setObjectName("label_17");
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));

        verticalLayout_5->addWidget(label_17);

        resolution_reclamation = new QLineEdit(layoutWidget_2);
        resolution_reclamation->setObjectName("resolution_reclamation");
        resolution_reclamation->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        verticalLayout_5->addWidget(resolution_reclamation);

        bt_modifier_reclamation = new QPushButton(groupBox_2);
        bt_modifier_reclamation->setObjectName("bt_modifier_reclamation");
        bt_modifier_reclamation->setGeometry(QRect(150, 530, 91, 31));
        bt_modifier_reclamation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(20, 400, 95, 31));
        label_18->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        etat_reclamation = new QComboBox(groupBox_2);
        etat_reclamation->addItem(QString());
        etat_reclamation->addItem(QString());
        etat_reclamation->addItem(QString());
        etat_reclamation->setObjectName("etat_reclamation");
        etat_reclamation->setGeometry(QRect(130, 400, 86, 26));
        etat_reclamation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 450, 95, 31));
        label_19->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        nom_client_reclamation = new QComboBox(groupBox_2);
        nom_client_reclamation->setObjectName("nom_client_reclamation");
        nom_client_reclamation->setGeometry(QRect(140, 450, 86, 26));
        nom_client_reclamation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_pic_2 = new QLabel(Projects_2);
        label_pic_2->setObjectName("label_pic_2");
        label_pic_2->setGeometry(QRect(1130, -20, 111, 81));
        groupBox_7 = new QGroupBox(Projects_2);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(320, 30, 841, 581));
        groupBox_7->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        tableView_reclamation = new QTableView(groupBox_7);
        tableView_reclamation->setObjectName("tableView_reclamation");
        tableView_reclamation->setGeometry(QRect(30, 120, 611, 141));
        tableView_reclamation->setStyleSheet(QString::fromUtf8("QTableView {\n"
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
        splitter_6 = new QSplitter(groupBox_7);
        splitter_6->setObjectName("splitter_6");
        splitter_6->setGeometry(QRect(480, 40, 341, 35));
        splitter_6->setOrientation(Qt::Orientation::Horizontal);
        pushButton_9 = new QPushButton(splitter_6);
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
        splitter_6->addWidget(pushButton_9);
        bt_supprimier_reclamation = new QPushButton(splitter_6);
        bt_supprimier_reclamation->setObjectName("bt_supprimier_reclamation");
        bt_supprimier_reclamation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        splitter_6->addWidget(bt_supprimier_reclamation);
        label_20 = new QLabel(groupBox_7);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(30, 440, 181, 31));
        label_20->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        verticalLayoutWidget_5 = new QWidget(groupBox_7);
        verticalLayoutWidget_5->setObjectName("verticalLayoutWidget_5");
        verticalLayoutWidget_5->setGeometry(QRect(230, 350, 431, 201));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(verticalLayoutWidget_5);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 427, 197));
        lineEdit_envoyer_chatbot = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_envoyer_chatbot->setObjectName("lineEdit_envoyer_chatbot");
        lineEdit_envoyer_chatbot->setGeometry(QRect(10, 160, 311, 41));
        bt_generate = new QPushButton(scrollAreaWidgetContents);
        bt_generate->setObjectName("bt_generate");
        bt_generate->setGeometry(QRect(330, 160, 83, 29));
        textEdit_text_chat = new QTextEdit(scrollAreaWidgetContents);
        textEdit_text_chat->setObjectName("textEdit_text_chat");
        textEdit_text_chat->setGeometry(QRect(0, 0, 431, 151));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        chercher_text = new QLineEdit(groupBox_7);
        chercher_text->setObjectName("chercher_text");
        chercher_text->setGeometry(QRect(130, 44, 114, 31));
        chercher_text->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_21 = new QLabel(groupBox_7);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(30, 44, 94, 31));
        label_21->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 */\n"
"    padding: 3px;\n"
"}\n"
""));
        id_supprimer_reclamation = new QComboBox(groupBox_7);
        id_supprimer_reclamation->setObjectName("id_supprimer_reclamation");
        id_supprimer_reclamation->setGeometry(QRect(680, 120, 131, 26));
        id_supprimer_reclamation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        bt_trier = new QPushButton(groupBox_7);
        bt_trier->setObjectName("bt_trier");
        bt_trier->setGeometry(QRect(290, 80, 91, 31));
        bt_trier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBox_ordre = new QComboBox(groupBox_7);
        comboBox_ordre->addItem(QString());
        comboBox_ordre->addItem(QString());
        comboBox_ordre->setObjectName("comboBox_ordre");
        comboBox_ordre->setGeometry(QRect(290, 40, 100, 26));
        comboBox_ordre->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBox_choix = new QComboBox(groupBox_7);
        comboBox_choix->addItem(QString());
        comboBox_choix->addItem(QString());
        comboBox_choix->addItem(QString());
        comboBox_choix->addItem(QString());
        comboBox_choix->addItem(QString());
        comboBox_choix->addItem(QString());
        comboBox_choix->addItem(QString());
        comboBox_choix->setObjectName("comboBox_choix");
        comboBox_choix->setGeometry(QRect(110, 80, 141, 26));
        comboBox_choix->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        reclamation_go_to_menu = new QPushButton(Projects_2);
        reclamation_go_to_menu->setObjectName("reclamation_go_to_menu");
        reclamation_go_to_menu->setGeometry(QRect(1100, 0, 91, 31));
        reclamation_go_to_menu->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tabWidget_3->addTab(Projects_2, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        label_stat = new QLabel(tab_6);
        label_stat->setObjectName("label_stat");
        label_stat->setGeometry(QRect(310, 180, 661, 441));
        tabWidget_3->addTab(tab_6, QString());
        MainWindow->setCentralWidget(centralWidget);
        gestion_employe->raise();
        gestion_client->raise();
        gestion_consultant->raise();
        gestion_projet->raise();
        menu->raise();
        gestion_reclamation->raise();
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
        stackedWidget_4->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);
        QJOUTERCONSULTQNTBUTTON->setDefault(true);
        tabWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
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
        gestion_client->setTitle(QString());
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "Ajouter un client ", nullptr));
        label_nomClient->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_prenomClient->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_typeClient->setText(QCoreApplication::translate("MainWindow", "Type Client", nullptr));
        label_61->setText(QCoreApplication::translate("MainWindow", "Num De T\303\251l\303\251phione", nullptr));
        pushButton_addClient->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_adresseClient->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_emailClient->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_cinClient->setText(QCoreApplication::translate("MainWindow", "Cin", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Ajouter Client", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "Liste Des Clients ", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        pushButton_notify->setText(QCoreApplication::translate("MainWindow", "Notifier Client", nullptr));
        pushButton_actualiser->setText(QCoreApplication::translate("MainWindow", "Actualiser", nullptr));
        pushButton_pdf->setText(QCoreApplication::translate("MainWindow", "List PDF", nullptr));
        pushButton_sortByName->setText(QCoreApplication::translate("MainWindow", "Tri par nom", nullptr));
        pushButton_sortByCin->setText(QCoreApplication::translate("MainWindow", "Tri par CIN", nullptr));
        pushButton_deleteClient->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_updateClient->setText(QCoreApplication::translate("MainWindow", "Modifier client", nullptr));
        pushButton_statistique->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        pushButton_backup->setText(QCoreApplication::translate("MainWindow", "BackUp", nullptr));
        projet_go_to_menu->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Affichier Client", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Statistique ", nullptr));
        bg_client->setText(QString());
        gestion_consultant->setTitle(QString());
        bg_projet_2->setText(QString());
        groupBox_19->setTitle(QCoreApplication::translate("MainWindow", "gestion des consultants:", nullptr));
        groupBox_20->setTitle(QCoreApplication::translate("MainWindow", "gestion de liste des consultants :", nullptr));
        label_74->setText(QCoreApplication::translate("MainWindow", "liste des consultants:", nullptr));
        label_75->setText(QCoreApplication::translate("MainWindow", "rechercher:", nullptr));
        label_76->setText(QCoreApplication::translate("MainWindow", "trier par id :", nullptr));
        tricroiradiobutton->setText(QCoreApplication::translate("MainWindow", "croissant", nullptr));
        tridecroiradiobutton->setText(QCoreApplication::translate("MainWindow", "decroissant", nullptr));
        supprierconsultqntpushbutton->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        odifyconsultant->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        exportpdfbutton->setText(QCoreApplication::translate("MainWindow", "exporter en pdf", nullptr));
        statistiquepushbutton->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        hidepushbutton->setText(QCoreApplication::translate("MainWindow", "hide", nullptr));
        sendsms->setText(QCoreApplication::translate("MainWindow", "send", nullptr));
        label_77->setText(QCoreApplication::translate("MainWindow", "numero de telephone :", nullptr));
        label_78->setText(QCoreApplication::translate("MainWindow", "sms :", nullptr));
        fanOnButton->setText(QCoreApplication::translate("MainWindow", "fanOnButton", nullptr));
        fanOffButton->setText(QCoreApplication::translate("MainWindow", "fanOffButton", nullptr));
        fanStatusLabel->setText(QCoreApplication::translate("MainWindow", "fanStatusLabel", nullptr));
        tempButton->setText(QCoreApplication::translate("MainWindow", "temp", nullptr));
        consultant_go_to_menu->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        groupBox_21->setTitle(QCoreApplication::translate("MainWindow", "ajouter un consultant", nullptr));
        label_79->setText(QCoreApplication::translate("MainWindow", "id du consultant: ", nullptr));
        label_80->setText(QCoreApplication::translate("MainWindow", "donner le nom du consultant:", nullptr));
        label_81->setText(QCoreApplication::translate("MainWindow", "prenom:", nullptr));
        label_82->setText(QCoreApplication::translate("MainWindow", "numero de telephone :", nullptr));
        QJOUTERCONSULTQNTBUTTON->setText(QCoreApplication::translate("MainWindow", "ajouter ", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        label_83->setText(QCoreApplication::translate("MainWindow", "date", nullptr));
        gestion_reclamation->setTitle(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "ajouter r\303\251clammations", nullptr));
        priorite_reclamation->setItemText(0, QCoreApplication::translate("MainWindow", "haute", nullptr));
        priorite_reclamation->setItemText(1, QCoreApplication::translate("MainWindow", "moyenne", nullptr));
        priorite_reclamation->setItemText(2, QCoreApplication::translate("MainWindow", "basse", nullptr));

        label_12->setText(QCoreApplication::translate("MainWindow", "Priorit\303\251 :", nullptr));
        bt_ajouter_reclamation->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Date  :", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Id r\303\251clammation :", nullptr));
        id_reclamation->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        description_reclamation->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "r\303\251solution :", nullptr));
        bt_modifier_reclamation->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Etat :", nullptr));
        etat_reclamation->setItemText(0, QCoreApplication::translate("MainWindow", "Traiter", nullptr));
        etat_reclamation->setItemText(1, QCoreApplication::translate("MainWindow", "En cour", nullptr));
        etat_reclamation->setItemText(2, QCoreApplication::translate("MainWindow", "annuler", nullptr));

        label_19->setText(QCoreApplication::translate("MainWindow", "id client:", nullptr));
        label_pic_2->setText(QString());
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "r\303\251clammations", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Export to PDF", nullptr));
        bt_supprimier_reclamation->setText(QCoreApplication::translate("MainWindow", "Supprimer ", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "chatbot IA :", nullptr));
        lineEdit_envoyer_chatbot->setPlaceholderText(QCoreApplication::translate("MainWindow", "parler avec moi", nullptr));
        bt_generate->setText(QCoreApplication::translate("MainWindow", "generate", nullptr));
        chercher_text->setText(QString());
        label_21->setText(QCoreApplication::translate("MainWindow", "rechercher :", nullptr));
        bt_trier->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        comboBox_ordre->setItemText(0, QCoreApplication::translate("MainWindow", "ASC", nullptr));
        comboBox_ordre->setItemText(1, QCoreApplication::translate("MainWindow", "DESC", nullptr));

        comboBox_choix->setItemText(0, QCoreApplication::translate("MainWindow", "Selectionner choix", nullptr));
        comboBox_choix->setItemText(1, QCoreApplication::translate("MainWindow", "ID_RECLAMATION", nullptr));
        comboBox_choix->setItemText(2, QCoreApplication::translate("MainWindow", "DESCRIPTION", nullptr));
        comboBox_choix->setItemText(3, QCoreApplication::translate("MainWindow", "RESOLUTION", nullptr));
        comboBox_choix->setItemText(4, QCoreApplication::translate("MainWindow", "ORDRE_PRIORITE", nullptr));
        comboBox_choix->setItemText(5, QCoreApplication::translate("MainWindow", "DATE_DE_RECLAMATION", nullptr));
        comboBox_choix->setItemText(6, QCoreApplication::translate("MainWindow", "ETAT", nullptr));

        reclamation_go_to_menu->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(Projects_2), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        label_stat->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Stat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
