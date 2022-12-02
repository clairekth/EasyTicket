#include "gestionnairedialogue.h"

GestionnaireDialogue::GestionnaireDialogue()
{
    // bdd.select("SELECT * FROM utilisateur");
}

QString GestionnaireDialogue::typeUtilisateur(QString id, QString mdp)
{
    //BDD check de savoir quel type d'utilisateur correspondent les id & mdp et renvoie le type. Si null -> user existe pas. ?
    QString id_categorie = bdd.type_utilisateur(id, mdp);

    return id_categorie;
}

Client GestionnaireDialogue::authentificationClient(QString id, QString mdp)
{

    //Récupère les info du Client dans la BDD
    return bdd.authentifierClient(id, mdp);
}

Ingenieur GestionnaireDialogue::authentificationIngenieur(QString id, QString mdp)
{
    //Récupère les info de l'ingénieur dans la BDD
    return bdd.authentifierIngenieur(id, mdp);
}

bool GestionnaireDialogue::verificationMessage(QString message)
{
    //Supprime tous les espaces
    for (int i = message.length() - 1 ; i > -1 ; i--){
        if(message[i]==' '){
            message.remove(i, 1);
        }
    }
    if (message == "" || message.length() < 15){
        return false;
    }
    return true;
}

void GestionnaireDialogue::setComboBox(QComboBox *box, QString type)
{
    bdd.setComboBox(box,type);
}

void GestionnaireDialogue::enregistrer_ticket(Ticket ticket) {
    bdd.enregistrer_ticket(ticket);
}


