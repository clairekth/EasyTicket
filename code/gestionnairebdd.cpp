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
    QString path = firstList.takeFirst() +"EasyTicket/code/database.db";
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


void GestionnaireBDD::setComboBox(QComboBox *box, const QString &type)
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select * from " + type);
    query->exec();

    if (type != "categorie"){
        box->addItem(" ");
    }
    while (query->next())
    {
        int id = query->value(0).toInt();
        QString nom = query->value(1).toString();
        if (type == "categorie"){
            Categorie item = Categorie(id,nom);
            box->addItem(item.getNom(), item.getId());
        } else if (type == "logiciel"){
            Logiciel item = Logiciel(id, nom);
            box->addItem(item.getNom(),item.getId());
        } else {
            Systeme item = Systeme(id,nom);
            box->addItem(item.getNom(), item.getId());
        }
    }
}

Utilisateur* GestionnaireBDD::authentifier(QString &id, QString &mdp)
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT * FROM utilisateur WHERE id_utilisateur = :id AND mot_de_passe = :mdp");
    query->bindValue(":id", id);
    query->bindValue(":mdp", mdp);
    query->exec();

    QString typeUser;
    Utilisateur *user = NULL;
    if (query->first())
    {
        typeUser = query->value("type_utilisateur").toString();

        if (typeUser == "client"){
            user = new Client(
                        query->value(0).toString(),  // Convertion : value -> QString -> QString
                        query->value(2).toString(),
                        query->value(1).toString(),
                        query->value(3).toString(),
                        query->value(4).toString());
        }
//        else if (typeUser == "ingenieur"){
//            user = new Ingenieur(
//                        query->value(0).toString(),  // Convertion : value -> QString -> QString
//                        query->value(2).toString(),
//                        query->value(1).toString(),
//                        query->value(3).toString(),
//                        query->value(4).toString());
//        }
    }



    query->clear();

    return user;
}




void GestionnaireBDD::enregistrer_ticket(Ticket &ticket) {
    // Insertion du ticket
    QSqlQuery *query = new QSqlQuery();
    query->prepare("insert into ticket (date_creation, id_categorie, id_systeme, id_logiciel, id_client) values (:date_creation, :id_categorie, :id_systeme, :id_logiciel, :id_client)");
    query->bindValue(":date_creation", ticket.getDate_creation());
    query->bindValue(":id_categorie", ticket.getCategorie()->getId());
    if (ticket.getSysteme()->getId() != -1)
        query->bindValue(":id_systeme", ticket.getSysteme()->getId());
    else
        query->bindValue(":id_systeme", 0);
    if (ticket.getLogiciel()->getId() != -1)
        query->bindValue(":id_logiciel", ticket.getLogiciel()->getId());
    else
        query->bindValue(":id_logiciel", 0);
    query->bindValue(":id_client", ticket.getAuteur()->getId());

    bool res = query->exec();
    //qDebug() << res;

    // Récupération de l'id du ticket qu'on vient d'insérer
    query = new QSqlQuery();
    query->prepare("SELECT id_ticket FROM ticket WHERE date_creation = :date");
    query->bindValue(":date", ticket.getDate_creation());
    query->exec();
    res = query->first();
    if (res)
        ticket.setId(query->value(0).toInt());
    //qDebug() << res;

    // Insertion des messages du ticket
    foreach (Message *message, ticket.getMessages()) {

        message->setTicket(&ticket);

        query = new QSqlQuery();
        query->prepare("insert into message (message, horodatage, id_utilisateur, id_ticket_associe) values (:message, :horodatage, :id_utilisateur, :id_ticket_associe)");
        query->bindValue(":message", message->getMessage());
        query->bindValue(":horodatage", message->getDate_envoi());
        query->bindValue(":id_utilisateur", message->getAuteur()->getId());
        query->bindValue(":id_ticket_associe", message->getTicket()->getId());
        res = query->exec();
        //qDebug() << res;
    }
    query->clear();

}
