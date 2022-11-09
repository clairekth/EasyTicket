#ifndef USERS_H
#define USERS_H

#include <iostream>

class Users
{
public:
private:
    std::string id_users;
    std::string nom;
    std::string prenom;
    std::string mdp;
    std::string id;
    std::string mail;

public:
    Users();
    /// @brief  La classe @ref Users permet de décrire un Utilisateur dans l'application EasyTicket.
    /// @param  id_users    L'identifiant de l'utilisateur
    /// @param  nom         Le nom de l'utilisateur
    /// @param  prenom      Le prénm de l'utilisateur
    /// @param  mdp         Le mot de passe de l'utilisateur
    /// @param  id          L'identifiant de l'utilisateur
    /// @param  mail        Le mail de l'utilisateur
    Users(
            std::string id_users,
            std::string nom,
            std::string prenom,
            std::string mdp,
            std::string id,
            std::string mail);

    ~Users();
    std::string getId_users() const;
    void setId_users(const std::string &value);
    std::string getNom() const;
    void setNom(const std::string &value);
    std::string getPrenom() const;
    void setPrenom(const std::string &value);
    std::string getMdp() const;
    void setMdp(const std::string &value);
    std::string getId() const;
    void setId(const std::string &value);
    std::string getMail() const;
    void setMail(const std::string &value);
};

#endif // USERS_H
