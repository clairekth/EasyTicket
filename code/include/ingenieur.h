#ifndef INGENIEUR_H
#define INGENIEUR_H

#include "personnel.h"

class Ingenieur : public Personnel
{
public:
    Ingenieur();

    /// @brief La classe @ref Ingenieur permet de décrire un ingénieur dans l'application EasyTicket
    /// @param  id_u        l'identifiant de l'ingénieur
    /// @param  n           le nom de l'ingénieur
    /// @param  p           le prénom de l'ingénieur
    /// @param  motdepasse  le mot de passe de l'ingénieur
    /// @param  email       l'email de l'ingénieur
    Ingenieur(
            std::string id_u,
            std::string n,
            std::string p,
            std::string motdepasse,
            std::string email);

    /// @brief Cette méthode permet de vérifier si un @ref Personnel est un @ref Ingénieur
    /// @return true
    bool estUnIngenieur();
};

#endif // INGENIEUR_H
