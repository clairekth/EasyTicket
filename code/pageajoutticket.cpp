#include "pageajoutticket.h"
#include "ui_pageajoutticket.h"

PageAjoutTicket::PageAjoutTicket(QWidget *parent, GestionnaireDialogue *gestionnaire_dialogue) :
    QWidget(parent),
    ui(new Ui::PageAjoutTicket)
{
    ui->setupUi(this);
    this->stack = qobject_cast<QStackedWidget*>(parent);

    bouton_retour = ui->bouton_retour;
    bouton_creer_le_ticket = ui->creer_le_ticket_bouton;

    categorie_box = ui->categorie_box;
    systeme_box = ui->systeme_box;
    logiciel_box = ui->logiciel_box;
    gestionnaire_dialogue->setComboBox(categorie_box, "categorie");
    gestionnaire_dialogue->setComboBox(systeme_box, "systeme");
    gestionnaire_dialogue->setComboBox(logiciel_box, "logiciel");

    this->message_text = ui->message_text;
    this->gestionnaire_dialogue = gestionnaire_dialogue;
    connect(bouton_retour, &QPushButton::clicked,this,&PageAjoutTicket::retour_bouton_clicked);
    connect(bouton_creer_le_ticket, &QPushButton::clicked, this, &PageAjoutTicket::creer_le_ticket_clicked);
}

PageAjoutTicket::~PageAjoutTicket()
{
    delete ui;
}

void PageAjoutTicket::setClient(Client *client)
{
    this->client = client;
}

void PageAjoutTicket::retour_bouton_clicked()
{
        stack->setCurrentIndex(ACCUEIL_CLIENT_PAGE); //Connexion correct -> Accueil client

}

void PageAjoutTicket::creer_le_ticket_clicked()
{
//    QString categorie = categorie_box->currentText();
//    int id_cat = categorie_box->currentData().toInt();
//    QString systeme = systeme_box->currentText();
//    int id_systeme = systeme_box->currentData().toInt();
//    QString logiciel = logiciel_box->currentText();
//    int id_logiciel = logiciel_box->currentData().toInt();
//    QString message = message_text->toPlainText();

//    if (gestionnaire_dialogue->verificationMessage(message)){
//        //Récupère la date+heure.
//        QString date = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss");
//        Categorie cat = Categorie(id_cat, categorie);
//        Ticket t = Ticket(date, cat, client);
//        if (!systeme.isEmpty()) {
//            t.setSysteme(Systeme(id_systeme, systeme));
//        } else {
//            t.setSysteme(Systeme(-1, ""));
//        }

//        if (!logiciel.isEmpty()) {
//            t.setLogiciel(Logiciel(id_logiciel, logiciel));
//        } else {
//            t.setLogiciel(Logiciel(-1, ""));
//        }
//        Message m = Message(date, client,&t, message);
//        t.addMessage(m);
//        gestionnaire_dialogue->enregistrer_ticket(t);

//        //Retour page accueil si tout est ok
//            stack->setCurrentIndex(ACCUEIL_CLIENT_PAGE);
//    } else {
//        QMessageBox::warning(this,"Erreur","Il n'y a pas de messages ou votre message est trop court.");
//    }
}
