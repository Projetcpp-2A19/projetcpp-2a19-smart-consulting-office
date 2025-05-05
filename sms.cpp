#include "sms.h"
#include <QUrl>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QDebug>

SmsSender::SmsSender(QObject *parent)
    : QObject(parent), manager(new QNetworkAccessManager(this)) {}

// QStringList SmsSender::recupererNumerosPatients() {
//     QStringList numeros;
//     QSqlQuery query("SELECT TELEPHONE FROM CONSULTANT");

//     while (query.next()) {
//         QString num = query.value(0).toString();
//         if (!num.isEmpty())
//             numeros << num;
//     }

//     return numeros;
// }

void SmsSender::envoyerSMS(const QString &numero, const QString &message) {
    QUrl url("https://api.twilio.com/2010-04-01/Accounts/ACcb18db76643b390965799cf149cb67f5/Messages.json");
    QNetworkRequest request(url);

    QString sid = "ACcb18db76643b390965799cf149cb67f5";
    QString authToken = "9b9616e4fe2a22a4188f21b47631e286";
    QString from = "+17623413349";

    QString credentials = sid + ":" + authToken;
    QByteArray encoded = credentials.toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + encoded);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("To", numero);   // ex: +216XXXXXXXX
    params.addQueryItem("From", from);
    params.addQueryItem("Body", message);

    manager->post(request, params.query(QUrl::FullyEncoded).toUtf8());

    qDebug() << "SMS envoyé à" << numero;
}

// void SmsSender::envoyerMessagesSensibilisation(const QString &message) {
//     QStringList numeros = recupererNumerosPatients();
//     for (const QString &num : numeros) {
//         envoyerSMS(num, message);
//     }
// }
