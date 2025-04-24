#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include "consultant.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sarah = new SmsSender(this);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
    }

    // Initialisation correcte du modèle de table
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
}

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


