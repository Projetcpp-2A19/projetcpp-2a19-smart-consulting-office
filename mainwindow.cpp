#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projet.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QDialog>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPainter>
#include <QStandardPaths>
#include <QMenu>
#include <QInputDialog>
#include <QDate>
#include <QPen>
#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QSqlQuery>
#include <QColor>
#include <QFont>
#include <QLinearGradient>
#include <QSoundEffect>
#include <QMessageBox>


#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QTableWidget>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDateTime>
#include <QThread>
#include <QRandomGenerator>
#include "consultant.h"
#include <QDebug>
#include "arduino.h"


//gston employe



#include "employe.h"

//pdf icludes
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QTextDocument>
#include <QMessageBox>
#include <QDateTime>

#include <QThread>
#include <QSystemTrayIcon>


#include <QDialog>
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>

#include <QTimer>


#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>
#include <QRandomGenerator>

Employe employe;


//gestion client

#include "client.h"
#include <QComboBox>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QAbstractItemModel>
#include <QMessageBox>
#include <QComboBox>
#include <QVBoxLayout>
#include "smtpclient.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QProcess>
#include <QDir>
#include <QDateTime>
#include <QChart>
#include <QPieSeries>
#include <QChartView>
#include<QtDebug>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    currentlySelectedRow(-1),
     m_currentClientId(-1)   // Pas de client sélectionné
    , m_editMode(false),
    ui(new Ui::MainWindow),
    employeModel(new QSqlQueryModel(this)),
    clientModel(new QSqlQueryModel(this)),
    trackingModel(new QSqlQueryModel(this)),
    chartView(nullptr),
    ganttScene(nullptr),
    temperatureTimer(new QTimer(this)),
    currentThreshold(25.0),
    currentProjectId(-1)// Default threshold

{
    ui->setupUi(this);

    //navigation
    ui->gestion_projet->hide();
    ui->menu->hide();
    ui->gestion_employe->show();
    ui->stackedWidget_4->setCurrentIndex(1);
    ui->gestion_client->hide();
    ui->gestion_consultant->hide();
    temperatureTimer = new QTimer(this);
    connect(temperatureTimer, &QTimer::timeout, this, &MainWindow::updateTemperature);

    // Initialize threshold display
    ui->thresholdSpinBox->setValue(currentThreshold);
    initializeGanttScene();
    this->setWindowTitle("Project Management System");

    ganttScene = new QGraphicsScene(this);
    ui->ganttGraphicsView_2->setScene(ganttScene);
    ui->ganttGraphicsView_2->setRenderHint(QPainter::Antialiasing);

    // Make absolutely sure it's visible
    ui->ganttGraphicsView_2->setBackgroundBrush(Qt::white);
    ui->ganttGraphicsView_2->setStyleSheet("border: 1px solid #ccc;");


    setupCharts();
    updateGanttChart();

    setupTrackingTable();
    // Add Export button
    connect(ui->exportButton, SIGNAL(clicked()), this, SLOT(on_exportButton_clicked()), Qt::UniqueConnection);

    // Add chart button
    QPushButton *chartBtn = new QPushButton("Show Budget Chart", this);
    ui->verticalLayout->addWidget(chartBtn);

    connect(chartBtn, &QPushButton::clicked, this, [this]() {
        QDialog chartDialog(this);
        chartDialog.setWindowTitle("Project Budgets");
        chartDialog.resize(850, 600);

        QVBoxLayout *mainLayout = new QVBoxLayout(&chartDialog);

        // Add the chart
        Projet p;
        if (QChartView *chartView = p.getColoredBudgetChart()) {
            mainLayout->addWidget(chartView);
        } else {
            mainLayout->addWidget(new QLabel("No project data available"));
        }

        // Add color legend
        QHBoxLayout *legendLayout = new QHBoxLayout();
        auto addLegendItem = [legendLayout](const QString &color, const QString &text) {
            QLabel *colorLabel = new QLabel();
            colorLabel->setFixedSize(20, 20);
            colorLabel->setStyleSheet(QString("background-color: %1; border: 1px solid #999").arg(color));
            legendLayout->addWidget(colorLabel);
            legendLayout->addWidget(new QLabel(text));
            legendLayout->addSpacing(15);
        };

        addLegendItem("#e74c3c", "Low (< $5k)");
        addLegendItem("#f39c12", "Medium ($5k-$20k)");
        addLegendItem("#2ecc71", "High (≥ $20k)");

        mainLayout->addLayout(legendLayout);
        chartDialog.exec();
    });

    // Setup validators
    ui->budgetLineEdit->setValidator(new QDoubleValidator(0, 999999, 2, this));

    // Load initial data
    loadEmployes();
    loadClients();
    loadData();

    // Setup connections
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()), Qt::UniqueConnection);
    connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tableView_clicked(QModelIndex)), Qt::UniqueConnection);
    connect(ui->modifyButton, SIGNAL(clicked()), this, SLOT(on_modifyButton_clicked()), Qt::UniqueConnection);
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(on_deleteButton_clicked()), Qt::UniqueConnection);
    connect(ui->searchLineEdit, &QLineEdit::textChanged,
            this, &MainWindow::on_searchLineEdit_textChanged);

    ui->sortComboBox->addItem("Default Order", 0);
    ui->sortComboBox->addItem("Priority: Low to High", 1);
    ui->sortComboBox->addItem("Priority: High to Low", 2);
    connect(ui->sortComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_sortComboBox_currentIndexChanged);

    // Initial load
    updateProjectView();
    updateTrackingView();
    updateGanttChart();






    //gestion employe


    ui->tableViewEmploye_4->setModel(employe.afficher());
    initializeSpecialityComboBox();
    displaySpecialiteStats();
    ui->lineEdit_password_4->setEchoMode(QLineEdit::Password);

    //Arduino=====INPUT + OUTPUT============================================
  /*  Atimer = new QTimer(this);
    connect(Atimer, &QTimer::timeout, this, [this]()
            {
                if (A.isConnected())
                {
                    Atimer->stop();
                    return;
                }
                switch (A.connect_arduino())
                {
                case 0:
                    qDebug() << "Arduino connected on port:" << A.getarduino_port_name();
                    Atimer->stop();

                    connect(A.getserial(), &QSerialPort::readyRead, this, [this]() {
                        QByteArray data = A.read_from_arduino();
                        QString message = QString::fromUtf8(data).trimmed();

                        if (message.startsWith("UID:")) {
                            QString cardUID = message.mid(4);
                            qDebug() << "Scanned RFID UID:" << cardUID;

                            QSqlQuery query;
                            query.prepare("SELECT ID_EMPLOYE FROM EMPLOYE WHERE CARD_UID = :uid");
                            query.bindValue(":uid", cardUID);

                            if (query.exec() && query.next()) {
                                qDebug() << "Access granted for employee ID:" << query.value(0).toString();
                                A.write_to_arduino("ACCESS_GRANTED\n");
                            } else {
                                qDebug() << "Access denied - UID not found";
                                A.write_to_arduino("ACCESS_DENIED\n");
                            }
                        }
                    });

                    break;
                case 1:
                    qDebug() << "Arduino available but not connected to:" << A.getarduino_port_name();
                    break;
                case -1:
                    qDebug() << "Arduino not available, retrying...";
                    break;
                }
            });
    Atimer->start(100);
    Atimer->setInterval(3000);*/
    //=====================================


    //********  gestion client

    ui->tableViewClients->setAlternatingRowColors(true);
    ui->tableViewClients->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableViewClients->setStyleSheet(
        "QTableView {"
        "    background-color: #ffffff;"
        "    alternate-background-color: #f2f2f2;"
        "    gridline-color: #ccc;"
        "    selection-background-color: #b7dff7;"
        "    selection-color: black;"
        "    font: 12pt 'Arial';"
        "    border: 1px solid #ccc;"
        "}"
        "QTableView::item {"
        "    padding: 5px;"
        "}"
        "QHeaderView::section {"
        "    background-color: #e6e6e6;"
        "    border: 1px solid #ccc;"
        "    padding: 4px;"
        "    font-weight: bold;"
        "    font: 12pt 'Arial';"
        "}"
        );

    // 1) Afficher l'onglet "Ajouter Client" en premier (index 0)
    ui->tabWidget->setCurrentIndex(0);

    // 2) Ajouter des valeurs au comboBox
    ui->comboBox_typeClient->addItem("Particulier");
    ui->comboBox_typeClient->addItem("Entreprise");

    // 3) Charger la liste des clients au démarrage (optionnel)
    //    pour la vue "Afficher Client" (index 1)
    Client client;
    QSqlQueryModel* model = client.afficher();
    ui->tableViewClients->setModel(model);
    ui->tableViewClients->setColumnHidden(0, true);

    ui->tableViewClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewClients->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableViewClients->setEditTriggers(QAbstractItemView::NoEditTriggers);
    /////////////:arduino
    ///
   /* serialbuffer="";
    QString portName;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.portName() == "COM9") {
            portName = info.portName();
            break;
        }
    }

    if (portName.isEmpty()) {
        qDebug() << "COM9 not found.";
    }
    serialPort = new QSerialPort(portName);
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readarduino);
    // Open the serial port
    if (!serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Failed to open the serial port.";
        delete serialPort;

    }*/




    // gestion consultant

    // Créer la table PROJET si elle n'existe pas
    QSqlQuery createTableQuery;
    createTableQuery.exec("CREATE TABLE PROJET ("
                          "ID_PROJET NUMBER PRIMARY KEY,"
                          "TEMPERATURE NUMBER(5,2) DEFAULT 20.0"
                          ")");

    // Insérer une valeur par défaut si la table est vide
    QSqlQuery checkEmptyQuery;
    checkEmptyQuery.exec("SELECT COUNT(*) FROM PROJET");
    if (checkEmptyQuery.next() && checkEmptyQuery.value(0).toInt() == 0) {
        QSqlQuery insertDefaultQuery;
        insertDefaultQuery.exec("INSERT INTO PROJET (ID_PROJET, TEMPERATURE) VALUES (58, 20.0)");
    }

    // Initialize Arduino connection
    if (arduino.connect_arduino() == 0) {
        qDebug() << "Arduino connecté avec succès";
        // Update UI to show Arduino status if you have status indicators
    } else {
        qDebug() << "Échec de connexion Arduino";
        // Update UI to show Arduino status if you have status indicators
    }

    // Configuration du LineEdit pour n'accepter que les nombres
    QDoubleValidator *validator = new QDoubleValidator(0, 100, 1, this);  // Min: 0, Max: 100, 1 décimale
    validator->setNotation(QDoubleValidator::StandardNotation);
    ui->temperatureLineEdit->setValidator(validator);

    // Charger la température actuelle
    QSqlQuery query;
    query.prepare("SELECT TEMPERATURE FROM PROJET WHERE ID_PROJET = 58");
    if (query.exec() && query.next()) {
        float temp = query.value(0).toFloat();
        ui->temperatureLineEdit->setText(QString::number(temp, 'f', 1));
    }

    // Initialisation du timer pour la vérification de la température
    temperatureTimer = new QTimer(this);
    connect(temperatureTimer, &QTimer::timeout, this, &MainWindow::checkTemperature);
    temperatureTimer->start(5000);
    QTimer::singleShot(0, this, &MainWindow::checkTemperature);

    initializeConsultantTableModel();

    // Configuration de la recherche
    connect(ui->chercherconsultqntlineedit, &QLineEdit::textChanged,
            this, &MainWindow::on_searchConsultantByTyping);

    // Création du bouton historique
    QPushButton* historiqueButton = new QPushButton("Historique des suppressions", this);
    historiqueButton->setObjectName("historiqueButton");
    historiqueButton->setGeometry(QRect(600, 500, 200, 30)); // Ajustez la position selon votre interface
    historiqueButton->setStyleSheet("QPushButton {"
                                    "background-color: #3498db;"
                                    "color: white;"
                                    "border-radius: 5px;"
                                    "padding: 8px 15px;"
                                    "font-size: 14px;"
                                    "}"
                                    "QPushButton:hover {"
                                    "background-color: #2980b9;"
                                    "}"
                                    "QPushButton:pressed {"
                                    "background-color: #1c5985;"
                                    "}");
    connect(historiqueButton, &QPushButton::clicked, this, &MainWindow::on_historiqueButton_clicked);

    ui->staticWidget->hide();
    ui->hidepushbutton->hide();



}

MainWindow::~MainWindow()
{
    delete ui;
    delete employeModel;
    delete clientModel;
    delete trackingModel;
    delete trackingTableView;
}

void MainWindow::loadData() {
    Projet p;
    QSqlQueryModel *model = p.afficher();
    updateTrackingView();
    ui->tableView->setModel(model);

    // Set column headers - ONLY 10 COLUMNS (0-9)
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, tr("Start Date"));
    model->setHeaderData(4, Qt::Horizontal, tr("End Date"));
    model->setHeaderData(5, Qt::Horizontal, tr("Status"));
    model->setHeaderData(6, Qt::Horizontal, tr("Priority"));  // ONLY PRIORITY HERE
    model->setHeaderData(7, Qt::Horizontal, tr("Budget"));
    model->setHeaderData(8, Qt::Horizontal, tr("Employee ID"));
    model->setHeaderData(9, Qt::Horizontal, tr("Client ID"));
    // NO HEADER FOR PROGRESS IN MAIN TABLE

    ui->tableView->resizeColumnsToContents();
}

void MainWindow::loadEmployes() {
    employeModel->clear();
    employeModel->setQuery("SELECT ID_EMPLOYE, NOM, PRENOM FROM EMPLOYE ORDER BY NOM, PRENOM");
    ui->employeComboBox->setModel(employeModel);
    ui->employeComboBox->setModelColumn(1); // Show name
}

void MainWindow::loadClients() {
    clientModel->clear();
    clientModel->setQuery("SELECT ID_CLIENT, NOM FROM CLIENT ORDER BY NOM");
    ui->clientComboBox->setModel(clientModel);
    ui->clientComboBox->setModelColumn(1); // Show name
}


void MainWindow::on_addButton_clicked() {
    ui->addButton->setEnabled(false);

    // Validate inputs
    QString nom = ui->nomLineEdit->text().trimmed();
    if(nom.isEmpty()) {
        QMessageBox::warning(this, "Error", "Project name cannot be empty");
        ui->addButton->setEnabled(true);
        return;
    }

    Projet tempProjet; // Temporary object just for name checking
    if(tempProjet.nomExists(nom)) {
        QMessageBox::warning(this, "Error", "Project name already exists");
        ui->addButton->setEnabled(true);
        return;
    }

    QString description = ui->descLineEdit->toPlainText().trimmed();
    if(description.isEmpty()) {
        QMessageBox::warning(this, "Error", "Description cannot be empty");
        ui->addButton->setEnabled(true);
        return;
    }

    bool budgetOk;
    double budget = ui->budgetLineEdit->text().toDouble(&budgetOk);
    if(!budgetOk || budget <= 0) {
        QMessageBox::warning(this, "Error", "Invalid budget amount");
        ui->addButton->setEnabled(true);
        return;
    }

    QDate date_debut = ui->dateDebutEdit->date();
    QDate date_fin = ui->dateFinEdit->date();
    if(date_fin < date_debut) {
        QMessageBox::warning(this, "Error", "End date cannot be before start date");
        ui->addButton->setEnabled(true);
        return;
    }

    QString status = ui->statusComboBox->currentText();
    int priorite = getPriorityValue(ui->prioriteComboBox->currentText());

    // Get selected employee ID
    int employeeIndex = ui->employeComboBox->currentIndex();
    int id_employe = employeModel->data(employeModel->index(employeeIndex, 0)).toInt();

    // Get selected client ID
    int clientIndex = ui->clientComboBox->currentIndex();
    int id_client = clientModel->data(clientModel->index(clientIndex, 0)).toInt();

    Projet p(nom, description, date_debut, date_fin, status, priorite, budget, id_employe, id_client);

    if(p.ajouter()) {
        QMessageBox::information(this, "Success", "Project added successfully");
        loadData();
        ui->nomLineEdit->clear();
        ui->descLineEdit->clear();
        ui->budgetLineEdit->clear();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add project");
    }

    ui->addButton->setEnabled(true);
     updateGanttChart();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index) {
    if(!index.isValid()) return;

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
    int id = model->data(model->index(index.row(), 0)).toInt();
    QString nom = model->data(model->index(index.row(), 1)).toString();
    QString description = model->data(model->index(index.row(), 2)).toString();
    QDate date_debut = QDate::fromString(model->data(model->index(index.row(), 3)).toString(), "yyyy-MM-dd");
    QDate date_fin = QDate::fromString(model->data(model->index(index.row(), 4)).toString(), "yyyy-MM-dd");
    QString status = model->data(model->index(index.row(), 5)).toString();
    int priorite = model->data(model->index(index.row(), 6)).toInt();
    double budget = model->data(model->index(index.row(), 7)).toDouble();
    int id_employe = model->data(model->index(index.row(), 8)).toInt();
    int id_client = model->data(model->index(index.row(), 9)).toInt();

    ui->nomLineEdit->setText(nom);
    ui->descLineEdit->setPlainText(description);
    ui->dateDebutEdit->setDate(date_debut);
    ui->dateFinEdit->setDate(date_fin);
    ui->statusComboBox->setCurrentText(status);
    ui->prioriteComboBox->setCurrentText(getPriorityText(priorite));
    ui->budgetLineEdit->setText(QString::number(budget));

    // Set employee combobox
    for(int i = 0; i < employeModel->rowCount(); ++i) {
        if(employeModel->data(employeModel->index(i, 0)).toInt() == id_employe) {
            ui->employeComboBox->setCurrentIndex(i);
            break;
        }
    }

    // Set client combobox
    for(int i = 0; i < clientModel->rowCount(); ++i) {
        if(clientModel->data(clientModel->index(i, 0)).toInt() == id_client) {
            ui->clientComboBox->setCurrentIndex(i);
            break;
        }
    }

    ui->nomLineEdit->setProperty("originalId", id);
}

