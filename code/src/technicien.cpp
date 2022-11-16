#include "technicien.h"

Technicien::Technicien() {}

Technicien::Technicien(std::string id, std::string nom, std::string prenom, std::string mdp, std::string mail, std::vector<Categorie*> liste_categorie) :
        Personnel(id, nom, prenom, mdp, mail) {
    categories = liste_categorie;
}

Technicien::~Technicien() {}

bool Technicien::estUnTechnicien() {
    return true;
}
