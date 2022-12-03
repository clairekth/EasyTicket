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
#include "gestionnairedialogue.h"
#include "utilisateur.h"

/// @brief La classe PageLogin correspond à la vue de la page de connexion pour les Utilisateur.
/// @author Victor Dallé, Nicolas Robert, Claire Kurth
/// @version 1.2

namespace Ui {
class PageLogin;
}

class PageLogin : public QWidget
{
    Q_OBJECT



public:
    /// @brief Constructeur
    /// @param parent                   Widget parent.
    /// @param *gestionnaire_dialogue   le GestionnaireDialogue de l'application
    explicit PageLogin(QWidget *parent = nullptr);

    /// @brief Destructeur.
    ~PageLogin();

public slots:
    /// @brief Cette méthode est appelée lors d'un click sur le bouton validation_bouton. Elle permet la connexion de l'Utilisateur si celui ci existe.
    void handle_validation();

private:
    /// @brief Champs correspondant à la vue de PageLogin.
    Ui::PageLogin *ui;
    /// @brief Bouton de validation de la connexion.
    QPushButton *validation_bouton;

    /// @brief Champs où l'Utilisateur rentre son identifiant.
    QLineEdit *id;

    /// @brief Champs où l'Utilisateur rentre son mot de passe.
    QLineEdit *mdp;

    QStackedWidget *stack;
};

#endif // PAGELOGIN_H
