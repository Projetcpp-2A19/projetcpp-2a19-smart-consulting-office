#include "consultant.h"

// Constructeur par défaut
Consultant::Consultant()
    : id_consultant(0), nom_consultant(""), prenom_consultant(""), telephone("") {}

// Constructeur paramétré
Consultant::Consultant(int id, QString nom, QString prenom, QString telephone)
    : id_consultant(id), nom_consultant(nom), prenom_consultant(prenom), telephone(telephone) {}

// Ajouter un consultant dans la base de données
bool Consultant::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO CONSULTANT (ID_CONSULTANT, NOM_CONSULTANT, PRENOM_CONSULTANT, TELEPHONE) "
                  "VALUES (:id, :nom, :prenom, :telephone)");
    query.bindValue(":id", id_consultant);
    query.bindValue(":nom", nom_consultant);
    query.bindValue(":prenom", prenom_consultant);
    query.bindValue(":telephone", telephone);

    if (!query.exec()) {
        qDebug() << "Échec de l'ajout du consultant :" << query.lastError().text();
        return false;
    }
    return true;
}

// Afficher tous les consultants
QSqlQueryModel* Consultant::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    if (!query.exec("SELECT * FROM CONSULTANT")) {
        qDebug() << "Erreur SQL lors de l'affichage :" << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(query);

    if (model->rowCount() == 0) {
        qDebug() << "Aucune donnée trouvée dans la table CONSULTANT.";
    }

    model->setHeaderData(0, Qt::Horizontal, "ID Consultant");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Prénom");
    model->setHeaderData(3, Qt::Horizontal, "Téléphone");

    return model;
}

// Supprimer un consultant
bool Consultant::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM CONSULTANT WHERE ID_CONSULTANT = :id");
    query.bindValue(":id", id);
    return query.exec();
}

// Modifier un consultant
bool Consultant::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE CONSULTANT SET NOM_CONSULTANT = :nom, PRENOM_CONSULTANT = :prenom, TELEPHONE = :telephone "
                  "WHERE ID_CONSULTANT = :id");
    query.bindValue(":nom", nom_consultant);
    query.bindValue(":prenom", prenom_consultant);
    query.bindValue(":telephone", telephone);
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Échec de la modification du consultant :" << query.lastError().text();
        return false;
    }
    return true;
}

// Rechercher un consultant
QSqlQueryModel* Consultant::rechercher(const QString& searchTerm) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    bool isNumber;
    int id = searchTerm.toInt(&isNumber);
    if (isNumber) {
        query.prepare("SELECT * FROM CONSULTANT WHERE ID_CONSULTANT = :id");
        query.bindValue(":id", id);
    } else {
        query.prepare("SELECT * FROM CONSULTANT WHERE LOWER(NOM_CONSULTANT) LIKE LOWER(:nom) "
                      "OR LOWER(PRENOM_CONSULTANT) LIKE LOWER(:prenom)");
        query.bindValue(":nom", "%" + searchTerm + "%");
        query.bindValue(":prenom", "%" + searchTerm + "%");
    }

    if (!query.exec()) {
        qDebug() << "Échec de la recherche :" << query.lastError().text();
    } else {
        model->setQuery(query);
    }

    return model;
}

