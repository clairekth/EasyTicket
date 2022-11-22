#ifndef PAGEACCUEILCLIENT_H
#define PAGEACCUEILCLIENT_H

#include <QWidget>
#include <QPushButton>
#include "gestionnairedialogue.h"

/// @brief La classe PageAccueilClient correspond à la vue de la page d'accueil pour les Client.
/// @author Victor Dallé, Nicolas Robert, Claire Kurth
/// @version 1.2

namespace Ui {
class PageAccueilClient;
}


class PageAccueilClient : public QWidget
{
    Q_OBJECT

protected :
    /// @brief Bouton de création d'un ticket.
    QPushButton *creer_ticket_bouton;

    /// @brief Bouton pour voir l'historique des tickets.
    QPushButton *historique_tickets_bouton;

    /// @brief Champs correspondant au GestionnaireDialogue.
    GestionnaireDialogue *gestionnaire_dialogue;

public:
    /// @brief Constructeur par défaut.
    /// @param *parent  Widget parent.
    explicit PageAccueilClient(QWidget *parent = nullptr);

    /// @brief Méthode pour set le GestionnaireDialogue.
    /// @param g    Pointeur sur le GestionnaireDialogue.
    void setGestionnaireDialogue(GestionnaireDialogue *g);

    /// @brief Destructeur.
    ~PageAccueilClient();

public slots:
    /// @brief Cette méthode est appelée lors d'un click sur le bouton creer_ticket_bouton. Elle permet la création d'un nouveau Ticket.
    void creation_ticket();

private:
    /// @brief Champs correspondant à la vue de PageAccueilClient.
    Ui::PageAccueilClient *ui;
};

#endif // PAGEACCUEILCLIENT_H
