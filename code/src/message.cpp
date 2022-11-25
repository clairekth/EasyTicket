#include "message.h"


Message::Message(std::string id_message, std::string date_envoie, Utilisateur *user, Ticket *ticket, std::string message):
    id_message(id_message), date_envoi(date_envoie), user(user), ticket(ticket), message(message)
{}


Ticket* Message::getTicket() const
{
    return ticket;
}

void Message::setTicket(Ticket* &value)
{
    ticket = value;
}

std::string Message::getDate_envoi() const
{
    return date_envoi;
}

void Message::setDate_envoi(double value)
{
    date_envoi = value;
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

std::string Message::toString(){
    return "Message = {\n\
            \tid: '" + id_message + "',\n\
            \tdate_creation: '" + date_envoi + "'\n\
            \tmessage: '" + message + "'\n\
            \tauteur: '" + user->toString() + "'\n}";
}
