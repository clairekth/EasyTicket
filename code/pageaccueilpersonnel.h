#ifndef PAGEACCUEILPERSONNEL_H
#define PAGEACCUEILPERSONNEL_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>

#include "constantes.h"
#include "gestionnairedialogue.h"
#include "pageresolutionticket.h"

namespace Ui {
class PageAccueilPersonnel;
}

/// @brief La classe PageAccueilPersonnel correspond à la vue de la page d'accueil pour les membres du Personnel.
///
/// L'interface graghique comporte un QLabel contenant "Bonjour," suivit du prénom, nom et de la fonction (Ingénieur ou
/// Technicien) du Personnel actuellement connecté. L'interface contient également deux QPushButton : un permettant de
/// demander un nouveau ticket à traiter et l'autre permettant d'accéder aux tickets en cours de résolution par le
/// Personnel connecté.
/// @author Victor Dallé, Nicolas Robert, Claire Kurth
/// @version 2.4
class PageAccueilPersonnel : public QWidget
{
    Q_OBJECT

public:
    /// @brief Constructeur par défaut.
    /// @param *parent                  le QStackedWidget parent
    /// @param *gestionnaire_dialogue   le GestionnaireDialogue de l'application
    explicit PageAccueilPersonnel(QStackedWidget *parent = nullptr, GestionnaireDialogue *gestionnaire = nullptr);

    /// @brief Destructeur de la classe.
    ~PageAccueilPersonnel();

    /// @brief Cette méthode permet de définir le Personnel actuellement connecté à la page d'accueil.
    void setPersonnel(Personnel *pers);

private slots:
    /// @brief Cette méthode est rattachée au bouton demander_ticket_bouton.
    /// Elle permet de récupérer le plus ancien ticket sans Personnel qui n'a pas été cloturé. Si il y a bien un ticket, elle
    /// envoit vers la PageResolutionTicket et link le Personnel au Ticket. Si il n'y a pas de ticket, affichage d'une QMessageBox.
    void nouveau_ticket_a_traiter();

private:
    /// @brief le GestionnaireDialogue de l'application.
    GestionnaireDialogue *gestionnaire_dialogue;

    /// @brief le QStackedWidget de l'application.
    QStackedWidget *stack;

    /// @brief Champs correspondant à la vue de PageAccueilPersonnel.
    Ui::PageAccueilPersonnel *ui;

    /// @brief Bouton de demander d'un nouveau Ticket à traiter.
    QPushButton *demander_ticket_bouton;

    /// @brief Bouton permettant d'accéder aux Ticket entrain d'être traité par le Personnel connecté.
    QPushButton *voir_ticket_bouton;

    /// @brief Label affichant "Bonjour" ainsi que le prénom, nom et fonction (Ingénieur ou Technicien)
    /// du Personnel connecté.
    QLabel *label;

    /// @brief Champs correspondant au Personnel connecté.
    Personnel *personnel;
};

#endif // PAGEACCUEILPERSONNEL_H
