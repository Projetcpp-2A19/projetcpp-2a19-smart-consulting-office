#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "projet.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QIntValidator>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->budgetLineEdit->setValidator(new QDoubleValidator(0, 999999, 2, this));  // Budget must be a positive number

    // Connect buttons to their respective slots
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()), Qt::UniqueConnection);
    connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tableView_clicked(QModelIndex)), Qt::UniqueConnection);
    connect(ui->modifyButton, SIGNAL(clicked()), this, SLOT(on_modifyButton_clicked()), Qt::UniqueConnection);
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(on_deleteButton_clicked()), Qt::UniqueConnection);

    // Load data into the table view when the program starts
    loadData();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked() {
    // Disable the button to avoid multiple clicks during the insertion process
    ui->addButton->setEnabled(false);

    // Validate project name
    QString nom = ui->nomLineEdit->text().trimmed();
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Error", "Project name cannot be empty.");
        ui->addButton->setEnabled(true);
        return;
    }

    // Validate description
    QString description = ui->descLineEdit->toPlainText().trimmed();
    if (description.isEmpty()) {
        QMessageBox::warning(this, "Error", "Description cannot be empty.");
        ui->addButton->setEnabled(true);
        return;
    }

    // Validate budget
    bool budgetValid = false;
    double budget = ui->budgetLineEdit->text().toDouble(&budgetValid);
    if (!budgetValid || budget <= 0) {
        QMessageBox::warning(this, "Error", "Budget must be a positive number.");
        ui->addButton->setEnabled(true);
        return;
    }

    // Get priority from the combo box
    int priorite = getPriorityValue(ui->prioriteComboBox->currentText());

    // Get dates from QDateEdit widgets
    QDate date_debut = ui->dateDebutEdit->date();
    QDate date_fin = ui->dateFinEdit->date();

    // Validate dates
    if (date_fin < date_debut) {
        QMessageBox::warning(this, "Error", "End date cannot be less than the start date.");
        ui->addButton->setEnabled(true);
        return;
    }

    // Create a Projet object with the collected data
    Projet p(nom, description, date_debut, date_fin, priorite, budget);

    // Insert the data into the database using the ajouter() method
    bool result = p.ajouter();

    // Re-enable the button after the operation
    ui->addButton->setEnabled(true);

    // Show the appropriate message box based on the result
    if (result) {
        QMessageBox::information(this, "Success", "Project added successfully!");
        loadData();  // Reload data after insertion to update the table view
    } else {
        QMessageBox::critical(this, "Error", "Failed to add project.");
    }
}

void MainWindow::loadData() {
    // Create an instance of the Projet class
    Projet p;

    // Fetch data using the afficher() method
    QSqlQueryModel *model = p.afficher();

    // Set the model to the table view
    ui->tableView->setModel(model);

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, tr("ID_PROJET"));
    model->setHeaderData(1, Qt::Horizontal, tr("NOM_PROJET"));
    model->setHeaderData(2, Qt::Horizontal, tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, tr("DATE_DEBUT"));
    model->setHeaderData(4, Qt::Horizontal, tr("DATE_FIN"));
    model->setHeaderData(5, Qt::Horizontal, tr("PRIORITE"));
    model->setHeaderData(6, Qt::Horizontal, tr("BUDGET"));

    ui->tableView->resizeColumnsToContents();  // Resize columns to fit content
}

void MainWindow::on_tableView_clicked(const QModelIndex &index) {
    if (!index.isValid()) return;

    // Get data from the selected row
    int id = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toInt();
    QString nom = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 1)).toString();
    QString description = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 2)).toString();
    QString date_debut = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 3)).toString();
    QString date_fin = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 4)).toString();
    int priorite = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 5)).toInt();
    double budget = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 6)).toDouble();

    // Convert date strings to QDate before setting them in the UI
    QDate debutDate = QDate::fromString(date_debut, "yyyy-MM-dd");
    QDate finDate = QDate::fromString(date_fin, "yyyy-MM-dd");

    // Populate the input fields
    ui->nomLineEdit->setText(nom);
    ui->descLineEdit->setPlainText(description);
    ui->dateDebutEdit->setDate(debutDate);
    ui->dateFinEdit->setDate(finDate);
    ui->prioriteComboBox->setCurrentText(getPriorityText(priorite));
    ui->budgetLineEdit->setText(QString::number(budget));

    // Store the original project ID in a hidden property
    ui->nomLineEdit->setProperty("originalId", id);
}


