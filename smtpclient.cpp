#include "smtpclient.h"
#include <QSslSocket>
#include <QTcpSocket>
#include <QDebug>

SmtpClient::SmtpClient(const QString &smtpHost,
                       quint16 smtpPort,
                       const QString &username,
                       const QString &password,
                       bool useSSL,
                       QObject *parent)
    : QObject(parent),
    m_smtpHost(smtpHost),
    m_smtpPort(smtpPort),
    m_username(username),
    m_password(password),
    m_useSSL(useSSL)
{
}

bool SmtpClient::sendMail(const QString &from,
                          const QString &to,
                          const QString &subject,
                          const QString &body)
{
    // 1) Créer le socket.
    // Si m_useSSL est vrai, on crée un QSslSocket, sinon un QTcpSocket.
    QAbstractSocket *socket = nullptr;
    if (m_useSSL) {
        socket = new QSslSocket(this);
    } else {
        socket = new QTcpSocket(this);
    }

    // 2) Se connecter au serveur SMTP
    socket->connectToHost(m_smtpHost, m_smtpPort);
    if (!socket->waitForConnected(5000)) {
        qDebug() << "Erreur: impossible de se connecter au serveur SMTP";
        return false;
    }

    // 3) Lire la réponse initiale du serveur
    if (!socket->waitForReadyRead(5000)) {
        qDebug() << "Erreur: pas de réponse du serveur SMTP (step 1)";
        return false;
    }
    qDebug() << socket->readAll();

    // 4) Envoyer EHLO
    QString localHost = "localhost";
    QString ehloCmd = "EHLO " + localHost + "\r\n";
    socket->write(ehloCmd.toUtf8());
    if (!socket->waitForBytesWritten(3000) ||
        !socket->waitForReadyRead(3000)) {
        qDebug() << "Erreur: EHLO n'a pas abouti";
        return false;
    }
    QByteArray ehloResponse = socket->readAll();
    qDebug() << ehloResponse;

    // 5) Si on utilise le port 587 avec SSL, envoyer STARTTLS et activer le chiffrement
    if (m_useSSL && m_smtpPort == 587) {
        // Puisque nous avons créé un QSslSocket dès le départ, on peut l'utiliser directement.
        QSslSocket *sslSocket = qobject_cast<QSslSocket*>(socket);
        if (!sslSocket) {
            qDebug() << "Erreur: cast en QSslSocket a échoué";
            return false;
        }
        // Envoyer la commande STARTTLS
        sslSocket->write("STARTTLS\r\n");
        if (!sslSocket->waitForReadyRead(3000)) {
            qDebug() << "Erreur: STARTTLS pas de réponse";
            return false;
        }
        QByteArray starttlsResponse = sslSocket->readAll();
        qDebug() << starttlsResponse;

        // Démarrer le chiffrement sur le même socket
        sslSocket->startClientEncryption();
        if (!sslSocket->waitForEncrypted(3000)) {
            qDebug() << "Erreur: l'upgrade en SSL a échoué";
            return false;
        }
    }

    // 6) Authentification (LOGIN)
    socket->write("AUTH LOGIN\r\n");
    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Erreur: AUTH LOGIN pas de réponse";
        return false;
    }
    qDebug() << socket->readAll();

    // 6a) Envoyer username en base64
    QByteArray usernameBase64 = m_username.toUtf8().toBase64();
    socket->write(usernameBase64 + "\r\n");
    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Erreur: username base64 pas de réponse";
        return false;
    }
    qDebug() << socket->readAll();

    // 6b) Envoyer password en base64
    QByteArray passwordBase64 = m_password.toUtf8().toBase64();
    socket->write(passwordBase64 + "\r\n");
    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Erreur: password base64 pas de réponse";
        return false;
    }
    qDebug() << socket->readAll();

    // 7) MAIL FROM
    QString mailFromCmd = "MAIL FROM: <" + from + ">\r\n";
    socket->write(mailFromCmd.toUtf8());
    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Erreur: MAIL FROM pas de réponse";
        return false;
    }
    qDebug() << socket->readAll();

    // 8) RCPT TO
    QString rcptToCmd = "RCPT TO: <" + to + ">\r\n";
    socket->write(rcptToCmd.toUtf8());
    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Erreur: RCPT TO pas de réponse";
        return false;
    }
    qDebug() << socket->readAll();

    // 9) DATA
    socket->write("DATA\r\n");
    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Erreur: DATA pas de réponse";
        return false;
    }
    qDebug() << socket->readAll();

    // 10) Envoyer le contenu du message
    QString message;
    message  = "From: " + from + "\r\n";
    message += "To: " + to + "\r\n";
    message += "Subject: " + subject + "\r\n";
    message += "Content-Type: text/html; charset=\"utf-8\"\r\n";
    message += "\r\n"; // Séparateur entêtes / corps

    // Exemple d'e-mail HTML plus élégant
    message += "<!DOCTYPE html>"
               "<html lang='fr'>"
               "<head>"
               "<meta charset='UTF-8'>"
               "<title>Notification</title>"
               "</head>"
               "<body style='margin:0; padding:0; background:#f4f4f4; font-family: Arial, sans-serif;'>"

               // En-tête coloré
               "<div style='background: #4CAF50; padding: 20px; text-align: center;'>"
               "<h1 style='color: #fff; margin: 0; font-size: 28px;'>Notification de création de compte</h1>"
               "</div>"

               // Container "carte" au centre
               "<div style='max-width: 600px; margin: 30px auto; background: #fff; border-radius: 10px;"
               "     box-shadow: 0 2px 5px rgba(0,0,0,0.2); overflow: hidden;'>"

               // Image (en-tête de la carte)
               "<div style='text-align:center; background:#fafafa; padding: 20px;'>"
               "<img src='https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcT3TWjRkPN6Kw6Ois7voOIZaFlmQjMrpAzn50XNEbaXamQO1k1CgtWkV043Fz1sMMLE9TA&usqp=CAU'"
               "     alt='Logo' style='width:120px;' />"
               "</div>"

               // Contenu de la carte
               "<div style='padding: 20px; color: #333;'>"
               "<h2 style='margin-top:0; color:#4CAF50;'>Bonjour,</h2>"
               "<p style='line-height:1.6;'>"
               "Nous sommes heureux de vous informer que votre compte a été créé avec succès !<br/>"
               "Vous pouvez dès à présent bénéficier de nos services et découvrir toutes nos fonctionnalités."
               "</p>"

               // Exemple de "boutons"
               "<div style='margin-top: 20px; text-align:center;'>"
               "<a href='#' style='display:inline-block; margin:0 5px; padding:12px 24px; background:#4CAF50; color:#fff; text-decoration:none; border-radius:5px;'>Découvrir</a>"
               "<a href='#' style='display:inline-block; margin:0 5px; padding:12px 24px; background:#2196F3; color:#fff; text-decoration:none; border-radius:5px;'>Se Connecter</a>"
               "</div>"

               "<p style='margin-top: 30px;'>"
               "Cordialement,<br/>"
               "<strong>L'équipe</strong>."
               "</p>"

               "</div>"  // Fin contenu carte
               "</div>"  // Fin container carte

               "</body></html>";

    // Terminer par .\r\n
    message += "\r\n.\r\n";


    socket->write(message.toUtf8());
    if (!socket->waitForReadyRead(3000)) {
        qDebug() << "Erreur: envoi du message pas de réponse";
        return false;
    }
    qDebug() << socket->readAll();

    // 11) QUIT
    socket->write("QUIT\r\n");
    socket->waitForBytesWritten(3000);
    socket->waitForReadyRead(3000);
    qDebug() << socket->readAll();

    socket->close();
    socket->deleteLater();

    qDebug() << "Email envoyé avec succès à" << to;
    return true;
}
