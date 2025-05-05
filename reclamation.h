#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
class reclamation
{
public:
    reclamation();

    reclamation(int id_reclamation,QString description,QString resolution,QString Priorite,QDate date,QString etat,int id);

    int getIdReclamation();
    QString getDescription();
    QString getResolution();
    QString getPriorite();
    QDate getDate();
    QString getEtat();
    void setIdReclamation(int id);
    void setDescription(QString description);
    void setResolution(QString resolution);
    void setPriorite(QString priorite);
    void setDate(QDate date);
    void setEtat(QString etat);


    bool ajouter();
    bool supprimer(int id);
    QSqlQueryModel * afficher();
    bool modifier();
    bool chercher_id_reclamation(int id);


    QSqlQueryModel * trier(QString choix,QString ordre);
    QSqlQueryModel * chercher(QString choix,QString text);
    int countPriorite(QString text);

private:
    int id_reclamation;
    QString description;
    QString resolution;
    QString Priorite ;
    QDate date_de_reclamation;
    QString etat;
    int id_client_reclamation;
};

#endif // RECLAMATION_H
