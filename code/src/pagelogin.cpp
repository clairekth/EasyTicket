#include "pagelogin.h"
#include "ui_pagelogin.h"
#include <QMessageBox>
#include <QStackedWidget>
#include "include/constantes.h"
#include "pageaccueilclient.h"

PageLogin::PageLogin(QWidget *parent, GestionnaireDialogue *gestionnaire_dialogue) :
    QWidget(parent),
    ui(new Ui::PageLogin)
{
    ui->setupUi(this);
    validation_bouton = ui->valider_bouton;
    id = ui->identifiant;
    mdp = ui->password;
    connect(validation_bouton, &QPushButton::clicked,this,&PageLogin::handle_validation);

    this->gestionnaire_dialogue = gestionnaire_dialogue;

}

PageLogin::~PageLogin()
{
    delete ui;
}

void PageLogin::handle_validation()
{
    QString idU = id->text();
    QString mdpU = mdp->text();

    //Récupère le type d'utilisateur, "null" si inconnu
    std::string typeUser = gestionnaire_dialogue->typeUtilisateur(idU.toStdString(), mdpU.toStdString());

    if (typeUser == "client"){
        Client c = gestionnaire_dialogue->authentification(idU.toStdString(), mdpU.toStdString());
        //Récupère le stack parent.
        QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
        if(stack){
            //On récupère le widget suivant pour lui set le client actuellement connecté.
            auto *widget = stack->widget(ACCUEIL_CLIENT_PAGE);
            auto *pageaccueil = qobject_cast<PageAccueilClient*>(widget);
            pageaccueil->setClient(c);
            stack->setCurrentIndex(ACCUEIL_CLIENT_PAGE); //Connexion correct -> Accueil client
       }
    } else {
        QMessageBox::warning(this,"PageLogin","Identifiant ou mot de passe incorrect.");

    }
}
