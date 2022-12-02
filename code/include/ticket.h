#ifndef TICKET_H
#define TICKET_H

#include <vector>
#include <QString>

#include "systeme.h"
#include "logiciel.h"
#include "client.h"
#include "personnel.h"
#include "message.h"
#include "categorie.h"

/// @brief La classe Ticket permet de décrire un ticket dans l'application EasyTicket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.6

class Ticket
{
private:
    /// @brief Champs contenant l'id du Ticket.
    int id_ticket;
    /// @brief Champs contenant la date de création du Ticket.
    QString date_creation;
    /// @brief Champs contenant la date de fermeture du Ticket.
    QString date_fermeture;
    /// @brief Champs contenant le Systeme d'exploitation du Client auteur du Ticket.
    Systeme systeme;
    /// @brief Champs contenant le Logiciel sur lequel il y a un problème.
    Logiciel logiciel;
    /// @brief Champs contenant la Categorie du Ticket.
    Categorie categorie;
    /// @brief Champs contenant la liste des Messages du Ticket.
    std::vector<Message*> liste_messages;
    /// @brief Champs contenant le Client à l'origine du Ticket.
    Client client;
    /// @brief Champs contenant le Personnel attitré à la résolution du Ticket.
    Personnel personnel;

public:
    /// @brief Constructeur par défaut.
    Ticket();

    /// @brief Constructeur de la classe Ticket avec les informations obligatoires.
    /// @param  id_ticket       l'identifiant du ticket
    /// @param  date_creation   la date de création du ticket
    /// @param  categorie       la Categorie concernée par le ticket
    /// @param  auteur          le Client auteur du ticket
    Ticket(QString date_creation,
           Categorie categorie,
           Client auteur,
           int id_ticket = -1);

    /// @brief Cette méthode permet de récupérer l'identifiant du Ticket
    /// @return L'identifiant du ticket
    int getId_ticket() const;

    /// @brief Cette méthode permet de définir l'identifiant du Ticket
    /// @param  value Le nouvel identifiant du ticket
    void setId_ticket(const int &value);

    /// @brief Cette méthode permet de récupérer la date de création du Ticket
    /// @return La date de création du ticket
    QString getDate_creation() const;

    /// @brief Cette méthode permet de définir la date de création du Ticket
    /// @param  value La nouvelle date de création du Ticket
    void setDate_creation(QString value);

    /// @brief Cette méthode permet de récupérer la date de fermeture du Ticket
    /// @return La date de fermeture du ticket
    QString getDate_fermeture() const;

    /// @brief Cette méthode permet de définir la date de fermeture du Ticket
    /// @param  value La nouvelle date de fermeture du Ticket
    void setDate_fermeture(QString value);

    /// @brief Cette méthode permet de récupérer le système d'exploitation concerné par le Ticket
    /// @return La date de fermeture du ticket
    Systeme getSysteme() const;

    /// @brief Cette méthode permet de définir le Systeme concerné par le Ticket
    /// @param  value Le nouveau Systeme concerné par le Ticket
    void setSysteme(const Systeme &value);

    /// @brief Cette méthode permet récupérer le Logiciel concerné par le Ticket
    /// @return Le Logiciel concerné par le Ticket
    Logiciel getLogiciel() const;

    /// @brief Cette méthode permet définir le Logiciel concerné par le Ticket
    /// @param  value Le nouveau Logiciel concerné par le Ticket
    void setLogiciel(const Logiciel &value);

    /// @brief Cette méthode permet de récupérer la liste des Message concerné par le Ticket
    /// @return La liste de Message concerné par le ticket
    std::vector<Message*> getListeMessages() const;

    /// @brief Cette méthode permet d'ajouter un Message concerné par le Ticket
    /// @param  value La nouvelle liste de Message
    void addMessage(Message &message);

    /// @brief Cette méthode permet de définir la liste des @Message concerné par le Ticket
    /// @param  value La nouvelle liste de Message
    void setListeMessages(const std::vector<Message*> &value);


    /// @brief Cette méthode permet de définir le Client auteur du Ticket
    /// @param value    Le Client auteur du Ticket
    void setClient(Client &value);

    /// @brief Cette méthode permet de récupérer le Client auteur du Ticket
    /// @return Le Client auteur du Ticket
    Client getClient();

    /// @brief Cette méthode permet de définir le Personnel qui traite le Ticket
    /// @param value Le nouveau Personnel
    void setPersonnel(Personnel &value);

    /// @brief Cette méthode permet de récupérer le Personnel qui traite le Ticket
    /// @return Le Personel traitant le Ticket
    Personnel getPersonnel();

    /// @brief Cette méthode permet d'afficher les attributs de la classe pour le débug.
    QString toString();

    Categorie getCategorie();

    /// @brief Destructeur de la classe.
    ~Ticket() {}
};

#endif // TICKET_H
