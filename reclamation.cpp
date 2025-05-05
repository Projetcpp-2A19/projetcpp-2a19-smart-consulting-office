 #include "reclamation.h"
#include <QDebug>
//constructeur
reclamation::reclamation()
{

    id_reclamation=0;
    description="";
    resolution="";
    Priorite="" ;
    date_de_reclamation=QDate::currentDate();
    etat="";
}
reclamation::reclamation(int id_reclamation,QString description,QString resolution,QString Priorite,QDate date,QString etat,int id)
{

    this->id_reclamation=id_reclamation;
    this-> description=description;
    this-> resolution=resolution;
    this-> Priorite=Priorite;
    this-> date_de_reclamation=date;
    this-> etat=etat;
    this->id_client_reclamation=id;
}

//getters
int reclamation::getIdReclamation()
{
    return id_reclamation;
}

QString reclamation::getDescription()
{
    return description;
}
QString reclamation::getResolution()
{
    return resolution;
}
QString reclamation::getPriorite()
{
    return Priorite;
}
QString reclamation::getEtat()
{
    return etat;
}
QDate reclamation::getDate()
{
    return date_de_reclamation;
}

//setters
void reclamation::setIdReclamation(int id)
{
    this->id_reclamation=id;
}
void reclamation::setDescription(QString description)
{
    this->description=description;
}
void reclamation::setPriorite(QString priorite)
{
    this->Priorite=priorite;
}
void reclamation::setResolution(QString resolution)
{
    this->resolution=resolution;
}
void reclamation::setEtat(QString etat)
{
    this->etat=etat;

}
void reclamation::setDate(QDate date)
{
    this->date_de_reclamation=date;
}

//ajout
bool reclamation::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO RECLAMATION (ID_RECLAMATION,DESCRIPTION,RESOLUTION,ORDRE_PRIORITE,DATE_DE_RECLAMATION,ETAT,ID_CLIENT)"
                  "VALUES (:id,:description,:resolution,:ordre,:date,:etat,:id_client)");

    query.bindValue(":id", id_reclamation);
    query.bindValue(":description", description);
    query.bindValue(":resolution",resolution);
    query.bindValue(":ordre",Priorite);
    query.bindValue(":date",date_de_reclamation);
    query.bindValue(":etat",etat);
    query.bindValue(":id_client",id_client_reclamation);


    bool test= query.exec();
    if(test)
    {
        return true;
    }
    else
        return false;


}
bool reclamation::supprimer(int id)
{

    QSqlQuery query;
    query.prepare("DELETE FROM RECLAMATION WHERE ID_RECLAMATION=:id");
    query.bindValue(":id",id);

    bool test= query.exec();
    if(test)
    {
        return true;
    }
    else
        return false;

}


QSqlQueryModel * reclamation::afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM RECLAMATION");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Resolution"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Priorite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_Client"));




    return model;
}

bool reclamation::modifier()
{
    QSqlQuery query;

    query.prepare("UPDATE RECLAMATION SET DESCRIPTION=:description, RESOLUTION=:resolution , ORDRE_PRIORITE=:ordre, DATE_DE_RECLAMATION=:date, ETAT=:etat, ID_CLIENT=:id_client WHERE ID_RECLAMATION=:id");

    query.bindValue(":description", description);
    query.bindValue(":resolution", resolution);  // Corrected line
    query.bindValue(":ordre", Priorite);
    query.bindValue(":date", date_de_reclamation);
    query.bindValue(":etat", etat);
    query.bindValue(":id_client", id_client_reclamation);
    query.bindValue(":id", id_reclamation);

    return query.exec();
}
bool reclamation::chercher_id_reclamation(int id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM RECLAMATION WHERE ID_RECLAMATION = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        if(count>0)
            return true;
        else
            return false;
    }
    return false;

}

QSqlQueryModel * reclamation::trier(QString choix,QString ordre)
{

    QSqlQueryModel * model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM RECLAMATION ORDER BY "+choix+" "+ordre);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Resolution"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Priorite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_Client"));




    return model;
}


QSqlQueryModel * reclamation::chercher(QString choix,QString text)
{

    QSqlQueryModel * model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM RECLAMATION WHERE "+choix+" LIKE '%" + text + "%' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Resolution"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Priorite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_Client"));




    return model;
}

int reclamation::countPriorite(QString text)
{
    int count=0;
    QSqlQuery query;
    query.prepare("SELECT COUNT(ORDRE_PRIORITE) FROM RECLAMATION WHERE ORDRE_PRIORITE=:p");
    query.bindValue(":p",text);
    if(query.exec() && query.next() )
    {
        count=query.value(0).toInt();

    }
    return count;
}
