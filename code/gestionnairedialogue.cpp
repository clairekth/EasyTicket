#include "gestionnairedialogue.h"

GestionnaireDialogue::GestionnaireDialogue()
{

}

GestionnaireDialogue::~GestionnaireDialogue()
{
    //qDebug() << "Destruction  gestionnaireDialogue\n";
}

Utilisateur *GestionnaireDialogue::authentification(QString &id, QString &mdp)
{
    return bdd.authentifier(id, mdp);
}

bool GestionnaireDialogue::verificationMessage(QString &message)
{
    int nb = 0;
    //Compte tous les espaces
    for (int i = message.length() - 1 ; i > -1 ; i--)
    {
       if(message[i]!=' ')
       {
            nb++;
       }
    }
    if (nb == 0 || nb < 15)
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
    ticket->setPersonnel(per);
    bdd.linkToTicket(ticket, per);
}

Ticket *GestionnaireDialogue::getPlusVieuxTicket()
{
    //Ticket *ticket = bdd.getPlusVieuxTicket();
    //qDebug() << "Dans le gestionnairedialogue";
    //qDebug() << ticket->getAuteur()->getPrenom();

    return bdd.getPlusVieuxTicket();
}

void GestionnaireDialogue::recuperer_messages(Ticket *ticket) {
    bdd.recuperer_messages(ticket);
}
