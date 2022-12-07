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
    liste_messages = ui->liste_messages;
    liste_messages->setColumnWidth(0, 150);
    liste_messages->setColumnWidth(1, 130);
    liste_messages->setColumnWidth(2, 300);
    liste_messages->setWordWrap(true);




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
    categorie->setText("Categorie : " + ticket->getCategorie().getNom());
    systeme->setText("Système : " + ticket->getSysteme().getNom());
    logiciel->setText("Ticket : " + ticket->getLogiciel().getNom());
    id_ticket->setText("Ticket : " + QString::number(ticket->getId()));
    date->setText("Date : " + ticket->getDate_creation() );
    proprietaire->setText("Propriétaire : " + ticket->getAuteur()->getPrenom() + " " + ticket->getAuteur()->getNom());
    personnelGestionnaire->setText("Gestionnaire : " + ticket->getPersonnel()->getPrenom() + " " + ticket->getPersonnel()->getNom());
    int row = 0;
// Bug
//    liste_messages->insertColumn(1);
//    liste_messages->setItem(row, 1, new QTableWidgetItem(t->getMessage()->getAuteur()->getPrenom() + " " + t->getMessage()->getAuteur()->getNom()));
//    liste_messages->insertColumn(2);
//    liste_messages->setItem(row, 2, new QTableWidgetItem(t->getMessage()->getMessage()));
    for (Message *m: t->getMessages())
    {
        qDebug() << m->getDate_envoi();
        liste_messages->insertRow(row);
        liste_messages->setItem(row, 0, new QTableWidgetItem(m->getDate_envoi()));
        liste_messages->setItem(row, 1, new QTableWidgetItem(m->getAuteur()->getPrenom() + " " + m->getAuteur()->getNom()));
        liste_messages->setItem(row, 2, new QTableWidgetItem(m->getMessage()));
        row++;
    }
    liste_messages->resizeRowsToContents();

}

void PageResolutionTicket::retour_accueil()
{
    stack->setCurrentIndex(ACCUEIL_PERSONNEL_PAGE);
}


