#ifndef PAGEACCUEILCLIENT_H
#define PAGEACCUEILCLIENT_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QDebug>

#include "constantes.h"
#include "gestionnairedialogue.h"
#include "pageajoutticket.h"

/// @brief La classe PageAccueilClient correspond à la vue de la page d'accueil pour les Client. L'interface graghique
/// comporte un QLabel contenant "Bonjour," suivit du prénom et nom du Client connecté. Elle contient également deux
/// QPushButton : un permettant de créer un nouveau ticket et l'autre permettant d'accéder à l'historique des tickets
/// du Client.
/// @author Victor Dallé, Nicolas Robert, Claire Kurth
/// @version 2.3

namespace Ui {
class PageAccueilClient;
}


class PageAccueilClient : public QWidget
{
    Q_OBJECT

public:
    /// @brief Constructeur par défaut.
    /// @param *parent                  le QStackedWidget parent
    /// @param *gestionnaire_dialogue   le GestionnaireDialogue de l'application
    explicit PageAccueilClient(QStackedWidget *parent = nullptr, GestionnaireDialogue *gestionnaire = nullptr);

    /// @brief Destructeur.
    ~PageAccueilClient();

    /// @brief Cette méthode permet de définir le Client actuellement connecté à la page d'accueil.
    void setClient(Client *client);

private slots:
    /// @brief Cette méthode est appelée lors d'un click sur le bouton creer_ticket_bouton. Elle permet la création d'un nouveau Ticket.
    void creation_ticket();

private:
    /// @brief le GestionnaireDialogue de l'application.
    GestionnaireDialogue *gestionnaire_dialogue;

    /// @brief le QStackedWidget de l'application.
    QStackedWidget *stack;

    /// @brief Champs correspondant à la vue de PageAccueilClient.
    Ui::PageAccueilClient *ui;

    /// @brief Bouton de création d'un ticket.
    QPushButton *creer_ticket_bouton;

    /// @brief Bouton pour voir l'historique des tickets.
    QPushButton *historique_tickets_bouton;

    /// @brief Label affichant "Bonjour" ainsi que le nom et prénom du Client connecté.
    QLabel *label;

    /// @brief Champs correspondant au Client connecté.
    Client *client;


};

#endif // PAGEACCUEILCLIENT_H
