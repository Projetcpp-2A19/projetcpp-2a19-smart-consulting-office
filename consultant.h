#ifndef CONSULTANT_H
#define CONSULTANT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class Consultant {
private:
    int id_consultant;
    QString nom_consultant;
    QString prenom_consultant;
    QString telephone;
    QString date_ajout;

public:
    Consultant();
    Consultant(int id, QString nom, QString prenom, QString telephone, QString dateAjout);

    int getIdConsultant() const;
    QString getNomConsultant() const;
    QString getPrenomConsultant() const;
    QString getTelephone() const;
    QString getDateAjout() const;

    void setIdConsultant(int id);
    void setNomConsultant(const QString &nom);
    void setPrenomConsultant(const QString &prenom);
    void setTelephone(const QString &telephone);
    void setDateAjout(const QString &dateAjout);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier(int id);
    QSqlQueryModel* rechercher(const QString& searchTerm);
    static bool restaurer(int id, const QString &nom, const QString &prenom, 
                         const QString &telephone, const QString &dateAjout);
    static bool supprimerDeLhistorique(const QString &ligne);
};

#endif // CONSULTANT_H
