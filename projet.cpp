#include "projet.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDate>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>

Projet::Projet() {}

Projet::Projet(QString nom, QString desc, QDate debut, QDate fin, QString status,
               int prio, double bud, int id_emp, int id_cli, int progress)
    : nom_projet(nom), description(desc), date_debut(debut), date_fin(fin),
    status(status), priorite(prio), budget(bud), id_employe(id_emp),
    id_client(id_cli), progress(progress) {}

int Projet::getProgress() const { return progress; }
void Projet::setProgress(int value) { progress = value; }

bool Projet::ajouter() {
    if (nomExists(nom_projet)) {
        qDebug() << "Project name already exists";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO PROJET (NOM_PROJET, DESCRIPTION, DATE_DEBUT, DATE_FIN, "
                  "STATUS, PRIORITE, BUDGET, ID_EMPLOYE, ID_CLIENT, PROGRESS) "
                  "VALUES (:nom, :desc, TO_DATE(:debut, 'YYYY-MM-DD'), TO_DATE(:fin, 'YYYY-MM-DD'), "
                  ":status, :prio, :budget, :id_emp, :id_cli, :progress)");

    query.bindValue(":nom", nom_projet);
    query.bindValue(":desc", description);
    query.bindValue(":debut", date_debut.toString("yyyy-MM-dd"));
    query.bindValue(":fin", date_fin.toString("yyyy-MM-dd"));
    query.bindValue(":status", status);
    query.bindValue(":prio", priorite);
    query.bindValue(":budget", budget);
    query.bindValue(":id_emp", id_employe);
    query.bindValue(":id_cli", id_client);
    query.bindValue(":progress", progress);



    if(!query.exec()) {
        qDebug() << "Error adding project:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* Projet::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, "
                    "TO_CHAR(DATE_DEBUT, 'YYYY-MM-DD'), "
                    "TO_CHAR(DATE_FIN, 'YYYY-MM-DD'), "
                    "STATUS, PRIORITE, BUDGET, "
                    "ID_EMPLOYE, ID_CLIENT "
                    "FROM PROJET");

    if(model->lastError().isValid()) {
        qDebug() << "Error loading projects:" << model->lastError().text();
    }
    return model;
}


bool Projet::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE PROJET SET NOM_PROJET=:nom, DESCRIPTION=:desc, "
                  "DATE_DEBUT=TO_DATE(:debut, 'YYYY-MM-DD'), DATE_FIN=TO_DATE(:fin, 'YYYY-MM-DD'), "
                  "STATUS=:status, PRIORITE=:prio, BUDGET=:budget, "
                  "ID_EMPLOYE=:id_emp, ID_CLIENT=:id_cli, PROGRESS=:progress "
                  "WHERE ID_PROJET=:id");

    query.bindValue(":nom", nom_projet);
    query.bindValue(":desc", description);
    query.bindValue(":debut", date_debut.toString("yyyy-MM-dd"));
    query.bindValue(":fin", date_fin.toString("yyyy-MM-dd"));
    query.bindValue(":status", status);
    query.bindValue(":prio", priorite);
    query.bindValue(":budget", budget);
    query.bindValue(":id_emp", id_employe);
    query.bindValue(":id_cli", id_client);
    query.bindValue(":progress", progress);
    query.bindValue(":id", id);

    if(!query.exec()) {
        qDebug() << "Error updating project:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Projet::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM PROJET WHERE ID_PROJET=:id");
    query.bindValue(":id", id);

    if(!query.exec()) {
        qDebug() << "Error deleting project:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Projet::nomExists(const QString &nom) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM PROJET WHERE NOM_PROJET=:nom");
    query.bindValue(":nom", nom);

    if(query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

QSqlQueryModel* Projet::rechercherEtTrier(const QString &nom, int sortOption) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    QString sql = "SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, "
                  "TO_CHAR(DATE_DEBUT, 'YYYY-MM-DD'), "
                  "TO_CHAR(DATE_FIN, 'YYYY-MM-DD'), "
                  "STATUS, PRIORITE, BUDGET, "
                  "ID_EMPLOYE, ID_CLIENT "
                  "FROM PROJET ";

    // Add search condition if needed
    if(!nom.isEmpty()) {
        sql += "WHERE UPPER(NOM_PROJET) LIKE UPPER(:nom) ";
    }

    // Add sorting
    switch(sortOption) {
    case 1: sql += "ORDER BY PRIORITE ASC"; break;  // Low to High
    case 2: sql += "ORDER BY PRIORITE DESC"; break; // High to Low
    default: sql += "ORDER BY ID_PROJET"; break;    // Default order
    }

    query.prepare(sql);
    if(!nom.isEmpty()) {
        query.bindValue(":nom", "%" + nom + "%");
    }

    if(query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Search/Sort failed:" << query.lastError();
        delete model;
        return nullptr;
    }
    return model;
}

QChartView* Projet::getColoredBudgetChart() {
    QSqlQuery query;
    if (!query.exec("SELECT NOM_PROJET, BUDGET FROM PROJET ORDER BY BUDGET DESC")) {
        qDebug() << "Chart error:" << query.lastError();
        return nullptr;
    }

    QChart *chart = new QChart();
    QBarSeries *series = new QBarSeries();
    QStringList categories;
    bool hasData = false;

    // Create separate bar sets for each color group
    QBarSet *lowBudgetSet = new QBarSet("Low Budget");
    QBarSet *mediumBudgetSet = new QBarSet("Medium Budget");
    QBarSet *highBudgetSet = new QBarSet("High Budget");

    // Set colors
    lowBudgetSet->setColor(QColor("#e74c3c"));    // Red
    mediumBudgetSet->setColor(QColor("#f39c12")); // Orange
    highBudgetSet->setColor(QColor("#2ecc71"));   // Green

    while (query.next()) {
        QString name = query.value(0).toString();
        double budget = query.value(1).toDouble();

        categories << name;

        if (budget < 5000) {
            *lowBudgetSet << budget;
            *mediumBudgetSet << 0;  // Placeholder
            *highBudgetSet << 0;    // Placeholder
        } else if (budget < 20000) {
            *lowBudgetSet << 0;
            *mediumBudgetSet << budget;
            *highBudgetSet << 0;
        } else {
            *lowBudgetSet << 0;
            *mediumBudgetSet << 0;
            *highBudgetSet << budget;
        }

        hasData = true;
    }

    if (!hasData) {
        delete chart;
        return nullptr;
    }

    // Add all bar sets to the series
    series->append(lowBudgetSet);
    series->append(mediumBudgetSet);
    series->append(highBudgetSet);
    chart->addSeries(series);

    // Configure axes
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setTitleText("Projects");
    axisX->setLabelsAngle(-45);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Budget ($)");
    axisY->setLabelFormat("$%.0f");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Chart styling
    chart->setTitle("Project Budgets by Priority Level");
    chart->setBackgroundBrush(Qt::white);
    chart->legend()->setVisible(false); // We'll use our custom legend

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(800, 500);

    return chartView;
}
