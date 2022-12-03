#ifndef PAGEAJOUTTICKET_H
#define PAGEAJOUTTICKET_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QStackedWidget>
#include <QDateTime>
#include <QMessageBox>

#include "constantes.h"
#include "gestionnairedialogue.h"


namespace Ui {
class PageAjoutTicket;
}

class PageAjoutTicket : public QWidget
{
    Q_OBJECT


public:
    /// @brief Constructeur
    /// @param parent Widget parent.
    /// @param gestionnaire_dialogue Le pointeur vers GestionnaireDialogue de l'application.
    PageAjoutTicket(QWidget *parent = nullptr, GestionnaireDialogue *gestionnaire_dialogue = nullptr);

    ~PageAjoutTicket();

    /// @brief Méthode permettant de set le Client actuellement connecté.
    /// @param client   le Client connecté.
    void setClient(Client *client);

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
    Client client;

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

    QStackedWidget *stack;


};

#endif // PAGEAJOUTTICKET_H