void MainWindow::on_modifyButton_clicked() {
    // Get the original project ID
    int id = ui->nomLineEdit->property("originalId").toInt();
    if(id <= 0) {
        QMessageBox::warning(this, "Error", "No project selected");
        return;
    }

    // Validate project name
    QString nom = ui->nomLineEdit->text().trimmed();
    if(nom.isEmpty()) {
        QMessageBox::warning(this, "Error", "Project name cannot be empty");
        return;
    }

    // Validate description
    QString description = ui->descLineEdit->toPlainText().trimmed();
    if(description.isEmpty()) {
        QMessageBox::warning(this, "Error", "Description cannot be empty");
        return;
    }

    // Validate budget
    bool budgetOk;
    double budget = ui->budgetLineEdit->text().toDouble(&budgetOk);
    if(!budgetOk || budget <= 0) {
        QMessageBox::warning(this, "Error", "Invalid budget amount");
        return;
    }

    // Validate dates
    QDate date_debut = ui->dateDebutEdit->date();
    QDate date_fin = ui->dateFinEdit->date();
    if(date_fin < date_debut) {
        QMessageBox::warning(this, "Error", "End date cannot be before start date");
        return;
    }

    // Get other values
    QString status = ui->statusComboBox->currentText();
    int priorite = getPriorityValue(ui->prioriteComboBox->currentText());

    // Get selected employee ID
    int employeeIndex = ui->employeComboBox->currentIndex();
    int id_employe = employeModel->data(employeModel->index(employeeIndex, 0)).toInt();

    // Get selected client ID
    int clientIndex = ui->clientComboBox->currentIndex();
    int id_client = clientModel->data(clientModel->index(clientIndex, 0)).toInt();

    // Create Project object
    Projet p(nom, description, date_debut, date_fin, status, priorite, budget, id_employe, id_client);

    // Attempt modification
    if(p.modifier(id)) {
        QMessageBox::information(this, "Success", "Project updated successfully");
        loadData();  // Refresh the table view
    } else {
        QMessageBox::critical(this, "Error", "Failed to update project");
    }
     updateGanttChart();
}

void MainWindow::on_deleteButton_clicked() {
    int id = ui->nomLineEdit->property("originalId").toInt();
    if(id <= 0) {
        QMessageBox::warning(this, "Error", "No project selected");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Delete", "Are you sure you want to delete this project?",
                                  QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes) {
        Projet p;
        if(p.supprimer(id)) {
            QMessageBox::information(this, "Success", "Project deleted successfully");
            loadData();
            // Clear form
            ui->nomLineEdit->clear();
            ui->descLineEdit->clear();
            ui->budgetLineEdit->clear();
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete project");
        }
    }
     updateGanttChart();
}

QStringList MainWindow::getPriorityOptions()
{
    return {"Low", "Medium", "High"};
}


int MainWindow::getPriorityValue(const QString &priorityText)
{
    if (priorityText == "Low") return 1;
    if (priorityText == "Medium") return 2;
    if (priorityText == "High") return 3;
    return 1; // Default to Low
}



QString MainWindow::getPriorityText(int priorityValue)
{
    switch(priorityValue) {
    case 1: return "Low";
    case 2: return "Medium";
    case 3: return "High";
    default: return "Low";
    }
}

void MainWindow::updateProjectView() {
    QString searchText = ui->searchLineEdit->text().trimmed();
    int sortOption = ui->sortComboBox->currentData().toInt();

    Projet p;
    QSqlQueryModel *model = p.rechercherEtTrier(searchText, sortOption);

    if(model) {
        ui->tableView->setModel(model);

        // Set headers
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Name"));
        model->setHeaderData(2, Qt::Horizontal, tr("Description"));
        model->setHeaderData(3, Qt::Horizontal, tr("Start Date"));
        model->setHeaderData(4, Qt::Horizontal, tr("End Date"));
        model->setHeaderData(5, Qt::Horizontal, tr("Status"));
        model->setHeaderData(6, Qt::Horizontal, tr("Priority"));
        model->setHeaderData(7, Qt::Horizontal, tr("Budget"));
        model->setHeaderData(8, Qt::Horizontal, tr("Employee ID"));
        model->setHeaderData(9, Qt::Horizontal, tr("Client ID"));
        model->setHeaderData(6, Qt::Horizontal, tr("Progress"));

        ui->tableView->resizeColumnsToContents();
    }
}

// Slots
void MainWindow::on_searchLineEdit_textChanged(const QString &) {
    updateProjectView();

}

void MainWindow::on_sortComboBox_currentIndexChanged(int) {
    updateProjectView();
}

void MainWindow::on_exportButton_clicked()
{
    // 1. Get save location
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Export Table to PDF",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/projects.pdf",
        "PDF Files (*.pdf)"
        );

    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf";
    }

    // 2. Setup PDF printer
    QPrinter printer(QPrinter::ScreenResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(7, 7, 7, 7), QPageLayout::Millimeter);

    // 3. Start painting
    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Error", "Failed to create PDF file");
        return;
    }

    // 4. Get table data
    QAbstractItemModel *model = ui->tableView->model();
    if (!model || model->rowCount() == 0) {
        painter.end();
        QMessageBox::warning(this, "Error", "No data to export");
        return;
    }

    // 5. Setup compact table parameters
    const int titleHeight = 20; // Added for title
    const int rowHeight = 18;
    const int colSpacing = 8;
    const int colCount = model->columnCount();
    const int rowCount = model->rowCount();

    // Calculate automatic column widths
    QVector<int> colWidths(colCount);
    painter.setFont(QFont("Arial", 9));

    for (int col = 0; col < colCount; ++col) {
        int width = painter.fontMetrics().horizontalAdvance(
                        model->headerData(col, Qt::Horizontal).toString()) + 7;

        for (int row = 0; row < qMin(20, rowCount); ++row) {
            width = qMax(width, painter.fontMetrics().horizontalAdvance(
                                    model->data(model->index(row, col)).toString().left(30)) + 7);
        }

        colWidths[col] = qMin(width, 125);
    }

    // 6. Draw title (NEW CODE)
    painter.setFont(QFont("Arial", 10, QFont::Bold)); // Larger bold font for title
    painter.drawText(0, 0, printer.width(), titleHeight,
                     Qt::AlignCenter, "Projects List");

    painter.setFont(QFont("Arial", 7));

    // 7. Draw table header
    int xPos = 7;
    int yPos = titleHeight + 20; // Adjusted for title
    painter.setFont(QFont("Arial", 7, QFont::Bold));

    for (int col = 0; col < colCount; ++col) {
        painter.drawText(xPos, yPos, colWidths[col], rowHeight,
                         Qt::AlignLeft,
                         model->headerData(col, Qt::Horizontal).toString());
        xPos += colWidths[col] + colSpacing;
    }
    yPos += rowHeight;

    // 8. Draw table data
    painter.setFont(QFont("Arial", 8));
    for (int row = 0; row < rowCount; ++row) {
        xPos = 5;

        // New page if needed
        if (yPos + rowHeight > printer.pageLayout().paintRectPixels(printer.resolution()).height() - 10) {
            printer.newPage();
            yPos = 5;

            // Redraw title on new page (NEW CODE)
            painter.setFont(QFont("Arial", 10, QFont::Bold));
            painter.drawText(0, 0, printer.width(), titleHeight,
                             Qt::AlignCenter, "Projects List (continued)");
            painter.setFont(QFont("Arial", 7));
        }

        for (int col = 0; col < colCount; ++col) {
            QString text = model->data(model->index(row, col)).toString();
            painter.drawText(xPos, yPos, colWidths[col], rowHeight,
                             Qt::AlignLeft,
                             text.left(30));
            xPos += colWidths[col] + colSpacing;
        }
        yPos += rowHeight;
    }

    // 9. Finish
    painter.end();
    QMessageBox::information(this, "Success",
                             QString("Table exported to:\n%1").arg(fileName));
}


void MainWindow::setupTrackingTable()
{
    //Création de la table
    trackingTableView = new QTableView(this);
    trackingTableView->setObjectName("trackingTableView");
    trackingTableView->setModel(trackingModel);
    //Ajout dans la mise en page (layout)
    QVBoxLayout *trackingLayout = findChild<QVBoxLayout*>("verticalLayoutTracking");
    if (trackingLayout) {
        trackingLayout->addWidget(trackingTableView);
    } else {
        ui->verticalLayout->addWidget(trackingTableView);
        qWarning() << "Tracking layout not found, using main layout as fallback";
    }
    //Personnalisation de la table
    trackingTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    trackingTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    trackingTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    trackingTableView->setAlternatingRowColors(true);
    trackingTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    //Connexion au menu contextuel
    connect(trackingTableView, &QTableView::customContextMenuRequested,
            this, &MainWindow::showTrackingContextMenu);

    trackingTableView->setItemDelegate(new TrackingDelegate(this));
    updateTrackingView();
    updateGanttChart();
}

void MainWindow::updateTrackingView()
{
    QSqlQuery query;
    query.prepare("SELECT ID_PROJET, NOM_PROJET, "
                  "TO_CHAR(DATE_DEBUT, 'YYYY-MM-DD'), "
                  "TO_CHAR(DATE_FIN, 'YYYY-MM-DD'), "
                  "STATUS, PRIORITE, PROGRESS "
                  "FROM PROJET "
                  "WHERE STATUS NOT LIKE '%Completed%' "
                  "ORDER BY PRIORITE DESC, DATE_FIN");
//Définit les noms de colonnes
    if(query.exec()) {
        trackingModel->setQuery(query);

        trackingModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
        trackingModel->setHeaderData(1, Qt::Horizontal, tr("Project Name"));
        trackingModel->setHeaderData(2, Qt::Horizontal, tr("Start Date"));
        trackingModel->setHeaderData(3, Qt::Horizontal, tr("End Date"));
        trackingModel->setHeaderData(4, Qt::Horizontal, tr("Status"));
        trackingModel->setHeaderData(5, Qt::Horizontal, tr("Priority"));
        trackingModel->setHeaderData(6, Qt::Horizontal, tr("Progress"));
// Personnalise l’apparence des colonnes
        trackingTableView->setColumnHidden(0, true);
        trackingTableView->setColumnWidth(1, 250);
        trackingTableView->setColumnWidth(2, 100);
        trackingTableView->setColumnWidth(3, 100);
        trackingTableView->setColumnWidth(4, 120);
        trackingTableView->setColumnWidth(5, 80);
        trackingTableView->setColumnWidth(6, 100);
//Post-traitement ligne par ligne
        QDate today = QDate::currentDate();
        for(int row = 0; row < trackingModel->rowCount(); ++row) {
            int priority = trackingModel->data(trackingModel->index(row, 5)).toInt();
            trackingModel->setData(trackingModel->index(row, 5), getPriorityText(priority));

            int progress = trackingModel->data(trackingModel->index(row, 6)).toInt();
            trackingModel->setData(trackingModel->index(row, 6), QString("%1%").arg(progress));

            QDate endDate = QDate::fromString(trackingModel->data(trackingModel->index(row, 3)).toString(), "yyyy-MM-dd");
            if(endDate < today) {
                QString status = "Delayed";
                trackingModel->setData(trackingModel->index(row, 4), status);
                trackingModel->setData(trackingModel->index(row, 4), QColor(Qt::red), Qt::ForegroundRole);
            }
        }

        updateProgressChart();
        updateStatusChart();
        updateGanttChart();
    } else {
        qDebug() << "Tracking view query error:" << query.lastError().text();
    }
}


void MainWindow::showTrackingContextMenu(const QPoint &pos)
{
    //Vérification de la validité du clic
    QModelIndex index = trackingTableView->indexAt(pos);
    if(!index.isValid()) return;
    // Récupération des informations du projet
    currentlySelectedRow = index.row();
    QString status = trackingModel->data(trackingModel->index(currentlySelectedRow, 4)).toString();
    int currentProgress = trackingModel->data(trackingModel->index(currentlySelectedRow, 6)).toInt();
    int projectId = trackingModel->data(trackingModel->index(currentlySelectedRow, 0)).toInt();
    //Création du menu contextuel
    QMenu menu(this);

    if(status.contains("In Progress", Qt::CaseInsensitive)) {
        //Création du widget
        QWidget *progressWidget = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(progressWidget);
    //Ajout d’un label, slider et valeur
        QLabel *progressLabel = new QLabel("Set Progress:");
        progressLabel->setAlignment(Qt::AlignCenter);

        QSlider *progressSlider = new QSlider(Qt::Horizontal);
        progressSlider->setRange(0, 100);
        progressSlider->setValue(currentProgress);

        QLabel *valueLabel = new QLabel(QString("%1%").arg(currentProgress));
        valueLabel->setAlignment(Qt::AlignCenter);
//Connexion du slider à la mise à jour de la base
        connect(progressSlider, &QSlider::valueChanged, [valueLabel, this, projectId](int value) {
            valueLabel->setText(QString("%1%").arg(value));

            QSqlQuery query;
            query.prepare("UPDATE PROJET SET PROGRESS = ? WHERE ID_PROJET = ?");
            query.addBindValue(value);
            query.addBindValue(projectId);
            if(!query.exec()) {
                qDebug() << "Failed to update progress:" << query.lastError();
            }

            updateTrackingView();
            updateGanttChart();
        });

        layout->addWidget(progressLabel);
        layout->addWidget(progressSlider);
        layout->addWidget(valueLabel);
        layout->setContentsMargins(10, 5, 10, 5);
//Ajout du widget dans le menu
        QWidgetAction *progressAction = new QWidgetAction(&menu);
        progressAction->setDefaultWidget(progressWidget);
        menu.addAction(progressAction);
        menu.addSeparator();
    }

    QAction *completeAction = menu.addAction("Mark as Completed");
    QAction *priorityAction = menu.addAction("Change Priority");
    QAction *statusAction = menu.addAction("Change Status");  // Replaced View Details with Change Status

    QAction *selected = menu.exec(trackingTableView->viewport()->mapToGlobal(pos));

    if(selected == completeAction) {
        markProjectCompleted();
    } else if(selected == priorityAction) {
        changeProjectPriority();
    } else if(selected == statusAction) {
        // Get current status for reference
        QString currentStatus = trackingModel->data(trackingModel->index(currentlySelectedRow, 4)).toString();

        // Show status selection dialog
        bool ok;
        QString newStatus = QInputDialog::getItem(
            this,
            "Change Status",
            "Select new status:",
            QStringList() << "Not Started" << "In Progress" << "Completed" << "On Hold",
            currentStatus == "Not Started" ? 0 :
                currentStatus == "In Progress" ? 1 :
                currentStatus == "Completed" ? 2 : 3,
            false,
            &ok
            );

        if(ok && !newStatus.isEmpty()) {
            changeProjectStatus(newStatus);
        }
    }
}

void MainWindow::changeProjectStatus(const QString &newStatus)
{
    if (currentlySelectedRow < 0) return;

    int id = trackingModel->data(trackingModel->index(currentlySelectedRow, 0)).toInt();

    QSqlQuery query;
    query.prepare("UPDATE PROJET SET STATUS = :status WHERE ID_PROJET = :id");
    query.bindValue(":status", newStatus);
    query.bindValue(":id", id);

    if(query.exec()) {
        QMessageBox::information(this, "Success", "Project status updated to: " + newStatus);
        updateTrackingView();
        loadData();
        currentlySelectedRow = -1;
    } else {
        QMessageBox::critical(this, "Error",
                              QString("Failed to update status:\n%1")
                                  .arg(query.lastError().text()));
    }
}
void MainWindow::markProjectCompleted()
{
    if (currentlySelectedRow < 0) return;

    int id = trackingModel->data(trackingModel->index(currentlySelectedRow, 0)).toInt();

    QSqlQuery query;
    query.prepare("UPDATE PROJET SET STATUS = 'Completed' WHERE ID_PROJET = ?");
    query.addBindValue(id);

    if(query.exec()) {
        // Play success sound
        QSoundEffect *effect = new QSoundEffect(this);
        effect->setSource(QUrl("qrc:/sounds/success.wav")); // Using resource file
        effect->setVolume(0.5f);
        effect->play();

        QMessageBox::information(this, "Success", "Project marked as completed");
        updateTrackingView();
        loadData();
        currentlySelectedRow = -1;
    } else {
        QMessageBox::critical(this, "Error",
                              QString("Failed to update status:\n%1")
                                  .arg(query.lastError().text()));
    }
}

