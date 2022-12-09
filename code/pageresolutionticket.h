#ifndef PAGERESOLUTIONTICKET_H
#define PAGERESOLUTIONTICKET_H

#include "gestionnairedialogue.h"
#include "constantes.h"
#include "personnel.h"

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QTableWidget>
#include <QTextEdit>
#include <QInputDialog>

namespace Ui {
class PageResolutionTicket;
}

/// @brief La classe PageResolutionTicket correspond à la vue de la page permettant aux Personnel de résoudre un Ticket.
///
/// L'interface graghique comporte un QPushButton "Retour" permettant de retourner à la PageAccueilPersonnel. Elle contient également
/// 8 QLabel :
///     - Un label pour afficher l'identifiant du Ticket
///     - Un label pour afficher la date du Ticket
///     - Un label pour afficher si le Ticket est en cours ou non
///     - Un label pour afficher la Categorie du Ticket
///     - Un label pour afficher le Systeme du Ticket
///     - Un label pour afficher le Logiciel du Ticket
///     - Un label pour afficher l'auteur du Ticket
///     - Un label pour afficher le Personnel chargé de résoudre le Ticket
/// Elle contient aussi une QTableWidget qui est dans un scrollAreaWidgetContents. La QTableWidget permet d'afficher les différents
/// messages du Ticket.
/// L'interface graphique contient également un QTextEdit pour écrire un nouveau message ainsi qu'un QPushButton "Envoyer" pour envoyer
/// le message.
/// Il y a aussi 3 autres QPushButton :
///     - "Changer catégorie du Ticket" qui permet de changer la catégorie d'un Ticket
///     - "Transmettre à ..." qui permet de transmettre à un autre membre du Personnel. Ce bouton est invisible si c'est un Ingenieur.
///     - "Clore" qui permet de clore un Ticket.
/// @author Victor Dallé, Nicolas Robert, Claire Kurth
/// @version 2.6
class PageResolutionTicket : public QWidget
{
    Q_OBJECT

public:
    /// @brief Constructeur par défaut.
    /// @param *parent                  le QStackedWidget parent
    /// @param *gestionnaire_dialogue   le GestionnaireDialogue de l'application
    explicit PageResolutionTicket(QStackedWidget *parent = nullptr, GestionnaireDialogue *gestionnaire = nullptr);

    /// @brief Destructeur de la classe.
    ~PageResolutionTicket();

    /// @brief Cette méthode permet de set le Personnel actuellement connecté qui résout le Ticket.
    /// @param *pers Pointeur sur le Personnel résolvant le Ticket.
    void setPersonnel(Personnel *pers);

    /// @brief Cette méthode permet de set le Ticket qui est entrain d'être résolu par le Personnel.
    /// @param *t Pointeur sur le Ticket entrain d'être résolu.
    void setTicket(Ticket *t);


private slots:
    /// @brief Cette méthode est appelée lors d'un click sur le bouton retour_bouton.
    /// Elle permet de renvoyer le Personnel sur la page d'accueil.
    void retour_accueil();

    /// @brief Méthode appelée lors d'un click sur le bouton boutonEnvoyerMessage.
    /// Elle permet d'enregistrer le message saisi par le Personnel.
    void ajouter_message();

    /// @brief Cette méthode est appelée lors d'un click sur le bouton changer_cat_bouton.
    /// Elle permet de changer la catégorie d'un ticket si le client l'a mal définie.
    void changer_categorie();

private:
    /// @brief le GestionnaireDialogue de l'application
    GestionnaireDialogue *gestionnaire_dialogue;

    /// @brief le QStackedWidget de l'application.
    QStackedWidget *stack;

    /// @brief Champs correspondant à la vue de PageResolutionTicket.
    Ui::PageResolutionTicket *ui;

    /// @brief Champs correspondant au Personnel chargé de résoudre le Ticket.
    Personnel *personnel;

    /// @brief Champs correspondant au Ticket à résoudre.
    Ticket *ticket;

    /// @brief Le bouton permettant de retourner à la PageAccueilPersonnel.
    /// Il est connecté au slot retour_accueil().
    QPushButton *retour_btn;

    /// @brief Le bouton permettant d'envoyer un message.
    /// Il est connecté au slot ajouter_message().
    QPushButton *envoyer_btn;

    /// @brief Le bouton permettant de changer la catégorie du ticket.
    /// Il est connecté au slot changer_categorie().
    QPushButton *changer_cat_btn;

    /// @brief La QTableWidget permet d'afficher tous les Message appartenant au Ticket.
    QTableWidget *liste_messages;

    /// @brief La zone pour écrire un nouveau message.
    QTextEdit *zoneMessage;

    /// @brief Le label où la catégorie du Ticket est affiché.
    QLabel *categorie;

    /// @brief Le label où le système du Ticket est affiché.
    QLabel *systeme;

    /// @brief Le label où le logiciel du Ticket est affiché.
    QLabel *logiciel;

    /// @brief Le label où l'identifiant du Ticket est affiché.
    QLabel *id_ticket;

    /// @brief Le label où la date de création du Ticket est affichée.
    QLabel *date;

    /// @brief Le label où le propriétaire du Ticket est affiché.
    QLabel *proprietaire;

    /// @brief Le label où le personne qui résout le Ticket est affiché.
    QLabel *personnelGestionnaire;
};

#endif // PAGERESOLUTIONTICKET_H
