#include "mainwindow.h"
#include <QApplication>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a connection object and attempt to connect to the database
    Connection c;
    bool test = c.createconnect();

    // Declare the MainWindow object outside the if block
    MainWindow w;

    if (test) {
        // If the connection is successful, show the MainWindow
        w.show();
    } else {
        // If the connection fails, exit the application
        return 0;
    }

    return a.exec();
}
