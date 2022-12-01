#include "technicien.h"

Technicien::Technicien() {}

Technicien::Technicien(QString id, QString nom, QString prenom, QString mdp, QString mail, std::vector<Categorie*> liste_categorie) :
        Personnel(id, nom, prenom, mdp, mail) {
    categories = liste_categorie;
}

Technicien::~Technicien() {}

bool Technicien::estUnTechnicien() {
    return true;
}
