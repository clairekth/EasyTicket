#ifndef LOGICIEL_H
#define LOGICIEL_H

#include <string>

class Logiciel
{
private:
    std::string id_logiciel;
    std::string nom;

public:
    Logiciel();

    /// @brief La classe @ref logiciel permet de décrire un logiciel dans l'application EasyTicket
    /// @param  id_logiciel     l'identifiant du logiciel
    /// @param  nom             le nom du logiciel
    Logiciel(std::string id_logiciel, std::string nom);
};

#endif // LOGICIEL_H
