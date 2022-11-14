#include "ticket.h"

Ticket::Ticket()
{
    
}

Ticket::Ticket(
        std::string id_ticket,
        double date_creation,
        Systeme systeme,
        Logiciel logiciel,
        Client auteur) :

        id_ticket(id_ticket),date_creation(date_creation), systeme(systeme), logiciel(logiciel), client(auteur)
{
    this->liste_messages = std::vector<Message*>{};
}



std::vector<Message*> Ticket::getListeMessages() const
{
    return liste_messages;
}

void Ticket::setListeMessages(const std::vector<Message*> &value)
{
    liste_messages = value;
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

void Ticket::setClient(Client &value){
    client = value;
}
Client Ticket::getClient(){
    return client;
}

void Ticket::setPersonnel(Personnel &value){
    personnel = value;
}
Personnel Ticket::getPersonnel(){
    return personnel;
}

