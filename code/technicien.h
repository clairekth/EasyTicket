#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "personnel.h"

class Technicien : public Personnel
{
public:
    /// @brief Constructeur par défaut.
    Technicien();

    /// @brief Constructeur de la classe Technicien.
    /// @param id       l'identifiant du technicien.
    /// @param nom      le nom du technicien.
    /// @param prenom   le prenom du technicien.
    /// @param email    l'email du technicien.
    Technicien(const QString &id,
              const QString &nom,
              const QString &prenom,
              const QString &email);

    /// @brief Destructeur de la classe.
    ~Technicien();

    /// @brief Cette méthode permet de savoir si le Personnel est un Technicien.
    /// @return true
    bool estUnTechnicien();

    /// @brief Cette méthode permet d'afficher les attributs de la classe pour le débug.
    /// @return "Technicien" ainsi que le nom et le prénom du technicien en QString.
    QString toString() const;
};

#endif // TECHNICIEN_H
