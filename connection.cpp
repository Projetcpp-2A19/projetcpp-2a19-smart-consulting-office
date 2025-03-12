#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection() {
    db = QSqlDatabase::addDatabase("QODBC");  // Pas besoin d'un nom de connexion personnalisé ici
}

bool Connection::createconnect() {
    // Vérifier si la connexion existe avant de la recréer
    if (db.isOpen()) {
        qDebug() << "La base de données est déjà connectée.";
        return true;
    }

    db.setDatabaseName("source_Projet1A");
    db.setUserName("sarah");
    db.setPassword("esprit123");


    if (!db.open()) {
        qDebug() << "Échec de la connexion à la base de données :" << db.lastError().text();
        return false;
    }

    qDebug() << "Connexion à la base de données réussie !";
    return true;
}

QString Connection::getLastError() const {
    return db.lastError().text();
}
