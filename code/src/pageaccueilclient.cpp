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
    connect(creer_ticket_bouton, &QPushButton::clicked, this, &PageAccueilClient::creation_ticket);
    this->gestionnaire_dialogue = gestionnaire_dialogue;
}

PageAccueilClient::~PageAccueilClient()
{
    delete ui;
}

void PageAccueilClient::creation_ticket()
{
    QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack){
        stack->setCurrentIndex(AJOUT_TICKET_PAGE); //Connexion correct -> Accueil client
    }
}
