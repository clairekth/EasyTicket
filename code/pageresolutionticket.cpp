#include "pageresolutionticket.h"
#include "ui_pageresolutionticket.h"

PageResolutionTicket::PageResolutionTicket(QStackedWidget *parent, GestionnaireDialogue *gestionnaire) :
    QWidget(parent),
    gestionnaire_dialogue(gestionnaire), stack(parent),
    ui(new Ui::PageResolutionTicket)
{
    ui->setupUi(this);
    retour_btn = ui->retour_bouton;
    envoyer_btn = ui->boutonEnvoyerMessage;
    changer_cat_btn = ui->changer_cat_bouton;
    clore_btn = ui->clore_bouton;
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

    connect(changer_cat_btn, &QPushButton::clicked, this, &PageResolutionTicket::changer_categorie);

    connect(clore_btn, &QPushButton::clicked, this, &PageResolutionTicket::clore_ticket);
}

PageResolutionTicket::~PageResolutionTicket()
{
//    delete retour_btn;
//    delete retour_btn;
//    delete changer_cat_btn;
//    delete clore_btn;
    delete zoneMessage;
    delete categorie;
    delete systeme;
    delete logiciel;
    delete id_ticket;
    delete date;
    delete personnelGestionnaire;
    delete proprietaire;
    delete liste_messages;
    delete ticket;
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
        zoneMessage->setText("");
    }
}

void PageResolutionTicket::changer_categorie()
{
    QStringList categories = gestionnaire_dialogue->get_categories();

    QString choix = QInputDialog::getItem(this, "Choisir une nouvelle catégorie", "Catégorie :", categories);

    //qDebug() << "nouvelle catégorie" << choix;
    gestionnaire_dialogue->changer_categorie(ticket->getId(), choix);
    categorie->setText("Categorie : " + choix);
}

void PageResolutionTicket::clore_ticket()
{
    qDebug() << "le ticket a été clos à : " << QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    gestionnaire_dialogue->clore_ticket(ticket->getId(), QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    retour_accueil();
}


