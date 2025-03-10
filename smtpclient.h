#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include <QObject>
#include <QString>

class SmtpClient : public QObject
{
    Q_OBJECT

public:
    explicit SmtpClient(const QString &smtpHost,
                        quint16 smtpPort,
                        const QString &username,
                        const QString &password,
                        bool useSSL = true,
                        QObject *parent = nullptr);

    // Envoie un email avec les paramètres suivants :
    // from : adresse expéditrice (doit correspondre au username pour Gmail)
    // to   : adresse destinataire
    // subject : objet du message
    // body : corps du message
    bool sendMail(const QString &from,
                  const QString &to,
                  const QString &subject,
                  const QString &body);

private:
    QString m_smtpHost;
    quint16 m_smtpPort;
    QString m_username;
    QString m_password;
    bool m_useSSL;
};

#endif // SMTPCLIENT_H
