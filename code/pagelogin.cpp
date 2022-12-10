#include "pagelogin.h"
#include <ui_pagelogin.h>

PageLogin::PageLogin(QStackedWidget *parent, GestionnaireDialogue *gestionnaire) :
    QWidget(parent),
    gestionnaire_dialogue(gestionnaire),stack(parent),
    ui(new Ui::PageLogin)
{
    ui->setupUi(this);
    validation_bouton = ui->valider_bouton;
    id = ui->identifiant;
    mdp = ui->password;
    connect(validation_bouton, &QPushButton::clicked,this,&PageLogin::handle_validation);
}

PageLogin::~PageLogin()
{
    delete mdp;
    delete id;
    //delete validation_bouton;
    delete ui;
    delete user;
    //qDebug() << "Destruction  pageLogin\n";
}

void PageLogin::handle_validation()
{
    QString idU = id->text();
    QString mdpU = mdp->text();
    user = gestionnaire_dialogue->authentification(idU, mdpU);

    if (user != nullptr)
    {
        if (user->estUnClient()){
            auto *widget = stack->widget(ACCUEIL_CLIENT_PAGE);
            auto *pageaccueil = qobject_cast<PageAccueilClient*>(widget);
            pageaccueil->setClient(dynamic_cast<Client*>(user));
            stack->setCurrentIndex(ACCUEIL_CLIENT_PAGE);
        } else if (user->estUnPersonnel()){
            auto *widget = stack->widget(ACCUEIL_PERSONNEL_PAGE);
            auto *pageaccueilpersonnel = qobject_cast<PageAccueilPersonnel*>(widget);
            pageaccueilpersonnel->setPersonnel(dynamic_cast<Personnel*>(user));
            stack->setCurrentIndex(ACCUEIL_PERSONNEL_PAGE);
        }
    }
    else
    {
        QMessageBox::warning(this, "Connexion", "Identifiant ou mot de passe incorrect");
    }

}
