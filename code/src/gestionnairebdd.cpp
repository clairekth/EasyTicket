#include "gestionnairebdd.h"
#include <iostream>
#include "categorie.h"
#include "logiciel.h"
#include "systeme.h"

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

QString GestionnaireBDD::type_utilisateur(QString id_utilisateur, QString mdp) {
    QString res = "null";
    std::cout << id_utilisateur.toStdString() << " et " << mdp.toStdString() << std::endl;
    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT type_utilisateur FROM utilisateur WHERE id_utilisateur = :id_utilisateur AND mot_de_passe= :mdp");
    query->bindValue(":id_utilisateur", id_utilisateur);
    query->bindValue(":mdp", mdp);
    query->exec();
    if (query->first())
        res = query->value("type_utilisateur").toString();
    query->clear();

    return res;
}

void GestionnaireBDD::setComboBox(QComboBox *box, QString type)
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from " + type);
    query->exec();

    if (type != "categorie"){
        box->addItem(" ");
    }
    while (query->next())
    {

        QString id = query->value(0).toString();
        QString nom = query->value(1).toString();
        if (type == "categorie"){
            Categorie item = Categorie(id,nom);
            box->addItem(item.getNom(), item.getID());
        } else if (type == "logiciel"){
            Logiciel item = Logiciel(id, nom);
            box->addItem(item.getNom(),item.getID());
        } else {
            Systeme item = Systeme(id,nom);
            box->addItem(item.getNom(), item.getId_systeme());
        }


    }
}

Client GestionnaireBDD::authentifier(QString id, QString mdp)
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT * FROM utilisateur WHERE id_utilisateur = :id AND mot_de_passe = :mdp");
    query->bindValue(":id", id);
    query->bindValue(":mdp", mdp);
    query->exec();

    Client client;

    if (query->first())
    {
//        for (int i = 0; i < query->record().count(); i ++) {
//            qDebug() << query->value(i).toString();
//        }

        client = Client(
                    query->value(0).toString(),  // Convertion : value -> QString -> QString
                    query->value(2).toString(),
                    query->value(1).toString(),
                    query->value(3).toString(),
                    query->value(4).toString());


        qDebug() << "----------";

    }
    query->clear();

    return client;
}


