#ifndef GESTIONNAIREDIALOGUE_H
#define GESTIONNAIREDIALOGUE_H

#include "ticket.h"

/// @brief Classe correspondant au Gestionnaire de Dialogue entre l'Utilisateur et le modèle.
/// @authors Nicolas Robert, Victor Dallé, Claire Kurth
/// @version 1.5
class GestionnaireDialogue
{
public:
    /// @brief Constructeur par défaut.
    GestionnaireDialogue();

    /// @brief Méthode qui permet d'identifier le type d'Utilisateur qui se connecte si il existe.
    /// @param id   L'identifiant de l'Utilisateur.
    /// @param mdp  Le mot de passe de l'Utilisateur.
    /// @return le nom du type d'utilisateur, null si l'utilisateur n'existe pas.
    std::string typeUtilisateur(std::string id, std::string mdp);

    /// @brief Méthode qui permet d'identifier un Client.
    /// @param id   L'identifiant du Client.
    /// @param mdp  Le mot de passe du Client.
    /// @return le Client identifié.
    Client authentification(std::string id, std::string mdp);

    /// @brief Méthode permettant de vérifier que le message est bon.
    /// @return true si le message est bon, false sinon.
    bool verificationMessage(std::string message);

};

#endif // GESTIONNAIREDIALOGUE_H
