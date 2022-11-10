#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "users.h"

class Personnel : public Users
{
public:
    Personnel();

    /// @brief La classe @ref Personnel permet de décrire un membre du personnel dans l'application EasyTicket
    /// @param  id_u    l'identifiant du personnel
    /// @param  n       le nom du personnel
    /// @param  p       le prénom du personnel
    /// @param  email   l'email du personnel
    Personnel(
            std::string id_u,
            std::string n,
            std::string p,
            std::string motdepasse,
            std::string email);
    ~Personnel();

    /// @brief  Cette méthode permet de vérifier si l'@ref Utilisateur est un @ref Personnel
    /// @return ???
    bool estUnPersonnel();

    /// @brief  Cette méthode permet de vérifier si l'@ref Ingenieur est un @ref Personnel
    /// @return ???
    bool estUnIngenieur();

    /// @brief  Cette méthode permet de vérifier si le @ref Technicien est un @ref Personnel
    /// @return ???

    bool estUnTechnicien();
};

#endif // PERSONNEL_H
