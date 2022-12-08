#ifndef PAGELOGIN_H
#define PAGELOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QStackedWidget>
#include <QDebug>
#include <QMessageBox>

#include "constantes.h"
#include "pageaccueilclient.h"
#include "pageaccueilpersonnel.h"
#include "gestionnairedialogue.h"
#include "utilisateur.h"

namespace Ui {
class PageLogin;
}

/// @brief La classe PageLogin correspond à la vue de la page de connexion pour les Utilisateur.
///
/// L'interface graphique est composé de 2 QLineEdit permettant de rentrer l'identifiant et le mot de passe de l'Utilisateur souhaitant
/// se connecter. La QLineEdit du mot de passe n'affiche pas le mot de passe. L'interface graphique est également
/// composée d'un QPushButton permettant de valider et de vérifier l'identifiant et le mot de passe de l'Utilisateur
/// essayant de se connecter. Si l'identifiant et le mot de passe ne correspondent à aucun Utilisateur, affichage d'une
/// QMessageBox::warning. Si l'Utilisateur correspond à un Client, le QPushButton affichage la PageAccueilClient. Si c'est
/// un Personnel, il affiche la PageAccueilPersonnel du QStackedWidget parent.
/// @author Victor Dallé, Nicolas Robert, Claire Kurth
/// @version 1.2
class PageLogin : public QWidget
{
    Q_OBJECT



public:
    /// @brief Constructeur par défaut.
    /// @param *parent                  le QStackedWidget parent
    /// @param *gestionnaire_dialogue   le GestionnaireDialogue de l'application
    explicit PageLogin(QStackedWidget *parent = nullptr, GestionnaireDialogue *gestionnaire = nullptr);

    /// @brief Destructeur.
    ~PageLogin();

private slots:
    /// @brief Cette méthode est appelée lors d'un click sur le bouton validation_bouton. Elle permet la connexion
    /// de l'Utilisateur si celui ci existe. Si l'Utilisateur est un Client, affichage de la PageAccueilClient. Si
    /// c'est un Personnel, affichage de la PageAccuilPersonnel.
    void handle_validation();

private:
    /// @brief le GestionnaireDialogue de l'application
    GestionnaireDialogue *gestionnaire_dialogue;
    /// @brief le QStackedWidget de l'application.
    QStackedWidget *stack;

    /// @brief Champs correspondant à la vue de PageLogin.
    Ui::PageLogin *ui;
    /// @brief Bouton de validation de la connexion.
    QPushButton *validation_bouton;
    /// @brief Champs où l'Utilisateur rentre son identifiant.
    QLineEdit *id;
    /// @brief Champs où l'Utilisateur rentre son mot de passe.
    QLineEdit *mdp;
    /// @brief Champs correspondant à l'utilisateur qui s'est connecté.
    Utilisateur *user;
};

#endif // PAGELOGIN_H
