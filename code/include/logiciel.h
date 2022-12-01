#ifndef LOGICIEL_H
#define LOGICIEL_H

#include <QString>

/// @brief La classe Logiciel permet de décrire un logiciel dans l'application EasyTicket
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.5
class Logiciel
{
private:
    /// @brief Champs contenant l'id du logiciel.
    QString id_logiciel;
    /// @brief Champs contenant le nom du logiciel.
    QString nom;

public:
    /// @brief Constructeur par défaut.
    Logiciel();

    /// @brief  Constructeur de la classe logiciel.
    /// @param  id_logiciel     l'identifiant du logiciel
    /// @param  nom             le nom du logiciel
    Logiciel(QString id_logiciel, QString nom);

    /// @brief Méthode permettant de récupérer le nom du Logiciel.
    /// @return nom
    QString getNom();
};

#endif // LOGICIEL_H
