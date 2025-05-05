#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableViewEmploye->setModel(employe.afficher());
    initializeSpecialityComboBox();
    displaySpecialiteStats();
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    //Arduino=====INPUT + OUTPUT============================================
    Atimer = new QTimer(this);
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
    Atimer->setInterval(3000);
    //=========================================================================================

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeSpecialityComboBox()
{
    // Clear existing items
    ui->comboBox_specialite->clear();

    // Add IT specialities
    ui->comboBox_specialite->addItem("Frontend Development");
    ui->comboBox_specialite->addItem("Backend Development");
    ui->comboBox_specialite->addItem("Mobile Development");
    ui->comboBox_specialite->addItem("DevOps & Cloud");

    // Add Business specialities
    ui->comboBox_specialite->addItem("Project Management");
    ui->comboBox_specialite->addItem("Business Analysis");
    ui->comboBox_specialite->addItem("Digital Marketing");

    // Set default selection
    ui->comboBox_specialite->setCurrentIndex(0);
}




void MainWindow::on_add_button_clicked()
{

    // Récupérer les valeurs des champs de l'interface utilisateur
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    QString adresse = ui->lineEdit_Adresse->text().trimmed();
    QString email = ui->lineEdit_email->text().trimmed();
    QString motDePasse = ui->lineEdit_mdp->text().trimmed();
    QString specialite = ui->comboBox_specialite->currentText(); // Changed from lineEdit to comboBox
    QString statut = ui->lineEdit_statut->text().trimmed();
    QDate dateEmbauche = ui->dateEdit_embauche->date();

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

        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->lineEdit_Adresse->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_mdp->clear();
        ui->comboBox_specialite->setCurrentIndex(0); // Reset combo box
        ui->lineEdit_statut->clear();
        ui->dateEdit_embauche->setDate(QDate::currentDate());

        // Mettre à jour l'affichage des employés dans le tableViewEmploye
        ui->tableViewEmploye->setModel(employe.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors de l'ajout de l'employé.");
    }
}


void MainWindow::on_modifStadeButton_clicked()
{
    bool ok;
    int id = ui->idEmploye->text().toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::critical(this, "Erreur", "ID de l'employé invalide.");
        return;
    }

    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString adresse = ui->lineEdit_Adresse->text();
    QString email = ui->lineEdit_email->text();
    QString motDePasse = ui->lineEdit_mdp->text();
    QString specialite = ui->comboBox_specialite->currentText(); // Changed from lineEdit to comboBox
    QString statut = ui->lineEdit_statut->text();
    QDate dateEmbauche = ui->dateEdit_embauche->date();

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
        ui->tableViewEmploye->setModel(employe.afficher());
        displaySpecialiteStats();

        // Effacer les champs après modification
        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->lineEdit_Adresse->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_mdp->clear();
        ui->comboBox_specialite->setCurrentIndex(0); // Reset combo box
        ui->lineEdit_statut->clear();
        ui->dateEdit_embauche->setDate(QDate::currentDate());

        QMessageBox::information(this, "Modification réussie", "Employé modifié avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors de la modification de l'employé.");
    }
}


void MainWindow::on_DeleteStadeButton_clicked()
{
    // Check if at least one row is selected
    QModelIndexList selectedIndexes = ui->tableViewEmploye->selectionModel()->selectedIndexes();

    if (!selectedIndexes.isEmpty()) {
        // Get the ID from the selected row
        int id = selectedIndexes.at(0).sibling(selectedIndexes.at(0).row(), 0).data().toInt();

        // Call the delete function
        bool supprime = employe.supprimer(id);

        if (supprime) {
            displaySpecialiteStats();
            // Refresh the table view
            ui->tableViewEmploye->setModel(employe.afficher());
            QMessageBox::information(this, "Suppression réussie", "Employé supprimé avec succès.");
        } else {
            QMessageBox::warning(this, "Échec de la suppression", "Échec de la suppression de l'employé.");
        }
    } else {
        QMessageBox::warning(this, "Aucun employé sélectionné", "Veuillez sélectionner un employé à supprimer.");
    }
}





