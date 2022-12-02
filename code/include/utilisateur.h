#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <vector>
#include <iostream>
#include <QString>

class Ticket;

/// @brief La classe Utilisateur est une classe abstraite qui permet de décrire l'ensemble des utilisateurs dans l'application EasyTicket.
///
/// Elle sert de classe mère aux autres classes comme Client, Personnel et Admin.
/// @authors Claire Kurth, Nicolas Robert, Victor Dallé
/// @version 1.1
class   Utilisateur {
protected:
    /// @brief Champs contenant l'identifiant de l'utilisateur.
    QString id;
    /// @brief Champs contenant le nom de l'utilisateur.
    QString nom;
    /// @brief Champs contenant le prénom de l'utilisateur.
    QString prenom;
    /// @brief Champs contenant le mot de passe de l'utilisateur.
    QString mdp;
    /// @brief Champs contenant l'adresse e-mail de l'utilisateur.
    QString mail;
    /// @brief Champs contenant la liste des tickets associée à l'utilisateur.
    std::vector<Ticket*> liste_tickets;

public:
    /// @brief Constructeur par défaut de la classe.
    Utilisateur();

    /// @brief Constructeur utilisant les données personnelles de l'utilisateur.
    /// @param id          L'identifiant de l'utilisateur.
    /// @param nom         Le nom de l'utilisateur.
    /// @param prenom      Le prénom de l'utilisateur.
    /// @param mdp         Le mot de passe de l'utilisateur.
    /// @param mail        Le mail de l'utilisateur.
    Utilisateur (
        QString id,
        QString nom,
        QString prenom,
        QString mdp,
        QString mail
    );

    /// @brief Destructeur virtuel pour rendre la classe abstraite.
    virtual ~Utilisateur();

    /// @brief Cette méthode permet de récupérer l'identifiant de l'utilisateur.
    /// @return L'identifiant de l'utilisateur.
    QString getID() const;

    /// @brief Cette méthode permet de récupérer le nom de l'utilisateur.
    /// @return Le nom de l'utilisateur.
    QString getNom() const;

    /// @brief Cette méthode permet de récupérer le prénom de l'utilisateur.
    /// @return Le prénom de l'utilisateur.
    QString getPrenom() const;


    /// @brief Cette méthode permet de vérifier si l'Utilisateur est un Client.
    /// @return false
    virtual bool estUnClient();

    /// @brief Cette méthode permet de vérifier si l'Utilisateur est un Personnel.
    /// @return false
    virtual bool estUnPersonnel();

    /// @brief Cette méthode permet de vérifier si l'Utilisateur est un Admin.
    /// @return false
    virtual bool estUnAdmin();

    /// @brief Cette méthode permet de vérifier si l'Utilisateur est un Technicien.
    /// @return false
    virtual bool estUnTechnicien();

    /// @brief Cette méthode permet de vérifier si l'Utilisateur est un Ingenieur.
    /// @return false
    virtual bool estUnIngenieur();

    /// @brief Cette méthode permet d'afficher les attributs de la classe pour le débug.
    QString toString();
};

#endif // UTILISATEUR_H
