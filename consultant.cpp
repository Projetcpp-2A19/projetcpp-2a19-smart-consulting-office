#include "consultant.h"

Consultant::Consultant()
    : id_consultant(0), nom_consultant(""), prenom_consultant(""), telephone(""), date_ajout("") {}

Consultant::Consultant(int id, QString nom, QString prenom, QString telephone, QString dateAjout)
    : id_consultant(id), nom_consultant(nom), prenom_consultant(prenom), telephone(telephone), date_ajout(dateAjout) {}
int Consultant::getIdConsultant() const { return id_consultant; }
QString Consultant::getNomConsultant() const { return nom_consultant; }
QString Consultant::getPrenomConsultant() const { return prenom_consultant; }
QString Consultant::getTelephone() const { return telephone; }
QString Consultant::getDateAjout() const { return date_ajout; }

void Consultant::setIdConsultant(int id) { this->id_consultant = id; }
void Consultant::setNomConsultant(const QString &nom) { this->nom_consultant = nom; }
void Consultant::setPrenomConsultant(const QString &prenom) { this->prenom_consultant = prenom; }
void Consultant::setTelephone(const QString &telephone) { this->telephone = telephone; }
void Consultant::setDateAjout(const QString &dateAjout) { this->date_ajout = dateAjout; }
// Ajouter un consultant dans la base de données
bool Consultant::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO CONSULTANT (ID_CONSULTANT, NOM_CONSULTANT, PRENOM_CONSULTANT, TELEPHONE, DATE_AJOUT) "
                  "VALUES (:id, :nom, :prenom, :telephone, TO_DATE(:dateajout, 'YYYY-MM-DD'))");
    query.bindValue(":id", id_consultant);
    query.bindValue(":nom", nom_consultant);
    query.bindValue(":prenom", prenom_consultant);
    query.bindValue(":telephone", telephone);
    query.bindValue(":dateajout", date_ajout); // plus besoin de TO_DATE()

    if (!query.exec()) {
        qDebug() << "Échec de l'ajout du consultant :" << query.lastError().text();
        return false;
    }
    return true;
}


QSqlQueryModel* Consultant::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    if (!query.exec("SELECT * FROM CONSULTANT")) {
        qDebug() << "Erreur SQL lors de l'affichage :" << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Prénom");
    model->setHeaderData(3, Qt::Horizontal, "Téléphone");
    model->setHeaderData(4, Qt::Horizontal, "Date Ajout");

    return model;
}


// Supprimer un consultant
bool Consultant::supprimer(int id) {
    // D'abord récupérer les informations du consultant avant la suppression
    QSqlQuery selectQuery;
    selectQuery.prepare("SELECT * FROM CONSULTANT WHERE ID_CONSULTANT = :id");
    selectQuery.bindValue(":id", id);
    
    QString consultantInfo;
    if (selectQuery.exec() && selectQuery.next()) {
        consultantInfo = QString("%1;%2;%3;%4;%5;%6")
            .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
            .arg(selectQuery.value(0).toString()) // ID
            .arg(selectQuery.value(1).toString()) // Nom
            .arg(selectQuery.value(2).toString()) // Prénom
            .arg(selectQuery.value(3).toString()) // Téléphone
            .arg(selectQuery.value(4).toString()); // Date d'ajout
    }

    // Effectuer la suppression
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM CONSULTANT WHERE ID_CONSULTANT = :id");
    deleteQuery.bindValue(":id", id);
    
    if (deleteQuery.exec()) {
        // Si la suppression a réussi, enregistrer dans l'historique
        if (!consultantInfo.isEmpty()) {
            QFile file("historique_suppressions.txt");
            if (file.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream stream(&file);
                stream << consultantInfo << "\n";
                file.close();
            }
        }
        return true;
    }
    return false;
}

// Modifier un consultant
bool Consultant::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE CONSULTANT SET "
                 "NOM_CONSULTANT = :nom, "
                 "PRENOM_CONSULTANT = :prenom, "
                 "TELEPHONE = :telephone, "
                 "DATE_AJOUT = TO_DATE(:dateAjout, 'YYYY-MM-DD') "
                 "WHERE ID_CONSULTANT = :id");

    query.bindValue(":nom", nom_consultant);
    query.bindValue(":prenom", prenom_consultant);
    query.bindValue(":telephone", telephone);
    query.bindValue(":dateAjout", date_ajout);
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Échec de la modification du consultant :" << query.lastError().text();
        qDebug() << "ID:" << id;
        qDebug() << "Nom:" << nom_consultant;
        qDebug() << "Prénom:" << prenom_consultant;
        qDebug() << "Téléphone:" << telephone;
        qDebug() << "Date:" << date_ajout;
        return false;
    }
    
    // Vérifier si la modification a affecté une ligne
    if (query.numRowsAffected() == 0) {
        qDebug() << "Aucune ligne modifiée pour l'ID:" << id;
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

bool Consultant::restaurer(int id, const QString &nom, const QString &prenom, 
                         const QString &telephone, const QString &dateAjout) {
    qDebug() << "Tentative de restauration avec les données suivantes:";
    qDebug() << "ID:" << id;
    qDebug() << "Nom:" << nom;
    qDebug() << "Prénom:" << prenom;
    qDebug() << "Téléphone:" << telephone;
    qDebug() << "Date d'ajout reçue:" << dateAjout;

    // Vérifier d'abord si l'ID existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM CONSULTANT WHERE ID_CONSULTANT = :id");
    checkQuery.bindValue(":id", id);
    
    if (!checkQuery.exec()) {
        qDebug() << "Erreur lors de la vérification de l'ID:" << checkQuery.lastError().text();
        return false;
    }

    if (checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        qDebug() << "L'ID" << id << "existe déjà dans la base de données";
        return false;
    }

    // Si l'ID n'existe pas, procéder à la restauration
    QSqlQuery query;
    query.prepare("INSERT INTO CONSULTANT (ID_CONSULTANT, NOM_CONSULTANT, PRENOM_CONSULTANT, TELEPHONE, DATE_AJOUT) "
                  "SELECT :id, :nom, :prenom, :telephone, SYSDATE FROM DUAL");
    
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":telephone", telephone);

    if (!query.exec()) {
        qDebug() << "Échec de la restauration du consultant:";
        qDebug() << "Erreur SQL:" << query.lastError().text();
        qDebug() << "Requête:" << query.lastQuery();
        
        // Afficher les valeurs liées
        qDebug() << "Valeurs liées:";
        qDebug() << "ID =" << query.boundValue(":id").toString();
        qDebug() << "Nom =" << query.boundValue(":nom").toString();
        qDebug() << "Prénom =" << query.boundValue(":prenom").toString();
        qDebug() << "Téléphone =" << query.boundValue(":telephone").toString();
        
        return false;
    }

    qDebug() << "Restauration réussie!";
    return true;
}

bool Consultant::supprimerDeLhistorique(const QString &ligne) {
    QFile file("historique_suppressions.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        return false;
    }

    // Lire tout le fichier
    QTextStream in(&file);
    QString contenu = in.readAll();
    
    // Supprimer la ligne spécifiée
    QStringList lignes = contenu.split("\n");
    lignes.removeOne(ligne);
    
    // Réécrire le fichier
    file.resize(0);
    QTextStream out(&file);
    out << lignes.join("\n");
    file.close();
    
    return true;
}

