#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDebug>

#include "utilisateur.h"


class Client: public Utilisateur
{
public:
    Client();

    Client(const QString id,
           const QString mdp,
           const QString nom = "Oui",
           const QString prenom = "Oui",
           const QString email = "oui-oui@easyticket.fr");

    virtual ~Client();

    virtual QString toString() const;
};

#endif // CLIENT_H