void MainWindow::changeProjectPriority()
{
    if (currentlySelectedRow < 0) return;

    int id = trackingModel->data(trackingModel->index(currentlySelectedRow, 0)).toInt();
    int currentPriority = trackingModel->data(trackingModel->index(currentlySelectedRow, 5)).toInt();
    QString currentPriorityText = getPriorityText(currentPriority);

    bool ok;
    QString newPriorityText = QInputDialog::getItem(
        this,
        "Change Priority",
        "Select new priority:",
        getPriorityOptions(),
        currentPriorityText == "Low" ? 0 :
            currentPriorityText == "Medium" ? 1 : 2,
        false,
        &ok
        );

    if(!ok || newPriorityText.isEmpty()) return;

    int newPriority = getPriorityValue(newPriorityText);

    QSqlQuery query;
    query.prepare("UPDATE PROJET SET PRIORITE = :priority WHERE ID_PROJET = :id");
    query.bindValue(":priority", newPriority);
    query.bindValue(":id", id);

    if(query.exec()) {
        QMessageBox::information(this, "Success", "Project priority updated");
        loadData();
        updateTrackingView();
        updateGanttChart();
        currentlySelectedRow = -1;
    } else {
        QMessageBox::critical(this, "Error",
                              QString("Failed to update priority:\n%1")
                                  .arg(query.lastError().text()));
    }
}


