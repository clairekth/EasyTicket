#include "pagelogin.h"
#include "ui_pagelogin.h"
#include "client.h"
#include <QMessageBox>
#include <QStackedWidget>
#include "include/constantes.h"

PageLogin::PageLogin(QWidget *parent, GestionnaireDialogue *gd) :
    QWidget(parent),
    ui(new Ui::PageLogin)
{
    ui->setupUi(this);
    validation_bouton = ui->valider_bouton;
    id = ui->identifiant;
    mdp = ui->password;
    connect(validation_bouton, &QPushButton::clicked,this,&PageLogin::handle_validation);

    this->gd = gd;

}

//void PageLogin::setGestionnaireDialogue(GestionnaireDialogue *g)
//{
//    gestionnaire_dialogue = g;
//}

PageLogin::~PageLogin()
{
    delete ui;
}

void PageLogin::handle_validation()
{
    QString idU = id->text();
    QString mdpU = mdp->text();

    //Récupère le type d'utilisateur, "null" si inconnu
    std::string typeUser = gd->typeUtilisateur(idU.toStdString(), mdpU.toStdString());


    if (typeUser == "client"){
        Client c = gd->authentification(idU.toStdString(), mdpU.toStdString());
        //Récupère le stack parent.
        QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
        if(stack){
            stack->setCurrentIndex(ACCUEIL_CLIENT_PAGE); //Connexion correct -> Accueil client
       }
    } else {
        QMessageBox::warning(this,"PageLogin","Identifiant ou mot de passe incorrect.");

    }



}
