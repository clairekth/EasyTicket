#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "personnel.h"
#include "categorie.h"

class Technicien : public Personnel
{
private :
    std::vector<Categorie*> categories;

public:
    Technicien();

    /// @brief Cette classe permet de décrire un @ref Technicien dans l'application EasyTicket
    /// @param  id_u                l'identifiant du technicien
    /// @param  n                   le nom du technicien
    /// @param  p                   le prénom du technicien
    /// @param  motdepasse          le mot de passe du technicien
    /// @param  mail                le mail du technicien
    /// @param  liste_categories    la liste des catégories que peut traiter le technicien
    Technicien(
            std::string id_u,
            std::string n,
            std::string p,
            std::string motdepasse,
            std::string email,
            std::vector<Categorie*> liste_categories);


    /// @brief Cette méthode permet de vérifier si un @ref Utilisateur est un @ref Technicien
    /// @return true
    bool estUnTechnicien();
};

#endif // TECHNICIEN_H
