#ifndef ADMIN_H
#define ADMIN_H

#include "users.h"

class Admin : public Users
{
public:
    Admin();
    Admin(
            std::string id_users,
            std::string nom,
            std::string prenom,
            std::string mdp,
            std::string id,
            std::string mail);
    ~Admin();
};

#endif // ADMIN_H
