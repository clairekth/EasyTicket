#ifndef GESTIONNAIREDIALOGUE_H
#define GESTIONNAIREDIALOGUE_H

#include <QString>
#include <QDebug>
#include <QComboBox>
#include <vector>

#include "utilisateur.h"
#include "client.h"
#include "ticket.h"
#include "gestionnairebdd.h"

class Client;


/// @brief La classe GestionnaireDialogue correspond à l'interface de communication entre l'Utilisateur et le modèle.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 2.5
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
    Utilisateur* authentification(QString &id, QString &mdp);

    /// @brief Méthode permettant de vérifier que le message est bon. Un message est bon si il contient au moins 15 caractères
    /// qui ne sont pas des espaces.
    /// @return true si le message est bon, false sinon.
    bool verificationMessage(QString &message);

    /// @brief Méthode qui remplit les comboBox de la page PageAjoutTicket en fonction de la BDD.
    /// @param box  La ComboBox.
    /// @param type Le type de donnée de la ComboBox (categorie, systeme, logiciel).
    void setComboBox(QComboBox *box, const QString &type);

    /// @brief Méthode qui permet d'enregistrer le ticket dans la BDD.
    /// @param ticket Le ticket à enregistrer.
    void enregistrer_ticket(Ticket *ticket);

    /// @brief Méthode qui permet de lier un Personnel à un ticket.
    /// @param ticket   Le ticket à lier au Personnel.
    /// @param pers     Le personnel qui va traiter le ticket.
    void linkToTicket(Ticket *ticket, Personnel *per);

    /// @brief Méthode qui renvoie le plus vieux ticket qui n'a pas encore été traité.
    /// @return Le plus vieux ticket non résolu.
    Ticket *getPlusVieuxTicket();

    /// @brief Méthode qui renvoie la liste des messages concernant un ticket
    /// @return la liste des messages
    void recuperer_messages(Ticket *ticket);

    /// @brief Méthode qui permet d'enregistrer un nouveau message et de l'associer à un ticket.
    /// @param auteur L'auteur du message.
    /// @param id_ticket L'identifiant du ticket associé au message.
    /// @param message Le message à enregistrer.
    /// @param date La date d'enregistrement du message.
    void enregistrer_message(const QString &auteur, const int id_ticket, const QString &message, const QString &date);

    /// @brief Méthode permettant de récupérer les catégories.
    /// @return La liste des catégories.
    QStringList get_categories();

    /// @brief Méthode permettant de changer la catégorie d'un ticket.
    /// @param id_ticket Le ticket concerné par le changement de catégorie.
    /// @param nom_categorie Le nom de la nouvelle catégorie.
    void changer_categorie(const int id_ticket, QString &nom_categorie);

    /// @brief Méthode permettant de clore un ticket.
    /// @param id_ticket Le ticket à clore.
    /// @param date La date de cloture
    void clore_ticket(const int id_ticket, const QString &date);

private:
    /// @brief Champs correspondant au gestionnaire de la base de données.
    GestionnaireBDD bdd;
};

#endif // GESTIONNAIREDIALOGUE_H
