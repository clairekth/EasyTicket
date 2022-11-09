#ifndef INGENIEUR_H
#define INGENIEUR_H

#include "personnel.h"

class Ingenieur : public Personnel
{
public:
    Ingenieur();
    Ingenieur(
            std::string id_users,
            std::string nom,
            std::string prenom,
            std::string mdp,
            std::string id,
            std::string mail);
};

#endif // INGENIEUR_H
