#include "ingenieur.h"

Ingenieur::Ingenieur() {}

Ingenieur::Ingenieur(std::string id, std::string nom, std::string prenom, std::string mdp, std::string mail) :
    Personnel(id, nom, prenom, mdp, mail) {}

Ingenieur::~Ingenieur() {}

bool Ingenieur::estUnIngenieur() {
    return true;
}
