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
