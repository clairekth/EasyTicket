#ifndef CLIENT_H
#define CLIENT_H

#include "utilisateur.h"

/// @brief La classe Client permet de décrire un utilisateur avec les droits clients sur le programme EasyTicket.
/// @authors Claire Kurth, Nicolas Robert, Victor Dallé
/// @version 1.1
class Client : public Utilisateur {
public:
    /// @brief Constructeur par défaut de la classe.
    Client();

    /// @brief Constructeur utilisant les données personnelles du client.
    /// @param id          L'identifiant du client.
    /// @param nom         Le nom du client.
    /// @param prenom      Le prénom du client.
    /// @param mdp         Le mot de passe du client.
    /// @param mail        Le mail du client.
    Client(
        std::string id,
        std::string nom,
        std::string prenom,
        std::string mdp,
        std::string mail
    );

    /// @brief Destructeur de la classe.
    ~Client();

    /// @brief Cette méthode permet de vérifier si l'Utilisateur est un Client.
    /// @return true
    bool estUnClient();
};

#endif // CLIENT_H