void MainWindow::setupCharts()
{
    // Find the existing vertical layout (created in Qt Designer)
    QVBoxLayout *chartsLayout = findChild<QVBoxLayout*>("verticalLayoutCharts");
    if (!chartsLayout) {
        qWarning() << "Charts layout not found!";
        return;
    }

    // Clear any existing widgets (if needed)
    QLayoutItem* item;
    while ((item = chartsLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Create progress chart (top)
    QChart *progressChart = new QChart();
    progressChart->setTitle("Project Progress");
    progressChart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *progressChartView = new QChartView(progressChart);
    progressChartView->setRenderHint(QPainter::Antialiasing);
    progressChartView->setObjectName("progressChartView");
    chartsLayout->addWidget(progressChartView);

    // Create status chart (bottom)
    QChart *statusChart = new QChart();
    statusChart->setTitle("Project Status");
    statusChart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *statusChartView = new QChartView(statusChart);
    statusChartView->setRenderHint(QPainter::Antialiasing);
    statusChartView->setObjectName("statusChartView");
    chartsLayout->addWidget(statusChartView);

    // Set stretch factors for equal sizing
    chartsLayout->setStretch(0, 1); // Progress chart
    chartsLayout->setStretch(1, 1); // Status chart

    // Initial update
    updateProgressChart();
    updateStatusChart();
}


void MainWindow::updateProgressChart()
{
    QSqlQuery query;
    query.prepare("SELECT "
                  "CASE "
                  "  WHEN PROGRESS < 25 THEN '0-24%' "
                  "  WHEN PROGRESS < 50 THEN '25-49%' "
                  "  WHEN PROGRESS < 75 THEN '50-74%' "
                  "  ELSE '75-100%' "
                  "END AS progress_range, "
                  "COUNT(*) FROM PROJET "
                  "GROUP BY "
                  "CASE "
                  "  WHEN PROGRESS < 25 THEN '0-24%' "
                  "  WHEN PROGRESS < 50 THEN '25-49%' "
                  "  WHEN PROGRESS < 75 THEN '50-74%' "
                  "  ELSE '75-100%' "
                  "END");

    if(query.exec()) {
        QPieSeries *series = new QPieSeries();
        QMap<QString, QColor> colorMap = {
            {"0-24%", QColor("#ff6b6b")}, // Red
            {"25-49%", QColor("#ffa502")}, // Orange
            {"50-74%", QColor("#feca57")}, // Yellow
            {"75-100%", QColor("#1dd1a1")} // Green
        };

        while(query.next()) {
            QString range = query.value(0).toString();
            int count = query.value(1).toInt();

            QPieSlice *slice = series->append(range, count);
            slice->setLabelVisible();
            slice->setLabel(QString("%1: %2").arg(range).arg(count));
            slice->setColor(colorMap.value(range));
        }

        QChartView *progressView = findChild<QChartView*>("progressChartView");
        if(progressView) {
            QChart *chart = progressView->chart();
            chart->removeAllSeries();
            chart->addSeries(series);
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignRight);
            chart->setTitle("Project Progress (" + QString::number(series->sum()) + " projects)");
        }
    } else {
        qDebug() << "Progress chart query error:" << query.lastError().text();
    }
}

void TrackingDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    if (index.column() == 6) { // Progress column
        QString progressText = index.data().toString();
        int progress = progressText.replace("%", "").toInt();

        QStyleOptionProgressBar progressBarOption;
        progressBarOption.rect = option.rect.adjusted(2, 2, -2, -2);
        progressBarOption.minimum = 0;
        progressBarOption.maximum = 100;
        progressBarOption.progress = progress;
        progressBarOption.text = progressText;
        progressBarOption.textVisible = true;

        // Color based on progress
        if (progress < 25) {
            progressBarOption.palette.setBrush(QPalette::Highlight, QColor("#ff6b6b"));
        } else if (progress < 50) {
            progressBarOption.palette.setBrush(QPalette::Highlight, QColor("#ffa502"));
        } else if (progress < 75) {
            progressBarOption.palette.setBrush(QPalette::Highlight, QColor("#feca57"));
        } else {
            progressBarOption.palette.setBrush(QPalette::Highlight, QColor("#1dd1a1"));
        }

        QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

void MainWindow::updateStatusChart()
{
    QSqlQuery query;
    query.prepare("SELECT STATUS, COUNT(*) FROM PROJET GROUP BY STATUS");

    if(query.exec()) {
        QBarSeries *series = new QBarSeries();
        QBarSet *set = new QBarSet("Projects");
        QStringList categories;

        while(query.next()) {
            QString status = query.value(0).toString();
            int count = query.value(1).toInt();

            *set << count;
            categories << status;

            if(status.contains("Complete", Qt::CaseInsensitive)) {
                set->setColor(QColor(50, 205, 50));
            } else if(status.contains("Delay", Qt::CaseInsensitive)) {
                set->setColor(QColor(220, 20, 60));
            } else {
                set->setColor(QColor(65, 105, 225));
            }
        }

        series->append(set);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Project Status (" + QString::number(set->sum()) + " projects)");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setLabelFormat("%d");
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        QChartView *statusView = findChild<QChartView*>("statusChartView");
        if(statusView) {
            statusView->setChart(chart);
        }
    } else {
        qDebug() << "Status chart query error:" << query.lastError().text();
    }
}

void MainWindow::initializeGanttScene()
{
    //Création d’une nouvelle scène graphique pour le Gantt
    ganttScene = new QGraphicsScene(this);
    ui->ganttGraphicsView_2->setScene(ganttScene);
    ui->ganttGraphicsView_2->setRenderHint(QPainter::Antialiasing);
    ui->ganttGraphicsView_2->setBackgroundBrush(QColor(245, 245, 245));
    ganttScene->setSceneRect(-300, 0, 2500, 800);
}

//Cette fonction met à jour dynamiquement le diagramme de Gantt, en affichant les projets et les dates
void MainWindow::updateGanttChart()
{
    if (!ganttScene) initializeGanttScene();
    ganttScene->clear();

    const int DAY_WIDTH = 30;  // Keep your spacing
    const int ROW_HEIGHT = 80; // Keep your row height
    const QDate TODAY = QDate::currentDate();

    // 1. Draw Timeline Headers (modified to show numbers only)
    drawMonthHeader(TODAY, DAY_WIDTH, 10);
    drawSimplifiedDayHeader(TODAY, DAY_WIDTH, 40); // New method replacing drawWeekHeader

    // 2. Draw Projects (keep your existing project drawing)
    int currentY = 80;
    QSqlQuery query("SELECT NOM_PROJET, DATE_DEBUT, DATE_FIN, PRIORITE FROM PROJET ORDER BY DATE_DEBUT");

    while (query.next()) {
        QString name = query.value(0).toString();
        QDate startDate = query.value(1).toDate();
        QDate endDate = query.value(2).toDate();
        int priority = query.value(3).toInt();

        int xPos = TODAY.daysTo(startDate) * DAY_WIDTH;
        int width = (startDate.daysTo(endDate) + 1) * DAY_WIDTH;

        drawProjectRow(xPos, currentY, width, name, startDate, endDate, priority);

        // Add separation line (the only new visual element)
        QGraphicsLineItem *line = new QGraphicsLineItem(
            -250, currentY + ROW_HEIGHT - 10,
            ganttScene->width(), currentY + ROW_HEIGHT - 10
            );
        line->setPen(QPen(QColor(220,220,220), 1));
        ganttScene->addItem(line);

        currentY += ROW_HEIGHT;
    }

    // 3. Keep your today marker if you want, or comment this out
    // drawTodayMarker(TODAY, DAY_WIDTH, currentY);

    adjustViewToContent(currentY);
}

void MainWindow::drawSimplifiedDayHeader(const QDate &today, int dayWidth, int yPos)
{
    QDate startDate = today.addDays(-14); // Show 2 weeks before today
    QDate endDate = today.addDays(45);    // Show ~6 weeks ahead

    QPen gridPen(QColor(230,230,230));

    for (QDate date = startDate; date <= endDate; date = date.addDays(1)) {
        int xPos = today.daysTo(date) * dayWidth;

        // Only show day number (no weekday names)
        if (date.day() % 5 == 0 || date == today || date.day() == 1) {
            QGraphicsTextItem *day = new QGraphicsTextItem(QString::number(date.day()));
            day->setPos(xPos - 5, yPos);

            // Highlight today
            if (date == today) {
                day->setDefaultTextColor(Qt::red);
                day->setFont(QFont("Arial", 9, QFont::Bold));

                // Optional: Add vertical line for today
                QGraphicsLineItem *todayLine = new QGraphicsLineItem(
                    xPos, yPos + 15, xPos, ganttScene->height()
                    );
                todayLine->setPen(QPen(Qt::red, 1, Qt::DashLine));
                ganttScene->addItem(todayLine);
            } else {
                day->setFont(QFont("Arial", 8));
            }
            ganttScene->addItem(day);
        }

        // Add light vertical grid lines
        QGraphicsLineItem *vLine = new QGraphicsLineItem(xPos, yPos + 15, xPos, ganttScene->height());
        vLine->setPen(gridPen);
        ganttScene->addItem(vLine);
    }
}

void MainWindow::drawMonthHeader(const QDate &today, int dayWidth, int yPos)
{
    QDate startDate = today.addMonths(-1);
    QDate endDate = today.addMonths(2);

    for (QDate date = startDate; date <= endDate; date = date.addMonths(1)) {
        int xPos = today.daysTo(date) * dayWidth;

        QGraphicsTextItem *month = new QGraphicsTextItem(date.toString("MMMM yyyy"));
        month->setPos(xPos, yPos);
        month->setFont(QFont("Arial", 10, QFont::Bold));
        ganttScene->addItem(month);
    }
}

void MainWindow::drawWeekHeader(const QDate &today, int dayWidth, int yPos)
{
    QDate startDate = today.addDays(-today.dayOfWeek() + 1); // Start of current week
    QDate endDate = startDate.addDays(28); // 4 weeks

    for (QDate date = startDate; date <= endDate; date = date.addDays(1)) {
        int xPos = today.daysTo(date) * dayWidth;

        if (date.dayOfWeek() == 1 || date == today) { // Monday or today
            QString dayText = date.toString("ddd d");
            if (date == today) dayText = "► " + dayText + " ◄";

            QGraphicsTextItem *day = new QGraphicsTextItem(dayText);
            day->setPos(xPos - 15, yPos);
            day->setDefaultTextColor(date == today ? Qt::red : Qt::black);
            day->setFont(QFont("Arial", 8, date == today ? QFont::Bold : QFont::Normal));
            ganttScene->addItem(day);
        }
    }
}

void MainWindow::drawProjectRow(int x, int y, int width,
                                const QString &name,
                                const QDate &startDate,
                                const QDate &endDate,
                                int priority)
{
    // 1. Make the bar more compact (reduced height from 20 to 15)
    QGraphicsRectItem *bar = new QGraphicsRectItem(x, y + 20, width, 15); // y+20 gives more space for name
    bar->setBrush(getPriorityColor(priority));
    bar->setPen(QPen(Qt::black, 1));
    ganttScene->addItem(bar);

    // 2. Project name with better positioning
    QGraphicsTextItem *nameLabel = new QGraphicsTextItem(name);
    nameLabel->setPos(-200, y);
    nameLabel->setFont(QFont("Arial", 9, QFont::Bold));
    ganttScene->addItem(nameLabel);

    // 3. Compact START/END markers (unchanged from your good version)
    QString startText = "START\n" + startDate.toString("MMM d");
    QGraphicsSimpleTextItem *startLabel = new QGraphicsSimpleTextItem(startText);
    startLabel->setFont(QFont("Arial", 8));
    startLabel->setPos(x - 30, y + 40);
    ganttScene->addItem(startLabel);

    if (!startDate.isNull() && !endDate.isNull() && startDate != endDate) {
        QString endText = "END\n" + endDate.toString("MMM d");
        QGraphicsSimpleTextItem *endLabel = new QGraphicsSimpleTextItem(endText);
        endLabel->setFont(QFont("Arial", 8));
        endLabel->setPos(x + width - 20, y + 40);
        ganttScene->addItem(endLabel);
    }
}


void MainWindow::drawTodayMarker(const QDate &today, int dayWidth, int bottomY)
{
    int xPos = 0;

    // Vertical line
    QGraphicsLineItem *line = new QGraphicsLineItem(xPos, 40, xPos, bottomY);
    line->setPen(QPen(Qt::red, 2, Qt::DashLine));
    ganttScene->addItem(line);

    // Label
    QGraphicsTextItem *label = new QGraphicsTextItem("TODAY\n" + today.toString("MMM d"));
    label->setPos(xPos + 10, 45);
    label->setDefaultTextColor(Qt::red);
    label->setFont(QFont("Arial", 9, QFont::Bold));
    ganttScene->addItem(label);
}

QColor MainWindow::getPriorityColor(int priority)
{
    switch (priority) {
    case 1: return QColor(100, 200, 100); // Green
    case 2: return QColor(255, 200, 100); // Orange
    case 3: return QColor(255, 100, 100); // Red
    default: return Qt::gray;
    }
}

void MainWindow::adjustViewToContent(int contentHeight)
{
    QRectF viewRect(-250, 0,
                    ui->ganttGraphicsView_2->width() + 200,
                    contentHeight + 50);
    ui->ganttGraphicsView_2->fitInView(viewRect, Qt::KeepAspectRatioByExpanding);
}


void MainWindow::on_connectArduino_clicked() {
    QSerialPort* port = arduino.getserial();
    port->setPortName("COM3"); // Or your actual port

    if(port->open(QIODevice::ReadWrite)) {
        port->setBaudRate(QSerialPort::Baud9600);
        port->setDataBits(QSerialPort::Data8);
        port->setParity(QSerialPort::NoParity);
        port->setStopBits(QSerialPort::OneStop);
        port->setFlowControl(QSerialPort::NoFlowControl);

        // Test communication
        port->write("PING\n");
        if(port->waitForReadyRead(1000)) {
            qDebug() << "Arduino response:" << port->readAll();
        }

        ui->arduinoStatusLabel->setText("Connected (Manual)");
        temperatureTimer->start(2000);
    } else {
        qDebug() << "Connection error:" << port->errorString();
    }
}

void MainWindow::updateTemperature()
{
    QSerialPort* port = arduino.getserial();
    if(port && port->isOpen()) {
        port->write("GET_TEMP\n");

        if(port->waitForReadyRead(500)) {
            QByteArray data = port->readAll();
            while(port->waitForReadyRead(50)) {
                data += port->readAll();
            }

            QString strData = QString(data).trimmed();
            qDebug() << "Received:" << strData;

            if(strData.startsWith("TEMP:")) {
                bool ok;
                float temperature = strData.mid(5).toFloat(&ok);
                if(ok) {
                    ui->temperatureLabel->setText(QString::number(temperature, 'f', 1) + " °C");

                    // Visual feedback in QT
                    QString style = temperature >= currentThreshold
                                        ? "color: red; font-weight: bold;"
                                        : "color: black;";
                    ui->temperatureLabel->setStyleSheet(style);

                    // Update database
                    if(currentProjectId > 0) {
                        QSqlQuery query;
                        query.prepare("UPDATE PROJET SET CURRENT_TEMP = ? WHERE ID = ?");
                        query.addBindValue(temperature);
                        query.addBindValue(currentProjectId);
                        query.exec();
                    }
                }
            }
        }
    }
}

void MainWindow::on_setThreshold_clicked()
{
    float newThreshold = ui->thresholdSpinBox->value();
    if (newThreshold != currentThreshold) {
        currentThreshold = newThreshold;

        // Send to Arduino
        arduino.write_to_arduino(QByteArray("SEUIL:" + QString::number(newThreshold).toUtf8()));

        // Update database
        if (currentProjectId > 0) {
            QSqlQuery query;
            query.prepare("UPDATE PROJET SET TEMP_SEUIL = :seuil WHERE ID = :id");
            query.bindValue(":seuil", newThreshold);
            query.bindValue(":id", currentProjectId);
            query.exec();
        }
    }
}



//gestion employe

void MainWindow::initializeSpecialityComboBox()
{
    // Clear existing items
    ui->comboBox_specialite_4->clear();

    // Add IT specialities
    ui->comboBox_specialite_4->addItem("Frontend Development");
    ui->comboBox_specialite_4->addItem("Backend Development");
    ui->comboBox_specialite_4->addItem("Mobile Development");
    ui->comboBox_specialite_4->addItem("DevOps & Cloud");

    // Add Business specialities
    ui->comboBox_specialite_4->addItem("Project Management");
    ui->comboBox_specialite_4->addItem("Business Analysis");
    ui->comboBox_specialite_4->addItem("Digital Marketing");

    // Set default selection
    ui->comboBox_specialite_4->setCurrentIndex(0);
}



void MainWindow::on_add_button_4_clicked()
{
    {

        // Récupérer les valeurs des champs de l'interface utilisateur
        QString nom = ui->lineEdit_nom_4->text().trimmed();
        QString prenom = ui->lineEdit_prenom_4->text().trimmed();
        QString adresse = ui->lineEdit_Adresse_4->text().trimmed();
        QString email = ui->lineEdit_email_7->text().trimmed();
        QString motDePasse = ui->lineEdit_mdp_4->text().trimmed();
        QString specialite = ui->comboBox_specialite_4->currentText(); // Changed from lineEdit to comboBox
        QString statut = ui->lineEdit_statut_4->text().trimmed();
        QDate dateEmbauche = ui->dateEdit_embauche_4->date();

        // Vérifier si tous les champs sont remplis
        if (nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || email.isEmpty() || motDePasse.isEmpty() || specialite.isEmpty() || statut.isEmpty() || !dateEmbauche.isValid()) {
            QMessageBox::warning(this, "Champ(s) manquant(s)", "Veuillez remplir tous les champs correctement.");
            return;
        }

        // Contrôle de saisie pour le nom et prénom (lettres uniquement)
        QRegularExpression nameRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s'-]+$");
        if (!nameRegex.match(nom).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le nom ne doit contenir que des lettres.");
            return;
        }
        if (!nameRegex.match(prenom).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le prénom ne doit contenir que des lettres.");
            return;
        }

        // Contrôle de saisie pour l'email (format valide)
        QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        if (!emailRegex.match(email).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer une adresse email valide.");
            return;
        }

        // Contrôle de saisie pour le mot de passe (au moins 8 caractères, une majuscule, une minuscule, un chiffre)
        QRegularExpression passwordRegex("^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d).{8,}$");
        if (!passwordRegex.match(motDePasse).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le mot de passe doit contenir au moins 8 caractères, une majuscule, une minuscule et un chiffre.");
            return;
        }

        // Contrôle de saisie pour la date d'embauche (doit être dans le passé ou aujourd'hui)
        if (dateEmbauche > QDate::currentDate()) {
            QMessageBox::warning(this, "Erreur de saisie", "La date d'embauche ne peut pas être dans le futur.");
            return;
        }

        qDebug() << "Nom:" << nom;
        qDebug() << "Prénom:" << prenom;
        qDebug() << "Adresse:" << adresse;
        qDebug() << "Email:" << email;
        qDebug() << "Mot de Passe:" << motDePasse;
        qDebug() << "Spécialité:" << specialite;
        qDebug() << "Statut:" << statut;
        qDebug() << "Date d'Embauche:" << dateEmbauche;

        // Créer une instance de la classe Employe avec les données récupérées
        Employe employe(nom, prenom, adresse, email, motDePasse, specialite, statut, dateEmbauche);

        // Appeler la méthode ajouter() pour insérer les données dans la base de données
        bool success = employe.ajouter();

        // Afficher un message en fonction du résultat de l'opération
        if (success) {
            QMessageBox::information(this, "Succès", "L'employé a été ajouté avec succès.");
            displaySpecialiteStats();

            ui->lineEdit_nom_4->clear();
            ui->lineEdit_prenom_4->clear();
            ui->lineEdit_Adresse_4->clear();
            ui->lineEdit_email_7->clear();
            ui->lineEdit_mdp_4->clear();
            ui->comboBox_specialite_4->setCurrentIndex(0); // Reset combo box
            ui->lineEdit_statut_4->clear();
            ui->dateEdit_embauche_4->setDate(QDate::currentDate());

            // Mettre à jour l'affichage des employés dans le tableViewEmploye
            ui->tableViewEmploye_4->setModel(employe.afficher());
        } else {
            QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors de l'ajout de l'employé.");
        }
    }
}


void MainWindow::on_modifStadeButton_4_clicked()
{
    {
        bool ok;
        int id = ui->idEmploye_4->text().toInt(&ok);
        if (!ok || id <= 0) {
            QMessageBox::critical(this, "Erreur", "ID de l'employé invalide.");
            return;
        }

        QString nom = ui->lineEdit_nom_4->text();
        QString prenom = ui->lineEdit_prenom_4->text();
        QString adresse = ui->lineEdit_Adresse_4->text();
        QString email = ui->lineEdit_email_7->text();
        QString motDePasse = ui->lineEdit_mdp_4->text();
        QString specialite = ui->comboBox_specialite_4->currentText(); // Changed from lineEdit to comboBox
        QString statut = ui->lineEdit_statut_4->text();
        QDate dateEmbauche = ui->dateEdit_embauche_4->date();

        // Vérifier si tous les champs sont remplis
        if (nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || email.isEmpty() || motDePasse.isEmpty() || specialite.isEmpty() || statut.isEmpty() || !dateEmbauche.isValid()) {
            QMessageBox::warning(this, "Champ(s) manquant(s)", "Veuillez remplir tous les champs correctement.");
            return;
        }

        // Contrôle de saisie pour le nom et prénom (lettres uniquement)
        QRegularExpression nameRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s'-]+$");
        if (!nameRegex.match(nom).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le nom ne doit contenir que des lettres.");
            return;
        }
        if (!nameRegex.match(prenom).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le prénom ne doit contenir que des lettres.");
            return;
        }

        // Contrôle de saisie pour l'email (format valide)
        QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        if (!emailRegex.match(email).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer une adresse email valide.");
            return;
        }

        // Contrôle de saisie pour le mot de passe (au moins 8 caractères, une majuscule, une minuscule, un chiffre)
        QRegularExpression passwordRegex("^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d).{8,}$");
        if (!passwordRegex.match(motDePasse).hasMatch()) {
            QMessageBox::warning(this, "Erreur de saisie", "Le mot de passe doit contenir au moins 8 caractères, une majuscule, une minuscule et un chiffre.");
            return;
        }

        // Créer une instance de la classe Employe avec les données récupérées
        Employe employe(id, nom, prenom, adresse, email, motDePasse, specialite, statut, dateEmbauche);

        // Appeler la méthode modifier() pour mettre à jour les données dans la base de données
        bool success = employe.modifier(id);

        if (success) {
            // Refresh the table view
            ui->tableViewEmploye_4->setModel(employe.afficher());
            displaySpecialiteStats();

            // Effacer les champs après modification
            ui->lineEdit_nom_4->clear();
            ui->lineEdit_prenom_4->clear();
            ui->lineEdit_Adresse_4->clear();
            ui->lineEdit_email_7->clear();
            ui->lineEdit_mdp_4->clear();
            ui->comboBox_specialite_4->setCurrentIndex(0); // Reset combo box
            ui->lineEdit_statut_4->clear();
            ui->dateEdit_embauche_4->setDate(QDate::currentDate());

            QMessageBox::information(this, "Modification réussie", "Employé modifié avec succès.");
        } else {
            QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors de la modification de l'employé.");
        }
    }

}


void MainWindow::on_DeleteStadeButton_4_clicked()
{
    {
        // Check if at least one row is selected
        QModelIndexList selectedIndexes = ui->tableViewEmploye_4->selectionModel()->selectedIndexes();

        if (!selectedIndexes.isEmpty()) {
            // Get the ID from the selected row
            int id = selectedIndexes.at(0).sibling(selectedIndexes.at(0).row(), 0).data().toInt();

            // Call the delete function
            bool supprime = employe.supprimer(id);

            if (supprime) {
                displaySpecialiteStats();
                // Refresh the table view
                ui->tableViewEmploye_4->setModel(employe.afficher());
                QMessageBox::information(this, "Suppression réussie", "Employé supprimé avec succès.");
            } else {
                QMessageBox::warning(this, "Échec de la suppression", "Échec de la suppression de l'employé.");
            }
        } else {
            QMessageBox::warning(this, "Aucun employé sélectionné", "Veuillez sélectionner un employé à supprimer.");
        }
    }
}


void MainWindow::on_trier_Button_4_clicked()
{
    {
        QString champ = "";
        // Determine which field to sort by based on first combo box
        if (ui->comboBoxsortchamp_4->currentText().compare("Nom", Qt::CaseInsensitive) == 0) {
            champ = "nom";
        } else if (ui->comboBoxsortchamp_4->currentText().compare("Date d'embauche", Qt::CaseInsensitive) == 0) {
            champ = "date_embauche";
        } else {
            // Default to sorting by ID if nothing is selected
            champ = "nom";
        }

        QString order = "asc";  // Default sort order
        // Update the sort order based on the second combo box selection
        if (ui->comboBox_order_4->currentText().compare("Descendant", Qt::CaseInsensitive) == 0) {
            order = "desc";
        }

        qDebug() << "Order:" << order;
        qDebug() << "Champ:" << champ;

        // Ensure we have a valid field to sort by
        if (champ.isEmpty()) {
            qDebug() << "Error: No valid field selected for sorting";
            return;
        }

        // Create an Employe object and call the Tri method
        Employe employe;
        ui->tableViewEmploye_4->setModel(employe.Tri(order, champ));
    }
}


void MainWindow::on_lineEdit_9_textChanged(const QString &arg1)
{
    Employe e;
    QSqlQueryModel* model = e.rechercherParNom(arg1);
    ui->tableViewEmploye_4->setModel(model);
}


void MainWindow::on_tableViewEmploye_4_doubleClicked(const QModelIndex &index)
{
    {
        int row = index.row();

        // Récupérer les données de la ligne sélectionnée

        int id = ui->tableViewEmploye_4->model()->data(ui->tableViewEmploye_4->model()->index(row, 0)).toInt();
        QString nom = ui->tableViewEmploye_4->model()->data(ui->tableViewEmploye_4->model()->index(row, 1)).toString();
        QString prenom = ui->tableViewEmploye_4->model()->data(ui->tableViewEmploye_4->model()->index(row, 2)).toString();
        QString adresse = ui->tableViewEmploye_4->model()->data(ui->tableViewEmploye_4->model()->index(row, 3)).toString();
        QString email = ui->tableViewEmploye_4->model()->data(ui->tableViewEmploye_4->model()->index(row, 4)).toString();
        QString motDePasse = ui->tableViewEmploye_4->model()->data(ui->tableViewEmploye_4->model()->index(row, 5)).toString();
        QString specialite = ui->tableViewEmploye_4->model()->data(ui->tableViewEmploye_4->model()->index(row, 6)).toString();
        QString statut = ui->tableViewEmploye_4->model()->data(ui->tableViewEmploye_4->model()->index(row, 7)).toString();
        QDate dateEmbauche = ui->tableViewEmploye_4->model()->data(ui->tableViewEmploye_4->model()->index(row, 8)).toDate();

        // Définir les données dans les éléments UI respectifs
        ui->idEmploye_4->setText(QString::number(id));
        ui->lineEdit_nom_4->setText(nom);
        ui->lineEdit_prenom_4->setText(prenom);
        ui->lineEdit_Adresse_4->setText(adresse);
        ui->lineEdit_email_7->setText(email);
        ui->lineEdit_mdp_4->setText(motDePasse); // Mot de passe
        // Set the speciality in the combo box
        int specialityIndex = ui->comboBox_specialite_4->findText(specialite);
        if (specialityIndex >= 0) {
            ui->comboBox_specialite_4->setCurrentIndex(specialityIndex);
        } else {
            ui->comboBox_specialite_4->setCurrentIndex(0);
        }
        ui->lineEdit_statut_4->setText(statut);
        ui->dateEdit_embauche_4->setDate(dateEmbauche);
    }

}




void MainWindow::on_pushButton_10_clicked()
{
    {
        QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
        if (fileName.isEmpty())
            return;

        // Make sure filename has .pdf extension
        if (!fileName.endsWith(".pdf", Qt::CaseInsensitive))
            fileName += ".pdf";

        // Create printer
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        printer.setPageSize(QPageSize(QPageSize::A4));

        // Create HTML content for the PDF
        QTextDocument doc;
        QString html = "<h1 align='center'>Liste des Employés</h1>";
        html += "<p align='center'>Date: " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss") + "</p>";
        html += "<table border='1' cellspacing='0' cellpadding='3' width='100%'>";

        // Add table headers based on your model
        html += "<tr bgcolor='#eeeeee'>";
        html += "<th>ID</th>";
        html += "<th>Nom</th>";
        html += "<th>Prénom</th>";
        html += "<th>Adresse</th>";
        html += "<th>Email</th>";
        html += "<th>Spécialité</th>";
        html += "<th>Statut</th>";
        html += "<th>Date d'Embauche</th>";
        html += "</tr>";

        // Get data from your tableView model
        QAbstractItemModel* model = ui->tableViewEmploye_4->model(); // Make sure to use your actual tableView name
        if (!model) {
            QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter");
            return;
        }

        // Get data from model and add rows to HTML table
        for (int row = 0; row < model->rowCount(); ++row) {
            html += "<tr>";
            for (int col = 0; col < model->columnCount(); ++col) {
                // Skip password column (index 5 based on your model)
                if (col == 5)
                    continue;

                QModelIndex index = model->index(row, col);
                html += "<td>" + model->data(index).toString() + "</td>";
            }
            html += "</tr>";
        }

        html += "</table>";

        // Add footer
        html += "<p align='right'><i>Document généré par le système de gestion des employés</i></p>";

        doc.setHtml(html);
        doc.print(&printer);

        QMessageBox::information(this, "PDF Exporté", "Le fichier PDF a été généré avec succès.\n" + fileName);
    }

}

void MainWindow::displaySpecialiteStats() {
    // Create an instance of Employe class
    Employe e;

    // Get the count of employees by speciality
    QMap<QString, int> specialiteCounts = e.getEmployeeCountBySpecialite();

    // Clear any existing layout in the frame
    QLayout* oldLayout = ui->frame_4->layout();
    if (oldLayout) {
        QLayoutItem* item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
        delete oldLayout;
    }

    // Create a new layout for the frame
    QVBoxLayout* frameLayout = new QVBoxLayout(ui->frame_4);
    ui->frame_4->setLayout(frameLayout);

    // Create a QChart object
    QChart* chart = new QChart();
    chart->setTitle("Répartition des employés par spécialité");
    chart->setAnimationOptions(QChart::AllAnimations);

    // Create a pie series
    QPieSeries* series = new QPieSeries();

    // Populate the series with data from the map
    QMapIterator<QString, int> i(specialiteCounts);
    while (i.hasNext()) {
        i.next();
        series->append(i.key() + " (" + QString::number(i.value()) + ")", i.value());
    }

    // Make the slices exploded and show percentage
    QList<QPieSlice*> slices = series->slices();
    for (QPieSlice* slice : slices) {
        slice->setLabelVisible(true);
        slice->setExploded(true);
        slice->setLabelPosition(QPieSlice::LabelOutside);
        slice->setLabelColor(Qt::black);

        // Connect signals for interaction
        connect(slice, &QPieSlice::hovered, this, [slice](bool state) {
            slice->setExploded(state);
        });
    }

    // Add the series to the chart
    chart->addSeries(series);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Create a chart view and set the chart
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Add the chart view to the frame layout
    frameLayout->addWidget(chartView);

    // Update the frame
    ui->frame_4->update();
}

void MainWindow::on_pushButton_11_clicked()
{
    {
        QString email = ui->lineEdit_email_8->text();
        QString password = ui->lineEdit_password_4->text();

        // Input validation
        if(email.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(this, "Login Failed", "Please enter both email and password.");
            return;
        }

        // Create a SQL query to check credentials
        QSqlQuery query;
        query.prepare("SELECT * FROM employe WHERE email = :email AND mot_de_passe = :password");
        query.bindValue(":email", email);
        query.bindValue(":password", password);

        // Execute the query
        if(query.exec() && query.next()) {
            // Login successful
            int employeeId = query.value("id_employe").toInt();
            QString employeeName = query.value("prenom").toString() + " " + query.value("nom").toString();
            QString role = query.value("statut").toString();

            // Store current logged-in user information (optional)
            currentUserId = employeeId;
            currentUserName = employeeName;

            // Show welcome message
            QMessageBox::information(this, "Login Successful", "Welcome, " + employeeName + "!");

            // Switch to the main application page (assuming index 1 is your main page)
            ui->stackedWidget_4->setCurrentIndex(0);

            // Clear the password field for security
            ui->lineEdit_password_4->clear();


            //++++
            ui->gestion_employe->hide();
            ui->menu->show();

        } else {
            // Login failed
            QMessageBox::critical(this, "Login Failed", "Invalid email or password. Please try again.");
            ui->lineEdit_password_4->clear();
            ui->lineEdit_password_4->setFocus();
        }
    }

}

bool MainWindow::sendResetEmail(const QString &email, const QString &name, const QString &code)
{
    // Check SSL support
    if (!QSslSocket::supportsSsl()) {
        qDebug() << "SSL is not supported - email cannot be sent";
        qDebug() << "SSL version used:" << QSslSocket::sslLibraryVersionString();
        return false;
    }

    // Gmail SMTP settings
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465; // Try 587 if 465 continues to be problematic
    QString username = "jery.wizin@gmail.com";
    QString password = "gysq rhyo kavv owdy";

    // Create the email content
    QString subject = "Password Reset Verification Code";
    QString body = "Hello " + name + ",\n\n"
                                     "We received a request to reset your password. Here is your verification code:\n\n"
                   + code + "\n\n"
                            "This code will expire in 1 hour.\n\n"
                            "If you didn't request a password reset, please ignore this email.\n\n"
                            "Regards,\nYour Application Team";

    // Try up to 3 times to send the email
    for (int attempt = 1; attempt <= 3; attempt++) {
        qDebug() << "Email sending attempt" << attempt;

        // Create a socket
        QSslSocket *socket = new QSslSocket(this);

        // Connect to the SMTP server
        socket->connectToHostEncrypted(smtpServer, smtpPort);

        // Set longer timeout (45 seconds)
        if (!socket->waitForConnected(45000)) {
            qDebug() << "Connection failed:" << socket->errorString();
            delete socket;

            // Wait before retry
            QThread::msleep(2000);
            continue;
        }

        // Wait for encryption
        if (!socket->waitForEncrypted(45000)) {
            qDebug() << "SSL Error: " << socket->errorString();
            qDebug() << "SSL Errors: " << socket->sslHandshakeErrors();
            delete socket;

            // Wait before retry
            QThread::msleep(2000);
            continue;
        }

        // Start a timeout timer for the entire process
        QElapsedTimer totalTimer;
        totalTimer.start();

        // Function to safely wait for response
        auto safeWaitForResponse = [&socket, &totalTimer]() -> bool {
            // Don't wait more than 15 seconds total for the entire email process
            while (socket->bytesAvailable() < 2 && totalTimer.elapsed() < 15000) {
                if (!socket->waitForReadyRead(1000)) {
                    if (socket->error() != QAbstractSocket::SocketTimeoutError)
                        return false;
                }
            }
            return true;
        };

        // Wait for the initial response
        if (!safeWaitForResponse()) {
            qDebug() << "Initial read failed:" << socket->errorString();
            delete socket;

            // Wait before retry
            QThread::msleep(2000);
            continue;
        }

        QByteArray response = socket->readAll();
        qDebug() << "Server greeting:" << response;

        // Start SMTP conversation
        bool success = true;

        // Send EHLO
        socket->write("EHLO localhost\r\n");
        if (!socket->waitForBytesWritten(5000) || !safeWaitForResponse()) {
            qDebug() << "Failed to send EHLO";
            success = false;
        }
        response = socket->readAll();
        qDebug() << "EHLO response:" << response;
        if (!success) {
            delete socket;
            QThread::msleep(2000);
            continue;
        }

        // Send AUTH LOGIN
        socket->write("AUTH LOGIN\r\n");
        if (!socket->waitForBytesWritten(5000) || !safeWaitForResponse()) {
            qDebug() << "Failed to send AUTH LOGIN";
            success = false;
        }
        response = socket->readAll();
        qDebug() << "AUTH LOGIN response:" << response;
        if (!success) {
            delete socket;
            QThread::msleep(2000);
            continue;
        }

        // Send username
        QByteArray encodedUsername = username.toUtf8().toBase64();
        socket->write(encodedUsername + "\r\n");
        if (!socket->waitForBytesWritten(5000) || !safeWaitForResponse()) {
            qDebug() << "Failed to send username";
            success = false;
        }
        response = socket->readAll();
        qDebug() << "Username response:" << response;
        if (!success) {
            delete socket;
            QThread::msleep(2000);
            continue;
        }

        // Send password
        QByteArray encodedPassword = password.toUtf8().toBase64();
        socket->write(encodedPassword + "\r\n");
        if (!socket->waitForBytesWritten(5000) || !safeWaitForResponse()) {
            qDebug() << "Failed to send password";
            success = false;
        }
        response = socket->readAll();
        qDebug() << "Password response:" << response;
        if (!success || !response.contains("235")) {
            qDebug() << "Authentication failed";
            delete socket;
            QThread::msleep(2000);
            continue;
        }

        // Send MAIL FROM
        socket->write(("MAIL FROM:<" + username + ">\r\n").toUtf8());
        if (!socket->waitForBytesWritten(5000) || !safeWaitForResponse()) {
            qDebug() << "Failed to send MAIL FROM";
            success = false;
        }
        response = socket->readAll();
        qDebug() << "MAIL FROM response:" << response;
        if (!success) {
            delete socket;
            QThread::msleep(2000);
            continue;
        }

        // Send RCPT TO
        socket->write(("RCPT TO:<" + email + ">\r\n").toUtf8());
        if (!socket->waitForBytesWritten(5000) || !safeWaitForResponse()) {
            qDebug() << "Failed to send RCPT TO";
            success = false;
        }
        response = socket->readAll();
        qDebug() << "RCPT TO response:" << response;
        if (!success) {
            delete socket;
            QThread::msleep(2000);
            continue;
        }

        // Send DATA
        socket->write("DATA\r\n");
        if (!socket->waitForBytesWritten(5000) || !safeWaitForResponse()) {
            qDebug() << "Failed to send DATA";
            success = false;
        }
        response = socket->readAll();
        qDebug() << "DATA response:" << response;
        if (!success) {
            delete socket;
            QThread::msleep(2000);
            continue;
        }

        // Send email content
        QString emailMessage = "From: Your App <" + username + ">\r\n"
                               + "To: " + name + " <" + email + ">\r\n"
                               + "Subject: " + subject + "\r\n"
                               + "Content-Type: text/plain; charset=UTF-8\r\n\r\n"
                               + body + "\r\n.\r\n";

        socket->write(emailMessage.toUtf8());
        if (!socket->waitForBytesWritten(5000) || !safeWaitForResponse()) {
            qDebug() << "Failed to send email content";
            success = false;
        }
        response = socket->readAll();
        qDebug() << "Email content response:" << response;
        if (!success) {
            delete socket;
            QThread::msleep(2000);
            continue;
        }

        // Send QUIT
        socket->write("QUIT\r\n");
        socket->waitForBytesWritten(5000);
        socket->waitForReadyRead(5000);
        response = socket->readAll();
        qDebug() << "QUIT response:" << response;

        // Close and cleanup
        socket->close();
        delete socket;

        // If we got here without continuing the retry loop, we succeeded
        qDebug() << "Email sent successfully on attempt" << attempt;
        return true;
    }

    qDebug() << "Failed to send email after 3 attempts";
    return false;
}





void MainWindow::on_pushButton_12_clicked()
{
    {
        // Create a dialog for the forgot password flow
        QDialog forgotPwdDialog(this);
        forgotPwdDialog.setWindowTitle("Password Recovery");
        forgotPwdDialog.setMinimumWidth(400);

        // Create layout
        QVBoxLayout* mainLayout = new QVBoxLayout(&forgotPwdDialog);

        // Add option selection
        QLabel* methodLabel = new QLabel("Select verification method:", &forgotPwdDialog);
        QHBoxLayout* methodLayout = new QHBoxLayout();
        QPushButton* emailMethodButton = new QPushButton("Email Verification", &forgotPwdDialog);
        QPushButton* questionMethodButton = new QPushButton("Security Question", &forgotPwdDialog);
        methodLayout->addWidget(emailMethodButton);
        methodLayout->addWidget(questionMethodButton);

        mainLayout->addWidget(methodLabel);
        mainLayout->addLayout(methodLayout);

        // Stacked widget to switch between methods
        QStackedWidget* stackedWidget = new QStackedWidget(&forgotPwdDialog);
        mainLayout->addWidget(stackedWidget);

        // Status label for showing messages
        QLabel* statusLabel = new QLabel(&forgotPwdDialog);
        statusLabel->setWordWrap(true);
        mainLayout->addWidget(statusLabel);

        // Create email verification page
        QWidget* emailPage = new QWidget();
        QVBoxLayout* emailLayout = new QVBoxLayout(emailPage);

        QLabel* emailLabel = new QLabel("Enter your email address:", emailPage);
        QLineEdit* emailInput = new QLineEdit(emailPage);
        QPushButton* sendResetLinkButton = new QPushButton("Send Verification Code", emailPage);

        emailLayout->addWidget(emailLabel);
        emailLayout->addWidget(emailInput);
        emailLayout->addWidget(sendResetLinkButton);
        emailLayout->addStretch();

        stackedWidget->addWidget(emailPage);

        // Create security question page
        QWidget* questionPage = new QWidget();
        QVBoxLayout* questionLayout = new QVBoxLayout(questionPage);

        QLabel* emailLabelQuestion = new QLabel("Enter your email address:", questionPage);
        QLineEdit* emailInputQuestion = new QLineEdit(questionPage);
        QPushButton* verifyButton = new QPushButton("Verify", questionPage);

        questionLayout->addWidget(emailLabelQuestion);
        questionLayout->addWidget(emailInputQuestion);
        questionLayout->addWidget(verifyButton);
        questionLayout->addStretch();

        stackedWidget->addWidget(questionPage);

        // Connect method selection buttons
        connect(emailMethodButton, &QPushButton::clicked, [&]() {
            stackedWidget->setCurrentIndex(0);
            statusLabel->clear();
        });

        connect(questionMethodButton, &QPushButton::clicked, [&]() {
            stackedWidget->setCurrentIndex(1);
            statusLabel->clear();
        });

        // Connect email verification button (modified to remove hashing)
        connect(sendResetLinkButton, &QPushButton::clicked, [&]() {
            QString email = emailInput->text().trimmed();

            if (email.isEmpty()) {
                statusLabel->setText("Please enter your email address.");
                statusLabel->setStyleSheet("color: red;");
                return;
            }

            QSqlQuery query;
            query.prepare("SELECT id_employe, nom, prenom, DATE_EMBAUCHE FROM employe WHERE email = :email");
            query.bindValue(":email", email);

            if (query.exec() && query.next()) {
                // Email exists in database
                int employeeId = query.value("id_employe").toInt();
                QString employeeName = query.value("prenom").toString() + " " + query.value("nom").toString();

                // Generate a numeric verification code (6 digits)
                QString verificationCode = generateVerificationCode();

                // Store the code in the database with an expiration time
                QDateTime expiryTime = QDateTime::currentDateTime().addSecs(3600); // Code valid for 1 hour

                QSqlQuery tokenQuery;
                tokenQuery.prepare("INSERT INTO password_reset_tokens (employee_id, token, expiry_time) "
                                   "VALUES (:employee_id, :token, :expiry_time)");
                tokenQuery.bindValue(":employee_id", employeeId);
                tokenQuery.bindValue(":token", verificationCode);
                tokenQuery.bindValue(":expiry_time", expiryTime);

                if (tokenQuery.exec()) {
                    // Send email with verification code
                    if (sendResetEmail(email, employeeName, verificationCode)) {
                        statusLabel->setText("Verification code has been sent to your email address.");
                        statusLabel->setStyleSheet("color: green;");

                        // Disable the email input and send button
                        sendResetLinkButton->setEnabled(false);
                        emailInput->setEnabled(false);

                        // Add verification code and password fields
                        QLabel* codeLabel = new QLabel("Verification Code:", emailPage);
                        QLineEdit* codeInput = new QLineEdit(emailPage);
                        QLabel* newPwdLabel = new QLabel("New Password:", emailPage);
                        QLineEdit* newPwdInput = new QLineEdit(emailPage);
                        newPwdInput->setEchoMode(QLineEdit::Password);
                        QLabel* confirmPwdLabel = new QLabel("Confirm Password:", emailPage);
                        QLineEdit* confirmPwdInput = new QLineEdit(emailPage);
                        confirmPwdInput->setEchoMode(QLineEdit::Password);
                        QPushButton* resetPwdButton = new QPushButton("Reset Password", emailPage);

                        emailLayout->addWidget(codeLabel);
                        emailLayout->addWidget(codeInput);
                        emailLayout->addWidget(newPwdLabel);
                        emailLayout->addWidget(newPwdInput);
                        emailLayout->addWidget(confirmPwdLabel);
                        emailLayout->addWidget(confirmPwdInput);
                        emailLayout->addWidget(resetPwdButton);

                        // Connect reset password button (modified to remove hashing)
                        connect(resetPwdButton, &QPushButton::clicked, [&, codeInput, newPwdInput, confirmPwdInput, statusLabel, &forgotPwdDialog, employeeId]() {
                            try {
                                QString enteredCode = codeInput->text().trimmed();
                                QString newPassword = newPwdInput->text();
                                QString confirmPassword = confirmPwdInput->text();

                                // Validate inputs
                                if (enteredCode.isEmpty() || newPassword.isEmpty() || confirmPassword.isEmpty()) {
                                    statusLabel->setText("Please fill all fields.");
                                    statusLabel->setStyleSheet("color: red;");
                                    return;
                                }

                                if (newPassword != confirmPassword) {
                                    statusLabel->setText("Passwords do not match.");
                                    statusLabel->setStyleSheet("color: red;");
                                    return;
                                }

                                // Check verification code
                                QSqlQuery checkCodeQuery;
                                checkCodeQuery.prepare("SELECT employee_id FROM password_reset_tokens "
                                                       "WHERE token = :code AND expiry_time > :current_time");
                                checkCodeQuery.bindValue(":code", enteredCode);
                                checkCodeQuery.bindValue(":current_time", QDateTime::currentDateTime());

                                if (!checkCodeQuery.exec()) {
                                    qDebug() << "Code verification failed:" << checkCodeQuery.lastError().text();
                                    statusLabel->setText("Error verifying code. Please try again.");
                                    statusLabel->setStyleSheet("color: red;");
                                    return;
                                }

                                if (checkCodeQuery.next()) {
                                    int employeeId = checkCodeQuery.value("employee_id").toInt();

                                    // Begin transaction
                                    QSqlDatabase::database().transaction();

                                    // Update password (without hashing)
                                    QSqlQuery updatePwdQuery;
                                    updatePwdQuery.prepare("UPDATE employe SET mot_de_passe = :password WHERE id_employe = :id");
                                    updatePwdQuery.bindValue(":password", newPassword); // Store plain text
                                    updatePwdQuery.bindValue(":id", employeeId);

                                    if (updatePwdQuery.exec()) {
                                        // Delete used code
                                        QSqlQuery deleteCodeQuery;
                                        deleteCodeQuery.prepare("DELETE FROM password_reset_tokens WHERE token = :code");
                                        deleteCodeQuery.bindValue(":code", enteredCode);

                                        if (deleteCodeQuery.exec()) {
                                            showPasswordChangeNotification();
                                            // Commit transaction only if everything succeeded
                                            QSqlDatabase::database().commit();
                                            statusLabel->setText("Password reset successfully!");
                                            statusLabel->setStyleSheet("color: green;");
                                            QTimer::singleShot(2000, &forgotPwdDialog, &QDialog::accept);
                                        } else {
                                            // Rollback on error
                                            QSqlDatabase::database().rollback();
                                            qDebug() << "Failed to delete token:" << deleteCodeQuery.lastError().text();
                                            statusLabel->setText("Password updated but cleanup failed.");
                                            statusLabel->setStyleSheet("color: orange;");
                                        }
                                    } else {
                                        // Rollback on error
                                        QSqlDatabase::database().rollback();
                                        qDebug() << "Failed to update password:" << updatePwdQuery.lastError().text();
                                        statusLabel->setText("Failed to update password.");
                                        statusLabel->setStyleSheet("color: red;");
                                    }
                                } else {
                                    statusLabel->setText("Invalid or expired verification code.");
                                    statusLabel->setStyleSheet("color: red;");
                                }
                            } catch (const std::exception& e) {
                                qDebug() << "Exception occurred:" << e.what();
                                statusLabel->setText("An error occurred. Please try again.");
                                statusLabel->setStyleSheet("color: red;");
                            } catch (...) {
                                qDebug() << "Unknown exception occurred";
                                statusLabel->setText("An error occurred. Please try again.");
                                statusLabel->setStyleSheet("color: red;");
                            }
                        });
                    } else {
                        statusLabel->setText("Failed to send email. Please try again.");
                        statusLabel->setStyleSheet("color: red;");
                    }
                } else {
                    statusLabel->setText("Database error. Please try again.");
                    statusLabel->setStyleSheet("color: red;");
                }
            } else {
                statusLabel->setText("Email not found in our records.");
                statusLabel->setStyleSheet("color: red;");
            }
        });

        // Connect security question verification button (modified to remove hashing)
        connect(verifyButton, &QPushButton::clicked, [&]() {
            QString email = emailInputQuestion->text().trimmed();

            if (email.isEmpty()) {
                statusLabel->setText("Please enter your email address.");
                statusLabel->setStyleSheet("color: red;");
                return;
            }

            // Query the database for the hiring date
            QSqlQuery query;
            query.prepare("SELECT id_employe, DATE_EMBAUCHE FROM employe WHERE email = :email");
            query.bindValue(":email", email);

            if (query.exec() && query.next()) {
                int employeeId = query.value("id_employe").toInt();
                QDate hiringDate = query.value("DATE_EMBAUCHE").toDate();

                // Clear previous widgets
                QLayoutItem* child;
                while ((child = questionLayout->takeAt(3))) { // Keep first three widgets
                    if (child->widget()) {
                        child->widget()->deleteLater();
                    }
                    delete child;
                }

                // Add security question and answer field
                QLabel* questionLabel = new QLabel("Quel est votre date d'embauche? (Format: AAAA-MM-JJ)", questionPage);
                QLineEdit* answerInput = new QLineEdit(questionPage);

                QLabel* newPwdLabel = new QLabel("New Password:", questionPage);
                QLineEdit* newPwdInput = new QLineEdit(questionPage);
                newPwdInput->setEchoMode(QLineEdit::Password);
                QLabel* confirmPwdLabel = new QLabel("Confirm Password:", questionPage);
                QLineEdit* confirmPwdInput = new QLineEdit(questionPage);
                confirmPwdInput->setEchoMode(QLineEdit::Password);
                QPushButton* resetPwdButton = new QPushButton("Reset Password", questionPage);

                questionLayout->addWidget(questionLabel);
                questionLayout->addWidget(answerInput);
                questionLayout->addWidget(newPwdLabel);
                questionLayout->addWidget(newPwdInput);
                questionLayout->addWidget(confirmPwdLabel);
                questionLayout->addWidget(confirmPwdInput);
                questionLayout->addWidget(resetPwdButton);

                // Disable email input and verify button
                emailInputQuestion->setEnabled(false);
                verifyButton->setEnabled(false);

                // Connect reset password button (modified to remove hashing)
                connect(resetPwdButton, &QPushButton::clicked, [&, answerInput, newPwdInput, confirmPwdInput, statusLabel, &forgotPwdDialog, email, hiringDate, employeeId]() {
                    QString answer = answerInput->text().trimmed();
                    QString newPassword = newPwdInput->text();
                    QString confirmPassword = confirmPwdInput->text();

                    // Validate inputs
                    if (answer.isEmpty() || newPassword.isEmpty() || confirmPassword.isEmpty()) {
                        statusLabel->setText("Please fill all fields.");
                        statusLabel->setStyleSheet("color: red;");
                        return;
                    }

                    if (newPassword != confirmPassword) {
                        statusLabel->setText("Passwords do not match.");
                        statusLabel->setStyleSheet("color: red;");
                        return;
                    }

                    // Verify hiring date
                    QDate providedDate = QDate::fromString(answer, "yyyy-MM-dd");
                    if (!providedDate.isValid()) {
                        statusLabel->setText("Invalid date format. Please use AAAA-MM-JJ.");
                        statusLabel->setStyleSheet("color: red;");
                        return;
                    }

                    if (providedDate != hiringDate) {
                        statusLabel->setText("Incorrect hiring date.");
                        statusLabel->setStyleSheet("color: red;");
                        return;
                    }

                    // Hiring date is correct, reset password (without hashing)
                    QSqlQuery updatePwdQuery;
                    updatePwdQuery.prepare("UPDATE employe SET mot_de_passe = :password WHERE id_employe = :id");
                    updatePwdQuery.bindValue(":password", newPassword); // Store plain text
                    updatePwdQuery.bindValue(":id", employeeId);

                    if (updatePwdQuery.exec()) {
                        statusLabel->setText("Password reset successfully!");
                        statusLabel->setStyleSheet("color: green;");
                        QTimer::singleShot(2000, &forgotPwdDialog, &QDialog::accept);
                    } else {
                        statusLabel->setText("Failed to update password.");
                        statusLabel->setStyleSheet("color: red;");
                    }
                    showPasswordChangeNotification();
                });
            } else {
                statusLabel->setText("Email not found in our records.");
                statusLabel->setStyleSheet("color: red;");
            }
        });

        forgotPwdDialog.exec();
    }
}


QString MainWindow::generateVerificationCode()
{
    // Generate a 6-digit numeric code
    QRandomGenerator *generator = QRandomGenerator::global();
    int code = generator->bounded(100000, 999999); // Generates a number between 100000 and 999999
    return QString::number(code);
}

void MainWindow::showPasswordChangeNotification()
{
    // First check if system tray is available
    if (QSystemTrayIcon::isSystemTrayAvailable())
    {
        QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);

        // Set an icon (you'll need to have this icon in your resources)
        trayIcon->setIcon(QIcon(":/icons/notification_icon.png"));

        // Show the icon
        trayIcon->show();

        // Show the notification message
        trayIcon->showMessage(
            "Password Changed",
            "Your password has been successfully updated.",
            QSystemTrayIcon::Information,
            3000 // Display duration in milliseconds
            );

        // Automatically delete the tray icon after it's done
        QObject::connect(trayIcon, &QSystemTrayIcon::messageClicked, trayIcon, &QSystemTrayIcon::hide);
        QTimer::singleShot(4000, trayIcon, &QObject::deleteLater);
    }
    else
    {
        // Fallback to message box if system tray isn't available
        QMessageBox::information(
            this,
            "Password Changed",
            "Your password has been successfully updated."
            );
    }
}




void MainWindow::on_menu_employe_clicked()
{
    ui->menu_employe->hide();
    ui->gestion_employe->show();
}


void MainWindow::on_employe_go_to_menu_clicked()
{
    ui->menu_employe->show();
    ui->gestion_employe->hide();
}

void MainWindow::on_pushButton_addClient_clicked()
{
    // Récupérer et nettoyer les valeurs saisies (trimmed pour éliminer les espaces en début/fin)
    QString nom = ui->lineEdit_nomCliet->text().trimmed();
    QString prenom = ui->lineEdit_prenomClient->text().trimmed();
    QString email = ui->lineEdit_emailClient->text().trimmed();
    QString cin = ui->lineEdit_cinClient->text().trimmed();
    QString adresse = ui->lineEdit_adresseClient->text().trimmed();
    QString typeClient = ui->comboBox_typeClient->currentText();
    QString numeroTelephone = ui->lineEdit_numClient->text().trimmed();

    QRegularExpression regexNom("^[A-Za-zÀ-ÖØ-öø-ÿ]+$"); // Accepte seulement des lettres, y compris accents
    QRegularExpressionMatch matchNom = regexNom.match(nom);

    if (nom.isEmpty() || nom.length() < 3 || !matchNom.hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ Nom doit contenir au moins 3 caractères alphabétiques.");
        return;
    }
    QRegularExpression regexPrenom("^[A-Za-zÀ-ÖØ-öø-ÿ]+$"); // Accepte uniquement les lettres
    QRegularExpressionMatch matchPrenom = regexPrenom.match(prenom);

    if (prenom.isEmpty() || prenom.length() < 3 || !matchPrenom.hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ Prénom doit contenir au moins 3 caractères alphabétiques.");
        return;
    }

    QRegularExpression regexEmail("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch matchEmail = regexEmail.match(email);
    if (!matchEmail.hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Adresse email invalide.");
        return;
    }

    QRegularExpression regexPhone("^[0-9]{8,}$");
    QRegularExpressionMatch matchPhone = regexPhone.match(numeroTelephone);
    if (!matchPhone.hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit comporter au moins 8 chiffres et ne contenir aucun espace.");
        return;
    }


    QRegularExpression regexCin("^[0-9]+$");
    QRegularExpressionMatch matchCin = regexCin.match(cin);
    if (!matchCin.hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ CIN doit contenir uniquement des chiffres.");
        return;
    }

    if (ui->pushButton_addClient->text() == "Modifier" && m_currentClientId != -1) {
        Client c;
        if (c.modifier(m_currentClientId, nom, prenom, email, cin, adresse, typeClient, numeroTelephone)) {
            QMessageBox::information(this, "Succès", "Client modifié avec succès.");
        } else {
            QMessageBox::critical(this, "Erreur", "La modification du client a échoué.");
            return;
        }
        m_editMode = false;
        m_currentClientId = -1;
        ui->pushButton_addClient->setText("Ajouter");
    } else {
        Client client(nom, prenom, email, cin, adresse, typeClient, numeroTelephone);
        if (client.ajouter()) {
            QMessageBox::information(this, "Succès", "Client ajouté avec succès !");
        } else {
            QMessageBox::critical(this, "Erreur", "L'ajout du client a échoué.");
            return;
        }
    }

    // Actualiser la liste des clients
    Client c;
    QSqlQueryModel* model = c.afficher();
    ui->tableViewClients->setModel(model);
    ui->tableViewClients->setColumnHidden(0, true);

    // Réinitialiser le formulaire
    ui->lineEdit_nomCliet->clear();
    ui->lineEdit_prenomClient->clear();
    ui->lineEdit_emailClient->clear();
    ui->lineEdit_cinClient->clear();
    ui->lineEdit_adresseClient->clear();
    ui->comboBox_typeClient->setCurrentIndex(0);
    ui->lineEdit_numClient->clear();

    ui->tabWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_deleteClient_clicked()
{
    // Récupérer la ligne sélectionnée dans tableViewClients
    QModelIndexList selection = ui->tableViewClients->selectionModel()->selectedRows();

    if (selection.count() == 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un client à supprimer.");
        return;
    }

    // On prend la première ligne sélectionnée
    int selectedRow = selection.at(0).row();

    // Lire l'ID dans la colonne 0
    int idClient = ui->tableViewClients->model()->data(ui->tableViewClients->model()->index(selectedRow, 0)).toInt();

    // Confirmation
    int reponse = QMessageBox::question(this, "Confirmation",
                                        "Voulez-vous vraiment supprimer ce client ?",
                                        QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes) {
        Client c;
        if (c.supprimer(idClient)) {
            QMessageBox::information(this, "Succès", "Client supprimé avec succès.");

            // Actualiser le tableau
            QSqlQueryModel* model = c.afficher();
            ui->tableViewClients->setModel(model);
            ui->tableViewClients->setColumnHidden(0, true);
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression du client.");
        }
    }
}
void MainWindow::on_pushButton_updateClient_clicked()
{
    // Vérifier qu'une ligne est sélectionnée
    QModelIndexList selection = ui->tableViewClients->selectionModel()->selectedRows();
    if (selection.count() == 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un client à modifier.");
        return;
    }

    int selectedRow = selection.at(0).row();

    // Lire l'ID (colonne 0)
    int idClient = ui->tableViewClients->model()->data(
                                                    ui->tableViewClients->model()->index(selectedRow, 0)
                                                    ).toInt();

    // Récupérer les autres infos pour pré-remplir le formulaire
    QString nom = ui->tableViewClients->model()->data(
                                                   ui->tableViewClients->model()->index(selectedRow, 1)
                                                   ).toString();
    QString prenom = ui->tableViewClients->model()->data(
                                                      ui->tableViewClients->model()->index(selectedRow, 2)
                                                      ).toString();
    QString email = ui->tableViewClients->model()->data(
                                                     ui->tableViewClients->model()->index(selectedRow, 3)
                                                     ).toString();
    QString cin = ui->tableViewClients->model()->data(
                                                   ui->tableViewClients->model()->index(selectedRow, 4)
                                                   ).toString();
    QString adresse = ui->tableViewClients->model()->data(
                                                       ui->tableViewClients->model()->index(selectedRow, 5)
                                                       ).toString();
    QString typeClient = ui->tableViewClients->model()->data(
                                                          ui->tableViewClients->model()->index(selectedRow, 6)
                                                          ).toString();
    QString numeroTel = ui->tableViewClients->model()->data(
                                                         ui->tableViewClients->model()->index(selectedRow, 7)
                                                         ).toString();

    // Pré-remplir le formulaire dans l’onglet “Ajouter Client”
    ui->lineEdit_nomCliet->setText(nom);
    ui->lineEdit_prenomClient->setText(prenom);
    ui->lineEdit_emailClient->setText(email);
    ui->lineEdit_cinClient->setText(cin);
    ui->lineEdit_adresseClient->setText(adresse);
    ui->comboBox_typeClient->setCurrentText(typeClient);
    ui->lineEdit_numClient->setText(numeroTel);

    // Mémoriser l'ID du client qu'on va modifier
    m_currentClientId = idClient;

    // Changer le texte du bouton pour indiquer qu’on est en mode “Modifier”
    ui->pushButton_addClient->setText("Modifier");

    // Bascule sur l’onglet 0 (Ajouter Client)
    ui->tabWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_cancel_clicked()
{
    // Vider les champs du formulaire
    ui->lineEdit_nomCliet->clear();
    ui->lineEdit_prenomClient->clear();
    ui->lineEdit_emailClient->clear();
    ui->lineEdit_cinClient->clear();
    ui->lineEdit_adresseClient->clear();
    ui->comboBox_typeClient->setCurrentIndex(0);
    ui->lineEdit_numClient->clear();

    // Réinitialiser le mode (passer en mode ajout)
    m_editMode = false;
    m_currentClientId = -1;

    // Réinitialiser le texte du bouton "Ajouter"
    ui->pushButton_addClient->setText("Ajouter");

    // Optionnel : si vous voulez retourner à l'onglet "Ajouter Client"
    ui->tabWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_pdf_clicked()
{
    // 1) Demander à l’utilisateur où sauvegarder le fichier PDF
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Exporter en PDF", QString(), "*.pdf");
    if (fileName.isEmpty()) {
        return; // L’utilisateur a annulé
    }
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf";
    }

    // 2) Créer un QPrinter configuré pour le PDF (mode paysage)
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);

    printer.setPageOrientation(QPageLayout::Landscape);
    printer.setOutputFileName(fileName);

    // 3) Récupérer le modèle du QTableView
    QAbstractItemModel* model = ui->tableViewClients->model();
    if (!model) {
        QMessageBox::warning(this, "Erreur",
                             "Aucun modèle n’est associé au QTableView !");
        return;
    }

    int rowCount = model->rowCount();
    int colCount = model->columnCount();

    // 4) Construire la chaîne HTML
    //    On force le "white-space: nowrap;" pour éviter les sauts de ligne
    //    dans les entêtes ou les cellules
    QString html;
    html += "<html><head><style type='text/css'>"
            "body { "
            "  font-family: 'Arial', sans-serif; "
            "  font-size: 14pt; "
            "  margin: 40px; "
            "  background-color: #f7f7f7; "
            "}"
            "h2 { "
            "  text-align: center; "
            "  color: #2c3e50; "
            "  margin-bottom: 30px; "
            "  font-size: 24pt; "
            "}"
            "table { "
            "  width: 100%; "
            "  border-collapse: collapse; "
            "  margin: auto; "
            "  table-layout: auto;"
            "}"
            "th, td { "
            "  border: 1px solid #bdc3c7; "
            "  padding: 10px 20px; "   /* plus de padding horizontal */
            "  text-align: center; "
            "  min-width: 150px; "    /* largeur minimale par colonne */
            "  white-space: nowrap; " /* empêcher les retours à la ligne */
            "}"
            "th { "
            "  background-color: #34495e; "
            "  color: #ecf0f1; "
            "  font-size: 16pt; "
            "}"
            "tr:nth-child(even) { background-color: #ecf0f1; }"
            "tr:nth-child(odd) { background-color: #ffffff; }"
            "tr:hover { "
            "  background-color: #95a5a6; "
            "  color: #ffffff; "
            "}"
            "caption { "
            "  caption-side: bottom; "
            "  text-align: center; "
            "  font-size: 12pt; "
            "  color: #7f8c8d; "
            "  margin-top: 15px; "
            "}"
            "</style></head><body>";

    html += "<h2>Liste des Clients</h2>";
    html += "<table>";

    // Entêtes de colonnes
    html += "<tr>";
    for (int col = 0; col < colCount; col++) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        html += "<th>" + header + "</th>";
    }
    html += "</tr>";

    // Lignes de données
    for (int row = 0; row < rowCount; row++) {
        html += "<tr>";
        for (int col = 0; col < colCount; col++) {
            QString data = model->data(model->index(row, col)).toString();
            html += "<td>" + data + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";

    // Légende (facultative)
    html += "<caption>Généré le "
            + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss")
            + "</caption>";

    html += "</body></html>";

    // 5) Créer un QTextDocument
    QTextDocument doc;
    doc.setHtml(html);

    // 6) Imprimer dans le QPrinter
    doc.print(&printer);

    // 7) Message de confirmation
    QMessageBox::information(this, "Export PDF",
                             "Le PDF a été généré avec succès !");
}

void MainWindow::on_pushButton_notify_clicked()
{
    // 1) Vérifier qu'une ligne est sélectionnée
    QModelIndexList selection = ui->tableViewClients->selectionModel()->selectedRows();
    if (selection.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un client.");
        return;
    }

    int row = selection.at(0).row();
    // La colonne 3 (par exemple) correspond à "email"
    QString emailClient = ui->tableViewClients->model()
                              ->data(ui->tableViewClients->model()->index(row, 3))
                              .toString();

    // 2) Construire le corps du message
    QString subject = "Notification";
    QString body = "Bonjour,\n\n"
                   "Votre compte a été créé dans notre application.\n"
                   "Nom : " + ui->tableViewClients->model()->data(ui->tableViewClients->model()->index(row, 1)).toString() + "\n"
                                                                                                                    "Prénom : " + ui->tableViewClients->model()->data(ui->tableViewClients->model()->index(row, 2)).toString() + "\n"
                                                                                                                    "Email : " + emailClient + "\n"
                                   "Cin : " + ui->tableViewClients->model()->data(ui->tableViewClients->model()->index(row, 4)).toString() + "\n"
                                                                                                                    "...\n\n"
                                                                                                                    "Cordialement,\nL'équipe.";

    // 3) Envoyer l'email via SmtpClient
    SmtpClient smtp("smtp.gmail.com", 587,
                    "ouni.mohaaamed@gmail.com",
                    "dref mdfj bepc hyne",
                    true);

    if (smtp.sendMail("votreEmail@gmail.com", emailClient, subject, body)) {
        QMessageBox::information(this, "Succès", "Email envoyé à " + emailClient);
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'envoyer l'email à " + emailClient);
    }
}

void MainWindow::on_lineEdit_searchEmail_textChanged(const QString &arg1)
{
    // Recherche dynamique par email
    Client c;
    QSqlQueryModel* model = c.rechercherEmail(arg1);
    ui->tableViewClients->setModel(model);
    ui->tableViewClients->setColumnHidden(0, true); // cacher la colonne ID
}

void MainWindow::on_pushButton_sortByName_clicked()
{
    // Tri par Nom (en ascendant par exemple)
    Client c;
    QSqlQueryModel* model = c.trierParNom(true); // true = ASC
    ui->tableViewClients->setModel(model);
    ui->tableViewClients->setColumnHidden(0, true);
}

void MainWindow::on_pushButton_sortByCin_clicked()
{
    // Tri par CIN (en ascendant par exemple)
    Client c;
    QSqlQueryModel* model = c.trierParCin(true); // true = ASC
    ui->tableViewClients->setModel(model);
    ui->tableViewClients->setColumnHidden(0, true);
}
void MainWindow::on_pushButton_actualiser_clicked()
{
    Client c;
    QSqlQueryModel* model = c.afficher();
    ui->tableViewClients->setModel(model);
    ui->tableViewClients->setColumnHidden(0, true);
}

void MainWindow::on_pushButton_statistique_clicked()
{
    // 1) Bascule sur l’onglet “Statistique” (index 2)
    ui->tabWidget_2->setCurrentIndex(2);

    // 2) Récupérer le nombre de clients Particulier vs Entreprise
    Client c;
    int countParticulier = c.countByType("Particulier");
    int countEntreprise  = c.countByType("Entreprise");

    // 3) Construire la série Pie
    QPieSeries *series = new QPieSeries();
    series->append("Particulier", countParticulier);
    series->append("Entreprise", countEntreprise);

    // Optionnel : Personnaliser
    // series->slices().at(0)->setLabel(QString("Particulier (%1)").arg(countParticulier));
    // series->slices().at(1)->setLabel(QString("Entreprise (%1)").arg(countEntreprise));

    // 4) Créer un QChart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des Clients par Type");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // 5) Créer un QChartView
    QChartView *chartView = new QChartView(chart, ui->tabWidget_2->widget(2));
    chartView->setRenderHint(QPainter::Antialiasing);

    // 6) Ajuster la taille/position dans l’onglet (index 2)
    chartView->setGeometry(10, 10,
                           ui->tabWidget_2->widget(2)->width() - 20,
                           ui->tabWidget_2->widget(2)->height() - 20);

    chartView->show();
}
void MainWindow::on_pushButton_backup_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Choisir le fichier de backup",
        QDir::homePath() + "/backup.dmp",
        "Fichier DUMP (*.dmp)"
        );
    if (fileName.isEmpty()) {
        return; // L'utilisateur a annulé
    }

    QFileInfo info(fileName);
    QString dumpFileName = info.fileName();
    QString logFileName  = info.completeBaseName() + ".log";

    QString program = "expdp";

    QString connection = "amensa/admin@XE";

    QStringList arguments;
    arguments << connection
              << "SCHEMAS=amensa"
              << "DIRECTORY=DATA_PUMP_DIR"
              << QString("DUMPFILE=%1").arg(dumpFileName)
              << QString("LOGFILE=%1").arg(logFileName);

    // 3) Lancer la commande via QProcess
    QProcess process(this);
    process.start(program, arguments);

    // Vérifier le démarrage
    if (!process.waitForStarted()) {
        QMessageBox::critical(this, "Erreur",
                              "Impossible de démarrer expdp (vérifiez le PATH ou utilisez le chemin complet).");
        return;
    }

    // Attendre la fin
    if (!process.waitForFinished()) {
        // Process interrompu ou délai dépassé
        QByteArray err = process.readAllStandardError();
        QMessageBox::critical(this, "Erreur",
                              "expdp ne s'est pas terminé correctement.\n\n" + QString(err));
        return;
    }

    // 4) Vérifier le code de sortie
    if (process.exitStatus() == QProcess::NormalExit && process.exitCode() == 0) {
        // Succès
        QMessageBox::information(this, "Succès",
                                 "Backup (schéma amen) créé avec succès.\n\n"
                                 "DUMPFILE : " + dumpFileName + "\n"
                                                      "LOGFILE  : " + logFileName +
                                     "\n(Vérifiez dans DATA_PUMP_DIR sur le serveur Oracle).");
    } else {
        // Échec : lire l'erreur
        QByteArray err = process.readAllStandardError();
        QMessageBox::critical(this, "Erreur",
                              "Échec du backup.\n\nSortie : " + QString(err));
    }
}



void MainWindow::readarduino()
{
    QByteArray data = serialPort->readAll();
    serialbuffer += QString::fromUtf8(data);

    int endOfLineIndex;
    while ((endOfLineIndex = serialbuffer.indexOf('\n')) != -1) {
        QString line = serialbuffer.left(endOfLineIndex).trimmed(); // Clean line
        serialbuffer = serialbuffer.mid(endOfLineIndex + 1);

        if (!line.isEmpty()) {
            qDebug() << "Received RFID UID:" << line;

            // Check in database using 'cin'
            QSqlQuery query;
            query.prepare("SELECT nom, prenom FROM Clients WHERE cin = :cin");
            query.bindValue(":cin", line);

            if (query.exec()) {
                if (query.next()) {
                    QString nom = query.value("nom").toString();
                    QString prenom = query.value("prenom").toString();

                    QString message = "Welcome " + nom + " " + prenom;

                    // Show popup
                    QMessageBox::information(this, "Access Granted", message);

                    // Send message back to Arduino
                    QByteArray toSend = message.toUtf8() + '\n';
                    serialPort->write(toSend);
                    qDebug() << "Sent to Arduino:" << toSend;
                } else {
                    QString message = "CIN not found";
                    QMessageBox::warning(this, "Access Denied", message);
                    serialPort->write((message + '\n').toUtf8());
                }
            } else {
                qDebug() << "Query failed:" << query.lastError().text();
            }
        }
    }



}

void MainWindow::on_projet_go_to_menu_clicked()
{
    ui->gestion_client->hide();
    ui->menu->show();
}


void MainWindow::on_menu_client_clicked()
{
    ui->gestion_client->show();
    ui->menu->hide();
}

//gestion conultant

void MainWindow::initializeConsultantTableModel() {
    // Create and configure the QSqlTableModel
    consultantTableModel = new QSqlTableModel(this);
    consultantTableModel->setTable("CONSULTANT"); // Set the table name
    consultantTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit); // Manual edit strategy

    // Définir les en-têtes des colonnes
    consultantTableModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    consultantTableModel->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    consultantTableModel->setHeaderData(2, Qt::Horizontal, tr("Prénom"));
    consultantTableModel->setHeaderData(3, Qt::Horizontal, tr("Téléphone"));
    consultantTableModel->setHeaderData(4, Qt::Horizontal, tr("Date d'ajout"));

    consultantTableModel->select(); // Load data from the database

    // Create and configure the QSortFilterProxyModel
    consultantProxyModel = new QSortFilterProxyModel(this);
    consultantProxyModel->setSourceModel(consultantTableModel);
    consultantProxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    consultantProxyModel->setFilterKeyColumn(-1); // Filter on all columns

    // Set the proxy model on the table
    ui->consultantTable->setModel(consultantProxyModel);
    ui->consultantTable->setSortingEnabled(true);

    // Ajuster la taille des colonnes
    ui->consultantTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_QJOUTERCONSULTQNTBUTTON_clicked()
{
    // Validation des entrées
    if (ui->lineEdit_ID->text().isEmpty() || ui->lineEdit_Nom->text().isEmpty() ||
        ui->lineEdit_Prenom->text().isEmpty() || ui->lineEdit_Telephone->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_Nom->text();
    QString prenom = ui->lineEdit_Prenom->text();
    QString telephone = ui->lineEdit_Telephone->text();
    QString dateAjout = ui->dateAjoutLineEdit->date().toString("yyyy-MM-dd");

    Consultant c(id, nom, prenom, telephone, dateAjout);

    if (c.ajouter()) {
        QMessageBox::information(this, "Succès", "Consultant ajouté avec succès !");

        // Rafraîchir le modèle
        consultantTableModel->select();

        // Vider les champs
        ui->lineEdit_ID->clear();
        ui->lineEdit_Nom->clear();
        ui->lineEdit_Prenom->clear();
        ui->lineEdit_Telephone->clear();

        // Trier par ID
        ui->consultantTable->sortByColumn(0, Qt::AscendingOrder);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du consultant. Vérifiez que l'ID n'existe pas déjà.");
    }
}

void MainWindow::on_supprierconsultqntpushbutton_clicked()
{
    // Vérifier si une ligne est sélectionnée
    QModelIndex currentIndex = ui->consultantTable->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un consultant à supprimer.");
        return;
    }

    // Obtenir l'ID du consultant sélectionné (première colonne)
    int sourceRow = consultantProxyModel->mapToSource(currentIndex).row();
    int id = consultantTableModel->data(consultantTableModel->index(sourceRow, 0)).toInt();

    // Demander confirmation
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation",
                                                              "Êtes-vous sûr de vouloir supprimer ce consultant ?",
                                                              QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Consultant c;
        if (c.supprimer(id)) {
            QMessageBox::information(this, "Succès", "Consultant supprimé avec succès !");
            // Rafraîchir la vue
            consultantTableModel->select();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression du consultant.");
        }
    }
}

void MainWindow::on_consultantTable_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        // Récupérer la ligne source (car nous utilisons un proxy model)
        int sourceRow = consultantProxyModel->mapToSource(index).row();

        // Remplir les champs avec les données du consultant sélectionné
        ui->lineEdit_ID->setText(consultantTableModel->data(consultantTableModel->index(sourceRow, 0)).toString());
        ui->lineEdit_Nom->setText(consultantTableModel->data(consultantTableModel->index(sourceRow, 1)).toString());
        ui->lineEdit_Prenom->setText(consultantTableModel->data(consultantTableModel->index(sourceRow, 2)).toString());
        ui->lineEdit_Telephone->setText(consultantTableModel->data(consultantTableModel->index(sourceRow, 3)).toString());

        // Convertir la date en QDate et la définir dans le dateEdit
        QString dateStr = consultantTableModel->data(consultantTableModel->index(sourceRow, 4)).toString();
        QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
        if (date.isValid()) {
            ui->dateAjoutLineEdit->setDate(date);
        } else {
            ui->dateAjoutLineEdit->setDate(QDate::currentDate());
        }

        // Désactiver le bouton d'ajout pour éviter la confusion
        ui->QJOUTERCONSULTQNTBUTTON->setEnabled(false);
    }
}

