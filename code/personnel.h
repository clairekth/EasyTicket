#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "utilisateur.h"

/// @brief La classe Personnel est une classe abstraite qui permet de décrire l'ensemble des Utilisateur appartenant
/// au personnel dans l'application EasyTicket.
/// Elle hérite de la classe Utilisateur et sert de classe mère à la classe Ingenieur.
/// @authors Claire Kurth, Nicolas Robert, Victor Dallé
/// @version 2.5
class Personnel: public Utilisateur
{
public:
    /// @brief Constructeur par défaut.
    Personnel();

    /// @brief Constructeur de la classe Personnel.
    /// @param id       l'identifiant du personnel.
    /// @param nom      le nom du personnel.
    /// @param prenom   le prenom du personnel.
    /// @param email    l'email du personnel.
    Personnel(const QString &id,
              const QString &nom,
              const QString &prenom,
              const QString &email);

    /// @brief Destructeur de la classe Personnel.
    virtual ~Personnel();

    /// @brief Cette méthode permet d'afficher les attributs de la classe pour le débug.
    /// @return "Personnel" ainsi que le nom et le prénom du Personnel en QString.
    virtual QString toString() const;

    /// @brief Cette méthode permet de savoir si l'Utilisateur est un Personnel.
    /// @return true
    bool estUnPersonnel();

    /// @brief Cette méthode permet de savoir si le Personnel est un Ingenieur.
    /// @return false
    virtual bool estUnIngenieur();
};

#endif // PERSONNEL_H
