#ifndef TICKET_H
#define TICKET_H

#include <vector>
#include "systeme.h"
#include "logiciel.h"
#include "client.h"
#include "personnel.h"
#include "message.h"
#include "categorie.h"

/// @brief La classe Ticket permet de décrire un ticket dans l'application EasyTicket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.5

class Ticket
{
private:
    /// @brief Champs contenant l'id du Ticket.
    std::string id_ticket;
    /// @brief Champs contenant la date de création du Ticket.
    std::string date_creation;
    /// @brief Champs contenant la date de fermeture du Ticket.
    std::string date_fermeture;
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
    Ticket(std::string id_ticket,
           std::string date_creation,
           Categorie categorie,
           Client auteur);

    /// @brief Cette méthode permet de récupérer l'identifiant du @ref Ticket
    /// @return l'identifiant du ticket
    std::string getId_ticket() const;

    /// @brief Cette méthode permet de définir l'identifiant du @ref Ticket
    /// @param  value   le nouvel identifiant du ticket
    void setId_ticket(const std::string &value);

    /// @brief Cette méthode permet de récupérer la date de création du @ref ticket
    /// @return la date de création du ticket
    std::string getDate_creation() const;

    /// @brief Cette méthode permet de définir la date de création du @ref Ticket
    /// @param  value   la nouvelle date de création du @ref Ticket
    void setDate_creation(double value);

    /// @brief Cette méthode permet de récupére la date de fermeture du @ref Ticket
    /// @return la date de fermeture du ticket
    std::string getDate_fermeture() const;

    /// @brief Cette méthode permet de définir la date de fermeture du @ref Ticket
    /// @param  value   la nouvelle date de fermeture du @ref Ticket
    void setDate_fermeture(double value);

    /// @brief Cette méthode permet de récupérer le système d'exploitation concerné par le @ref Ticket
    /// @return la date de fermeture du ticket
    Systeme getSysteme() const;

    /// @brief Cette méthode permet de définir le @ref Systeme concerné par le @ref Ticket
    /// @param  value   le nouveau @ref Systeme concerné par le @ref Ticket
    void setSysteme(const Systeme &value);

    /// @brief Cette méthode permet récupérer le @ref Logiciel concerné par le @ref Ticket
    /// @return le @ref Logiciel concerné par le @ref Ticket
    Logiciel getLogiciel() const;

    /// @brief Cette méthode permet définir le @ref Logiciel concerné par le @ref Ticket
    /// @param  value   le nouveau @ref Logiciel concerné par le @ref Ticket
    void setLogiciel(const Logiciel &value);

    /// @brief Cette méthode permet de récupérer la liste des @ref Message concerné par le @ref Ticket
    /// @return la liste de @ref Message concerné par le ticket
    std::vector<Message*> getListeMessages() const;

    /// @brief Cette méthode permet d'ajouter un Message concerné par le @ref Ticket
    /// @param  value   la nouvelle liste de @ref Message
    void setListeMessages(const std::vector<Message*> &value);

    /// @brief Cette méthode permet de définir la liste des @Message concerné par le @ref Ticket
    /// @param  value   la nouvelle liste de @ref Message
    void addMessage(const Message &message);

    /// @brief Cette méthode permet de définir le @ref Client auteur du @ref Ticket
    /// @param value    le @ref Client auteur du @ref Ticket
    void setClient(Client &value);

    /// @brief Cette méthode permet de récupérer le @ref Client auteur du @ref Ticket
    /// @return Le @ref Client auteur du @ref Ticket
    Client getClient();

    /// @brief Cette méthode permet de définir le @ref Personnel qui traite le @ref Ticket
    /// @param value    le nouveau @ref Personnel
    void setPersonnel(Personnel &value);

    /// @brief Cette méthode permet de récupérer le @ref Personnel qui traite le @ref Ticket
    /// @return le @ref Personel traitant le @ref Ticket
    Personnel getPersonnel();

    /// @brief Cette méthode permet d'afficher les attributs de la classe pour le débug.
    std::string toString();

    /// @brief Destructeur.
    ~Ticket() {}
};

#endif // TICKET_H
