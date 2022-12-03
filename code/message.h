#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>

#include "utilisateur.h"
class Utilisateur;
class Ticket;

class Message
{
public:
    Message();

    Message(QString &date_envoi, Utilisateur *user, Ticket *ticket, QString &message, int id_message = -1);

    ~Message();

    void setTicket(Ticket *ticket);

    QString getMessage() const;

    QString getDate_envoi() const;

    Utilisateur* getAuteur();

    Ticket* getTicket();

private:
    QString date_envoi;

    Utilisateur *auteur;

    Ticket *ticket;

    QString message;

    int id_message;
};

#endif // MESSAGE_H
