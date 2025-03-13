#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDate>

class Employe {
public:
    Employe();
    Employe(int id_employe, QString nom, QString prenom, QString adresse, QString email, QString mot_de_passe, QString specialite, QString statut, QDate date_embauche);
    Employe(QString nom, QString prenom, QString adresse, QString email, QString mot_de_passe, QString specialite, QString statut, QDate date_embauche);

    // Getter methods
    int getIDEmploye() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getAdresse() const;
    QString getEmail() const;
    QString getMotDePasse() const;
    QString getSpecialite() const;
    QString getStatut() const;
    QDate getDateEmbauche() const;

    // Setter methods
    void setIDEmploye(int id_employe);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setAdresse(QString adresse);
    void setEmail(QString email);
    void setMotDePasse(QString mot_de_passe);
    void setSpecialite(QString specialite);
    void setStatut(QString statut);
    void setDateEmbauche(QDate date_embauche);

    // Database operations
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id_employe);
    bool modifier(int id_employe);
    static QSqlQueryModel* rechercherParNom(QString nom);
    QSqlQueryModel* Tri(QString cls, QString champ);

private:
    int id_employe;
    QString nom;
    QString prenom;
    QString adresse;
    QString email;
    QString mot_de_passe;
    QString specialite;
    QString statut;
    QDate date_embauche;
};

#endif // EMPLOYE_H
