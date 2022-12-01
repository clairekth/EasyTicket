#include "personnel.h"

#include <iostream>

Personnel::Personnel()
{
}

Personnel::Personnel(QString id, QString nom, QString prenom, QString mdp, QString mail) :
    Utilisateur(id,nom,prenom,mdp,mail) {
}

Personnel::~Personnel() {}

bool Personnel::estUnPersonnel() {
    return true;
}
