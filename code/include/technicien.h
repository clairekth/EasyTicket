#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "personnel.h"

class Technicien : public Personnel
{
public:
    Technicien();
    Technicien(
            std::string id_users,
            std::string nom,
            std::string prenom,
            std::string mdp,
            std::string id,
            std::string mail);
};

#endif // TECHNICIEN_H
