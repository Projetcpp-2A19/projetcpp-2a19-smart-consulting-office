#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{

bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");//inserer le nom de la source de données
db.setUserName("test");//inserer nom de l'utilisateur
db.setPassword("1234");//inserer mot de passe de cet utilisateur

if (db.open()){
test=true;
qDebug() << "Connexion à la base de données réussie !";

}



    return  test;
}
