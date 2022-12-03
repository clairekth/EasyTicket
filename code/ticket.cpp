#include "ticket.h"

Ticket::Ticket()
{

}

Ticket::Ticket(QString &date_creation, Categorie &categorie, Client *auteur, int id_ticket):
    date_creation(date_creation), categorie(categorie), auteur(auteur), id_ticket(id_ticket)
{

}

Ticket::~Ticket()
{

}

QString Ticket::getDate_creation() const
{
    return date_creation;
}

Categorie Ticket::getCategorie() const
{
    return categorie;
}

Logiciel Ticket::getLogiciel() const
{
    return logiciel;
}

Systeme Ticket::getSysteme() const
{
    return systeme;
}

Client Ticket::getAuteur() const
{
    return *auteur;
}

QVector<Message> Ticket::getMessages() const
{
    return liste_messages;
}

int Ticket::getId() const
{
    return id_ticket;
}

void Ticket::setId(const int id)
{
    id_ticket = id;
}

