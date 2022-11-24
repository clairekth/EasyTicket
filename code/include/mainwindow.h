#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
