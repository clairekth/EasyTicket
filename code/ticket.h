#ifndef TICKET_H
#define TICKET_H

#include <QVector>
#include <QString>

#include "systeme.h"
#include "logiciel.h"
#include "client.h"
#include "categorie.h"
#include "message.h"
#include "personnel.h"

class Client;

class Ticket
{
public:
    Ticket();

    Ticket(QString &date_creation,
           Categorie &categorie,
           Client *auteur,
           int id_ticket = -1);

    ~Ticket();

    QString getDate_creation() const;

    Categorie getCategorie() const;

    Logiciel getLogiciel() const;

    Systeme getSysteme() const;

    Client getAuteur() const;

    QVector<Message> getMessages() const;

    int getId() const;

    void setId(const int id);

private:
    QString date_creation, date_fermeture;

    Categorie categorie;

    Logiciel logiciel;

    Systeme systeme;

    QVector<Message> liste_messages;

    Client *auteur;

    Personnel personnel;

    int id_ticket;

};



#endif // TICKET_H
