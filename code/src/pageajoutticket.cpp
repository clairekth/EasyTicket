#include "pageajoutticket.h"
#include "ui_pageajoutticket.h"

#include <QStackedWidget>
#include "constantes.h"
#include "categorie.h"
#include <QDateTime>
#include <QMessageBox>

PageAjoutTicket::PageAjoutTicket(QWidget *parent, GestionnaireDialogue *gestionnaire_dialogue) :
    QWidget(parent),
    ui(new Ui::PageAjoutTicket)
{
    ui->setupUi(this);
    this->bouton_retour = ui->bouton_retour;
    this->bouton_creer_le_ticket = ui->creer_le_ticket_bouton;

    this->categorie_box = ui->categorie_box;
    this->systeme_box = ui->systeme_box;
    this->logiciel_box = ui->logiciel_box;
    gestionnaire_dialogue->setComboBox(categorie_box, "categorie");
    gestionnaire_dialogue->setComboBox(systeme_box, "systeme");
    gestionnaire_dialogue->setComboBox(logiciel_box, "logiciel");

    this->message_text = ui->message_text;
    this->gestionnaire_dialogue = gestionnaire_dialogue;
    connect(bouton_retour, &QPushButton::clicked,this,&PageAjoutTicket::retour_bouton_clicked);
    connect(bouton_creer_le_ticket, &QPushButton::clicked, this, &PageAjoutTicket::creer_le_ticket_clicked);

}

void PageAjoutTicket::setClient(Client client)
{
    this->client = client;
}

PageAjoutTicket::~PageAjoutTicket()
{
    delete ui;
}

void PageAjoutTicket::retour_bouton_clicked()
{
    QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack){
        stack->setCurrentIndex(ACCUEIL_CLIENT_PAGE); //Connexion correct -> Accueil client
    }
}

void PageAjoutTicket::creer_le_ticket_clicked()
{
    QString categorie = categorie_box->currentText();
    QString id_cat = categorie_box->currentData().toString();
    QString systeme = systeme_box->currentText();
    QString id_systeme = systeme_box->currentData().toString();
    QString logiciel = logiciel_box->currentText();
    QString id_logiciel = logiciel_box->currentData().toString();
    QString message = message_text->toPlainText();

    if (gestionnaire_dialogue->verificationMessage(message)){
        //Récupère la date+heure.
        QString date = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss");
        Categorie cat = Categorie(id_cat, categorie);
        Ticket t = Ticket("T1",date, cat, client);
        if (!systeme.isEmpty()) {
            t.setSysteme(Systeme(id_systeme, systeme));
        }

        if (!logiciel.isEmpty()) {
            t.setLogiciel(Logiciel(id_logiciel, logiciel));
        }
        Message m = Message("M1", date, &client,&t, message);
        t.addMessage(m);
        gestionnaire_dialogue->enregistrer_ticket(t);

        QMessageBox::information(this,"Ticket créé.",t.toString());

        //Retour page accueil si tout est ok
        QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
        if(stack){
            stack->setCurrentIndex(ACCUEIL_CLIENT_PAGE);
        }
    } else {
        QMessageBox::warning(this,"Erreur","Il n'y a pas de messages ou votre message est trop court.");
    }



}

