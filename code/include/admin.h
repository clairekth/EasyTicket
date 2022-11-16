#ifndef ADMIN_H
#define ADMIN_H

#include "utilisateur.h"

/// @brief La classe Admin permet de décrire un utilisateur avec les droits administrateurs sur le programme EasyTicket.
class Admin : public Utilisateur {
public:
    /// @brief Constructeur par défaut de la classe.
    Admin();

    /// @brief Constructeur utilisant les données personnelles de l'admin.
    /// @param id          L'identifiant de l'admin.
    /// @param nom         Le nom de l'admin.
    /// @param prenom      Le prénom de l'admin.
    /// @param mdp         Le mot de passe de l'admin.
    /// @param mail        Le mail de l'admin.
    Admin (
        std::string id,
        std::string nom,
        std::string prenom,
        std::string mdp,
        std::string mail
    );

    /// @brief Destructeur de la classe.
    ~Admin();

    /// @brief Cette méthode permet de vérifier si l'utilisateur est un Admin.
    /// @return true
    bool estUnAdmin();
};

#endif // ADMIN_H
