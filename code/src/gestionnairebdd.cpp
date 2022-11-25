#include "gestionnairebdd.h"

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

    /*if (!my_db.open())
    {
        qDebug() << "Erreur de connexion à la BDD";
        created = false;
    }

    else
    {
        qDebug() <<"Connexion réussie à la BDD";
        created = true;
    }*/
}

void GestionnaireBDD::select(QString query)
{
    if (!my_db.open())
    {
        qDebug() << "Erreur de connexion à la BDD";
    }

    else
    {
        qDebug() <<"Connexion réussie à la BDD";
        QSqlQuery *statement = new QSqlQuery();
        statement->exec(query);
        QString res;
        while (statement->next())
        {
            qDebug() << statement->value(0).toString();
        }
        statement->clear();
        my_db.close();
    }

}


