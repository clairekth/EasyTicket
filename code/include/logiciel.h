#ifndef LOGICIEL_H
#define LOGICIEL_H

#include <string>

/// @brief La classe Logiciel permet de décrire un logiciel dans l'application EasyTicket
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.5
class Logiciel
{
private:
    /// @brief Champs contenant l'id du logiciel.
    std::string id_logiciel;
    /// @brief Champs contenant le nom du logiciel.
    std::string nom;

public:
    /// @brief Constructeur par défaut.
    Logiciel();

    /// @brief  Constructeur de la classe logiciel.
    /// @param  id_logiciel     l'identifiant du logiciel
    /// @param  nom             le nom du logiciel
    Logiciel(std::string id_logiciel, std::string nom);

    /// @brief Méthode permettant de récupérer le nom du Logiciel.
    /// @return nom
    std::string getNom();
};

#endif // LOGICIEL_H
