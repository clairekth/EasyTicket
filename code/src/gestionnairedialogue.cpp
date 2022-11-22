#include "gestionnairedialogue.h"
#include "utilisateur.h"
#include "client.h"
GestionnaireDialogue::GestionnaireDialogue()
{

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
    Client c = Client(id, "Vous", "Même", mdp, id + "@easyticket.fr");
    return c;
}


