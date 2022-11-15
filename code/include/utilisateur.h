#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <vector>
#include <iostream>
// #include <ticket.h>
class Ticket; // forward declaration https://stackoverflow.com/a/8526965

/// @brief La classe Utilisateur est une classe abstraite qui permet de décrire l'ensemble des utilisateurs dans l'application EasyTicket.
///
/// Elle sert de bloc de base aux autres classes comme Client, Personnel, Admin, Technicien et Ingenieur.
class Utilisateur {
protected:
    /// @brief Champs contenant l'identifiant de l'utilisateur.
    std::string id;
    /// @brief Champs contenant le nom de l'utilisateur.
    std::string nom;
    /// @brief Champs contenant le prénom de l'utilisateur.
    std::string prenom;
    /// @brief Champs contenant le mot de passe de l'utilisateur.
    std::string mdp;
    /// @brief Champs contenant l'adresse e-mail de l'utilisateur.
    std::string mail;
    /// @brief Champs contenant la liste des tickets associée à l'utilisateur.
    std::vector<Ticket*> liste_tickets;

public:
    /// @brief Constructeur par défaut de la classe.
    Utilisateur();

    /// @brief Constructeur utilisant les données personnelles de l'utilisateur.
    /// @param  id          L'identifiant de l'utilisateur.
    /// @param  nom         Le nom de l'utilisateur.
    /// @param  prenom      Le prénom de l'utilisateur.
    /// @param  mdp         Le mot de passe de l'utilisateur.
    /// @param  mail        Le mail de l'utilisateur.
    Utilisateur(
            std::string id,
            std::string nom,
            std::string prenom,
            std::string mdp,
            std::string mail
    );

    /// @brief Destructeur virtuel pour rendre la classe abstraite.
    virtual ~Utilisateur() = default;

    /// @brief Cette méthode permet de récupérer l'identifiant de l'utilisateur.
    /// @return L'identifiant de l'utilisateur.
    std::string getID() const;

    /// @brief Cette méthode permet de définir l'identifiant de l'utilisateur.
    /// @param value Le nouvel identifiant de l'utilisateur.
    void setID(const std::string &value);

    /// @brief Cette méthode permet de récupérer le nom de l'utilisateur.
    /// @return Le nom de l'utilisateur.
    std::string getNom() const;

    /// @brief Cette méthode permet de définir le nom de l'utilisateur.
    /// @param value Le nouveau nom de l'utilisateur.
    void setNom(const std::string &value);

    /// @brief Cette méthode permet de récupérer le prénom de l'utilisateur.
    /// @return Le prénom de l'utilisateur.
    std::string getPrenom() const;

    /// @brief Cette méthode permet de définir le prénom de l'utilisateur.
    /// @param value Le nouveau prénom de l'utilisateur.
    void setPrenom(const std::string &value);

    /// @brief Cette métode permet de récupérer le mot de passe de l'utilisateur.
    /// @return Le mot de passe de l'utilisateur.
    std::string getMDP() const;

    /// @brief Cette méthode permet de définir le mot de passe de l'utilisateur.
    /// @param value Le nouveau mot de passe de l'utilisateur.
    void setMDP(const std::string &value);

    /// @brief Cette méthode permet de récupérer le mail de l'utilisateur.
    /// @return Le mail de l'utilisateur.
    std::string getMail() const;

    /// @brief Cette méthode permet de définir le mail de l'utilisateur.
    /// @param value Le nouveau mail de l'utilisateur.
    void setMail(const std::string &value);

    /// @brief Cette méthode permet de vérifier si un utilisateur est un Client.
    /// @return false
    bool estUnClient();

    /// @brief Cette méthode permet de vérifier si l'utilisateur est un Personnel.
    /// @return false
    bool estUnPersonnel();

    /// @brief Cette méthode permet de vérifier si un utilisateur est un Admin.
    /// @return false
    bool estUnAdmin();
};

#endif // UTILISATEUR_H
