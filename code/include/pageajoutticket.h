#ifndef PAGEAJOUTTICKET_H
#define PAGEAJOUTTICKET_H

#include <QWidget>
#include "gestionnairedialogue.h"
namespace Ui {
class PageAjoutTicket;
}

class PageAjoutTicket : public QWidget
{
    Q_OBJECT

public:
    /// @brief Constructeur
    /// @param parent   Widget parent.
    /// @param *gestionnaire_dialogue le @ref GestionnaireDialogue de l'application
    explicit PageAjoutTicket(QWidget *parent = nullptr, GestionnaireDialogue *gestionnaire_dialogue = nullptr);
    ~PageAjoutTicket();

private slots:
    /// @brief Le bouton "Ajouter ticket" est cliqué
    void on_bouton_ajout_ticket_clicked();

private:
    Ui::PageAjoutTicket *ui;

    /// @brief le @ref GestionnaireDialogue de l'application
    GestionnaireDialogue *gestionnaire_dialogue;
};

#endif // PAGEAJOUTTICKET_H
