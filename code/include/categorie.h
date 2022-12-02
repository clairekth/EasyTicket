#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QString>

/// @brief La classe Categorie permet de décrire les différentes catégories d'un Ticket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.5
class Categorie
{
private:
    /// @brief Champs contenant l'id de la catégorie.
    int id_categorie;

    /// @brief Champs contenant le nom de la catégorie.
    QString nom_categorie;

public:
    /// @brief Constructeur par défaut.
    Categorie();

    /// @brief  Constructeur de la classe Catégorie.
    /// @param  id_categorie    l'identifiant de la catégorie
    /// @param  nom_categorie   le nom de la catégorie
    Categorie(
            int id_categorie,
            QString nom_categorie);

    /// @brief Méthode permettant de récupérer le nom de la Categorie.
    /// @return nom_categorie
    QString getNom();

    /// @brief Méthode retournant l'id de la catégorie.
    /// @return L'id de la categorie.
    int getID();

};

#endif // CATEGORIE_H
