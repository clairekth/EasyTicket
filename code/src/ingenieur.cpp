#include "ingenieur.h"

Ingenieur::Ingenieur() {}

Ingenieur::Ingenieur(QString id, QString nom, QString prenom, QString mdp, QString mail) :
    Personnel(id, nom, prenom, mdp, mail) {}

Ingenieur::~Ingenieur() {}

bool Ingenieur::estUnIngenieur() {
    return true;
}