void MainWindow::on_trier_Button_clicked()
{
    QString champ = "";
    // Determine which field to sort by based on first combo box
    if (ui->comboBoxsortchamp->currentText().compare("Nom", Qt::CaseInsensitive) == 0) {
        champ = "nom";
    } else if (ui->comboBoxsortchamp->currentText().compare("Date d'embauche", Qt::CaseInsensitive) == 0) {
        champ = "date_embauche";
    } else {
        // Default to sorting by ID if nothing is selected
        champ = "nom";
    }

    QString order = "asc";  // Default sort order
    // Update the sort order based on the second combo box selection
    if (ui->comboBox_order->currentText().compare("Descendant", Qt::CaseInsensitive) == 0) {
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
    ui->tableViewEmploye->setModel(employe.Tri(order, champ));
}


void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    Employe e;
    QSqlQueryModel* model = e.rechercherParNom(arg1);
    ui->tableViewEmploye->setModel(model);
}


void MainWindow::on_tableViewEmploye_doubleClicked(const QModelIndex &index)
{
    int row = index.row();

    // Récupérer les données de la ligne sélectionnée

    int id = ui->tableViewEmploye->model()->data(ui->tableViewEmploye->model()->index(row, 0)).toInt();
    QString nom = ui->tableViewEmploye->model()->data(ui->tableViewEmploye->model()->index(row, 1)).toString();
    QString prenom = ui->tableViewEmploye->model()->data(ui->tableViewEmploye->model()->index(row, 2)).toString();
    QString adresse = ui->tableViewEmploye->model()->data(ui->tableViewEmploye->model()->index(row, 3)).toString();
    QString email = ui->tableViewEmploye->model()->data(ui->tableViewEmploye->model()->index(row, 4)).toString();
    QString motDePasse = ui->tableViewEmploye->model()->data(ui->tableViewEmploye->model()->index(row, 5)).toString();
    QString specialite = ui->tableViewEmploye->model()->data(ui->tableViewEmploye->model()->index(row, 6)).toString();
    QString statut = ui->tableViewEmploye->model()->data(ui->tableViewEmploye->model()->index(row, 7)).toString();
    QDate dateEmbauche = ui->tableViewEmploye->model()->data(ui->tableViewEmploye->model()->index(row, 8)).toDate();

    // Définir les données dans les éléments UI respectifs
    ui->idEmploye->setText(QString::number(id));
    ui->lineEdit_nom->setText(nom);
    ui->lineEdit_prenom->setText(prenom);
    ui->lineEdit_Adresse->setText(adresse);
    ui->lineEdit_email->setText(email);
    ui->lineEdit_mdp->setText(motDePasse); // Mot de passe
    // Set the speciality in the combo box
    int specialityIndex = ui->comboBox_specialite->findText(specialite);
    if (specialityIndex >= 0) {
        ui->comboBox_specialite->setCurrentIndex(specialityIndex);
    } else {
        ui->comboBox_specialite->setCurrentIndex(0);
    }
    ui->lineEdit_statut->setText(statut);
    ui->dateEdit_embauche->setDate(dateEmbauche);
}


void MainWindow::on_pushButton_clicked()
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
    QAbstractItemModel* model = ui->tableViewEmploye->model(); // Make sure to use your actual tableView name
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

void MainWindow::displaySpecialiteStats() {
    // Create an instance of Employe class
    Employe e;

    // Get the count of employees by speciality
    QMap<QString, int> specialiteCounts = e.getEmployeeCountBySpecialite();

    // Clear any existing layout in the frame
    QLayout* oldLayout = ui->frame->layout();
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
    QVBoxLayout* frameLayout = new QVBoxLayout(ui->frame);
    ui->frame->setLayout(frameLayout);

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
    ui->frame->update();
}


void MainWindow::on_pushButton_2_clicked()
{
    QString email = ui->lineEdit_email_2->text();
    QString password = ui->lineEdit_password->text();

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
        ui->stackedWidget->setCurrentIndex(0);

        // Clear the password field for security
        ui->lineEdit_password->clear();


    } else {
        // Login failed
        QMessageBox::critical(this, "Login Failed", "Invalid email or password. Please try again.");
        ui->lineEdit_password->clear();
        ui->lineEdit_password->setFocus();
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

void MainWindow::on_pushButton_3_clicked()
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