void MainWindow::on_odifyconsultant_clicked()
{
    // Validation des entrées
    if (ui->lineEdit_ID->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez d'abord sélectionner un consultant à modifier.");
        return;
    }

    if (ui->lineEdit_Nom->text().isEmpty() ||
        ui->lineEdit_Prenom->text().isEmpty() ||
        ui->lineEdit_Telephone->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs sont obligatoires.");
        return;
    }

    // Récupération des données
    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_Nom->text().trimmed();
    QString prenom = ui->lineEdit_Prenom->text().trimmed();
    QString telephone = ui->lineEdit_Telephone->text().trimmed();
    QString dateAjout = ui->dateAjoutLineEdit->date().toString("yyyy-MM-dd");

    // Validation du numéro de téléphone (doit contenir uniquement des chiffres)
    QRegularExpression regExp("^[0-9+]+$");
    if (!regExp.match(telephone).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone ne doit contenir que des chiffres et éventuellement le caractère '+'.");
        return;
    }

    // Création de l'objet consultant avec les nouvelles données
    Consultant c(id, nom, prenom, telephone, dateAjout);

    // Tentative de modification
    if (c.modifier(id)) {
        QMessageBox::information(this, "Succès", "Consultant modifié avec succès !");

        // Rafraîchir la vue
        consultantTableModel->select();

        // Vider les champs
        ui->lineEdit_ID->clear();
        ui->lineEdit_Nom->clear();
        ui->lineEdit_Prenom->clear();
        ui->lineEdit_Telephone->clear();
        ui->dateAjoutLineEdit->setDate(QDate::currentDate());

        // Réactiver le bouton d'ajout si nécessaire
        ui->QJOUTERCONSULTQNTBUTTON->setEnabled(true);
    } else {
        QMessageBox::critical(this, "Erreur",
                              "Échec de la modification du consultant.\n"
                              "Veuillez vérifier que l'ID existe et que les données sont valides.");
    }
}

