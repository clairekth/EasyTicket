#include "pageresolutionticket.h"
#include "ui_pageresolutionticket.h"

#include <vector>

PageResolutionTicket::PageResolutionTicket(QStackedWidget *parent, GestionnaireDialogue *gestionnaire) :
    QWidget(parent),
    gestionnaire_dialogue(gestionnaire), stack(parent),
    ui(new Ui::PageResolutionTicket)
{
    ui->setupUi(this);
    retour_btn = ui->retour_bouton;
    zoneMessage = ui->zoneMessage;
    categorie = ui->categorie;
    systeme = ui->systeme;
    logiciel = ui->logiciel;
    id_ticket = ui->id_ticket;
    date = ui ->date;
    personnelGestionnaire = ui->personnelGestionnaire;
    proprietaire = ui->proprietaire;




    connect(retour_btn, &QPushButton::clicked, this, &PageResolutionTicket::retour_accueil);

//    if (personnel->estUnIngenieur())
//    {
//        label->setText(personnel->getPrenom() + " " + personnel->getNom() + ", (Ingénieur)");
//    }
}

PageResolutionTicket::~PageResolutionTicket()
{
    delete retour_btn;
    delete ui;
}

void PageResolutionTicket::setPersonnel(Personnel *pers)
{
    personnel = pers;
}

Ticket* PageResolutionTicket::getTicket() {
    return ticket;
}

void PageResolutionTicket::setTicket(Ticket *t)
{
    ticket = t;
<<<<<<< HEAD
    categorie->setText(ticket->getCategorie().getNom());
    systeme->setText(ticket->getSysteme().getNom());
    logiciel->setText(ticket->getLogiciel().getNom());
=======
    categorie->setText("Categorie : " + ticket->getCategorie().getNom());
    systeme->setText("Système : " + ticket->getSysteme().getNom());
    logiciel->setText("Ticket : " + ticket->getLogiciel().getNom());
    id_ticket->setText("Ticket : " + QString::number(ticket->getId()));
    date->setText("Date : " + ticket->getDate_creation() );
    proprietaire->setText("Propriétaire : " + ticket->getAuteur()->getPrenom() + " " + ticket->getAuteur()->getNom());
    personnelGestionnaire->setText("Gestionnaire : " + ticket->getPersonnel()->getPrenom() + " " + ticket->getPersonnel()->getNom());
>>>>>>> 47ebbdc31b2e495b61fa0faf05f1492b24d92d4e
}

void PageResolutionTicket::retour_accueil()
{
    stack->setCurrentIndex(ACCUEIL_PERSONNEL_PAGE);
}

QTableWidget* PageResolutionTicket::getListeMessage() {
    return liste_messages;
}

void PageResolutionTicket::setListeMessages(QTableWidget* liste_messages) {
    this->liste_messages = liste_messages;
}
