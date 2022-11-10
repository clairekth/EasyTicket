#ifndef INGENIEUR_H
#define INGENIEUR_H

#include "personnel.h"

class Ingenieur : public Personnel
{
public:
    Ingenieur();
    Ingenieur(
            std::string id_u,
            std::string n,
            std::string p,
            std::string motdepasse,
            std::string email);

    bool estUnIngenieur();
};

#endif // INGENIEUR_H
