#include "employe.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

// Constructors
Employe::Employe() {}

Employe::Employe(int id_employe, QString nom, QString prenom, QString adresse, QString email, QString mot_de_passe, QString specialite, QString statut, QDate date_embauche)
    : id_employe(id_employe), nom(nom), prenom(prenom), adresse(adresse), email(email), mot_de_passe(mot_de_passe), specialite(specialite), statut(statut), date_embauche(date_embauche) {}

Employe::Employe(QString nom, QString prenom, QString adresse, QString email, QString mot_de_passe, QString specialite, QString statut, QDate date_embauche)
    : nom(nom), prenom(prenom), adresse(adresse), email(email), mot_de_passe(mot_de_passe), specialite(specialite), statut(statut), date_embauche(date_embauche) {}

// Getters
int Employe::getIDEmploye() const {
    return id_employe;
}

QString Employe::getNom() const {
    return nom;
}

QString Employe::getPrenom() const {
    return prenom;
}

QString Employe::getAdresse() const {
    return adresse;
}

QString Employe::getEmail() const {
    return email;
}

QString Employe::getMotDePasse() const {
    return mot_de_passe;
}

QString Employe::getSpecialite() const {
    return specialite;
}

QString Employe::getStatut() const {
    return statut;
}

QDate Employe::getDateEmbauche() const {
    return date_embauche;
}

// Setters
void Employe::setIDEmploye(int id_employe) {
    this->id_employe = id_employe;
}

void Employe::setNom(QString nom) {
    this->nom = nom;
}

void Employe::setPrenom(QString prenom) {
    this->prenom = prenom;
}

void Employe::setAdresse(QString adresse) {
    this->adresse = adresse;
}

void Employe::setEmail(QString email) {
    this->email = email;
}

void Employe::setMotDePasse(QString mot_de_passe) {
    this->mot_de_passe = mot_de_passe;
}

void Employe::setSpecialite(QString specialite) {
    this->specialite = specialite;
}

void Employe::setStatut(QString statut) {
    this->statut = statut;
}

void Employe::setDateEmbauche(QDate date_embauche) {
    this->date_embauche = date_embauche;
}

// Database operations
bool Employe::ajouter() {
    QSqlQuery query;

    query.prepare("INSERT INTO employe (nom, prenom, adresse, email, mot_de_passe, specialite, statut, date_embauche) "
                  "VALUES (:nom, :prenom, :adresse, :email, :mot_de_passe, :specialite, :statut, :date_embauche)");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":mot_de_passe", mot_de_passe);
    query.bindValue(":specialite", specialite);
    query.bindValue(":statut", statut);
    query.bindValue(":date_embauche", date_embauche);

    return query.exec();
}

QSqlQueryModel* Employe::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id_employe AS id, nom, prenom, adresse, email, mot_de_passe, specialite, statut, date_embauche FROM employe ORDER BY id_employe");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mot de Passe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Spécialité"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Date d'Embauche"));
    return model;
}

bool Employe::supprimer(int id_employe) {
    QSqlQuery query;
    query.prepare("DELETE FROM employe WHERE id_employe = :id");
    query.bindValue(":id", id_employe);
    return query.exec();
}

bool Employe::modifier(int id_employe) {
    QSqlQuery query;

    query.prepare("UPDATE employe SET nom = :nom, prenom = :prenom, adresse = :adresse, "
                  "email = :email, mot_de_passe = :mot_de_passe, specialite = :specialite, "
                  "statut = :statut, date_embauche = :date_embauche WHERE id_employe = :id");
    query.bindValue(":id", id_employe);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":mot_de_passe", mot_de_passe);
    query.bindValue(":specialite", specialite);
    query.bindValue(":statut", statut);
    query.bindValue(":date_embauche", date_embauche);

    return query.exec();
}

QSqlQueryModel* Employe::rechercherParNom(QString terme) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Prepare the query to search by employee name
    query.prepare("SELECT id_employe AS id, nom, prenom, adresse, email, specialite, statut, date_embauche FROM employe WHERE nom LIKE :terme OR prenom LIKE :terme");
    query.bindValue(":terme", "%" + terme + "%");

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Failed to execute search query:" << query.lastError().text();
    }

    return model;
}

QSqlQueryModel* Employe::Tri(QString cls, QString champ) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryString = "SELECT * FROM employe ORDER BY " + champ + " " + cls;
    QSqlQuery query;
    query.prepare(queryString);
    query.exec();
    model->setQuery(query);

    // Set column headers for the employe table
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMPLOYE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mot de Passe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Spécialité"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Date d'Embauche"));

    return model;
}
