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

/// @brief La classe PageAjoutTicket correspond à la vue de la page qui permet au Client connecté de créer un nouveau Ticket.
///
/// L'interface graphique est composée d'un QPushButton permettant de retourner à la PageAccueilClient. Elle contient
/// également 3 QComboBox contenant les différentes Categorie, Logiciel et Systeme disponibles à spécifier pour la
/// création du Ticket. Le Client est obligé de choisir une Categorie alors qu'il peut laisser en blanc pour le choix du
/// Logiciel et du Systeme. On retrouve aussi un QTextEdit permettant au Client de rentrer le message qu'il veut. Le message
/// est obligatoire pour la création d'un Ticket. Le QPushButton "valider" permet de valider la création d'un Ticket lorsque
/// les champs obligatoires (categorie et message) sont remplis. Si tout est valide, ce dernier permet de retourner à la
/// PageAccueilClient.
/// @author Victor Dallé, Nicolas Robert, Claire Kurth
/// @version 2.3
class PageAjoutTicket : public QWidget
{
    Q_OBJECT


public:
    /// @brief Constructeur par défaut.
    /// @param *parent                  le QStackedWidget parent
    /// @param *gestionnaire_dialogue   le GestionnaireDialogue de l'application
    explicit PageAjoutTicket(QStackedWidget *parent = nullptr, GestionnaireDialogue *gestionnaire_dialogue = nullptr);

    ~PageAjoutTicket();

    /// @brief Méthode permettant de set le Client actuellement connecté.
    /// @param client   le Client connecté.
    void setClient(Client *client);

private slots:
    /// @brief Le bouton bouton_retour est cliqué. Cette méthode permet de retourner à PageAccueilClient.
    void retour_bouton_clicked();

    /// @brief Le bouton creer_le_ticket_clicked est cliqué. Cette méthode permet de créer un nouveau Ticket et de
    /// retourner à la PageAccueilClient si le Ticket a été créé correctement (tous les champs obligatoires ont été remplis).
    void creer_le_ticket_clicked();

private:
    /// @brief le GestionnaireDialogue de l'application
    GestionnaireDialogue *gestionnaire_dialogue;
    /// @brief le QStackedWidget de l'application.
    QStackedWidget *stack;
    /// @brief Champs correspondant à la vue de PageAccueilClient.
    Ui::PageAjoutTicket *ui;
    /// @brief Champs contenant le Client connecté.
    Client *client;
    /// @brief Bouton de retour à la PageAccueilClient.
    QPushButton *bouton_retour;
    /// @brief Bouton de validation qui permet de créer le Ticket et de retourner à la PageAccueilClient si la création
    /// du Ticket est valide.
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
