#include "pageaccueilclient.h"
#include "ui_pageaccueilclient.h"

PageAccueilClient::PageAccueilClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAccueilClient)
{
    ui->setupUi(this);
    creer_ticket_bouton = ui->creer_ticket_bouton;
    historique_tickets_bouton = ui->historique_tickets_bouton;
}

void PageAccueilClient::setGestionnaireDialogue(GestionnaireDialogue *g)
{
    gestionnaire_dialogue = g;
}

PageAccueilClient::~PageAccueilClient()
{
    delete ui;
}

void PageAccueilClient::creation_ticket()
{

}
