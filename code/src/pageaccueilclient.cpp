#include "pageaccueilclient.h"
#include "ui_pageaccueilclient.h"
#include "pageajoutticket.h"
#include <QStackedWidget>

#include "constantes.h"

PageAccueilClient::PageAccueilClient(QWidget *parent, GestionnaireDialogue *gestionnaire_dialogue) :
    QWidget(parent),
    ui(new Ui::PageAccueilClient)
{
    ui->setupUi(this);
    creer_ticket_bouton = ui->creer_ticket_bouton;
    historique_tickets_bouton = ui->historique_tickets_bouton;
    connect(creer_ticket_bouton, &QPushButton::clicked, this, &PageAccueilClient::creation_ticket);
    this->gestionnaire_dialogue = gestionnaire_dialogue;
}

void PageAccueilClient::setClient(Client client)
{
    this->client = client;

}

PageAccueilClient::~PageAccueilClient()
{
    delete ui;
}

void PageAccueilClient::creation_ticket()
{
    QStackedWidget *stack = qobject_cast<QStackedWidget* >(parentWidget());
    if(stack){
        //On transfère le client à la page suivante.
        auto *widget = stack->widget(AJOUT_TICKET_PAGE);
        auto *ajoutticket = qobject_cast<PageAjoutTicket*>(widget);
        ajoutticket->setClient(this->client);
        stack->setCurrentIndex(AJOUT_TICKET_PAGE);
    }
}
