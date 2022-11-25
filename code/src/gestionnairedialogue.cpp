#include "gestionnairedialogue.h"

GestionnaireDialogue::GestionnaireDialogue()
{
    bdd = GestionnaireBDD();

    //Récupère le path absolue de l'exécutable
    QString p = qApp->QCoreApplication::applicationDirPath() ;
    //On coupe le lien en 2 avec EasyTicket/
    QRegExp tagExp("EasyTicket/");
    QStringList firstList = p.split(tagExp);
    //Ajoute ce qui manque pour arriver au file
    QString path = firstList.takeFirst() +"EasyTicket/code/resources/database.db";
    bdd.select("SELECT * FROM utilisateur");
    bdd.select("SELECT * FROM utilisateur");

}

std::string GestionnaireDialogue::typeUtilisateur(std::string id, std::string mdp)
{
    //BDD check de savoir quel type d'utilisateur correspondent les id & mdp et renvoie le type. Si null -> user existe pas. ?
    if (id == "client"){
        return "client";
    }
    return "null";
}

Client GestionnaireDialogue::authentification(std::string id, std::string mdp)
{
    //Récupère les info du Client dans la BDD
    Client c = Client(id, "Vous", "Même", mdp, id + "@easyticket.fr");
    return c;
}

bool GestionnaireDialogue::verificationMessage(std::string message)
{
    //Supprime tous les espaces
    for (int i = message.length() - 1 ; i > -1 ; i--){
        if(message[i]==' '){
            message.erase(i,1);
        }
    }
    if (message == "" || message.length() < 15){
        return false;
    }
    return true;
}




