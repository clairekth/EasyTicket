#include "gestionnairebdd.h"

GestionnaireBDD::GestionnaireBDD()
{
    my_db = QSqlDatabase::addDatabase("QSQLITE");
    my_db.setDatabaseName("C:/Users/Victor/Documents/Github/EasyTicket/code/resources/database.db");

    if (!my_db.open())
    {
        qDebug() << "Erreur de connexion à la BDD";
        created = false;
    }

    else
    {
        qDebug() <<"Connexion réussie à la BDD";
        created = true;
    }
}

void GestionnaireBDD::select(QString query)
{
    if (created) {
        QSqlQuery *statement = new QSqlQuery();
        statement->exec(query);
        QString res;
        while (statement->next())
        {
            qDebug() << statement->value(0).toString();
        }
        statement->clear();
    }
}
