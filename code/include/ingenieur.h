#ifndef INGENIEUR_H
#define INGENIEUR_H

#include "personnel.h"

/// @brief La classe Ingenieur permet de décrire un utilisateur appartenant au Personnel avec les droits ingénieur sur le programme EasyTicket.
/// @authors Claire Kurth, Nicolas Robert, Victor Dallé
/// @version 1.1
class Ingenieur : public Personnel {
public:
    /// @brief Constructeur par défaut de la classe.
    Ingenieur();

    /// @brief Constructeur utilisant les données personnelles de l'ingénieur.
    /// @param id          L'identifiant de l'ingénieur.
    /// @param nom         Le nom de l'ingénieur.
    /// @param prenom      Le prénom de l'ingénieur.
    /// @param mdp         Le mot de passe de l'ingénieur.
    /// @param mail        Le mail de l'ingénieur.
    Ingenieur (
        std::string id,
        std::string nom,
        std::string prenom,
        std::string mdp,
        std::string mail
    );

    /// @brief Destructeur de la classe.
    ~Ingenieur();

    /// @brief Cette méthode permet de vérifier si l'Utilisateur est un Ingénieur.
    /// @return true
    bool estUnIngenieur();
};

#endif // INGENIEUR_H
