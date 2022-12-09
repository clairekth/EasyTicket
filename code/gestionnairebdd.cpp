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
    QSqlQuery query = QSqlQuery();
    query.prepare("select * from " + type);
    query.exec();

    if (type != "categorie"){
        box->addItem(" ");
    }
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString nom = query.value(1).toString();
        box->addItem(nom, id);

    }
}

void GestionnaireBDD::linkToTicket(Ticket *ticket, Personnel *pers)
{

    QSqlQuery query = QSqlQuery();
    qDebug() << "id_ticket" << ticket->getId();
    qDebug() << "id_pers" << pers->getId();
    query.prepare("UPDATE ticket SET id_personnel = :id_p WHERE id_ticket = :id_ticket");
    query.bindValue(":id_p", pers->getId());
    query.bindValue(":id_ticket", ticket->getId());
    qDebug() << "update ticket : " << query.exec();

}

Ticket *GestionnaireBDD::getPlusVieuxTicket()
{
    /*
     * Il faut penser à vérifier que le ticket n'a pas été cloturé et qu'il n'a pas déjà été attribué
     */
    Ticket *ticket = nullptr;
    Client *auteur = nullptr;
    Categorie categorie;
    Logiciel logiciel;
    Systeme systeme;

    QSqlQuery query = QSqlQuery();
    query.prepare("SELECT * FROM ticket WHERE date_cloture IS NULL AND id_personnel IS NULL ORDER BY date_creation;");
    query.exec();

    QString id_client;
    QString id_categorie;
    QString id_logiciel;
    QString id_systeme;

    QString date_creation;
    int id_ticket = -1;
    bool presence_ticket = false;
    if (query.first())
    {
        id_client = query.value("id_client").toString();
        id_categorie = query.value("id_categorie").toString();
        id_logiciel = query.value("id_logiciel").toString();
        id_systeme = query.value("id_systeme").toString();
        date_creation = query.value("date_creation").toString();
        id_ticket = query.value("id_ticket").toInt();
        presence_ticket = true;
    }
    query.clear();
// -----------------------
    //qDebug() << presence_ticket;
    if (presence_ticket){//Il y a bien un ticket qui n'a pas de gestionnaire et qui n'est pas fermé.
        query.prepare("SELECT * FROM utilisateur WHERE id_utilisateur=:id");
        query.bindValue(":id",id_client);
        query.exec();

        if (query.first())
        {
            if (query.value("type_utilisateur").toString() == "client")
            {
                auteur = new Client(query.value(0).toString(),
                                    query.value(1).toString(),
                                    query.value(3).toString(),
                                    query.value(4).toString());
            }
        }
        //qDebug() << auteur->toString();
        query.clear();
    // -----------------------
        query.prepare("SELECT * FROM categorie WHERE id_categorie = " + id_categorie);
        query.exec();

        if (query.first())
        {
            categorie = Categorie(query.value("id_categorie").toInt(), query.value("nom").toString());
        }
        query.clear();
        //qDebug() << "categorie recup";
    // -----------------------
        if (id_logiciel != "0") {
            query.prepare("SELECT * FROM logiciel WHERE id_logiciel = " + id_logiciel);
            query.exec();

            if (query.first())
            {
                logiciel = Logiciel(query.value("id_logiciel").toInt(), query.value("nom").toString());
            }
            query.clear();
            //qDebug() << "logiciel recup";
        }
    // -----------------------
        if (id_systeme != "0") {
            query.prepare("SELECT * FROM systeme WHERE id_systeme = " + id_systeme);
            query.exec();

            if (query.first())
            {
                systeme = Systeme(query.value("id_systeme").toInt(), query.value("nom").toString());
            }
            query.clear();
            qDebug() << "systeme recup";
        }

        ticket = new Ticket(date_creation, categorie, auteur, id_ticket);
        //qDebug() << "ticket créé";
        //qDebug() << ticket->getAuteur()->getPrenom();
        //qDebug() << ticket.toString();
        if (id_logiciel != "0")
            ticket->setLogiciel(logiciel);
        if (id_systeme != "0")
            ticket->setSysteme(systeme);
    }
    return ticket;
}