void MainWindow::on_modifyButton_clicked() {
    // Get the original project ID from the hidden property
    int id = ui->nomLineEdit->property("originalId").toInt();

    // Validate project name
    QString nom = ui->nomLineEdit->text().trimmed();
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Error", "Project name cannot be empty.");
        return;
    }

    // Check if a project with the same name already exists (excluding the current project)
    Projet p;
    if (p.nomExists(nom)) {
        // Fetch the name of the current project being modified
        QSqlQuery query;
        query.prepare("SELECT NOM_PROJET FROM PROJET WHERE ID_PROJET = :id");
        query.bindValue(":id", id);

        if (query.exec() && query.next()) {
            QString currentNom = query.value(0).toString();
            if (currentNom != nom) {
                QMessageBox::warning(this, "Error", "A project with the same name already exists.");
                return;
            }
        } else {
            qWarning() << "Failed to fetch current project name: " << query.lastError();
        }
    }

    // Validate description
    QString description = ui->descLineEdit->toPlainText().trimmed();
    if (description.isEmpty()) {
        QMessageBox::warning(this, "Error", "Description cannot be empty.");
        return;
    }

    // Validate budget
    bool budgetValid = false;
    double budget = ui->budgetLineEdit->text().toDouble(&budgetValid);
    if (!budgetValid || budget <= 0) {
        QMessageBox::warning(this, "Error", "Budget must be a positive number.");
        return;
    }

    // Get priority from the combo box and map it to the corresponding integer value
    QString priorityText = ui->prioriteComboBox->currentText();
    int priorite = getPriorityValue(priorityText);  // Use the helper function to map "Low"/"Medium"/"High" to 1/2/3

    // Get dates from QDateEdit widgets
    QDate date_debut = ui->dateDebutEdit->date();
    QDate date_fin = ui->dateFinEdit->date();

    // Validate dates
    if (date_fin < date_debut) {
        QMessageBox::warning(this, "Error", "End date cannot be less than the start date.");
        return;
    }

    // Create a Projet object with the updated data
    Projet projet(nom, description, date_debut, date_fin, priorite, budget);

    // Call a new method in the Projet class to update the project
    bool result = projet.modifier(id);

    // Show the appropriate message box based on the result
    if (result) {
        QMessageBox::information(this, "Success", "Project updated successfully!");
        loadData();  // Reload data after updating to refresh the table view
    } else {
        QMessageBox::critical(this, "Error", "Failed to update project.");
    }
}

void MainWindow::on_deleteButton_clicked() {
    // Get the selected project's ID from the hidden property
    int id = ui->nomLineEdit->property("originalId").toInt();

    // Ask for confirmation before deleting
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Project", "Are you sure you want to delete this project?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Create a Projet object and call a new method to delete the project
        Projet p;
        bool result = p.supprimer(id);

        // Show the appropriate message box based on the result
        if (result) {
            QMessageBox::information(this, "Success", "Project deleted successfully!");
            loadData();  // Reload data after deletion to refresh the table view
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete project.");
        }
    }
}

int MainWindow::getPriorityValue(const QString &priorityText) {
    if (priorityText == "Low") return 1;
    if (priorityText == "Medium") return 2;
    if (priorityText == "High") return 3;
    return 1; // Default to "Low" if no match
}

QString MainWindow::getPriorityText(int priorityValue) {
    switch (priorityValue) {
    case 1: return "Low";
    case 2: return "Medium";
    case 3: return "High";
    default: return "Low"; // Default to "Low" if no match
    }
}

