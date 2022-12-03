#include "gestionnairedialogue.h"

GestionnaireDialogue::GestionnaireDialogue()
{

}

GestionnaireDialogue::~GestionnaireDialogue()
{
    qDebug() << "Destruction  gestionnaireDialogue\n";
}

Utilisateur *GestionnaireDialogue::authentification(QString &id, QString &mdp)
{
    if (id == "client" && mdp == "client")
        return new Client(id, mdp);
    return nullptr;
}

bool GestionnaireDialogue::verificationMessage(QString message)
{
    //Supprime tous les espaces
    for (int i = message.length() - 1 ; i > -1 ; i--)
    {
       if(message[i]==' ')
       {
           message.remove(i, 1);
       }
    }
    if (message == "" || message.length() < 15)
    {
       return false;
    }
    return true;
}

void GestionnaireDialogue::setComboBox(QComboBox *box, QString type)
{
    // A compléter avec la BDD.
}

void GestionnaireDialogue::enregistrer_ticket(Ticket ticket)
{
    // A compléter avec la BDD.
}
