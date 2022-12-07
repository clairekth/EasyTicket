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
    QMessageBox::information(stack, "Information ticket", t->toString());
    categorie->setText(ticket->getCategorie().getNom());
    systeme->setText(ticket->getSysteme().getNom());
    logiciel->setText(ticket->getLogiciel().getNom());
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

QTextEdit* PageResolutionTicket::getZoneMessage()
{
    return zoneMessage;
}
void PageResolutionTicket::on_boutonEnvoyerMessage_clicked()
{

    QString message = getZoneMessage()->toPlainText();
    qDebug() << getTicket();
    gestionnaire_dialogue->enregistrerMessage(*getTicket(), message);

}
