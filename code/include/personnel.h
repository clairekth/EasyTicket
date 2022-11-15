#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "utilisateur.h"

class Personnel : public Utilisateur
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

    /// @brief Déconstructeur virtuel pour rendre la classe Personnel abstraite
    virtual ~Personnel() = default;

    /// @brief  Cette méthode permet de vérifier si le @ref Utilisateur est un @ref Personnel
    /// @return true
    bool estUnPersonnel();

    /// @brief  Cette méthode permet de vérifier si le @ref Personnel est un @ref Personnel
    /// @return false
    bool estUnIngenieur();

    /// @brief Cette méthode permet de vérifier si un @ref Personnel est un @ref Technicien
    /// @return false
    bool estUnTechnicien();
};

#endif // PERSONNEL_H
