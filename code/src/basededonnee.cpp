#include "basededonnee.h"

BaseDeDonnee::BaseDeDonnee()
{
    my_db = QSqlDatabase::addDatabase("QSQLITE");
    my_db.setDatabaseName("C:/Users/Victor/Documents/GitHub/EasyTicket/code/resources/database.db");

    if (!my_db.open()) {
        qDebug() << "Erreur: Connexion à la BDD impossble";
    } else {
         qDebug() << "BDD: Connexion a la BDD reussie";
    }
}

BaseDeDonnee::~BaseDeDonnee()
{
    my_db.close();
}

QVector<QString> BaseDeDonnee::select(QString s)
{
    QVector<QString> res = QVector<QString>();
    QSqlQuery *query = new QSqlQuery(my_db);
    query->exec("SELECT * FROM utilisateur");


    return res;
}
