#ifndef SMS_SENDER_H
#define SMS_SENDER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QSqlDatabase>
#include <QSqlQuery>

class SmsSender : public QObject {
    Q_OBJECT

public:
    explicit SmsSender(QObject *parent = nullptr);
    void envoyerMessagesSensibilisation(const QString &message);
    void envoyerSMS(const QString &numero, const QString &message);

private:
    QNetworkAccessManager *manager;


};

#endif // SMS_SENDER_H
