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
    liste_messages = ui->liste_messages;

    Categorie categorie = Categorie();
    Ticket ticket = Ticket("test", categorie, new Client(), 28);

    std::vector<Message> messages = gestionnaire_dialogue->recuperer_messages(ticket);

    for (Message m : messages) {
        liste_messages->insertRow(liste_messages->rowCount());
        liste_messages->setItem(liste_messages->rowCount() - 1, 0, new QTableWidgetItem(m.getDate_envoi()));
        liste_messages->setItem(liste_messages->rowCount() - 1, 1, new QTableWidgetItem(m.getAuteur()->getNom()));
        liste_messages->setItem(liste_messages->rowCount() - 1, 2, new QTableWidgetItem(m.getMessage()));
    }

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

void PageResolutionTicket::setTicket(Ticket *t)
{
    ticket = t;

    QMessageBox::information(stack, "Information ticket", t->toString());
}

void PageResolutionTicket::retour_accueil()
{
    stack->setCurrentIndex(ACCUEIL_PERSONNEL_PAGE);
}
