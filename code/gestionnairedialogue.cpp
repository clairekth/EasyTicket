#include "gestionnairedialogue.h"

GestionnaireDialogue::GestionnaireDialogue()
{

}

GestionnaireDialogue::~GestionnaireDialogue()
{
    //qDebug() << "Destruction  gestionnaireDialogue\n";
}

Utilisateur *GestionnaireDialogue::authentification(QString id, QString mdp)
{
    return bdd.authentifier(id, mdp);
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

void GestionnaireDialogue::setComboBox(QComboBox *box, const QString &type)
{
    bdd.setComboBox(box, type);
}

void GestionnaireDialogue::enregistrer_ticket(Ticket *ticket)
{
    bdd.enregistrer_ticket(ticket);
}

void GestionnaireDialogue::linkToTicket(Ticket *ticket, Personnel *per)
{
    bdd.linkToTicket(ticket, per);
}

Ticket *GestionnaireDialogue::getPlusVieuxTicket()
{
    return bdd.getPlusVieuxTicket();
}
