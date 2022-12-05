#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QString>
#include <QVector>
#include <QDebug>

class Ticket;

/// @brief La classe Utilisateur est une classe abstraite qui permet de décrire l'ensemble des utilisateurs dans
/// l'application EasyTicket.
///
/// Elle sert de classe mère aux classes Client et Personnel.
/// @authors Claire Kurth, Nicolas Robert, Victor Dallé
/// @version 2.3
class Utilisateur
{
public:
    /// @brief Constructeur par défaut.
    Utilisateur();

    /// @brief Constructeur de la classe Utilisateur.
    /// @param id       l'identifiant du utilisateur.
    /// @param mdp      le mot de passe du utilisateur.
    /// @param nom      le nom du utilisateur.
    /// @param prenom   le prenom du utilisateur.
    /// @param email    l'email du utilisateur.
    Utilisateur(const QString id,
                const QString mdp,
                const QString nom,
                const QString prenom,
                const QString email);

    /// @brief Destructeur de la classe.
    virtual ~Utilisateur();

    /// @brief Cette méthode permet d'afficher les attributs de la classe pour le débug.
    /// @return les attributs de la classe en QString.
    virtual QString toString() const = 0;

    /// @brief Cette méthode permet de retourner le nom de l'utilisateur.
    /// @return le nom de l'utilisateur en QString.
    QString getNom() const;

    /// @brief Cette méthode permet de retourner le prénom de l'utilisateur.
    /// @return le prénom de l'utilisateur en QString.
    QString getPrenom() const;

    /// @brief Cette méthode permet de retourner l'identifiant de l'utilisateur.
    /// @return l'identifiant de l'utilisateur en QString.
    QString getId() const;

    /// @brief Cette méthode permet d'ajouter un Ticket à la liste des tickets de l'utilisateur.
    /// @param *ticket  le Ticket à ajouter à la liste des tickets de l'utilisateur.
    void addTicket(Ticket *ticket);

    /// @brief Cette méthode permet de savoir si l'Utilisateur est un Client.
    /// @return false
    virtual bool estUnClient();

    /// @brief Cette méthode permet de savoir si l'Utilisateur est un Personnel.
    /// @return false
    virtual bool estUnPersonnel();

protected:
    /// @brief Champs correspondant à l'identifiant de l'utilisateur.
    QString id;
    /// @brief Champs correspondant au nom de l'utilisateur.
    QString nom;
    /// @brief Champs correspondant au prénom de l'utilisateur.
    QString prenom;
    /// @brief Champs correspondant à l'email de l'utilisateur.
    QString email;
    /// @brief Champs correspondant au mot de passe de l'utilisateur.
    QString mdp;
    /// @brief Champs correspondant à la liste des tickets contenant les Ticket de l'utilisateur.
    QVector<Ticket*> liste_tickets;
};

#endif // UTILISATEUR_H
