#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include <vector>

#include "personnel.h"
#include "categorie.h"

/// @brief La classe Technicien permet de décrire un utilisateur appartenant au Personnel avec les droits technicien sur le programme EasyTicket.
/// @authors Claire Kurth, Nicolas Robert, Victor Dallé
/// @version 1.1
class Technicien : public Personnel
{
private :
    /// @brief Catégories maitrisées par le technicien.
    std::vector<Categorie*> categories;

public:
    /// @brief Constructeur par défaut de la classe.
    Technicien();

    /// @brief Constructeur utilisant les données personnelles du technicien.
    /// @param id          L'identifiant du technicien.
    /// @param nom         Le nom du technicien.
    /// @param prenom      Le prénom du technicien.
    /// @param mdp         Le mot de passe du technicien.
    /// @param mail        Le mail du technicien.
    /// @param categories  La liste de catégories maitrisées par le technicien.
    Technicien (
        std::string id,
        std::string nom,
        std::string prenom,
        std::string mdp,
        std::string mail,
        std::vector<Categorie*> categories
    );

    /// @brief Destructeur de la classe.
    ~Technicien();

    /// @brief Cette méthode permet de vérifier si l'Utilisateur est un Technicien.
    /// @return true
    bool estUnTechnicien();

};

#endif // TECHNICIEN_H
