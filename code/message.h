#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>

#include "utilisateur.h"
class Utilisateur;
class Ticket;

/// @brief La classe Message est la classe correspondant à un Message sur un Ticket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 2.3
class Message
{
public:
    /// @brief Constructeur par défaut.
    Message();

    /// @brief Constructeur de la classe Message.
    /// @param date_envoie  La date et l'heure d'envoi du message.
    /// @param *user        Pointeur sur l'Utilisateur à l'origine du message.
    /// @param *ticket      Pointeur sur le Ticket rattaché au message.
    /// @param message      Le message du Message.
    /// @param id_message   L'id du message.
    Message(const QString date_envoi, Utilisateur *user, Ticket *ticket, QString message, int id_message = -1);

    /// @brief Destructeur de la classe.
    ~Message();

    /// @brief Cette méthode définie le Ticket dans lequel se trouve le message.
    /// @param ticket le Ticket dans lequel se trouve le message.
    void setTicket(Ticket *ticket);

    /// @brief Cette méthode permet de retourner le contenu du message.
    /// @return le contenu du message en QString.
    QString getMessage() const;

    /// @brief Cette méthode permet de retourner la date d'envoi du message.
    /// @return la date et l'heure d'envoi sous forme de QString.
    QString getDate_envoi() const;

    /// @brief Cette méthode permet de retourner le pointeur sur l'Utilisateur auteur du message.
    /// @return un pointeur sur l'Utilisateur auteur du message.
    Utilisateur* getAuteur();

    /// @brief Cette méthode permet de retourner le pointeur sur le Ticket rattaché au message.
    /// @return un pointeur sur le Ticket rattaché au message.
    Ticket* getTicket();

private:
    /// @brief Champs correspondant à l'heure et la date d'envoi du message.
    QString date_envoi;

    /// @brief Champs correspondant à l'Utilisateur auteur du message.
    Utilisateur *auteur;

    /// @brief Champs correspondant au Ticket rattaché au message.
    Ticket *ticket;

    /// @brief Champs correspondant au contenu du message.
    QString message;

    /// @brief Champs correspondant à l'id du message.
    int id_message;
};

#endif // MESSAGE_H
