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
        resolution_ticket->setTicket(t);

        QTableWidget *liste_messages = resolution_ticket->getListeMessage();

        Categorie categorie = Categorie();

        std::vector<Message> messages = gestionnaire_dialogue->recuperer_messages(*t);

        for (Message m : messages) {
            liste_messages->insertRow(liste_messages->rowCount());
            liste_messages->setItem(liste_messages->rowCount() - 1, 0, new QTableWidgetItem(m.getDate_envoi()));
            liste_messages->setItem(liste_messages->rowCount() - 1, 1, new QTableWidgetItem(m.getAuteur()->getNom()));
            liste_messages->setItem(liste_messages->rowCount() - 1, 2, new QTableWidgetItem(m.getMessage()));
        }

        resolution_ticket->setListeMessages(liste_messages);



        resolution_ticket->setTicket(t);


        stack->setCurrentIndex(RESOLUTION_TICKET_PAGE);
    } else {
        QMessageBox::warning(stack, "Erreur", "Il n'y a plus de tickets sans gestionnaire");
    }
}
