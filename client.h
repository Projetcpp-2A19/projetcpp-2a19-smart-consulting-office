#ifndef CLIENT_H
#define CLIENT_H
#include <QSqlQueryModel>
#include <QString>

class Client {
public:
    Client(int idClient, const QString &nom, const QString &prenom, const QString &email, const QString &cin,const QString &adresse,const QString &typeClient, const QString &numeroTelephone);
    Client(const QString &nom, const QString &prenom, const QString &email, const QString &cin,const QString &adresse,const QString &typeClient, const QString &numeroTelephone);

    Client();

    int getIdClient() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getEmail() const;
    QString getCin() const;
    QString getAdresse() const;
    QString getTypeClient() const;
    QString getNumeroTelephone() const;

    void setIdClient(int idClient);
    void setNom(const QString &nom);
    void setPrenom(const QString &prenom);
    void setEmail(const QString &email);
    void setCin(const QString &cin);
    void setAdresse(const QString &adresse);
    void setTypeClient(const QString &typeClient);
    void setNumeroTelephone(const QString &numeroTelephone);
    bool ajouter();

    bool supprimer(int idClient);

    bool modifier(int idClient, const QString &nom, const QString &prenom,const QString &email,const QString &cin,
                  const QString &adresse, const QString &typeClient, const QString &numeroTelephone);
    QSqlQueryModel* afficher();

    QSqlQueryModel* rechercherEmail(const QString &email);
    QSqlQueryModel* trierParNom(bool ascending = true);
    QSqlQueryModel* trierParCin(bool ascending = true);

    int countByType(const QString &type);


private:
    int idClient;
    QString nom;
    QString prenom;
    QString email;
    QString cin;
    QString adresse;
    QString typeClient;
    QString numeroTelephone;
};

#endif // CLIENT_H
