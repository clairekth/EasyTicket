#include "pageaccueilclient.h"
#include "ui_pageaccueilclient.h"

PageAccueilClient::PageAccueilClient(QStackedWidget *parent, GestionnaireDialogue *gestionnaire) :
    QWidget(parent),
    gestionnaire_dialogue(gestionnaire), stack(parent),
    ui(new Ui::PageAccueilClient)
{
    ui->setupUi(this);

    creer_ticket_bouton = ui->creer_ticket_bouton;
    historique_tickets_bouton = ui->historique_tickets_bouton;
    label = ui->bonjour_client;
    connect(creer_ticket_bouton, &QPushButton::clicked, this, &PageAccueilClient::creation_ticket);
}

PageAccueilClient::~PageAccueilClient()
{
    delete creer_ticket_bouton;
    delete historique_tickets_bouton;
    delete label;
    delete ui;
   // qDebug() << "Destruction  pageAccueilClient\n";
}

void PageAccueilClient::setClient(Client *client)
{
    this->client = client;
    label->setText("Bonjour, " + this->client->getPrenom() + " " + (this->client->getNom()));
}

void PageAccueilClient::creation_ticket()
{
        //On transfère le client à la page suivante.
        auto *widget = stack->widget(AJOUT_TICKET_PAGE);
        auto *ajoutticket = qobject_cast<PageAjoutTicket*>(widget);
        ajoutticket->setClient(client);
        stack->setCurrentIndex(AJOUT_TICKET_PAGE);
}
