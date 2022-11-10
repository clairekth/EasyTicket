#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <ticket.h>

class Users
{
public:

private:
    std::string id_user;
    std::string nom;
    std::string prenom;
    std::string mdp;
    std::string mail;
    std::vector<Ticket> liste_tickets;

public:
    Users();
    /// @brief  La classe @ref Users permet de décrire un Utilisateur dans l'application EasyTicket.
    /// @param  id_u        L'identifiant de l'utilisateur
    /// @param  n           Le nom de l'utilisateur
    /// @param  p           Le prénm de l'utilisateur
    /// @param  motdepasse  Le mot de passe de l'utilisateur
    /// @param  email       Le mail de l'utilisateur
    Users(
            std::string id_u,
            std::string n,
            std::string p,
            std::string motdepasse,
            std::string email);

    /// @brief Cette méthode permet de récupérer l'identifiant de l'utilisateur.
    /// @return L'identifiant de l'utilisateur.
    std::string getId_users() const;

    /// @brief Cette méthode permet de définir l'identifiant de l'utilisateur.
    /// @param value le nouvel identifiant de l'utilisateur.
    void setId_users(const std::string &value);

    /// @brief Cette méthode permet de récupérer le nom de l'utilisateur.
    /// @return Le nom de l'utilisateur.
    std::string getNom() const;

    /// @brief Cette méthode permet de définir le nom de l'utilisateur.
    /// @param value le nouveau nom de l'utilisateur.
    void setNom(const std::string &value);

    /// @brief Cette méthode permet de récupérer le prénom de l'utilisateur.
    /// @return Le prénom de l'utilisateur.
    std::string getPrenom() const;

    /// @brief Cette méthode permet de définir le prénom de l'utilisateur.
    /// @param value Le nouveau prénom de l'utilisateur.
    void setPrenom(const std::string &value);

    /// @brief Cette métode permet de récupérer le mot de passe de l'utilisateur.
    /// @return Le mot de passe de l'utilisateur.
    std::string getMdp() const;

    /// @brief Cette méthode permet de définir le mot de passe de l'utilisateur.
    /// @param value Le nouveau mot de passe de l'utilisateur.
    void setMdp(const std::string &value);

    /// @brief Cette méthode permet de récupérer le mail de l'utilisateur.
    /// @return Le mail de l'utilisateur.
    std::string getMail() const;

    /// @brief Cette méthode permet de définir le mail de l'utilisateur.
    /// @param value le mail
    void setMail(const std::string &value);


    bool estUnClient();
    bool estUnPersonnel();
    bool estUnAdmin();

};

#endif // USERS_H
