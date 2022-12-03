#ifndef GESTIONNAIREDIALOGUE_H
#define GESTIONNAIREDIALOGUE_H

#include <QString>
#include <QDebug>
#include <QComboBox>

#include "utilisateur.h"
#include "client.h"
#include "ticket.h"

class GestionnaireDialogue
{
public:
    GestionnaireDialogue();

    ~GestionnaireDialogue();

    Utilisateur* authentification(QString &id, QString &mdp);

    /// @brief Méthode permettant de vérifier que le message est bon.
    /// @return true si le message est bon, false sinon.
    bool verificationMessage(QString message);

    /// @brief Méthode qui remplit les comboBox de la page PageAjoutTicket en fct de la BDD.
    /// @param box La ComboBox.
    /// @param type Le type de donnée de la ComboBox (categorie, systeme, logiciel).
    void setComboBox(QComboBox *box, QString type);

    /// @brief Méthode qui permet d'enregistrer le ticket dans la BDD.
    /// @param ticket Le ticket à enregistrer.
    void enregistrer_ticket(Ticket ticket);
};

#endif // GESTIONNAIREDIALOGUE_H
