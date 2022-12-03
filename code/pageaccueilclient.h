#ifndef PAGEACCUEILCLIENT_H
#define PAGEACCUEILCLIENT_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>

/// @brief La classe PageAccueilClient correspond à la vue de la page d'accueil pour les Client.
/// @author Victor Dallé, Nicolas Robert, Claire Kurth
/// @version 1.5

namespace Ui {
class PageAccueilClient;
}


class PageAccueilClient : public QWidget
{
    Q_OBJECT

public:
    /// @brief Constructeur par défaut.
    /// @param *parent                  Widget parent.
    /// @param *gestionnaire_dialogue   le GestionnaireDialogue de l'application
    explicit PageAccueilClient(QWidget *parent = nullptr);

    /// @brief Destructeur.
    ~PageAccueilClient();

private slots:
    /// @brief Cette méthode est appelée lors d'un click sur le bouton creer_ticket_bouton. Elle permet la création d'un nouveau Ticket.
    void creation_ticket();

private:
    /// @brief Champs correspondant à la vue de PageAccueilClient.
    Ui::PageAccueilClient *ui;
    /// @brief Bouton de création d'un ticket.
    QPushButton *creer_ticket_bouton;

    /// @brief Bouton pour voir l'historique des tickets.
    QPushButton *historique_tickets_bouton;

    QStackedWidget *stack;

};

#endif // PAGEACCUEILCLIENT_H
