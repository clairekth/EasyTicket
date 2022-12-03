#include "pageaccueilclient.h"
#include "ui_pageaccueilclient.h"

PageAccueilClient::PageAccueilClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAccueilClient)
{
    ui->setupUi(this);
    this->stack = qobject_cast<QStackedWidget*>(parent);

    creer_ticket_bouton = ui->creer_ticket_bouton;
    historique_tickets_bouton = ui->historique_tickets_bouton;

    connect(creer_ticket_bouton, &QPushButton::clicked, this, &PageAccueilClient::creation_ticket);
}

PageAccueilClient::~PageAccueilClient()
{
    delete ui;
    delete creer_ticket_bouton;
    delete historique_tickets_bouton;
    qDebug() << "Destruction  pageAccueilClient\n";
}

void PageAccueilClient::creation_ticket()
{
        //On transfère le client à la page suivante.
        stack->setCurrentIndex(AJOUT_TICKET_PAGE);
}
