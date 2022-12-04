#include "pageaccueilpersonnel.h"
#include "ui_pageaccueilpersonnel.h"

PageAccueilPersonnel::PageAccueilPersonnel(QStackedWidget *parent, GestionnaireDialogue *gestionnaire) :
    QWidget(parent),
    gestionnaire_dialogue(gestionnaire), stack(parent),
    ui(new Ui::PageAccueilPersonnel)
{
    ui->setupUi(this);
    demander_ticket_bouton = ui->demander_ticket_bouton;
    voir_ticket_bouton = ui->consulter_tickets_bouton;
    label = ui->label;
}

PageAccueilPersonnel::~PageAccueilPersonnel()
{
    delete demander_ticket_bouton;
    delete voir_ticket_bouton;
    delete label;
    delete ui;
}

void PageAccueilPersonnel::setPersonnel(Personnel *pers)
{

    this->personnel = pers;
    if (personnel->estUnIngenieur()){
        label->setText("Bonjour, " + personnel->getPrenom() + " " + personnel->getNom() + " (Ingénieur)");
        qDebug() << "Inge";
    } else {
        qDebug() << "nn";
    }
}
