#include "ticket.h"

std::vector<_Tp1> Ticket::getListeMessages() const
{
    return listeMessages;
}

void Ticket::setListeMessages(const std::vector<_Tp1> &value)
{
    listeMessages = value;
}

Ticket::Ticket()
{
    
}

double Ticket::getDate_creation() const
{
    return date_creation;
}

void Ticket::setDate_creation(double value)
{
    date_creation = value;
}

double Ticket::getDate_fermeture() const
{
    return date_fermeture;
}

void Ticket::setDate_fermeture(double value)
{
    date_fermeture = value;
}

Systeme Ticket::getSysteme() const
{
    return systeme;
}

void Ticket::setSysteme(const Systeme &value)
{
    systeme = value;
}

Logiciel Ticket::getLogiciel() const
{
    return logiciel;
}

void Ticket::setLogiciel(const Logiciel &value)
{
    logiciel = value;
}

std::string Ticket::getId_ticket() const
{
    return id_ticket;
}

void Ticket::setId_ticket(const std::string &value)
{
    id_ticket = value;
}
