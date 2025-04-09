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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    employeModel(new QSqlQueryModel(this)),
    clientModel(new QSqlQueryModel(this))
{
    ui->setupUi(this);

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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete employeModel;
    delete clientModel;
}

void MainWindow::loadData() {
    Projet p;
    QSqlQueryModel *model = p.afficher();
    ui->tableView->setModel(model);

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, tr("Start Date"));
    model->setHeaderData(4, Qt::Horizontal, tr("End Date"));
    model->setHeaderData(5, Qt::Horizontal, tr("Status"));
    model->setHeaderData(6, Qt::Horizontal, tr("Priority"));
    model->setHeaderData(7, Qt::Horizontal, tr("Budget"));
    model->setHeaderData(8, Qt::Horizontal, tr("Employee ID"));  // Changed from "Employee"
    model->setHeaderData(9, Qt::Horizontal, tr("Client ID"));    // Changed from "Client"

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
}

int MainWindow::getPriorityValue(const QString &priorityText) {
    if(priorityText == "Low") return 1;
    if(priorityText == "Medium") return 2;
    if(priorityText == "High") return 3;
    return 1;
}

QString MainWindow::getPriorityText(int priorityValue) {
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
    printer.setPageMargins(QMarginsF(5, 5, 5, 5), QPageLayout::Millimeter); // Small margins

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
    const int rowHeight = 15; // Small row height
    const int colSpacing = 3; // Small space between columns
    const int colCount = model->columnCount();
    const int rowCount = model->rowCount();

    // Calculate automatic column widths
    QVector<int> colWidths(colCount);
    painter.setFont(QFont("Arial", 7)); // Small font for measurement

    for (int col = 0; col < colCount; ++col) {
        // Header width
        int width = painter.fontMetrics().horizontalAdvance(
                        model->headerData(col, Qt::Horizontal).toString()) + 5;

        // Content width (check first 20 rows only)
        for (int row = 0; row < qMin(20, rowCount); ++row) {
            width = qMax(width, painter.fontMetrics().horizontalAdvance(
                                    model->data(model->index(row, col)).toString().left(30)) + 5); // Limit to 30 chars
        }

        colWidths[col] = qMin(width, 120); // Cap column width at 120px
    }

    // 6. Draw table header
    int xPos = 5;
    int yPos = 5;
    painter.setFont(QFont("Arial", 7, QFont::Bold)); // Bold header

    for (int col = 0; col < colCount; ++col) {
        painter.drawText(xPos, yPos, colWidths[col], rowHeight,
                         Qt::AlignLeft,
                         model->headerData(col, Qt::Horizontal).toString());
        xPos += colWidths[col] + colSpacing;
    }
    yPos += rowHeight;

    // 7. Draw table data
    painter.setFont(QFont("Arial", 7)); // Regular font for data
    for (int row = 0; row < rowCount; ++row) {
        xPos = 5;

        // New page if needed
        if (yPos + rowHeight > printer.pageLayout().paintRectPixels(printer.resolution()).height() - 10) {
            printer.newPage();
            yPos = 5;
        }

        for (int col = 0; col < colCount; ++col) {
            QString text = model->data(model->index(row, col)).toString();
            painter.drawText(xPos, yPos, colWidths[col], rowHeight,
                             Qt::AlignLeft,
                             text.left(30)); // Show first 30 chars
            xPos += colWidths[col] + colSpacing;
        }
        yPos += rowHeight;
    }

    // 8. Finish
    painter.end();
    QMessageBox::information(this, "Success",
                             QString("Table exported to:\n%1").arg(fileName));
}

void MainWindow::exportTableToPDF()
{
    // 1. Get save location
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Export PDF",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/projects.pdf",
        "PDF Files (*.pdf)"
        );
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) fileName += ".pdf";

    // 2. Setup printer
    QPrinter printer(QPrinter::ScreenResolution); // Lower resolution for smaller file
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(5, 5, 5, 5), QPageLayout::Millimeter); // Smaller margins

    // 3. Create painter
    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Error", "Could not create PDF file");
        return;
    }

    // 4. Get model data
    QAbstractItemModel *model = ui->tableView->model();
    if (!model || model->rowCount() == 0) {
        painter.end();
        QMessageBox::warning(this, "Error", "No data to export");
        return;
    }

    // 5. Calculate compact layout
    const int colCount = model->columnCount();
    const int rowCount = model->rowCount();
    const int rowHeight = 15; // Smaller row height
    const int pageWidth = printer.pageLayout().paintRectPixels(printer.resolution()).width();
    const int colSpacing = 5;

    // Calculate automatic column widths
    QVector<int> colWidths(colCount, 0);
    for (int col = 0; col < colCount; ++col) {
        // Get header width
        int width = painter.fontMetrics().horizontalAdvance(model->headerData(col, Qt::Horizontal).toString()) + 10;

        // Get content width
        for (int row = 0; row < qMin(20, rowCount); ++row) { // Check first 20 rows
            width = qMax(width, painter.fontMetrics().horizontalAdvance(model->data(model->index(row, col)).toString()) + 5);
        }

        colWidths[col] = qMin(width, 150); // Cap at 150px to prevent too wide columns
    }

    // 6. Draw table
    int xPos = 5;
    int yPos = 5;

    // Draw headers
    painter.setFont(QFont("Arial", 7, QFont::Bold)); // Smaller font
    for (int col = 0; col < colCount; ++col) {
        painter.drawText(xPos, yPos, colWidths[col], rowHeight,
                         Qt::AlignLeft | Qt::TextWordWrap,
                         model->headerData(col, Qt::Horizontal).toString());
        xPos += colWidths[col] + colSpacing;
    }
    yPos += rowHeight;

    // Draw data
    painter.setFont(QFont("Arial", 7)); // Smaller font
    for (int row = 0; row < rowCount; ++row) {
        xPos = 5;

        // New page if needed
        if (yPos + rowHeight > printer.pageLayout().paintRectPixels(printer.resolution()).height() - 10) {
            printer.newPage();
            yPos = 5;
        }

        for (int col = 0; col < colCount; ++col) {
            painter.drawText(xPos, yPos, colWidths[col], rowHeight,
                             Qt::AlignLeft | Qt::TextWordWrap,
                             model->data(model->index(row, col)).toString());
            xPos += colWidths[col] + colSpacing;
        }
        yPos += rowHeight;
    }

    painter.end();
    QMessageBox::information(this, "Success", "Table exported to PDF");
}
