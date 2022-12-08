#ifndef TICKET_H
#define TICKET_H

#include <QVector>
#include <QString>

#include "systeme.h"
#include "logiciel.h"
#include "client.h"
#include "personnel.h"
#include "message.h"
#include "categorie.h"


/// @brief La classe Ticket permet de décrire un ticket dans l'application EasyTicket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 2.6
class Ticket
{
public:
    /// @brief Constructeur par défaut.
    Ticket();

    /// @brief Constructeur de la classe Ticket avec les informations obligatoires.
    /// @param  date_creation   la date et l'heure de création du ticket
    /// @param  categorie       pointeur sur la Categorie concernée par le ticket
    /// @param  auteur          pointeur sur le Client auteur du ticket
    /// @param  id_ticket       l'identifiant du ticket
    Ticket(const QString &date_creation,
           Categorie &categorie,
           Client *auteur,
           int id_ticket = -1);

    /// @brief Destructeur de la classe.
    ~Ticket();

    /// @brief Cette méthode permet de retourner la date et l'heure de création du ticket.
    /// @return la date et l'heure de création du ticket sous la forme d'un QString.
    QString getDate_creation() const;

    /// @brief Cette méthode permet de retourner le pointeur de la Categorie concernée par le ticket.
    /// @return un pointeur sur la categorie concernée par le ticket.
    Categorie getCategorie() const;

    /// @brief Cette méthode permet de retourner le pointeur du Logiciel concerné par le ticket.
    /// @return un pointeur sur le logiciel concerné par le ticket.
    Logiciel getLogiciel() const;

    /// @brief Cette méthode permet de retourner le pointeur du Systeme concerné par le ticket.
    /// @return un pointeur sur le systeme concerné par le ticket.
    Systeme getSysteme() const;

    /// @brief Cette méthode permet de retourner le pointeur du Client auteur du ticket.
    /// @return un pointeur sur le Client concerné par le ticket.
    Client *getAuteur() const;

    /// @brief Cette méthode permet de retourner la liste des Message appartenant au Ticket
    /// @return La liste de Message appartenant au ticket
    QVector<Message*> getMessages();

    /// @brief Cette méthode permet de retourner le Personnel chargé de résoudre le Ticket.
    /// @return Le Personnel qui résout le Ticket.
    Personnel *getPersonnel() const;

    /// @brief Cette méthode permet de retourner l'identifiant du ticket.
    /// @return l'identifiant du ticket sous la forme d'un int.
    int getId() const;

    /// @brief Cette méthode permet de définir l'identifiant du ticket.
    /// @param id   l'identifiant
    void setId(const int id);

    /// @brief Cette méthode permet de définir le pointeur sur le systeme concerné du ticket.
    /// @param *systeme   le pointeur sur le systeme
    void setSysteme(Systeme &systeme);

    /// @brief Cette méthode permet de définir le pointeur sur le logiciel concerné du ticket.
    /// @param *logiciel   le pointeur sur le logiciel
    void setLogiciel(Logiciel &logiciel);

    /// @brief Cette méthode permet d'ajouter un Message à la liste des messages appartenant au Ticket
    /// @param  *message le pointeur sur le Message à ajouter à la liste des messages du Ticket.
    void addMessage(Message *message);

    /// @brief Cette méthode permet d'attribuer au Ticket un membre du Personnel chargé de résoudre ce Ticket.
    /// @param *personnel Pointeur sur le Personnel chargé de résoudre ce Ticket.
    void setPersonnel(Personnel *personnel);

    /// @brief Cette méthode permet d'afficher les attributs de la classe pour le débug.
    /// @return les attributs de la classe en QString.
    QString toString();

private:
    /// @brief Champs correspondant à l'heure et la date de création du ticket.
    QString date_creation;
    /// @brief Champs correspondant à l'heure et la date de création du ticket.
    QString date_fermeture;
    /// @brief Champs correspondant à la Categorie concernée par le ticket.
    Categorie categorie;
    /// @brief Champs correspondant au Logiciel concerné par le ticket.
    Logiciel logiciel;
    /// @brief Champs correspondant au Systeme concerné par le ticket.
    Systeme systeme;
    /// @brief Champs correspondant à la liste des messages contenant les Message appartenant au ticket.
    QVector<Message*> liste_messages;
    /// @brief Champs correspondant au Client auteur du ticket.
    Client *auteur;
    /// @brief Champs correspondant au Personnel chargé de résoudre le ticket.
    Personnel *personnel;
    /// @brief Champs correspondant à l'identifiant du ticket.
    int id_ticket;

};



#endif // TICKET_H
