#include "projet.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDate>

Projet::Projet() {}

Projet::Projet(QString nom, QString desc, QDate debut, QDate fin, int prio, double bud)
    : nom_projet(nom), description(desc), date_debut(debut), date_fin(fin), priorite(prio), budget(bud)
{
}

bool Projet::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO PROJET (NOM_PROJET, DESCRIPTION, DATE_DEBUT, DATE_FIN, PRIORITE, BUDGET) "
                  "VALUES (:nom, :description, :date_debut, :date_fin, :priorite, :budget)");

    query.bindValue(":nom", nom_projet);
    query.bindValue(":description", description);
    query.bindValue(":date_debut", date_debut);  // Bind QDate directly
    query.bindValue(":date_fin", date_fin);      // Bind QDate directly
    query.bindValue(":priorite", priorite);
    query.bindValue(":budget", budget);

    if (query.exec()) {
        return true;  // Successfully added the project
    } else {
        qWarning() << "Insert failed: " << query.lastError();
        return false;  // Failed to insert the project
    }
}

QSqlQueryModel* Projet::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();

    // Query to select all projects from the database
    QSqlQuery query;
    query.prepare("SELECT * FROM PROJET");

    // Execute the query
    if (query.exec()) {
        // Set the query to the model
        model->setQuery(query);
    } else {
        qWarning() << "Failed to fetch data: " << query.lastError();
    }

    return model;  // Return the model containing the project data
}

bool Projet::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE PROJET SET NOM_PROJET = :nom, DESCRIPTION = :description, DATE_DEBUT = :date_debut, "
                  "DATE_FIN = :date_fin, PRIORITE = :priorite, BUDGET = :budget WHERE ID_PROJET = :id");

    query.bindValue(":nom", nom_projet);
    query.bindValue(":description", description);
    query.bindValue(":date_debut", date_debut);  // Bind QDate directly
    query.bindValue(":date_fin", date_fin);      // Bind QDate directly
    query.bindValue(":priorite", priorite);
    query.bindValue(":budget", budget);
    query.bindValue(":id", id);

    if (query.exec()) {
        return true;  // Successfully updated the project
    } else {
        qWarning() << "Update failed: " << query.lastError();
        return false;  // Failed to update the project
    }
}

bool Projet::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM PROJET WHERE ID_PROJET = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        return true;  // Successfully deleted the project
    } else {
        qWarning() << "Delete failed: " << query.lastError();
        return false;  // Failed to delete the project
    }
}

bool Projet::nomExists(const QString &nom) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM PROJET WHERE NOM_PROJET = :nom");
    query.bindValue(":nom", nom);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return (count > 0);  // Return true if a project with the same name exists
    } else {
        qWarning() << "Failed to check for duplicate name: " << query.lastError();
        return false;
    }
}
