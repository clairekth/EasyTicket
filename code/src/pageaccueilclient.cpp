#include "pageaccueilclient.h"
#include "ui_pageaccueilclient.h"

#include <QStackedWidget>

#include "constantes.h"

PageAccueilClient::PageAccueilClient(QWidget *parent, GestionnaireDialogue *gestionnaire_dialogue) :
    QWidget(parent),
    ui(new Ui::PageAccueilClient)
{
    ui->setupUi(this);
    creer_ticket_bouton = ui->creer_ticket_bouton;
    historique_tickets_bouton = ui->historique_tickets_bouton;

    this->gestionnaire_dialogue = gestionnaire_dialogue;
}

PageAccueilClient::~PageAccueilClient()
{
    delete ui;
}

void PageAccueilClient::creation_ticket()
{

}

void PageAccueilClient::on_creer_ticket_bouton_clicked()
{
    QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack){
        stack->setCurrentIndex(AJOUT_TICKET_PAGE); //Connexion correct -> Accueil client
    }
}
