#ifndef GESTIONNAIREDIALOGUE_H
#define GESTIONNAIREDIALOGUE_H

#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "ticket.h"
#include "gestionnairebdd.h"



/// @brief La classe GestionnaireDialogue correspond à l'interface de communication entre l'Utilisateur et le modèle.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.5
class GestionnaireDialogue
{
public:
    /// @brief Constructeur par défaut.
    GestionnaireDialogue();

    /// @brief Méthode qui permet d'identifier le type d'Utilisateur qui se connecte si il existe.
    /// @param id   L'identifiant de l'Utilisateur.
    /// @param mdp  Le mot de passe de l'Utilisateur.
    /// @return le nom du type d'utilisateur, null si l'utilisateur n'existe pas.
    QString typeUtilisateur(QString id, QString mdp);

    /// @brief Méthode qui permet d'identifier un Client.
    /// @param id   L'identifiant du Client.
    /// @param mdp  Le mot de passe du Client.
    /// @return le Client identifié.
    Client authentification(QString id, QString mdp);

    /// @brief Méthode permettant de vérifier que le message est bon.
    /// @return true si le message est bon, false sinon.
    bool verificationMessage(QString message);

    /// @brief Méthode qui remplit les comboBox de la page PageAjoutTicket en fct de la BDD.
    /// @param box La ComboBox.
    /// @param type Le type de donnée de la ComboBox (categorie, systeme, logiciel).
    void setComboBox(QComboBox *box, QString type);

    /// @brief Méthode qui permet d'enregistrer le ticket dans la BDD.
    /// @param ticket Le ticket à enregistrer.
    void enregistrer_ticket(Ticket ticket);


private:
    /// @brief Champs servant à communiquer avec la bdd, (interface de communication).
    GestionnaireBDD bdd;

};

#endif // GESTIONNAIREDIALOGUE_H
