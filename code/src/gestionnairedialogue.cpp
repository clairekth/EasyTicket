#include "gestionnairedialogue.h"

GestionnaireDialogue::GestionnaireDialogue()
{
    // bdd.select("SELECT * FROM utilisateur");
}

std::string GestionnaireDialogue::typeUtilisateur(std::string id, std::string mdp)
{
    //BDD check de savoir quel type d'utilisateur correspondent les id & mdp et renvoie le type. Si null -> user existe pas. ?
    std::string id_categorie = bdd.type_utilisateur(QString::fromStdString(id));

    if (id_categorie == "client"){
        return "client";
    }
    return "null";
}

Client GestionnaireDialogue::authentification(std::string id, std::string mdp)
{

    //Récupère les info du Client dans la BDD
    // Client c = Client(id, "Vous", "Même", mdp, id + "@easyticket.fr");
    return bdd.authentifier(QString::fromStdString(id), QString::fromStdString(mdp));
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




