#ifndef PAGEAJOUTTICKET_H
#define PAGEAJOUTTICKET_H

#include <QWidget>
#include "gestionnairedialogue.h"
#include <QPushButton>

/// @brief La classe PageAjoutTicket correspond à la vue de la page qui permet au Client connecté de créer un nouveau Ticket.
/// @author Victor Dallé, Nicolas Robert, Claire Kurth
/// @version 1.3
namespace Ui {
class PageAjoutTicket;
}

class PageAjoutTicket : public QWidget
{
    Q_OBJECT


public:
    /// @brief Constructeur
    /// @param parent                   Widget parent.
    /// @param *gestionnaire_dialogue   le @ref GestionnaireDialogue de l'application
    explicit PageAjoutTicket(QWidget *parent = nullptr, GestionnaireDialogue *gestionnaire_dialogue = nullptr);
    ~PageAjoutTicket();

private slots:
    /// @brief Le bouton bouton_retour est cliqué. Il permet de retourner à PageAccueilClient.
    void retour_bouton_clicked();

private:
    Ui::PageAjoutTicket *ui;
    /// @brief le @ref GestionnaireDialogue de l'application
    GestionnaireDialogue *gestionnaire_dialogue;

    /// @brief Bouton de retour à la PageAccueilClient.
    QPushButton *bouton_retour;


};

#endif // PAGEAJOUTTICKET_H
