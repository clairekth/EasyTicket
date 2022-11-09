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

    std::string getId_systeme() const;
    void setId_systeme(const std::string &value);
    std::string getNom() const;
    void setNom(const std::string &value);
};

#endif // SYSTEME_H
