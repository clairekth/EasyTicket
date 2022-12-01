#include "admin.h"
#include <QString>

Admin::Admin() {}

Admin::Admin(QString id, QString nom, QString prenom, QString mdp, QString mail) :
    Utilisateur(id, nom, prenom, mdp, mail) {
}

Admin::~Admin() {}

bool Admin::estUnAdmin(){
    return true;
}
