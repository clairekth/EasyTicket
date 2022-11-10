#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "users.h"

class Personnel : public Users
{
public:
    Personnel();
    Personnel(
            std::string id_u,
            std::string n,
            std::string p,
            std::string motdepasse,
            std::string email);
    ~Personnel();

    bool estUnPersonnel();
    bool estUnIngenieur();
    bool estUnTechnicien();
};

#endif // PERSONNEL_H
