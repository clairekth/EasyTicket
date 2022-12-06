#ifndef SYSTEME_H
#define SYSTEME_H

#include <QString>

/// @brief La classe Systeme permet de décrire les différents systèmes d'exploitation d'un Ticket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 2.5
class Systeme
{
public:
    /// @brief Constructeur par défaut.
    Systeme();

    /// @brief  Constructeur de la classe Systeme.
    /// @param  id_systeme      l'identifiant du système.
    /// @param  nom_systeme     le nom du système.
    Systeme(const int id_systeme, const QString &nom_systeme);

    /// @brief Destructeur de la classe.
    ~Systeme();

    /// @brief Méthode retournant l'id du système.
    /// @return un int représentant l'id du système.
    int getId() const;

    /// @brief Méthode retournant le nom du système.
    /// @return le nom du système en QString.
    QString getNom() const;
private:
    /// @brief Champs correspondant à l'id du système.
    int id_systeme;
    /// @brief Champs correspondant au nom du système.
    QString nom_systeme;
};

#endif // SYSTEME_H
