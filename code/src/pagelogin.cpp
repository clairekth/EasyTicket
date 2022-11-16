#include "pagelogin.h"
#include "ui_pagelogin.h"
#include "client.h"
#include <QMessageBox>

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

PageLogin::~PageLogin()
{
    delete ui;
}

void PageLogin::handle_validation()
{
    QString idU = id->text();
    idU = idU.trimmed(); //Enlève espaces
    QString mdpU = mdp->text();
    mdpU = mdpU.trimmed();
    if(idU == "" || mdpU == "") {
        QMessageBox::warning(this,"PageLogin","Identifiant ou mot de passe incorrect.");
    } else {
        Client client1 = Client(idU.toLower().toStdString(), "Vous", "Même", mdpU.toStdString(), idU.toLower().toStdString() + "@easyticket.fr");
        QMessageBox::information(this,"Interface Client",QString::fromStdString(client1.toString()));
    }
}
