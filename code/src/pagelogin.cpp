#include "pagelogin.h"
#include "ui_pagelogin.h"
#include <QMessageBox>

PageLogin::PageLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageLogin)
{
    ui->setupUi(this);
    validation_boutton = ui->valider_boutton;
    id = ui->identifiant;
    mdp = ui->password;
    connect(validation_boutton, &QPushButton::clicked,this,&PageLogin::handle_validation);

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
        if(idU == "" || mdpU=="") {
                QMessageBox::warning(this,"PageLogin","Password not correct.");
        } else {
            QMessageBox::information(this,"PageLogin","Client");
        }
}
