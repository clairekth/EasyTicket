#include "message.h"


Message::Message(std::string id_message, double date_envoie, Utilisateur *user, Ticket *ticket):
    id_message(id_message), date_envoie(date_envoie), user(user), ticket(ticket)
{}


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
