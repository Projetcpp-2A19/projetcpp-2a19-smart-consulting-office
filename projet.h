#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QDate>  // Include QDate for date handling
#include <QSqlQuery>
#include <QSqlQueryModel>

class Projet
{
public:
    Projet();
    Projet(QString nom, QString desc, QDate debut, QDate fin, int prio, double bud);

    bool ajouter();  // Function to insert project data into the database
    QSqlQueryModel *afficher();  // Function to display projects
    bool modifier(int id);       // Function to update a project by ID
    bool supprimer(int id);      // Function to delete a project by ID
    bool nomExists(const QString &nom);  // Function to check if a project name already exists

private:
    int id_projet;    // New primary key field
    QString nom_projet;
    QString description;
    QDate date_debut;  // Change to QDate
    QDate date_fin;    // Change to QDate
    int priorite;
    double budget;
};

#endif // PROJET_H
