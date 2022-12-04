#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QString>

/// @brief La classe Categorie permet de décrire les différentes catégories d'un Ticket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 2.3
class Categorie
{
public:
    /// @brief Constructeur par défaut.
    Categorie();

    /// @brief  Constructeur de la classe Categorie.
    /// @param  id_categorie    l'identifiant de la categorie
    /// @param  nom_categorie   le nom de la categorie
    Categorie(const int id_categorie, const QString nom_categorie);

    /// @brief Destructeur de la classe Categorie.
    ~Categorie();

    /// @brief Méthode retournant l'id de la categorie.
    /// @return un int représentant l'id de la categorie.
    int getId() const;

    /// @brief Méthode retournant le nom de la categorie.
    /// @return le nom de la categorie en QString.
    QString getNom() const;

private:
    /// @brief Champs correspondant à l'id de la categorie.
    int id_categorie;

    /// @brief Champs correspondant au nom de la categorie.
    QString nom_categorie;
};

#endif // CATEGORIE_H
