#ifndef GESTIONNAIREBDD_H
#define GESTIONNAIREBDD_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "client.h"
#include "ticket.h"

/// @brief La classe GestionnaireBDD correspond à l'interface de communication entre les données du projet et le GestionnaireDialogue.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.7
class GestionnaireBDD
{
public:
    /// @brief Constructeur par défaut.
    GestionnaireBDD();

    /// @brief  Méthode qui permet d'authentifier un client.
    /// @param  id  L'identifiant du client.
    /// @param  mdp Le mot de passe du client.
    /// @return  le Client identifié.
    Client authentifier(QString id, QString mdp);

    /// @brief  Méthode qui permet de récupérer la catégorie d'un Utilisateur.
    /// @param  id_utilisateur  l'identifiant de l'Utilisateur.
    /// @param  mdp             le mot de passe de l'Utilisateur.
    /// @return la catégorie de l'utilisateur s'il existe, null sinon
    QString type_utilisateur(QString id_utilisateur, QString mdp);

    /// @brief Méthode qui permet d'enregistrer un ticket dans la BDD.
    /// @param ticket Le ticket à enregistrer.
    void enregistrer_ticket(Ticket &ticket);

    /// @brief Méthode qui remplit les comboBox de la page PageAjoutTicket en fct de la BDD.
    /// @param box La ComboBox.
    /// @param type Le type de donnée de la ComboBox (categorie, systeme, logiciel).
    void setComboBox(QComboBox *box, QString type);


protected:
    /// @brief La base de donnée SQLite.
    QSqlDatabase my_db;
};

#endif // GESTIONNAIREBDD_H
