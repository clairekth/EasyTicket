#ifndef TICKET_H
#define TICKET_H

#include <vector>

#include "systeme.h"
#include "logiciel.h"
#include "message.h"
#include "client.h"
#include "personnel.h"

class Ticket
{
private:
    std::string id_ticket;
    double date_creation;
    double date_fermeture;
    Systeme systeme;
    Logiciel logiciel;
    std::vector<Message*> liste_messages;
    Client client;
    Personnel personnel;

public:
    Ticket();
    /// @brief la classe @ref Ticket permet de décrire un ticket dans l'application EasyTicket.
    /// @param  id_ticket       l'identifiant du ticket
    /// @param  date_creation   la date de création du ticket
    /// @param  systeme         le @ref Systeme concerné par le ticket
    /// @param  logiciel        le @ref Logiciel concerné par le ticket
    /// @param  auteur          le @ref Client auteur du ticket
    Ticket(
            std::string id_ticket,
            double date_creation,
            Systeme systeme,
            Logiciel logiciel,
            Client auteur);

    /// @brief Cette méthode permet de récupérer l'identifiant du @ref Ticket
    /// @return l'identifiant du ticket
    std::string getId_ticket() const;

    /// @brief Cette méthode permet de définir l'identifiant du @ref Ticket
    /// @param  value   le nouvel identifiant du ticket
    void setId_ticket(const std::string &value);

    /// @brief Cette méthode permet de récupérer la date de création du @ref ticket
    /// @return la date de création du ticket
    double getDate_creation() const;

    /// @brief Cette méthode permet de définir la date de création du @ref Ticket
    /// @param  value   la nouvelle date de création du @ref Ticket
    void setDate_creation(double value);

    /// @brief Cette méthode permet de récupére la date de fermeture du @ref Ticket
    /// @return la date de fermeture du ticket
    double getDate_fermeture() const;

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

    /// @brief Cette méthode permet de définir la liste des @Message concerné par le @ref Ticket
    /// @param  value   la nouvelle liste de @ref Message
    void setListeMessages(const std::vector<Message*> &value);

    void setClient(const Client &value);
    Client getClient();

    void setPersonnel(const Personnel &value);
    Personnel getPersonnel();

};

#endif // TICKET_H
