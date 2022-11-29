#ifndef GESTIONNAIREBDD_H
#define GESTIONNAIREBDD_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "client.h"

/// @brief La classe GestionnaireBDD correspond à l'interface de communication entre les données du projet et le GestionnaireDialogue.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.7
class GestionnaireBDD
{
public:
    /// @brief Constructeur par défaut.
    GestionnaireBDD();

    /// @brief Méthode qui permet d'afficher le résultat d'une requete passée en paramètre.
    /// @param query La requête à envoyer à la bdd.
    void select(QString query);

    /// @brief  Méthode qui permet d'authentifier un client.
    /// @param  id  L'identifiant du client.
    /// @param  mdp Le mot de passe du client.
    /// @return  le Client identifié.
    Client authentifier(QString id, QString mdp);

    /// @brief  Méthode qui permet de récupérer la catégorie d'un Utilisateur.
    /// @param  id_utilisateur  l'identifiant de l'Utilisateur.
    /// @param  mdp             le mot de passe de l'Utilisateur.
    /// @return la catégorie de l'utilisateur s'il existe, null sinon
    std::string type_utilisateur(QString id_utilisateur, QString mdp);

protected:
    /// @brief La base de donnée SQLite.
    QSqlDatabase my_db;
};

#endif // GESTIONNAIREBDD_H
