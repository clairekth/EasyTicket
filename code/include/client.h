#ifndef CLIENT_H
#define CLIENT_H

#include "users.h"

class Client : public Users
{
public:
    Client();
    /// @brief  La classe @ref Client permet de décrire un Client dans l'application EasyTicket.
    /// @param  id_u        L'identifiant de l'utilisateur
    /// @param  n           Le nom de l'utilisateur
    /// @param  p           Le prénm de l'utilisateur
    /// @param  motdepasse  Le mot de passe de l'utilisateur
    /// @param  email       Le mail de l'utilisateur
    Client(
            std::string id_u,
            std::string n,
            std::string p,
            std::string motdepasse,
            std::string email);
    ~Client();


    /// @brief Cette méthode permet de vérifier si un @ref Utilisateur est un @ref Client
    /// @return true
    bool estUnClient();
};

#endif // CLIENT_H
