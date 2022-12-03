#include "utilisateur.h"

Utilisateur::Utilisateur()
{

}

Utilisateur::Utilisateur(const QString &id, const QString &nom, const QString &prenom, const QString &email, const QString &mdp):
    id(id),
    nom(nom),
    prenom(prenom),
    email(email),
    mdp(mdp)
{
    liste_tickets = QVector<Ticket>();
}

Utilisateur::~Utilisateur()
{
    qDebug() << "Destruction  utilisateur\n";
}

QString Utilisateur::getNom() const
{
    return nom;
}

QString Utilisateur::getPrenom() const
{
    return prenom;
}

QString Utilisateur::getId() const
{
    return id;
}

void Utilisateur::addTicket(const Ticket &ticket)
{
    liste_tickets.push_back(ticket);
}
