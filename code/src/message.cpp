#include "message.h"


QString Message::getMessage() const
{
    return message;
}

void Message::setMessage(const QString &value)
{
    message = value;
}

Message::Message(QString date_envoie, Utilisateur *user, Ticket *ticket, QString message, int id_message):
    id_message(id_message), date_envoi(date_envoie), user(user), ticket(ticket), message(message)
{}


Ticket* Message::getTicket() const
{
    return ticket;
}

void Message::setTicket(Ticket* value)
{
    ticket = value;
}

QString Message::getDate_envoi() const
{
    return date_envoi;
}

void Message::setDate_envoi(QString value)
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


int Message::getId_message() const
{
    return id_message;
}

void Message::setId_message(const int &value)
{
    id_message = value;
}

QString Message::toString(){
    return "Message = {\n\
            \tid: '" + QString::number(id_message) + "',\n\
            \tdate_creation: '" + date_envoi + "'\n\
            \tmessage: '" + message + "'\n\
            \tauteur: '" + user->toString() + "'\n}";
}
