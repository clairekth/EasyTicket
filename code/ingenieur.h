#ifndef INGENIEUR_H
#define INGENIEUR_H

#include "personnel.h"


/// @brief La classe Ingenieur permet de décrire un utilisateur appartenant au Personnel avec les droits ingénieur sur
/// le programme EasyTicket.
/// Elle hérite de la classe Personnel.
/// @authors Claire Kurth, Nicolas Robert, Victor Dallé
/// @version 2.3
class Ingenieur: public Personnel
{
public:
    /// @brief Constructeur par défaut.
    Ingenieur();

    /// @brief Constructeur de la classe Ingenieur.
    /// @param id       l'identifiant du ingenieur.
    /// @param mdp      le mot de passe du ingenieur.
    /// @param nom      le nom du ingenieur.
    /// @param prenom   le prenom du ingenieur.
    /// @param email    l'email du ingenieur.
    Ingenieur(const QString id,
              const QString mdp,
              const QString nom,
              const QString prenom,
              const QString email);

    /// @brief Destructeur de la classe.
    ~Ingenieur();

    /// @brief Cette méthode permet de savoir si le Personnel est un Ingenieur.
    /// @return true
    bool estUnIngenieur();

    /// @brief Cette méthode permet d'afficher les attributs de la classe pour le débug.
    /// @return "Ingenieur" ainsi que le nom et le prénom de l'ingénieur en QString.
    QString toString() const;


};

#endif // INGENIEUR_H
