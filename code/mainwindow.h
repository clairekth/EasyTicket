#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QDebug>

#include "constantes.h"

#include "pagelogin.h"
#include "pageaccueilclient.h"
#include "pageajoutticket.h"
#include "pageaccueilpersonnel.h"
#include "pageresolutionticket.h"

/// @brief Classe correspondant à la fenêtre principale de l'application EasyTicket. Elle contient un QStackedWidget
/// contenant plusieurs Pages définie par des index (voir constantes.h) permettant de naviguer entre ces différentes
/// pages suivant les actions de l'Utilisateur connecté.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 2.1

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// @brief Constructeur par défaut.
    /// @param  *parent Pointeur sur le Widget Parent.
    MainWindow(QWidget *parent = nullptr);

    /// @brief Destructeur de la classe.
    ~MainWindow();

protected :
    /// @brief Champs correspondant au StackedWidget qui stock les différentes Page de l'application.
    QStackedWidget *stack;

    /// @brief Champs correspondant au GestionnaireDialogue.
    GestionnaireDialogue gestionnaire_dialogue;

    /// @brief Champs correspondant à la PageLogin.
    PageLogin *page_login;

    /// @brief Champs correspondant à la PageAccueilClient.
    PageAccueilClient *page_accueil_client;

    /// @brief Champs correspondant à la PageAjoutTicket.
    PageAjoutTicket *page_ajout_ticket;

    /// @brief Champs correspondant à la PageAccueilClient.
    PageAccueilPersonnel *page_accueil_personnel;

    /// @brief Champs correspondant à la PageResolutionTicket.
    PageResolutionTicket *page_resolution_ticket;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
