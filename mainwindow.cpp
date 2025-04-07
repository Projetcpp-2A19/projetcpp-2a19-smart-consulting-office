#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include "consultant.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Consultant c;
    consultantProxyModel=new QSortFilterProxyModel(this);
    consultantProxyModel->setSourceModel(ui->consultantTable->model());
    ui->consultantTable->setModel(consultantProxyModel);





    consultantModel = c.afficher();  // Utiliser la méthode afficher()
    ui->consultantTable->setModel(consultantModel);
    initializeConsultantTableModel();
    connect(ui->chercherconsultqntlineedit,&QLineEdit::textChanged,this,&MainWindow::on_searchConsultantByTyping);
    ui->staticWidget->hide();
    ui->hidepushbutton->hide();



}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::on_QJOUTERCONSULTQNTBUTTON_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_Nom->text();
    QString prenom = ui->lineEdit_Prenom->text();
    QString telephone = ui->lineEdit_Telephone->text();
    QString dateAjout = ui->dateAjoutLineEdit->date().toString("yyyy-MM-dd");

    Consultant c(id, nom, prenom, telephone, dateAjout);

    if (c.ajouter()) {
        QMessageBox::information(this, "Succès", "Consultant ajouté avec succès !");
        consultantTableModel->select(); // refresh
        consultantProxyModel->sort(0, Qt::AscendingOrder);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du consultant.");
    }
}


void MainWindow::on_supprierconsultqntpushbutton_clicked()
{
    int id = ui->chercherconsultqntlineedit->text().toInt();

    Consultant c;
    if (c.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Consultant supprimé avec succès !");
        consultantTableModel->select(); // <-- refresh data
        consultantProxyModel->sort(0, Qt::AscendingOrder);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du consultant.");
    }
}
void MainWindow::initializeConsultantTableModel() {
    // Create and configure the QSqlTableModel
   consultantTableModel = new QSqlTableModel(this);
   consultantTableModel->setTable("CONSULTANT"); // Set the table name
    consultantTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit); // Manual edit strategy
    consultantTableModel->select(); // Load data from the database

    // Create and configure the QSortFilterProxyModel
    consultantProxyModel = new QSortFilterProxyModel(this);
    consultantProxyModel->setSourceModel(consultantTableModel);
    consultantProxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive); // Case insensitive filtering
    consultantProxyModel->setFilterKeyColumn(-1); // Filter on all columns

    // Set the proxy model on the table
    ui->consultantTable->setModel(consultantProxyModel);
    ui->consultantTable->setSortingEnabled(true); // Enable sorting
}




void MainWindow::on_odifyconsultant_clicked() {
    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_Nom->text();
    QString prenom = ui->lineEdit_Prenom->text();
    QString telephone = ui->lineEdit_Telephone->text();
    QString dateAjout = ui->dateAjoutLineEdit->date().toString("yyyy-MM-dd");


    // Création avec la date ajoutée
    Consultant c(id, nom, prenom, telephone, dateAjout);

    if (c.modifier(id)) {
        QMessageBox::information(this, "Succès", "Consultant modifié avec succès !");
        ui->consultantTable->setModel(c.afficher());  // Rafraîchir
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du consultant.");
    }
}



void MainWindow::on_consultantTable_clicked(const QModelIndex &index)
{

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

    // Afficher dans staticWidget (assure-toi qu’il a un layout vide)
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

