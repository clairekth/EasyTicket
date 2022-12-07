#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDebug>

#include "utilisateur.h"

/// @brief La classe Client permet de décrire un utilisateur avec les droits clients sur le programme EasyTicket.
/// Elle hérite de la classe Utilisateur.
/// @authors Claire Kurth, Nicolas Robert, Victor Dallé
/// @version 2.5
class Client: public Utilisateur
{
public:
    /// @brief Constructeur par défaut.
    Client();

    /// @brief Constructeur de la classe Client.
    /// @param id       l'identifiant du client.
    /// @param nom      le nom du client.
    /// @param prenom   le prenom du client.
    /// @param email    l'email du client.
    Client(const QString &id,
           const QString &nom,
           const QString &prenom,
           const QString &email);

    /// @brief Destructeur de la classe Client.
    ~Client();

    /// @brief Cette méthode permet d'afficher les attributs de la classe pour le débug.
    /// @return "Client" ainsi que le nom et le prénom du client en QString.
    QString toString() const;

    /// @brief Cette méthode permet de savoir si l'Utilisateur est un Client.
    /// @return true
    bool estUnClient();
};

#endif // CLIENT_H
