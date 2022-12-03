#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QString>
#include <QVector>
#include <QDebug>

#include "ticket.h"

class Utilisateur
{
public:
    Utilisateur();

    Utilisateur(const QString &id,
                const QString &mdp,
                const QString &nom,
                const QString &prenom,
                const QString &email);

    virtual ~Utilisateur();

    virtual QString toString() const = 0;

    virtual QString getNom() const;

    virtual QString getPrenom() const;

    virtual QString getId() const;

    virtual void addTicket(Ticket *ticket);

protected:
    QString id, nom, prenom, email, mdp;
    QVector<Ticket*> liste_tickets;
};

#endif // UTILISATEUR_H
