#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

bool connecterBaseDeDonnees(QSqlDatabase& db) {
    // Configurer les paramètres de la base de données
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("amensa");
    db.setPassword("admin");

    // Vérifier la connexion
    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données : " << db.lastError().text();
        return false;
    }

    qDebug() << "Connexion réussie !";
    return true;
}
