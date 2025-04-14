#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts/QChartView>

class Projet
{
public:
    Projet();
    Projet(QString nom, QString desc, QDate debut, QDate fin, QString status,
           int prio, double bud, int id_emp, int id_cli, int progress = 0);

    int getProgress() const;
    void setProgress(int value);

    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier(int id);
    bool supprimer(int id);
    bool nomExists(const QString &nom);
    QSqlQueryModel *rechercherEtTrier(const QString &nom, int sortOption);
    QChartView* getProjectBudgetChart();
    QChartView* getColoredBudgetChart();


private:
    int id_projet;
    QString nom_projet;
    QString description;
    QDate date_debut;
    QDate date_fin;
    QString status;
    int priorite;
    double budget;
    int id_employe;
    int id_client;
    int progress;
};

#endif // PROJET_H
