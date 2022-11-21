#include "admin.h"

Admin::Admin() {}

Admin::Admin(std::string id, std::string nom, std::string prenom, std::string mdp, std::string mail) :
    Utilisateur(id, nom, prenom, mdp, mail) {
}

Admin::~Admin() {}

bool Admin::estUnAdmin(){
    return true;
}