void MainWindow::on_searchConsultantByTyping(const QString&searchText){
    QRegularExpression regex(searchText,QRegularExpression::CaseInsensitiveOption);
    consultantProxyModel->setFilterRegularExpression(regex);
}

void MainWindow::on_tricroiradiobutton_clicked()
{
    if(consultantProxyModel){
        consultantProxyModel->sort(0,Qt::AscendingOrder);
    }
}

void MainWindow::on_tridecroiradiobutton_clicked()
{
    if(consultantProxyModel){
        consultantProxyModel->sort(0,Qt::DescendingOrder);
    }
}

void MainWindow::on_exportpdfbutton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter les consultants", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty())
        return;

    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive))
        filePath += ".pdf";

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QTextDocument pdfDocument;
    QString html;

    html += "<h1 style='text-align:center;font-family:Arial,sans-serif;'>Rapport des Consultants</h1>";
    html += "<table border='1' cellspacing='0' cellpadding='5' style='width:100%; border-collapse: collapse;'>";
    html += "<tr style='background-color:#f2f2f2;text-align:left;'>";

    QAbstractItemModel* model = ui->consultantTable->model();
    if (!model) {
        QMessageBox::warning(this, "Erreur d'export", "Aucune donnée à exporter.");
        return;
    }

    // En-têtes des colonnes
    for (int col = 0; col < model->columnCount(); ++col) {
        html += "<th>" + model->headerData(col, Qt::Horizontal).toString() + "</th>";
    }
    html += "</tr>";

    // Données des lignes
    for (int row = 0; row < model->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < model->columnCount(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            html += "<td>" + data + "</td>";
        }
        html += "</tr>";
    }

    html += "</table>";

    pdfDocument.setHtml(html);
    pdfDocument.print(&pdfWriter);

    QMessageBox::information(this, "Succès", "Exportation en PDF terminée !");
}

