#ifndef GESTIONNAIREBDD_H
#define GESTIONNAIREBDD_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

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

protected:
    /// @brief La base de donnée SQLite.
    QSqlDatabase my_db;
};

#endif // GESTIONNAIREBDD_H