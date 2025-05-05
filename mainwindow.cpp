#include "mainwindow.h"
#include "ui_mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_currentClientId(-1)   // Pas de client sélectionné
    , m_editMode(false)
{
    ui->setupUi(this);

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
    serialbuffer="";
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

          }
    ///////////////////

}

MainWindow::~MainWindow()
{
    delete ui;
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
    ui->tabWidget->setCurrentIndex(2);

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
    QChartView *chartView = new QChartView(chart, ui->tabWidget->widget(2));
    chartView->setRenderHint(QPainter::Antialiasing);

    // 6) Ajuster la taille/position dans l’onglet (index 2)
    chartView->setGeometry(10, 10,
                           ui->tabWidget->widget(2)->width() - 20,
                           ui->tabWidget->widget(2)->height() - 20);

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
