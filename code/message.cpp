#include "message.h"

Message::Message()
{

}

Message::Message(const QString date_envoi, Utilisateur *user, Ticket *ticket, QString message, int id_message):
    date_envoi(date_envoi), auteur(user), ticket(ticket), message(message), id_message(id_message)
{

}

Message::~Message()
{
}

void Message::setTicket(Ticket *ticket)
{
    this->ticket = ticket;
}

QString Message::getMessage() const
{
    return message;
}

QString Message::getDate_envoi() const
{
    return date_envoi;
}

Utilisateur *Message::getAuteur()
{
    return auteur;
}

Ticket *Message::getTicket()
{
    return ticket;
}
