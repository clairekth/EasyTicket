#ifndef ADMIN_H
#define ADMIN_H

#include "users.h"

class Admin : public Users
{
public:
    Admin();
    Admin(
            std::string id_user,
            std::string nom,
            std::string prenom,
            std::string mdp,
            std::string id,
            std::string mail);

    bool estUnAdmin();

    ~Admin();
};

#endif // ADMIN_H
