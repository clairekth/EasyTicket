#include "pagelogin.h"
#include <ui_pagelogin.h>

PageLogin::PageLogin(QWidget *parent, GestionnaireDialogue *gestionnaire) :
    QWidget(parent),
    gestionnaire_dialogue(gestionnaire),
    ui(new Ui::PageLogin)
{
    ui->setupUi(this);
    validation_bouton = ui->valider_bouton;
    id = ui->identifiant;
    mdp = ui->password;
    connect(validation_bouton, &QPushButton::clicked,this,&PageLogin::handle_validation);
    this->stack = qobject_cast<QStackedWidget*>(parent);

}

PageLogin::~PageLogin()
{
    delete mdp;
    delete id;
    delete validation_bouton;
    delete ui;
    qDebug() << "Destruction  pageLogin\n";
}

void PageLogin::handle_validation()
{
    QString idU = id->text();
    QString mdpU = mdp->text();
    Utilisateur *user = gestionnaire_dialogue->authentification(idU, mdpU);
    if (user != nullptr)
    {
        if (true)
        {
            auto *widget = stack->widget(ACCUEIL_CLIENT_PAGE);
            auto *pageaccueil = qobject_cast<PageAccueilClient*>(widget);
            pageaccueil->setClient(dynamic_cast<Client*>(user));
            stack->setCurrentIndex(ACCUEIL_CLIENT_PAGE);
        }
    }
    else
    {
        QMessageBox::warning(this, "Connexion", "Identifiant ou mot de passe incorrect");
    }

    delete user;
}
