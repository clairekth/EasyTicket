#include "personnel.h"
#include "ingenieur.h"
#include "technicien.h"

#include <iostream>

Personnel::Personnel()
{
}

Personnel::Personnel(std::string id, std::string n, std::string p, std::string mdp, std::string email) :
    Utilisateur(id,n,p,mdp,email) {
}

Personnel::~Personnel() {}

bool Personnel::estUnPersonnel() {
    return true;
}
