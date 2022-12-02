#include "pagelogin.h"
#include "ui_pagelogin.h"
#include <QMessageBox>
#include <QStackedWidget>
#include "include/constantes.h"
#include "pageaccueilclient.h"
#include "pageaccueilpersonnel.h"

PageLogin::PageLogin(QWidget *parent, GestionnaireDialogue *gestionnaire_dialogue) :
    QWidget(parent),
    ui(new Ui::PageLogin)
{
    ui->setupUi(this);
    validation_bouton = ui->valider_bouton;
    id = ui->identifiant;
    mdp = ui->password;
    connect(validation_bouton, &QPushButton::clicked,this,&PageLogin::handle_validation);
    this->stack = qobject_cast<QStackedWidget*>(parent);
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

    Utilisateur *user = gestionnaire_dialogue->authentification(idU,mdpU);
    if (!user){
        QMessageBox::warning(this,"PageLogin","Identifiant ou mot de passe incorrect.");
    } else {
        if (user->estUnClient()){
             //On récupère le widget suivant pour lui set le client actuellement connecté.
             auto *widget = stack->widget(ACCUEIL_CLIENT_PAGE);
             auto *pageaccueil = qobject_cast<PageAccueilClient*>(widget);
             Client *c = static_cast<Client*>(user);
             pageaccueil->setClient(c);
             stack->setCurrentIndex(ACCUEIL_CLIENT_PAGE); //Connexion correct -> Accueil client

        } else if (user->estUnIngenieur()){
                auto *widget = stack->widget(ACCUEIL_PERSONNEL_PAGE);
                auto *pageaccueil = qobject_cast<PageAccueilPersonnel*>(widget);
                Personnel *p = static_cast<Personnel*>(user);
                pageaccueil->setPersonnel(p);
                stack->setCurrentIndex(ACCUEIL_PERSONNEL_PAGE); //Connexion correct -> Accueil personnel

        }
    }
}
