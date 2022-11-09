#ifndef CLIENT_H
#define CLIENT_H

#include "users.h"

class Client : public Users
{
public:
    Client();
    Client(
            std::string id_users,
            std::string nom,
            std::string prenom,
            std::string mdp,
            std::string id,
            std::string mail);
    ~Client();
};

#endif // CLIENT_H
