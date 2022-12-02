#ifndef PAGEACCUEILPERSONNEL_H
#define PAGEACCUEILPERSONNEL_H

#include <QWidget>
#include "gestionnairedialogue.h"
#include <QPushButton>

/// @brief La classe PageAccueilPersonnel correspond à la vue de la page d'accueil pour le Personnel.
/// @author Victor Dallé, Nicolas Robert, Claire Kurth
/// @version 2.1
namespace Ui {
class PageAccueilPersonnel;
}

class PageAccueilPersonnel : public QWidget
{
    Q_OBJECT

public:
    /// @brief Constructeur par défaut.
    /// @param *parent                  Widget parent.
    /// @param *gestionnaire_dialogue   le GestionnaireDialogue de l'application
    explicit PageAccueilPersonnel(QWidget *parent = nullptr, GestionnaireDialogue *gestionnaire_dialogue = nullptr);

    /// @brief Méthode permettant de set le Personnel actuellement connecté.
    /// @param *personnel   le Personnel connecté.
    void setPersonnel(Personnel *personnel);

    /// @brief Destructeur.
    ~PageAccueilPersonnel();

private:
    Ui::PageAccueilPersonnel *ui;
    /// @brief Champs correspondant au GestionnaireDialogue.
    GestionnaireDialogue *gestionnaire_dialogue;
    /// @brief Bouton de demande d'un nouveau ticket
    QPushButton *demander_ticket_bouton;
    /// @brief Bouton de consultation des tickets en cours
    QPushButton *consulter_tickets_bouton;
    /// @brief Champs contenant le Personnel actuellement connecté
    Personnel *personnel;
};

#endif // PAGEACCUEILPERSONNEL_H
