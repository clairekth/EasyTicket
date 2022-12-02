#include "ticket.h"

Ticket::Ticket()
{
    
}

Ticket::Ticket(QString date_creation, Categorie categorie, Client *auteur, int id_ticket) :
    id_ticket(id_ticket), date_creation(date_creation), categorie(categorie), client(auteur)
{
    this->liste_messages = std::vector<Message*>{};
}

std::vector<Message*> Ticket::getListeMessages() const
{
    return liste_messages;
}

void Ticket::setListeMessages(const std::vector<Message*> &value) {
    liste_messages = value;
}

void Ticket::addMessage(Message &message)
{
    liste_messages.push_back(&message);
}

QString Ticket::getDate_creation() const
{
    return date_creation;
}

void Ticket::setDate_creation(QString value)
{
    date_creation = value;
}

QString Ticket::getDate_fermeture() const
{
    return date_fermeture;
}

void Ticket::setDate_fermeture(QString value)
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

int Ticket::getId_ticket() const
{
    return id_ticket;
}

void Ticket::setId_ticket(const int &value)
{
    id_ticket = value;
}

void Ticket::setClient(Client *value){
    client = value;
}
Client *Ticket::getClient(){
    return client;
}

void Ticket::setPersonnel(Personnel *value){
    personnel = value;
}
Personnel *Ticket::getPersonnel(){
    return personnel;
}

QString Ticket::toString()
{
    return "Ticket = {\n\
            \tid: '" + QString::number(id_ticket) + "',\n\
            \tdate_creation: '" + date_creation + "'\n\
            \tdate_fermeture: '" + date_fermeture + "'\n\
            \tauteur: '" + client->toString() + "'\n\
            \tcategorie: '" + categorie.getNom() + "'\n\
            \tsysteme: '" + systeme.getNom() + "'\n\
            \tlogiciel: '" + logiciel.getNom() + "'\n\
            \tmessage_auteur: '" + liste_messages[0]->toString() + "'\n}";

}

Categorie Ticket::getCategorie()
{
    return categorie;
}

