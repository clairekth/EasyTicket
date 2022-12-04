#include "pageresolutionticket.h"
#include "ui_pageresolutionticket.h"

PageResolutionTicket::PageResolutionTicket(QStackedWidget *parent, GestionnaireDialogue *gestionnaire) :
    QWidget(parent),
    gestionnaire_dialogue(gestionnaire),
    ui(new Ui::PageResolutionTicket)
{
    ui->setupUi(this);
    retour_btn = ui->retour_bouton;
    label = ui->label;

    connect(retour_btn, &QPushButton::clicked, this, &PageResolutionTicket::retour_accueil);

//    if (personnel->estUnIngenieur())
//    {
//        label->setText(personnel->getPrenom() + " " + personnel->getNom() + ", (Ingénieur)");
//    }
}

PageResolutionTicket::~PageResolutionTicket()
{
    delete retour_btn;
    delete label;
    delete ui;
}

void PageResolutionTicket::setPersonnel(Personnel *pers)
{
    personnel = pers;
}

void PageResolutionTicket::retour_accueil()
{
    stack->setCurrentIndex(ACCUEIL_PERSONNEL_PAGE);
}
