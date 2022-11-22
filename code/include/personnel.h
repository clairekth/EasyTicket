#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "utilisateur.h"

/// @brief La classe Personnel est une classe abstraite qui permet de décrire l'ensemble des Utilisateur appartenant au personnel dans l'application EasyTicket.
///
/// Elle sert de classe mère aux autres classes comme Ingenieur et Technicien.
/// @authors Claire Kurth, Nicolas Robert, Victor Dallé
/// @version 1.1
class Personnel : public Utilisateur {
public:
    /// @brief Constructeur par défaut de la classe.
    Personnel();

    /// @brief Constructeur utilisant les données personnelles du personnel.
    /// @param id          L'identifiant du personnel.
    /// @param nom         Le nom du personnel.
    /// @param prenom      Le prénom du personnel.
    /// @param mdp         Le mot de passe du personnel.
    /// @param mail        Le mail du personnel.
    Personnel (
        std::string id,
        std::string nom,
        std::string prenom,
        std::string mdp,
        std::string mail
    );

    /// @brief Destructeur virtuel pour rendre la classe Personnel abstraite.
    virtual ~Personnel();

    /// @brief  Cette méthode permet de vérifier si l'Utilisateur est un Personnel.
    /// @return true
    virtual bool estUnPersonnel();
};

#endif // PERSONNEL_H
