#include "pagelogin.h"
#include <ui_pagelogin.h>

PageLogin::PageLogin(QWidget *parent) :
    QWidget(parent),
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
    GestionnaireDialogue gestionnaire;
    Utilisateur *user = gestionnaire.authentification(idU, mdpU);
    if (user != nullptr)
        qDebug() << user->toString();

    Utilisateur *test = gestionnaire.authentification(idU, mdpU);
    if (test != nullptr)
        qDebug() << test->toString();

    delete user;
    delete test;
}