void MainWindow::on_statistiquepushbutton_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT TO_CHAR(DATE_AJOUT, 'YYYY-MM') AS mois, COUNT(*) AS nombre "
                  "FROM CONSULTANT "
                  "GROUP BY TO_CHAR(DATE_AJOUT, 'YYYY-MM') "
                  "ORDER BY mois");

    QBarSet *barSet = new QBarSet("Consultants");
    QStringList categories;

    if (query.exec()) {
        while (query.next()) {
            QString mois = query.value("mois").toString();
            int nombre = query.value("nombre").toInt();
            *barSet << nombre;
            categories << mois;
        }
    }

    QBarSeries *series = new QBarSeries();
    series->append(barSet);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Consultants ajoutés par mois");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Afficher dans staticWidget (assure-toi qu'il a un layout vide)
    QLayout *oldLayout =ui-> staticWidget->layout();
    if (oldLayout)
        delete oldLayout;

    QVBoxLayout *layout = new QVBoxLayout(ui-> staticWidget);
    layout->addWidget(chartView);
    ui-> staticWidget->setLayout(layout);
    ui-> staticWidget->setVisible(true);
    ui->hidepushbutton->show();
}

void MainWindow::on_hidepushbutton_clicked()
{
    ui->staticWidget->hide();
    ui->hidepushbutton->hide();
}

