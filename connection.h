#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QString>

class Connection
{
public:
    Connection();  // Constructor
    bool createconnect();  // Connect to DB
    QString getLastError() const;  // Get last error message

private:
    QSqlDatabase db;  // Store the database object persistently
};

#endif // CONNECTION_H
