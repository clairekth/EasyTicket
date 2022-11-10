#ifndef ADMIN_H
#define ADMIN_H

#include "users.h"

class Admin : public Users
{
public:
    /// @brief La classe @ref Admin permet de décrire un Administrateur dans l'application EasyTicket
    /// @param  id_user l'identifiant de l'administrateur
    /// @param  nom     le nom de l'administrateur
    /// @param  prenom  le prenom de l'administrateur
    /// @param  mail    le mail de l'administrateur
    Admin();
    Admin(
            std::string id_user,
            std::string nom,
            std::string prenom,
            std::string mdp,
            std::string id,
            std::string mail);

    /// @brief Cette méthode permet de savoir si un utilisateur est un @ref Admin ou non
    /// @return
    bool estUnAdmin();

    ~Admin();
};

#endif // ADMIN_H
