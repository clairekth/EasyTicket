#include "personnel.h"
#include "ingenieur.h"
#include "technicien.h"

#include <iostream>

Personnel::Personnel()
{
}

Personnel::Personnel(
        std::string id_u,
        std::string n,
        std::string p,
        std::string motdepasse,
        std::string email) : Utilisateur(id_u,n,p,motdepasse,email)
{

}

bool Personnel::estUnIngenieur(Personnel *personnel) {
    return dynamic_cast<Ingenieur*>(personnel) != nullptr;
}

bool Personnel::estUnTechnicien(Personnel *personnel) {
    return dynamic_cast<Technicien*>(personnel) != nullptr;
}
