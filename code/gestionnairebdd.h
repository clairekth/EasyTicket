#ifndef GESTIONNAIREBDD_H
#define GESTIONNAIREBDD_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "client.h"
#include "ticket.h"
#include "categorie.h"
#include "logiciel.h"
#include "systeme.h"
#include "message.h"

/// @brief La classe GestionnaireBDD correspond à l'interface de communication entre les données du projet et le GestionnaireDialogue.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 2.2
class GestionnaireBDD
{
public:
    /// @brief Constructeur par défaut.
    GestionnaireBDD();

    /// @brief Méthode permettant d'identifier un Utilisateur grâce à la BDD.
    /// @param  id      l'identifiant de l'Utilisateur.
    /// @param  mdp     le mot de passe de l'Utilisateur.
    /// @return l'Utilisateur identifié.
    Utilisateur *authentifier(QString &id, QString &mdp);

    /// @brief Méthode qui permet d'enregistrer un ticket dans la BDD.
    /// @param ticket Le ticket à enregistrer.
    void enregistrer_ticket(Ticket *ticket);

    /// @brief Méthode qui remplit les comboBox de la page PageAjoutTicket en fct de la BDD.
    /// @param box La ComboBox.
    /// @param type Le type de donnée de la ComboBox (categorie, systeme, logiciel).
    void setComboBox(QComboBox *box, const QString &type);


protected:
    /// @brief La base de donnée SQLite.
    QSqlDatabase my_db;
};

#endif // GESTIONNAIREBDD_H
