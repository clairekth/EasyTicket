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
    envoyer_btn = ui->boutonEnvoyerMessage;
    zoneMessage = ui->zoneMessage;
    categorie = ui->categorie;
    systeme = ui->systeme;
    logiciel = ui->logiciel;
    id_ticket = ui->id_ticket;
    date = ui ->date;
    personnelGestionnaire = ui->personnelGestionnaire;
    proprietaire = ui->proprietaire;
    liste_messages = ui->liste_messages;
    liste_messages->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    liste_messages->setWordWrap(true);
    liste_messages->setStyleSheet("QHeaderView::section{background-color: rgb(220, 220, 220); height: 32px;}");

    connect(retour_btn, &QPushButton::clicked, this, &PageResolutionTicket::retour_accueil);

    connect(envoyer_btn, &QPushButton::clicked, this, &PageResolutionTicket::ajouter_message);


}

PageResolutionTicket::~PageResolutionTicket()
{
    delete ticket;
    delete retour_btn;
    delete zoneMessage;
    delete categorie;
    delete systeme;
    delete logiciel;
    delete id_ticket;
    delete date;
    delete personnelGestionnaire;
    delete proprietaire;
    delete liste_messages;
    delete ui;
}

void PageResolutionTicket::setPersonnel(Personnel *pers)
{
    personnel = pers;
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

    for (Message *m: t->getMessages())
    {
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

void PageResolutionTicket::ajouter_message()
{
    QString message = zoneMessage->toPlainText();
    if (!message.isEmpty()) {
        gestionnaire_dialogue->enregistrer_message(personnel->getId(), ticket->getId(), message, QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    }
    retour_accueil();
}


