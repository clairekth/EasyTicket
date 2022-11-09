#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "users.h"

class Personnel : public Users
{
public:
    Personnel();
    Personnel(
            std::string id_users,
            std::string nom,
            std::string prenom,
            std::string mdp,
            std::string id,
            std::string mail);
    ~Personnel();
};

#endif // PERSONNEL_H
