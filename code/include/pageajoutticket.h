#ifndef PAGEAJOUTTICKET_H
#define PAGEAJOUTTICKET_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include "gestionnairedialogue.h"

/// @brief La classe PageAjoutTicket correspond à la vue de la page qui permet au Client connecté de créer un nouveau Ticket.
/// @author Victor Dallé, Nicolas Robert, Claire Kurth
/// @version 1.8
namespace Ui {
class PageAjoutTicket;
}

class PageAjoutTicket : public QWidget
{
    Q_OBJECT


public:
    /// @brief Constructeur
    /// @param parent                   Widget parent.
    /// @param *gestionnaire_dialogue   le GestionnaireDialogue de l'application
    explicit PageAjoutTicket(QWidget *parent = nullptr, GestionnaireDialogue *gestionnaire_dialogue = nullptr);

    /// @brief Méthode permettant de set le Client actuellement connecté.
    /// @param client   le Client connecté.
    void setClient(Client *client);
    ~PageAjoutTicket();

private slots:
    /// @brief Le bouton bouton_retour est cliqué. Cette méthode permet de retourner à PageAccueilClient.
    void retour_bouton_clicked();
    /// @brief Le bouton creer_le_ticket_clicked est cliqué. Cette méthode permet de créer un nouveau Ticket.
    void creer_le_ticket_clicked();

private:
    Ui::PageAjoutTicket *ui;
    /// @brief le GestionnaireDialogue de l'application
    GestionnaireDialogue *gestionnaire_dialogue;

    /// @brief Champs contenant le Client connecté.
    Client *client;

    /// @brief Bouton de retour à la PageAccueilClient.
    QPushButton *bouton_retour;

    /// @brief Bouton de retour qui créer le Ticket.
    QPushButton *bouton_creer_le_ticket;

    /// @brief ComboBox correspondant aux différentes catégories disponibles.
    QComboBox *categorie_box;
    /// @brief ComboBox correspondant aux différents systèmes disponibles.
    QComboBox *systeme_box;
    /// @brief ComboBox correspondant aux différents logiciels disponibles.
    QComboBox *logiciel_box;
    /// @brief Zone de de texte pour entrer le message.
    QTextEdit *message_text;


};

#endif // PAGEAJOUTTICKET_H
