#ifndef PAGERESOLUTIONTICKET_H
#define PAGERESOLUTIONTICKET_H

#include "gestionnairedialogue.h"
#include "constantes.h"
#include "personnel.h"

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class PageResolutionTicket;
}

class PageResolutionTicket : public QWidget
{
    Q_OBJECT

public:
    explicit PageResolutionTicket(QStackedWidget *parent = nullptr, GestionnaireDialogue *gestionnaire = nullptr);

    ~PageResolutionTicket();

    void setPersonnel(Personnel *pers);

private slots:
    /// @brief Cette méthode est appelée lors d'un click sur le bouton retour_bouton.
    /// Elle permet de renvoyer le Personnel sur la page d'accueil.
    void retour_accueil();

private:
    /// @brief le GestionnaireDialogue de l'application
    GestionnaireDialogue *gestionnaire_dialogue;

    /// @brief le QStackedWidget de l'application.
    QStackedWidget *stack;

    /// @brief Champs correspondant à la vue de PageResolutionTicket.
    Ui::PageResolutionTicket *ui;


    Personnel *personnel;

    Ticket *ticket;

    QPushButton *retour_btn;

    QLabel *label;
};

#endif // PAGERESOLUTIONTICKET_H
