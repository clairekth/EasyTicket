#include "personnel.h"
#include "ingenieur.h"
#include "technicien.h"

#include <iostream>

Personnel::Personnel()
{
}

Personnel::Personnel(std::string id, std::string nom, std::string prenom, std::string mdp, std::string mail) :
    Utilisateur(id,nom,prenom,mdp,mail) {
}

Personnel::~Personnel() {}

bool Personnel::estUnPersonnel() {
    return true;
}
