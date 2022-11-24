#include "pageajoutticket.h"
#include "ui_pageajoutticket.h"

#include <QStackedWidget>
#include <constantes.h>

PageAjoutTicket::PageAjoutTicket(QWidget *parent, GestionnaireDialogue *gestionnaire_dialogue) :
    QWidget(parent),
    ui(new Ui::PageAjoutTicket)
{
    ui->setupUi(this);
    this->bouton_retour = ui->bouton_retour;
    this->gestionnaire_dialogue = gestionnaire_dialogue;
    connect(bouton_retour, &QPushButton::clicked,this,&PageAjoutTicket::retour_bouton_clicked);

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
