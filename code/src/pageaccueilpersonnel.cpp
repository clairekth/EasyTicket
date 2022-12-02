#include "pageaccueilpersonnel.h"
#include "ui_pageaccueilpersonnel.h"

PageAccueilPersonnel::PageAccueilPersonnel(QWidget *parent, GestionnaireDialogue *gestionnaire_dialogue) :
    QWidget(parent),
    ui(new Ui::PageAccueilPersonnel)
{
    ui->setupUi(this);
    consulter_tickets_bouton = ui->consulter_tickets_bouton;
    demander_ticket_bouton = ui->demander_ticket_bouton;
}

void PageAccueilPersonnel::setPersonnel(Personnel *p)
{
    this->personnel = p;
    if (this->personnel->estUnIngenieur()){
        qDebug() << "Inge";
    } else {
        qDebug() << "WSH";
    }
    QLabel *bonjour = ui->bonjour_personnel;
    bonjour->setText("Bonjour, " + (personnel->getPrenom()) + " " + (personnel->getNom()));
}

PageAccueilPersonnel::~PageAccueilPersonnel()
{
    delete ui;
}