Utilisateur* GestionnaireBDD::authentifier(QString &id, QString &mdp)
{
    QSqlQuery query = QSqlQuery();
    query.prepare("SELECT * FROM utilisateur WHERE id_utilisateur = :id AND mot_de_passe = :mdp");
    query.bindValue(":id", id);
    query.bindValue(":mdp", mdp);
    query.exec();

    QString typeUser;
    Utilisateur *user = nullptr;
    if (query.first())
    {
        typeUser = query.value("type_utilisateur").toString();

        if (typeUser == "client"){
            user = new Client(
                        query.value(0).toString(),
                        query.value(1).toString(),
                        query.value(3).toString(),
                        query.value(4).toString());
        }
        else if (typeUser == "ingenieur"){
            user = new Ingenieur(
                        query.value(0).toString(),
                        query.value(1).toString(),
                        query.value(3).toString(),
                        query.value(4).toString());
        }
    }
    query.clear();

    return user;
}

void GestionnaireBDD::enregistrer_ticket(Ticket *ticket) {
    // Insertion du ticket
    QSqlQuery query = QSqlQuery();
    query.prepare("insert into ticket (date_creation, id_categorie, id_systeme, id_logiciel, id_client) values (:date_creation, :id_categorie, :id_systeme, :id_logiciel, :id_client)");
    query.bindValue(":date_creation", ticket->getDate_creation());
    query.bindValue(":id_categorie", ticket->getCategorie().getId());
    if (ticket->getSysteme().getId() != -1)
        query.bindValue(":id_systeme", ticket->getSysteme().getId());
    else
        query.bindValue(":id_systeme", 0);
    if (ticket->getLogiciel().getId() != -1)
        query.bindValue(":id_logiciel", ticket->getLogiciel().getId());
    else
        query.bindValue(":id_logiciel", 0);
    query.bindValue(":id_client", ticket->getAuteur()->getId());

    bool res = query.exec();
    //qDebug() << res;
    query.clear();

    // Récupération de l'id du ticket qu'on vient d'insérer    query = QSqlQuery();

    query.prepare("SELECT id_ticket FROM ticket WHERE date_creation = :date");
    query.bindValue(":date", ticket->getDate_creation());
    query.exec();
    res = query.first();
    if (res)
        ticket->setId(query.value(0).toInt());
    //qDebug() << res;

    query.clear();
    // Insertion des messages du ticket
    foreach (Message *message, ticket->getMessages()) {

        message->setTicket(ticket);

        query = QSqlQuery();
        query.prepare("insert into message (message, horodatage, id_utilisateur, id_ticket_associe) values (:message, :horodatage, :id_utilisateur, :id_ticket_associe)");
        query.bindValue(":message", message->getMessage());
        query.bindValue(":horodatage", message->getDate_envoi());
        query.bindValue(":id_utilisateur", message->getAuteur()->getId());
        query.bindValue(":id_ticket_associe", message->getTicket()->getId());
        res = query.exec();
        //qDebug() << res;
    }
    query.clear();

}

void GestionnaireBDD::recuperer_messages(Ticket *ticket) {
    QSqlQuery query = QSqlQuery();
    query.prepare("SELECT id_message, message, horodatage, id_utilisateur, id_ticket, prenom, nom, email, type_utilisateur FROM ticket INNER JOIN message ON ticket.id_ticket = message.id_ticket_associe NATURAL JOIN utilisateur WHERE id_ticket = :id_ticket");
    query.bindValue(":id_ticket", ticket->getId());
    query.exec();

    while (query.next())
    {
        int id_message = query.value(0).toInt();
        QString message = query.value(1).toString();
        const QString horodatage = query.value(2).toString();
        QString id_utilisateur = query.value(3).toString();
        Utilisateur *user = nullptr;
        if (query.value("type_utilisateur") == "client")
        {
            user = new  Client(query.value("id_utilisateur").toString(), query.value("nom").toString(), query.value("prenom").toString(), query.value("email").toString());
        }

        Message *mess = new Message(horodatage, user, ticket, message, id_message);
        ticket->addMessage(mess);
    }

    query.clear();
}

void GestionnaireBDD::enregistrer_message(QString &auteur, int id_ticket, QString &message, QString &date)
{
    QSqlQuery query = QSqlQuery();
    query.prepare("INSERT INTO message (message, horodatage, id_utilisateur, id_ticket_associe) VALUES (:message, :date, :id_auteur, :id_ticket_ass)");
    query.bindValue(":message", message);
    query.bindValue(":date", date);
    query.bindValue("id_auteur", auteur);
    query.bindValue("id_ticket_ass", id_ticket);

    if (query.exec())
        qDebug() << "Ajout du message dans la bdd";
    query.clear();
}
