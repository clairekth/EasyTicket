#ifndef LOGICIEL_H
#define LOGICIEL_H

#include <QString>

/// @brief La classe Logiciel permet de décrire les différents logiciel d'un Ticket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 2.3
class Logiciel
{
public:
    /// @brief Constructeur par défaut.
    Logiciel();

    /// @brief  Constructeur de la classe Logiciel.
    /// @param  id_logiciel   l'identifiant du logiciel
    /// @param  nom_logiciel   le nom dulogiciel
    Logiciel(const int id_logiciel, const QString nom_logiciel);

    /// @brief Destructeur de la classe.
    ~Logiciel();

    /// @brief Méthode retournant l'id du logiciel.
    /// @return un int représentant l'id du logiciel.
    int getId() const;

    /// @brief Méthode retournant le nom du logiciel.
    /// @return le nom du logiciel en QString.
    QString getNom() const;

private:
    /// @brief Champs correspondant à l'id du logiciel.
    int id_logiciel;
    /// @brief Champs correspondant au nom dud logiciel.
    QString nom_logiciel;
};

#endif // LOGICIEL_H
