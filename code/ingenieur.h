#ifndef INGENIEUR_H
#define INGENIEUR_H

#include "personnel.h"

class Ingenieur: public Personnel
{
public:
    Ingenieur();
    Ingenieur(const QString id,
           const QString mdp,
           const QString nom = "Oui",
           const QString prenom = "Oui",
           const QString email = "oui-oui@easyticket.fr");

    bool estUnIngenieur();
    QString toString() const;


};

#endif // INGENIEUR_H
