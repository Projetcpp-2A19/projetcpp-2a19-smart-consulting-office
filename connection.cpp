#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("koussay");
    db.setPassword("fokaad123");

    if (db.open()) {
        test = true;
        qDebug() << "Connection successful";
    } else {
        qDebug() << "Error: " << db.lastError().text();
    }

    return test;
}
