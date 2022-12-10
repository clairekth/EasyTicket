#include "pageajoutticket.h"
#include "ui_pageajoutticket.h"

PageAjoutTicket::PageAjoutTicket(QStackedWidget *parent, GestionnaireDialogue *gestionnaire_dialogue) :
    QWidget(parent),
    gestionnaire_dialogue(gestionnaire_dialogue), stack(parent),
    ui(new Ui::PageAjoutTicket)
{
    ui->setupUi(this);

    bouton_retour = ui->bouton_retour;
    bouton_creer_le_ticket = ui->creer_le_ticket_bouton;

    categorie_box = ui->categorie_box;
    systeme_box = ui->systeme_box;
    logiciel_box = ui->logiciel_box;
    gestionnaire_dialogue->setComboBox(categorie_box, "categorie");
    gestionnaire_dialogue->setComboBox(systeme_box, "systeme");
    gestionnaire_dialogue->setComboBox(logiciel_box, "logiciel");

    message_text = ui->message_text;

    connect(bouton_retour, &QPushButton::clicked,this,&PageAjoutTicket::retour_bouton_clicked);
    connect(bouton_creer_le_ticket, &QPushButton::clicked, this, &PageAjoutTicket::creer_le_ticket_clicked);
}

PageAjoutTicket::~PageAjoutTicket()
{
    delete message_text;
    delete bouton_creer_le_ticket;
    delete bouton_retour;
    delete categorie_box;
    delete logiciel_box;
    delete systeme_box;
    delete ui;
}

void PageAjoutTicket::setClient(Client *client)
{
    this->client = client;
    //qDebug() << this->client->toString();
}

void PageAjoutTicket::retour_bouton_clicked()
{
    stack->setCurrentIndex(ACCUEIL_CLIENT_PAGE); //Connexion correct -> Accueil client

}

void PageAjoutTicket::creer_le_ticket_clicked()
{
    QString categorie = categorie_box->currentText();
    int id_cat = categorie_box->currentData().toInt();
    QString systeme = systeme_box->currentText();
    int id_systeme = systeme_box->currentData().toInt();
    QString logiciel = logiciel_box->currentText();
    int id_logiciel = logiciel_box->currentData().toInt();
    QString message = message_text->toPlainText();

    if (gestionnaire_dialogue->verificationMessage(message)){
        //Récupère la date+heure.
        QString date = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
        Categorie cat = Categorie(id_cat, categorie);
        Ticket t = Ticket(date, cat, client);
        if (!systeme.isEmpty()) {
            Systeme sys = Systeme(id_systeme,systeme);
            t.setSysteme(sys);
        } else {
            Systeme sys = Systeme(-1, "");
            t.setSysteme(sys);
        }

        if (!logiciel.isEmpty()) {
            Logiciel log = Logiciel(id_logiciel, logiciel);
            t.setLogiciel(log);
        } else {
            Logiciel log = Logiciel(-1, "");
            t.setLogiciel(log);
        }
        Message m = Message(date, client, &t, message);
        t.addMessage(&m);
        gestionnaire_dialogue->enregistrer_ticket(&t);

        //Retour page accueil si tout est ok
        message_text->setText("");
        categorie_box->setCurrentIndex(0);
        logiciel_box->setCurrentIndex(0);
        systeme_box->setCurrentIndex(0);
            stack->setCurrentIndex(ACCUEIL_CLIENT_PAGE);
    } else {
        QMessageBox::warning(this,"Erreur","Il n'y a pas de messages ou votre message est trop court.");
    }
}
