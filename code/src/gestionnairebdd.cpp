#include "gestionnairebdd.h"
#include <iostream>


GestionnaireBDD::GestionnaireBDD()
{
    my_db = QSqlDatabase::addDatabase("QSQLITE");
    //Récupère le path absolue de l'exécutable
    QString p = qApp->QCoreApplication::applicationDirPath() ;
    //On coupe le lien en 2 avec EasyTicket/
    QRegExp tagExp("EasyTicket/");
    QStringList firstList = p.split(tagExp);
    //Ajoute ce qui manque pour arriver au file
    QString path = firstList.takeFirst() +"EasyTicket/code/resources/database.db";
    my_db.setDatabaseName(path);

    if (!my_db.open())
    {
        qDebug() << "Erreur de connexion à la BDD";
    }

    else
    {
        qDebug() <<"Connexion réussie à la BDD";
    }
}

void GestionnaireBDD::select(QString query)
{

        qDebug() <<"Connexion réussie à la BDD";
        QSqlQuery *statement = new QSqlQuery();
        statement->exec(query);
        QString res;
        while (statement->next())
        {
            for (int i = 0; i < statement->record().count(); i ++){
                qDebug() << statement->value(i).toString();

            }
            qDebug() << "----------";

        }
        statement->clear();


}

std::string GestionnaireBDD::type_utilisateur(QString id_utilisateur, QString mdp) {
    std::string res = "null";

    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from client natural join utilisateur where id_utilisateur = :id_utilisateur and mot_de_passe= :mdp");
    query->bindValue(":id_utilisateur", id_utilisateur);
    query->bindValue(":mdp", mdp);
    query->exec();
    while (query->next()) {
        res = "client";
    }
    query->clear();

    return res;
}

Client GestionnaireBDD::authentifier(QString id, QString mdp)
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from utilisateur where id_utilisateur = :id and mot_de_passe = :mdp");
    query->bindValue(":id", id);
    query->bindValue(":mdp", mdp);
    query->exec();

    Client client;

    while (query->next())
    {
        for (int i = 0; i < query->record().count(); i ++) {
            qDebug() << query->value(i).toString();
        }

        client = *new Client(
                    query->value(0).toString().toStdString(),  // Convertion : value -> QString -> std::string
                    query->value(2).toString().toStdString(),
                    query->value(1).toString().toStdString(),
                    query->value(3).toString().toStdString(),
                    query->value(4).toString().toStdString());


        qDebug() << "----------";

    }
    query->clear();

    return client;
}


