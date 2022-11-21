#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <string>

/// @brief La classe Categorie permet de décrire les différentes catégories d'un Ticket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.1
class Categorie
{
private:
    /// @brief Champs contenant l'id de la catégorie.
    std::string id_categorie;
    /// @brief Champs contenant le nom de la catégorie.
    std::string nom_categorie;

public:
    /// @brief Constructeur par défaut.
    Categorie();
    /// @brief  Constructeur de la classe Catégorie.
    /// @param  id_categorie    l'identifiant de la catégorie
    /// @param  nom_categorie   le nom de la catégorie
    Categorie(
            std::string id_categorie,
            std::string nom_categorie);
};

#endif // CATEGORIE_H
