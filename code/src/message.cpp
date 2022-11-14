#include "message.h"
#include "ticket.h"

Ticket* Message::getTicket() const
{
    return ticket;
}

void Message::setTicket(Ticket* &value)
{
    ticket = value;
}

double Message::getDate_envoie() const
{
    return date_envoie;
}

void Message::setDate_envoie(double value)
{
    date_envoie = value;
}

Utilisateur* Message::getUser() const
{
    return user;
}

void Message::setUser(Utilisateur* &value)
{
    user = value;
}


std::string Message::getId_message() const
{
    return id_message;
}

void Message::setId_message(const std::string &value)
{
    id_message = value;
}
