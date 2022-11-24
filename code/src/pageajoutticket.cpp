#include "pageajoutticket.h"
#include "ui_pageajoutticket.h"

#include <QStackedWidget>
#include "constantes.h"
#include "categorie.h"

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
    //Pour l'instant les items ont été ajouté à la main directement dans la confection de l'ui mais avec la BDD : boucle qui pr chaque catégorie/logiciel/systeme
    //->créer une Categorie(..), Logiciel(..), Systeme(...) et fait ensuite un nom_combobox->addItem(cat.getNom())

    this->message_text = ui->message_text;
    this->gestionnaire_dialogue = gestionnaire_dialogue;
    connect(bouton_retour, &QPushButton::clicked,this,&PageAjoutTicket::retour_bouton_clicked);
    connect(bouton_creer_le_ticket, &QPushButton::clicked, this, &PageAjoutTicket::creer_le_ticket_clicked);

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
    QString systeme = systeme_box->currentText();
    QString logiciel = logiciel_box->currentText();
    QString message = message_text->toPlainText();
    std::cout << "Categorie :" + categorie.toStdString() << std::endl;

    if (systeme == ""){
        std::cout << "Pas de systeme selectionne." << std::endl;
    }else {
        std::cout << "Systeme :" + systeme.toStdString() << std::endl;
    }
    if (logiciel == ""){
        std::cout << "Pas de logiciel selectionne." << std::endl;
    } else {
        std::cout << "Logiciel :" + logiciel.toStdString() << std::endl;
    }

    if (message == ""){
        std::cout << "Pas de message." << std::endl;
    } else {
        std::cout << message.toStdString() << std::endl;
    }
    fflush(stderr);



}
