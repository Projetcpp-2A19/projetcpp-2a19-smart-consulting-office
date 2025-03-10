#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox> // Ajout de l'en-tête pour les fenêtres popup

bool connecterBaseDeDonnees(QSqlDatabase& db);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Début du programme...";

    // Créer l'objet de connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    // Appeler la fonction de connexion
    if (!connecterBaseDeDonnees(db)) {
        // Si la connexion échoue, afficher un message d'erreur
        QMessageBox::critical(nullptr, "Erreur de connexion", "Échec de la connexion à la base de données !");
        return -1; // Erreur de connexion
    }

    // Si la connexion réussit, afficher un message de succès
    QMessageBox::information(nullptr, "Connexion réussie", "Connexion réussie à la base de données.");
    MainWindow w;
    w.show();
    return a.exec();
}
