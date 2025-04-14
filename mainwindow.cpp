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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    currentlySelectedRow(-1),
    ui(new Ui::MainWindow),
    employeModel(new QSqlQueryModel(this)),
    clientModel(new QSqlQueryModel(this)),
    trackingModel(new QSqlQueryModel(this)),
    chartView(nullptr),
    ganttScene(nullptr)
{
    ui->setupUi(this);
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
    model->setHeaderData(6, Qt::Horizontal, tr("Progress"));
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
    trackingTableView = new QTableView(this);
    trackingTableView->setObjectName("trackingTableView");
    trackingTableView->setModel(trackingModel);

    QVBoxLayout *trackingLayout = findChild<QVBoxLayout*>("verticalLayoutTracking");
    if (trackingLayout) {
        trackingLayout->addWidget(trackingTableView);
    } else {
        ui->verticalLayout->addWidget(trackingTableView);
        qWarning() << "Tracking layout not found, using main layout as fallback";
    }

    trackingTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    trackingTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    trackingTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    trackingTableView->setAlternatingRowColors(true);
    trackingTableView->setContextMenuPolicy(Qt::CustomContextMenu);

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

    if(query.exec()) {
        trackingModel->setQuery(query);

        trackingModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
        trackingModel->setHeaderData(1, Qt::Horizontal, tr("Project Name"));
        trackingModel->setHeaderData(2, Qt::Horizontal, tr("Start Date"));
        trackingModel->setHeaderData(3, Qt::Horizontal, tr("End Date"));
        trackingModel->setHeaderData(4, Qt::Horizontal, tr("Status"));
        trackingModel->setHeaderData(5, Qt::Horizontal, tr("Priority"));
        trackingModel->setHeaderData(6, Qt::Horizontal, tr("Progress"));

        trackingTableView->setColumnHidden(0, true);
        trackingTableView->setColumnWidth(1, 250);
        trackingTableView->setColumnWidth(2, 100);
        trackingTableView->setColumnWidth(3, 100);
        trackingTableView->setColumnWidth(4, 120);
        trackingTableView->setColumnWidth(5, 80);
        trackingTableView->setColumnWidth(6, 100);

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
    QModelIndex index = trackingTableView->indexAt(pos);
    if(!index.isValid()) return;

    currentlySelectedRow = index.row();
    QString status = trackingModel->data(trackingModel->index(currentlySelectedRow, 4)).toString();
    int currentProgress = trackingModel->data(trackingModel->index(currentlySelectedRow, 6)).toInt();
    int projectId = trackingModel->data(trackingModel->index(currentlySelectedRow, 0)).toInt();

    QMenu menu(this);

    if(status.contains("In Progress", Qt::CaseInsensitive)) {
        QWidget *progressWidget = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(progressWidget);

        QLabel *progressLabel = new QLabel("Set Progress:");
        progressLabel->setAlignment(Qt::AlignCenter);

        QSlider *progressSlider = new QSlider(Qt::Horizontal);
        progressSlider->setRange(0, 100);
        progressSlider->setValue(currentProgress);

        QLabel *valueLabel = new QLabel(QString("%1%").arg(currentProgress));
        valueLabel->setAlignment(Qt::AlignCenter);

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
    ganttScene = new QGraphicsScene(this);
    ui->ganttGraphicsView_2->setScene(ganttScene);
    ui->ganttGraphicsView_2->setRenderHint(QPainter::Antialiasing);
    ui->ganttGraphicsView_2->setBackgroundBrush(QColor(245, 245, 245));
    ganttScene->setSceneRect(-300, 0, 2500, 800);
}

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