void MainWindow::on_sendsms_clicked()
{
    // Récupérer le message et le numéro
    QString message = ui->textsms->text();   // ✅ QTextEdit
    QString numero = ui->numerolineedit->text();    // ✅ QLineEdit

    // Vérification si le message est vide (en ignorant les espaces)
    if (message.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Message vide", "⚠️ Veuillez entrer un message à envoyer.");
        return;
    }

    // Vérification si le numéro est vide
    if (numero.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Numéro vide", "⚠️ Veuillez entrer un numéro de téléphone.");
        return;
    }

    // Validation du format du numéro (exemple : 8 à 15 chiffres, optionnel +)
    QRegularExpression regex("^\\+?[0-9]{8,15}$");
    if (!regex.match(numero).hasMatch()) {
        QMessageBox::warning(this, "Numéro invalide", "⚠️ Le numéro doit contenir entre 8 et 15 chiffres, avec ou sans '+' au début.");
        return;
    }

    // Envoi du SMS
    sarah->envoyerSMS(numero, message);

    QMessageBox::information(this, "Succès", "📩 SMS envoyé avec succès !");
}

void MainWindow::afficherHistorique()
{
    // Créer une nouvelle fenêtre de dialogue
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Historique des suppressions");
    dialog->setMinimumSize(800, 400);

    // Créer un QTableWidget pour afficher l'historique
    QTableWidget *tableWidget = new QTableWidget(dialog);
    tableWidget->setColumnCount(7); // +1 pour le bouton restaurer
    tableWidget->setHorizontalHeaderLabels({"Date de suppression", "ID", "Nom", "Prénom", "Téléphone", "Date d'ajout", "Actions"});

    // Configurer la mise en page
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(tableWidget);

    // Lire le fichier d'historique
    QFile file("historique_suppressions.txt");
    QStringList toutesLesLignes;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (!line.isEmpty()) {
                toutesLesLignes << line;
                QStringList fields = line.split(";");

                if (fields.size() >= 6) {
                    int row = tableWidget->rowCount();
                    tableWidget->insertRow(row);

                    // Ajouter les données dans les colonnes
                    for (int col = 0; col < 6; ++col) {
                        QTableWidgetItem *item = new QTableWidgetItem(fields[col]);
                        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                        tableWidget->setItem(row, col, item);
                    }

                    // Ajouter le bouton restaurer
                    QPushButton *restoreButton = new QPushButton("Restaurer");
                    restoreButton->setStyleSheet("QPushButton {"
                                                 "background-color: #27ae60;"
                                                 "color: white;"
                                                 "border-radius: 5px;"
                                                 "padding: 5px 10px;"
                                                 "}"
                                                 "QPushButton:hover {"
                                                 "background-color: #219a52;"
                                                 "}");

                    connect(restoreButton, &QPushButton::clicked, [=]() {
                        try {
                            qDebug() << "Début de la restauration...";
                            qDebug() << "Ligne complète:" << line;

                            if (fields.size() < 6) {
                                QMessageBox::warning(dialog, "Erreur",
                                                     "Format de données invalide dans l'historique.");
                                qDebug() << "Nombre de champs insuffisant:" << fields.size();
                                return;
                            }

                            bool ok;
                            int id = fields[1].toInt(&ok);
                            if (!ok) {
                                QMessageBox::warning(dialog, "Erreur",
                                                     "ID consultant invalide dans l'historique.");
                                qDebug() << "ID invalide:" << fields[1];
                                return;
                            }

                            QString nom = fields[2].trimmed();
                            QString prenom = fields[3].trimmed();
                            QString telephone = fields[4].trimmed();
                            QString dateAjout = fields[5].trimmed();

                            qDebug() << "Données à restaurer:";
                            qDebug() << "ID:" << id;
                            qDebug() << "Nom:" << nom;
                            qDebug() << "Prénom:" << prenom;
                            qDebug() << "Téléphone:" << telephone;
                            qDebug() << "Date d'ajout:" << dateAjout;

                            if (Consultant::restaurer(id, nom, prenom, telephone, dateAjout)) {
                                if (Consultant::supprimerDeLhistorique(line)) {
                                    QMessageBox::information(dialog, "Succès",
                                                             "Le consultant a été restauré avec succès !");

                                    consultantTableModel->select();
                                    tableWidget->removeRow(row);
                                    qDebug() << "Restauration et mise à jour réussies";
                                } else {
                                    QMessageBox::warning(dialog, "Attention",
                                                         "Le consultant a été restauré mais l'historique n'a pas pu être mis à jour.");
                                    qDebug() << "Échec de la suppression de l'historique";
                                }
                            } else {
                                QMessageBox::warning(dialog, "Erreur",
                                                     "Impossible de restaurer le consultant. L'ID existe peut-être déjà.");
                                qDebug() << "Échec de la restauration";
                            }
                        } catch (const std::exception& e) {
                            qDebug() << "Exception lors de la restauration:" << e.what();
                            QMessageBox::critical(dialog, "Erreur",
                                                  "Une erreur inattendue s'est produite lors de la restauration.");
                        }
                    });

                    tableWidget->setCellWidget(row, 6, restoreButton);
                }
            }
        }
        file.close();

        // Ajuster la taille des colonnes
        tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // Ajouter un bouton pour fermer
        QPushButton *closeButton = new QPushButton("Fermer", dialog);
        layout->addWidget(closeButton);
        connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

        // Ajouter un bouton pour exporter en PDF
        QPushButton *exportButton = new QPushButton("Exporter en PDF", dialog);
        layout->addWidget(exportButton);
        connect(exportButton, &QPushButton::clicked, [=]() {
            QString filePath = QFileDialog::getSaveFileName(dialog, "Exporter l'historique", "", "PDF Files (*.pdf)");
            if (!filePath.isEmpty()) {
                if (!filePath.endsWith(".pdf", Qt::CaseInsensitive))
                    filePath += ".pdf";

                QPdfWriter pdfWriter(filePath);
                pdfWriter.setPageSize(QPageSize(QPageSize::A4));
                pdfWriter.setResolution(300);

                QPainter painter(&pdfWriter);
                painter.setPen(Qt::black);

                // Configurer la police
                QFont titleFont("Arial", 16, QFont::Bold);
                QFont headerFont("Arial", 10, QFont::Bold);
                QFont contentFont("Arial", 10);

                // Titre
                painter.setFont(titleFont);
                painter.drawText(QRect(0, 0, pdfWriter.width(), 50),
                                 Qt::AlignHCenter | Qt::AlignVCenter,
                                 "Historique des suppressions de consultants");

                // En-têtes
                painter.setFont(headerFont);
                QStringList headers = {"Date de suppression", "ID", "Nom", "Prénom", "Téléphone", "Date d'ajout"};
                int yPos = 100;
                int xPos = 50;
                int colWidth = (pdfWriter.width() - 100) / 6;

                for (int i = 0; i < headers.size(); ++i) {
                    painter.drawText(QRect(xPos + i * colWidth, yPos, colWidth, 30),
                                     Qt::AlignLeft | Qt::AlignVCenter, headers[i]);
                }

                // Contenu
                painter.setFont(contentFont);
                yPos = 150;
                for (int row = 0; row < tableWidget->rowCount(); ++row) {
                    xPos = 50;
                    for (int col = 0; col < 6; ++col) { // Seulement les 6 premières colonnes (pas le bouton)
                        QString text = tableWidget->item(row, col)->text();
                        painter.drawText(QRect(xPos + col * colWidth, yPos, colWidth, 30),
                                         Qt::AlignLeft | Qt::AlignVCenter, text);
                    }
                    yPos += 30;

                    if (yPos > pdfWriter.height() - 100) {
                        pdfWriter.newPage();
                        yPos = 50;
                    }
                }

                QMessageBox::information(dialog, "Succès", "L'historique a été exporté en PDF avec succès !");
            }
        });
    } else {
        QLabel *label = new QLabel("Aucun historique de suppression disponible.", dialog);
        layout->addWidget(label);
    }

    dialog->exec();
    delete dialog;
}

void MainWindow::on_historiqueButton_clicked()
{
    afficherHistorique();
}

void MainWindow::on_fanOnButton_clicked()
{
    // Fermer et rouvrir la connexion pour s'assurer qu'elle est fraîche
    if (arduino.getserial()->isOpen()) {
        arduino.close_arduino();
    }

    if (arduino.connect_arduino() == 0) {
        // Envoyer la commande
        arduino.write_to_arduino("FAN_ON\n");

        // Attendre un peu pour s'assurer que la commande est envoyée
        QThread::msleep(100);

        // Lire la réponse de l'Arduino si disponible
        QByteArray response = arduino.read_from_arduino();
        if (!response.isEmpty()) {
            qDebug() << "Réponse Arduino:" << response;
        }

        ui->fanStatusLabel->setText("Ventilateur en marche");
        ui->fanStatusLabel->setStyleSheet("color: green; font-weight: bold;");
    } else {
        QMessageBox::warning(this, "Erreur", "La connexion avec l'Arduino n'est pas disponible.");
        ui->fanStatusLabel->setText("Erreur de connexion");
        ui->fanStatusLabel->setStyleSheet("color: red; font-weight: bold;");
    }
}

void MainWindow::on_fanOffButton_clicked()
{
    // Fermer et rouvrir la connexion pour s'assurer qu'elle est fraîche
    if (arduino.getserial()->isOpen()) {
        arduino.close_arduino();
    }

    if (arduino.connect_arduino() == 0) {
        // Envoyer la commande
        arduino.write_to_arduino("FAN_OFF\n");

        // Attendre un peu pour s'assurer que la commande est envoyée
        QThread::msleep(100);

        // Lire la réponse de l'Arduino si disponible
        QByteArray response = arduino.read_from_arduino();
        if (!response.isEmpty()) {
            qDebug() << "Réponse Arduino:" << response;
        }

        ui->fanStatusLabel->setText("Ventilateur arrêté");
        ui->fanStatusLabel->setStyleSheet("color: red; font-weight: bold;");
    } else {
        QMessageBox::warning(this, "Erreur", "La connexion avec l'Arduino n'est pas disponible.");
        ui->fanStatusLabel->setText("Erreur de connexion");
        ui->fanStatusLabel->setStyleSheet("color: red; font-weight: bold;");
    }
}

void MainWindow::on_tempButton_clicked()
{
    // Générer une nouvelle température aléatoire entre 20 et 30 degrés
    float newTemp = 20.0 + (QRandomGenerator::global()->bounded(101)) / 10.0;

    // Mettre à jour la base de données
    QSqlQuery query;
    query.prepare("UPDATE PROJET SET TEMPERATURE = :temp WHERE ID_PROJET = 58");
    query.bindValue(":temp", newTemp);

    if (query.exec()) {
        ui->temperatureLineEdit->setText(QString::number(newTemp, 'f', 1));
        checkTemperature();
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de la mise à jour de la température");
    }
}

void MainWindow::on_temperatureLineEdit_editingFinished()
{
    QString tempStr = ui->temperatureLineEdit->text();
    bool ok;
    float temperature = tempStr.toFloat(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une valeur numérique valide");
        return;
    }

    // Vérifier si la température est dans une plage raisonnable
    if (temperature < 0 || temperature > 50) {
        QMessageBox::warning(this, "Erreur", "La température doit être comprise entre 0 et 50 degrés");
        return;
    }

    // Mettre à jour la température dans la base de données
    QSqlQuery query;
    query.prepare("UPDATE PROJET SET TEMPERATURE = :temp WHERE ID_PROJET = 58");
    query.bindValue(":temp", temperature);

    if (query.exec()) {
        qDebug() << "Température mise à jour avec succès:" << temperature << "°C";

        // Vérifier immédiatement si le ventilateur doit être activé ou désactivé
        if (temperature > 24.0) {
            // Température élevée - activer le ventilateur
            if (arduino.getserial()->isOpen()) {
                arduino.close_arduino();
            }

            if (arduino.connect_arduino() == 0) {
                arduino.write_to_arduino("FAN_ON\n");
                QThread::msleep(100);
                ui->fanStatusLabel->setText("Ventilateur en marche");
                ui->fanStatusLabel->setStyleSheet("color: green; font-weight: bold;");
                QMessageBox::information(this, "Information",
                                         QString("Température de %1°C détectée. Le ventilateur a été activé.").arg(temperature));
            } else {
                QMessageBox::warning(this, "Erreur", "Impossible de communiquer avec le ventilateur");
            }
        } else {
            // Température normale - désactiver le ventilateur
            if (arduino.getserial()->isOpen()) {
                arduino.close_arduino();
            }

            if (arduino.connect_arduino() == 0) {
                arduino.write_to_arduino("FAN_OFF\n");
                QThread::msleep(100);
                ui->fanStatusLabel->setText("Ventilateur arrêté");
                ui->fanStatusLabel->setStyleSheet("color: red; font-weight: bold;");
                QMessageBox::information(this, "Information",
                                         QString("Température de %1°C détectée. Le ventilateur a été désactivé.").arg(temperature));
            } else {
                QMessageBox::warning(this, "Erreur", "Impossible de communiquer avec le ventilateur");
            }
        }
    } else {
        qDebug() << "Erreur lors de la mise à jour de la température:" << query.lastError().text();
        QMessageBox::warning(this, "Erreur", "Impossible de mettre à jour la température dans la base de données");
    }
}

void MainWindow::checkTemperature()
{
    QSqlQuery query;
    query.prepare("SELECT TEMPERATURE FROM PROJET WHERE ID_PROJET = 58");
    if (query.exec() && query.next()) {
        float temperature = query.value(0).toFloat();

        ui->temperatureLineEdit->setText(QString::number(temperature, 'f', 1));

        if (temperature > 24.0) {
            if (arduino.getserial()->isOpen()) {
                arduino.close_arduino();
            }

            if (arduino.connect_arduino() == 0) {
                arduino.write_to_arduino("FAN_ON\n");
                QThread::msleep(100);
                ui->fanStatusLabel->setText("Ventilateur en marche");
                ui->fanStatusLabel->setStyleSheet("color: green; font-weight: bold;");
            }
        } else {
            if (arduino.getserial()->isOpen()) {
                arduino.close_arduino();
            }

            if (arduino.connect_arduino() == 0) {
                arduino.write_to_arduino("FAN_OFF\n");
                QThread::msleep(100);
                ui->fanStatusLabel->setText("Ventilateur arrêté");
                ui->fanStatusLabel->setStyleSheet("color: red; font-weight: bold;");
            }
        }
    }
}



void MainWindow::on_menu_consultant_clicked()
{
    ui->gestion_consultant->show();
    ui->menu->hide();
}


void MainWindow::on_consultant_go_to_menu_clicked()
{
    ui->gestion_consultant->hide();
    ui->menu->show();
}

