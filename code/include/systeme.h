#ifndef SYSTEME_H
#define SYSTEME_H

#include <QString>

/// @brief La classe Systeme permet de décrire un système d'exploitation dans l'application EasyTicket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.1
class Systeme
{
private:
    /// @brief Champs contenant l'id du Système.
    int id_systeme;
    /// @brief Champs contenant le nom du Système.
    QString nom;

public:
    /// @brief Constructeur par défaut.
    Systeme();

    /// @brief  Constructeur de la classe Systeme.
    /// @param  id_systeme  L'identifiant du système d'exploitation
    /// @param  nom         Le nom du système d'exploitation
    Systeme(
            int id_systeme,
            QString nom);

    /// @brief Cette méthode permet de récupérer l'identifiant du système
    /// @return l'identifiant du système
    int getId_systeme() const;

    /// @brief Cette méthode permet de définir l'identifiant du système
    /// @param  value   l'identifiant du système
    void setId_systeme(const int &value);

    /// @brief Cette méthode permet de récupérer le nom du système
    /// @return le nom du système
    QString getNom() const;

    /// @brief Cette méthode permet de définir le nom du système
    /// @param  value   le nouveau nom du système
    void setNom(const QString &value);

    ~Systeme() {}
};

#endif // SYSTEME_H
