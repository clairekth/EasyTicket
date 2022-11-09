#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <string>

class Categorie
{
private:
    std::string id_categorie;
    std::string nom_categorie;

public:
    Categorie();
    /// @brief la classe @ref Categorie permet de décrire une catégorie de ticket dans l'application EasyTicket.
    /// @param  id_categorie    l'identifiant de la catégorie
    /// @param  nom_categorie   le nom de la catégorie
    Categorie(
            std::string id_categorie,
            std::string nom_categorie);
};

#endif // CATEGORIE_H
