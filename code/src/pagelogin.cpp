#include "pagelogin.h"
#include "ui_pagelogin.h"
#include "client.h"
#include <QMessageBox>
#include <QStackedWidget>
#include "include/constantes.h"

PageLogin::PageLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageLogin)
{
    ui->setupUi(this);
    validation_bouton = ui->valider_bouton;
    id = ui->identifiant;
    mdp = ui->password;
    connect(validation_bouton, &QPushButton::clicked,this,&PageLogin::handle_validation);

}

void PageLogin::setGestionnaireDialogue(GestionnaireDialogue *g)
{
    gestionnaire_dialogue = g;
}

PageLogin::~PageLogin()
{
    delete ui;
}

void PageLogin::handle_validation()
{
    QString idU = id->text();
    QString mdpU = mdp->text();

    std::string typeUser = gestionnaire_dialogue->typeUtilisateur(idU.toStdString(), mdpU.toStdString());


    if (typeUser == "client"){
        Client c = gestionnaire_dialogue->authentification(idU.toStdString(), mdpU.toStdString());
        QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
        if(stack){
            stack->setCurrentIndex(ACCUEIL_CLIENT_PAGE); //Login correct -> Accueil client
       }
    } else {
        QMessageBox::warning(this,"PageLogin","Identifiant ou mot de passe incorrect.");

    }



}
