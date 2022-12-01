#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <QString>
#include "utilisateur.h"
class Ticket;

/// @brief La classe Message est la classe correspondant à un Message sur un Ticket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.6
class Message
{
private:
    /// @brief Champs contenant l'id du Message.
    QString id_message;
    /// @brief Champs contenant la date d'envoi du Message.
    QString date_envoi;
    /// @brief Champs contenant l'Utilisateur auteur du Message.
    Utilisateur *user;
    /// @brief Champs contenant le Ticket auquel est rattaché le Message.
    Ticket *ticket;
    /// @brief Champs contenant le message du Message.
    QString message;

public:
    /// @brief Le constructeur par défaut de la classe.
    Message();

    /// @brief Constructeur de message.
    /// @param id_message   L'id du message.
    /// @param date_envoie  La date d'envoi du message.
    /// @param *user        Pointeur sur l'Utilisateur à l'origine du message.
    /// @param *ticket      Pointeur sur le Ticket rattaché au message.
    /// @param message      Le message du Message.
    Message(QString id_message, QString date_envoi, Utilisateur *user, Ticket *ticket, QString message);

    /// @brief Cette méthode permet de récupérer l'identifiant du message.
    /// @return l'identifiant du message
    QString getId_message() const;

    /// @brief Cette méthode permet de définir l'identifiant du message.
    /// @param value Le nouvel identifiant du message
    void setId_message(const QString &value);

    /// @brief Cette méthode permet de récupérer la date à laquelle le message a été envoyé.
    /// @return la date d'envoi du message
    QString getDate_envoi() const;

    /// @brief Cette méthode permet de définir la date à laquelle a été envoyé le message.
    /// @param  value la nouvelle date d'envoi
    void setDate_envoi(QString value);

    /// @brief Cette méthode permet de récupérer l'Utilisateur auteur du message.
    /// @return le nouvel Utilisateur.
    Utilisateur* getUser() const;

    /// @brief Cette méthode permet de définir l'Utilisateur auteur du message.
    /// @param  value Le nouvel Utilisateur.
    void setUser(Utilisateur* &value);

    /// @brief Cette méthode permet de récupérer le Ticket dans lequel se trouve le message.
    /// @return la classe Ticket
    Ticket* getTicket() const;

    /// @brief Cette méthode définis le Ticket dans lequel se trouve le message.
    /// @param  value Le nouveau Ticket
    void setTicket(Ticket* &value);

    /// @brief Cette méthode permet d'afficher les attributs de la classe pour le débug.
    /// @return String avec les infos de la classe.
    QString toString();

    /// @brief  Cette méthode permet de récupérer le contenu d'un message.
    /// @return le contenu du message.
    QString getMessage() const;

    /// @brief  Cette méthode permet définir le contenu du message.
    /// @param  value   Le nouveau contenu du message.
    void setMessage(const QString &value);

    /// @brief Descructeur de la classe.
    ~Message() {}

};

#endif // MESSAGE_H
