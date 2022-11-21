#ifndef MESSAGE_H
#define MESSAGE_H

// pour les affichages
#include <iostream>
#include "utilisateur.h"
class Ticket;

/// @brief La classe Message est la classe correspondant à un Message sur un Ticket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.1
class Message
{
private:
    /// @brief Champs contenant l'id du message.
    std::string id_message;
    /// @brief Champs contenant la date d'envoie du message.
    double date_envoie;
    /// @brief Champs contenant l'Utilisateur auteur du message.
    Utilisateur *user;
    /// @brief Champs contenant le Ticket auquel est rattaché le message.
    Ticket *ticket;

public:
    /// @brief Le constructeur par défaut de la classe.
    Message();

    /// @brief Constructeur de message.
    /// @param id_message   L'id du message.
    /// @param date_envoie  La date d'envoie du message.
    /// @param *user        Pointeur sur l'Utilisateur à l'origine du message.
    /// @param *ticket      Pointeur sur le Ticket rattaché au message.
    Message(std::string id_message, double date_envoie, Utilisateur *user, Ticket *ticket);

    /// @brief Cette méthode permet de récupérer l'identifiant du message.
    /// @return l'identifiant du message
    std::string getId_message() const;

    /// @brief Cette méthode permet de définir l'identifiant du message.
    /// @param  value   Le nouvel identifiant du message
    void setId_message(const std::string &value);

    /// @brief Cette méthode permet de récupérer la date à laquelle le message a été envoyé.
    /// @return la date d'envoie du message
    double getDate_envoie() const;

    /// @brief Cette méthode permet de définir la date à laquelle a été envoyé le message.
    /// @param  value la nouvelle date d'envoie
    void setDate_envoie(double value);

    /// @brief Cette méthode permet de récupérer l' @ref Users qui est l'auteur du message.
    /// @param  value   le nouveau @ref Users
    Utilisateur* getUser() const;

    /// @brief Cette méthode permet de définir l' @ref Utilisateur qui l'auteur du message.
    /// @param  value   le nouveau @ref Users
    void setUser(Utilisateur* &value);

    /// @brief Cette méthode permet de récupérer le @ref Ticket dans lequel se trouve le message.
    /// @return la classe @ref Users
    Ticket* getTicket() const;

    /// @brief Cette méthode définis le @ref Ticket dans lequel se trouve le message.
    /// @param  value   le nouveau @ref Ticket
    void setTicket(Ticket* &value);

    /// @brief Descructeur de la classe.
    ~Message() {}
}; // fin de la classe Message

#endif // MESSAGE_H
