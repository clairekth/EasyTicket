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


/// @brief La classe PageResolutionTicket correspond à la vue de la page permettant aux Personnel de résoudre un Ticket.
///
/// L'interface graghique comporte un QPushButton "Retour" permettant de retourner à la PageAccueilPersonnel.
/// @author Victor Dallé, Nicolas Robert, Claire Kurth
/// @version 2.4
namespace Ui {
class PageResolutionTicket;
}

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

    Ticket* getTicket();

    /// @brief Cette méthode permet de set le QTableWidget qui contient la liste des messages du ticket.
    /// @param  liste_messages  la nouvelles liste des messages.
    void setListeMessages(QTableWidget* liste_messages);

    /// @brief Cette méthode permet de get le QTableWidget qui contient la liste des messages du ticket.
    /// @return  la liste des messages.
    QTableWidget* getListeMessage();

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

    /// @brief Champs correspondant au Personnel chargé de résoudre le Ticket.
    Personnel *personnel;

    /// @brief Champs correspondant au Ticket à résoudre.
    Ticket *ticket;

    /// @brief Le bouton permettant de retourner à la PageAccueilPersonnel.
    QPushButton *retour_btn;

    /// @brief La liste des tickets.
    QTableWidget *liste_messages;

    /// @brief La zone pour écrire un nouveau message.
    QTextEdit *zoneMessage;

    QLabel *categorie;
    QLabel *systeme;
    QLabel *logiciel;
    QLabel *id_ticket;
    QLabel *date;
};

#endif // PAGERESOLUTIONTICKET_H
