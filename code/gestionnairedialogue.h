#ifndef GESTIONNAIREDIALOGUE_H
#define GESTIONNAIREDIALOGUE_H

#include <QString>
#include <QDebug>
#include <QComboBox>

#include "utilisateur.h"
#include "client.h"
#include "ticket.h"
#include "gestionnairebdd.h"

class Client;


/// @brief La classe GestionnaireDialogue correspond à l'interface de communication entre l'Utilisateur et le modèle.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 2.2
class GestionnaireDialogue
{
public:
    /// @brief Constructeur par défaut.
    GestionnaireDialogue();

    /// @brief Destructeur de la classe.
    ~GestionnaireDialogue();

    /// @brief Méthode permettant d'identifier un Utilisateur en envoyant les informations au GestionnaireBDD.
    /// @param  id      l'identifiant de l'Utilisateur.
    /// @param  mdp     le mot de passe de l'Utilisateur.
    /// @return l'Utilisateur identifié.
    Utilisateur* authentification(QString id, QString mdp);

    /// @brief Méthode permettant de vérifier que le message est bon. Un message est bon si il contient au moins 15 caractères
    /// qui ne sont pas des espaces.
    /// @return true si le message est bon, false sinon.
    bool verificationMessage(QString message);

    /// @brief Méthode qui remplit les comboBox de la page PageAjoutTicket en fonction de la BDD.
    /// @param box  La ComboBox.
    /// @param type Le type de donnée de la ComboBox (categorie, systeme, logiciel).
    void setComboBox(QComboBox *box, const QString &type);

    /// @brief Méthode qui permet d'enregistrer le ticket dans la BDD.
    /// @param ticket Le ticket à enregistrer.
    void enregistrer_ticket(Ticket *ticket);

    void linkToTicket(Ticket *ticket, Personnel *per);

    Ticket *getPlusVieuxTicket();

private:
    /// @brief Champs correspondant au gestionnaire de la base de données.
    GestionnaireBDD bdd;
};

#endif // GESTIONNAIREDIALOGUE_H
