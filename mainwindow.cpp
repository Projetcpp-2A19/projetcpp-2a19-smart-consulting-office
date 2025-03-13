#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include "employe.h"






Employe employe;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableViewEmploye->setModel(employe.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_add_button_clicked()
{

    // Récupérer les valeurs des champs de l'interface utilisateur
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    QString adresse = ui->lineEdit_Adresse->text().trimmed();
    QString email = ui->lineEdit_email->text().trimmed();
    QString motDePasse = ui->lineEdit_mdp->text().trimmed();
    QString specialite = ui->lineEdit_specialite->text().trimmed();
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

        // Effacer les champs après ajout
        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->lineEdit_Adresse->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_mdp->clear();
        ui->lineEdit_specialite->clear();
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
    QString specialite = ui->lineEdit_specialite->text();
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

        // Effacer les champs après modification
        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->lineEdit_Adresse->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_mdp->clear();
        ui->lineEdit_specialite->clear();
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

}


void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{

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
    QString motDePasse = ui->tableViewEmploye->model()->data(ui->tableViewEmploye->model()->index(row, 5)).toString(); // Mot de passe
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
    ui->lineEdit_specialite->setText(specialite);
    ui->lineEdit_statut->setText(statut);
    ui->dateEdit_embauche->setDate(dateEmbauche);
}

