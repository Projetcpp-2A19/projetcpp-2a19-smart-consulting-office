#include "client.h"
#include <qsqlerror.h>
#include <qsqlquery.h>
#include <qsqlquerymodel.h>

Client::Client(int idClient, const QString &nom, const QString &prenom,const QString &email,const QString &cin, const QString &adresse, const QString &typeClient, const QString &numeroTelephone)
    : idClient(idClient), nom(nom), prenom(prenom),email(email),cin(cin), adresse(adresse), typeClient(typeClient), numeroTelephone(numeroTelephone) {}
Client::Client(const QString &nom, const QString &prenom,const QString &email,const QString &cin, const QString &adresse, const QString &typeClient, const QString &numeroTelephone)
    : nom(nom), prenom(prenom), email(email) ,cin(cin) , adresse(adresse), typeClient(typeClient), numeroTelephone(numeroTelephone) {}

Client::Client() {}
int Client::getIdClient() const {
    return idClient;
}

QString Client::getNom() const {
    return nom;
}

QString Client::getPrenom() const {
    return prenom;
}

QString Client::getEmail() const {
    return email;
}

QString Client::getCin() const {
    return cin;
}


QString Client::getAdresse() const {
    return adresse;
}

QString Client::getTypeClient() const {
    return typeClient;
}

QString Client::getNumeroTelephone() const {
    return numeroTelephone;
}

void Client::setIdClient(int idClient) {
    this->idClient = idClient;
}

void Client::setNom(const QString &nom) {
    this->nom = nom;
}

void Client::setPrenom(const QString &prenom) {
    this->prenom = prenom;
}
void Client::setEmail(const QString &cin) {
    this->cin = cin;
}
void Client::setCin(const QString &prenom) {
    this->prenom = prenom;
}

void Client::setAdresse(const QString &adresse) {
    this->adresse = adresse;
}

void Client::setTypeClient(const QString &typeClient) {
    this->typeClient = typeClient;
}

void Client::setNumeroTelephone(const QString &numeroTelephone) {
    this->numeroTelephone = numeroTelephone;
}
bool Client::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO Clients (nom, prenom, email, cin, adresse, typeClient, numeroTelephone) "
                  "VALUES (:nom, :prenom, :email, :cin, :adresse, :typeClient, :numeroTelephone)");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":cin", cin);
    query.bindValue(":adresse", adresse);
    query.bindValue(":typeClient", typeClient);
    query.bindValue(":numeroTelephone", numeroTelephone);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de l'ajout du client :" << query.lastError().text();
        return false;
    }
}

// --- supprimer(int) ---
bool Client::supprimer(int idClient)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Clients WHERE idClient = :idClient");
    query.bindValue(":idClient", idClient);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression du client :" << query.lastError().text();
        return false;
    }
}

// --- modifier(int, ...) ---
bool Client::modifier(int idClient, const QString &nom, const QString &prenom, const QString &email, const QString &cin,
                      const QString &adresse, const QString &typeClient, const QString &numeroTelephone)
{
    QSqlQuery query;
    query.prepare("UPDATE Clients "
                  "SET nom = :nom, prenom = :prenom, email = :email, cin = :cin, adresse = :adresse, "
                  "    typeClient = :typeClient, numeroTelephone = :numeroTelephone "
                  "WHERE idClient = :idClient");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":cin", cin);
    query.bindValue(":adresse", adresse);
    query.bindValue(":typeClient", typeClient);
    query.bindValue(":numeroTelephone", numeroTelephone);
    query.bindValue(":idClient", idClient);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de la modification du client :" << query.lastError().text();
        return false;
    }
}

// --- afficher() ---
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Inclure l'idClient pour pouvoir supprimer/modifier
    model->setQuery("SELECT idClient, nom, prenom, email, cin, adresse, typeClient, numeroTelephone FROM Clients");

    // Pour debug
    qDebug() << "Nombre de lignes récupérées :" << model->rowCount();

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Téléphone"));

    return model;
}

QSqlQueryModel* Client::rechercherEmail(const QString &email)
{
    // On filtre sur la colonne email avec un LIKE
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT idClient, nom, prenom, email, cin, adresse, typeClient, numeroTelephone "
                  "FROM Clients "
                  "WHERE email LIKE :email");
    query.bindValue(":email", "%" + email + "%");
    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche par email :" << query.lastError().text();
    }
    model->setQuery(query);

    // Redéfinir les en-têtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Téléphone"));

    return model;
}

QSqlQueryModel* Client::trierParNom(bool ascending)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString ordre = ascending ? "ASC" : "DESC";

    model->setQuery("SELECT idClient, nom, prenom, email, cin, adresse, typeClient, numeroTelephone "
                    "FROM Clients "
                    "ORDER BY nom " + ordre);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Téléphone"));

    return model;
}

QSqlQueryModel* Client::trierParCin(bool ascending)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString ordre = ascending ? "ASC" : "DESC";

    model->setQuery("SELECT idClient, nom, prenom, email, cin, adresse, typeClient, numeroTelephone "
                    "FROM Clients "
                    "ORDER BY cin " + ordre);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Téléphone"));

    return model;
}

int Client::countByType(const QString &type)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Clients WHERE typeClient = :type");
    query.bindValue(":type", type);
    if (!query.exec()) {
        qDebug() << "Erreur countByType :" << query.lastError().text();
        return 0;
    }
    int count = 0;
    if (query.next()) {
        count = query.value(0).toInt();
    }
    return count;
}
