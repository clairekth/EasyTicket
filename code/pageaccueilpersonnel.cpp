#include "pageaccueilpersonnel.h"
#include "ui_pageaccueilpersonnel.h"
#include <QMessageBox>

PageAccueilPersonnel::PageAccueilPersonnel(QStackedWidget *parent, GestionnaireDialogue *gestionnaire) :
    QWidget(parent),
    gestionnaire_dialogue(gestionnaire), stack(parent),
    ui(new Ui::PageAccueilPersonnel)
{
    ui->setupUi(this);
    demander_ticket_bouton = ui->demander_ticket_bouton;
    voir_ticket_bouton = ui->consulter_tickets_bouton;
    label = ui->label;

    connect(demander_ticket_bouton, &QPushButton::clicked, this, &PageAccueilPersonnel::nouveau_ticket_a_traiter);
}

PageAccueilPersonnel::~PageAccueilPersonnel()
{
//    delete demander_ticket_bouton;
//    delete voir_ticket_bouton;
    delete label;
    delete ui;
}

void PageAccueilPersonnel::setPersonnel(Personnel *pers)
{

    this->personnel = pers;
    if (personnel->estUnIngenieur()){
        label->setText("Bonjour, " + personnel->getPrenom() + " " + personnel->getNom() + " (Ingénieur)");
    }
}

void PageAccueilPersonnel::nouveau_ticket_a_traiter()
{
    Ticket *t = gestionnaire_dialogue->getPlusVieuxTicket();

    if (t){
        gestionnaire_dialogue->linkToTicket(t, personnel);
        auto *widget = stack->widget(RESOLUTION_TICKET_PAGE);
        auto *resolution_ticket = qobject_cast<PageResolutionTicket*>(widget);
        resolution_ticket->setPersonnel(personnel);

        gestionnaire_dialogue->recuperer_messages(t);

        resolution_ticket->setTicket(t);


        stack->setCurrentIndex(RESOLUTION_TICKET_PAGE);
    } else {
        QMessageBox::warning(stack, "Erreur", "Il n'y a plus de tickets dans le gestionnaire");
    }
}
