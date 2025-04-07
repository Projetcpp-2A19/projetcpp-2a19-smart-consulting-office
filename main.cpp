#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "connection.h"
#include<QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;


    bool test = c.createconnect();
     MainWindow w;

    if(test)
    {
        w.show();
         qDebug() << "Drivers disponibles :" << QSqlDatabase::drivers();
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."),
                                 QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);

        // Print detailed error message
        qDebug() << "Database Connection Failed: " << c.getLastError();
    }

    return a.exec();
}

