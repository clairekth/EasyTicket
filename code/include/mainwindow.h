#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/// \mainpage Documentation EasyTicket
///
/// \section versions_sec Version
/// \subsection v1_1_subsec v1.1
/// Page de connexion avec au moment de la connexion, la création d'un objet Utilisateur.
///
/// Peut importe le login et le mot de passe, on affiche un message contenant le 'toString' de notre objet Utilisateur.
///
/// \subsection v1_2_subsec v1.2
/// Une fois connecté avec un compte 'client', l'utilisateur accède à la page d'accueil (PageAccueilClient).
///
/// Ajout d'un GestionnaireDialogue qui fait le lien entre l'utilisateur et les données.
///
/// \subsection v1_3_subsec v1.3
/// Le bouton de création de ticket mène à une page vierge qui servira pour créer les tickets (PageAjoutTicket).
///
/// Ajout d'un bouton de retour à la page d'accueil quand on est sur la page de création de ticket.
///
/// \subsection v1_4_subsec v1.4
/// Création de la mise en page du formulaire pour créer le ticket.
///
/// Affiche le resultat sur la sortie standard et si jamais il y a des champs invalides.
///
/// \subsection v1_5_subsec v1.5
/// Vérification des champs saisis par l'utilisation lors de la création d'un nouveau ticket.
///
/// Fonctions de vérifications pour le Message du ticket et génération d'un message contenant le descriptif du Ticket créé (sans encore le message).
///
/// \subsection v1_6_subsec v1.6
/// Implémentation de l'ajout de Message dans le Ticket au moment de sa création. Au moment du clic pour créer le Ticket, on affiche les données du Ticket ainsi que le Message ajouté.
///
/// Si tout est ok, on retourne à la page d'accueil (PageAccueilClient).
///
/// \subsection v1_7_subsec v1.7
/// Ajout de la base de donnée au format db avec SQLite.
///
/// Ajout d'une classe GestionnaireBDD pour gérer l'interfaçage avec le bdd.
///
/// - Importer la bdd.
///
/// - Faire un select sur la bdd, etc.
///
/// \subsection v1_8_subsec v1.8
/// Ajout des fonctions pour communiquer avec la bdd :
/// - Au niveau de la connexion.
///
/// - et de l'enregistrement d'un ticket et du message.
///
/// Création des ComboBox en fonction des tables de la BDD.

#include <QMainWindow>
#include <QStackedWidget>
#include "pagelogin.h"
#include "constantes.h"
#include "gestionnairedialogue.h"
#include "pageaccueilclient.h"
#include "pageajoutticket.h"

/// @brief Classe correspondant à la fenêtre principale de l'application EasyTicket.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.3

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected :
    /// @brief Champs contenant le StackedWidget qui stock les différentes Page de l'application.
    QStackedWidget *stack;
    /// @brief Champs contenant le GestionnaireDialogue.
    GestionnaireDialogue *gestionnaire_dialogue;
    /// @brief Champs contenant la PageLogin.
    PageLogin *page_login;
    /// @brief Champs contenant la PageAccueilClient.
    PageAccueilClient *page_accueil_client;
    /// @brief Champs contenant la PageAjoutTicket
    PageAjoutTicket *page_ajout_ticket;

public:
    /// @brief Constructeur.
    /// @param  *parent Pointeur sur le Widget Parent.
    MainWindow(QWidget *parent = nullptr);

    /// @brief Méthode pour set le GestionnaireDialogue.
    /// @param g    Pointeur sur le GestionnaireDialogue.
    void setGestionnaireDialogue(GestionnaireDialogue *g);

    /// @brief Destructeur.
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
