#include "pagelogin.h"
#include "ui_pagelogin.h"
#include <QMessageBox>
#include <QStackedWidget>
#include "include/constantes.h"
#include "pageaccueilclient.h"

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
    delete ui;
}

void PageLogin::handle_validation()
{
    QString idU = id->text();
    QString mdpU = mdp->text();
}
