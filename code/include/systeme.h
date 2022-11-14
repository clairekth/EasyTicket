#ifndef SYSTEME_H
#define SYSTEME_H

#include <string>

class Systeme
{
private:
    std::string id_systeme;
    std::string nom;
public:
    Systeme();
    /// @brief La classe @ref Systeme permet de décrire un système d'exploitation dans l'application EasyTicket.
    /// @param  id_systeme  L'identifiant du système d'exploitation
    /// @param  nom         Le nom du système d'exploitation
    Systeme(
            std::string id_systeme,
            std::string nom);

    /// @brief Cette méthode permet de récupérer l'identifiant du système
    /// @return l'identifiant du système
    std::string getId_systeme() const;

    /// @brief Cette méthode permet de définir l'identifiant du système
    /// @param  value   l'identifiant du système
    void setId_systeme(const std::string &value);

    /// @brief Cette méthode permet de récupérer le nom du système
    /// @return le nom du système
    std::string getNom() const;

    /// @brief Cette méthode permet de définir le nom du système
    /// @param  value   le nouveau nom du système
    void setNom(const std::string &value);

    ~Systeme() {}
};

#endif // SYSTEME_H
