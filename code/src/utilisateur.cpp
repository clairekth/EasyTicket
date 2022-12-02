#include "utilisateur.h"
#include <string>


Utilisateur::Utilisateur()
{
}

Utilisateur::Utilisateur(QString id, QString n, QString p, QString mdp, QString mail) :
    id(id), nom(n), prenom(p), mdp(mdp), mail(mail) {}

Utilisateur::~Utilisateur() {}

QString Utilisateur::getNom() const
{
    return nom;
}


QString Utilisateur::getPrenom() const
{
    return prenom;
}


QString Utilisateur::getID() const
{
    return id;
}

bool Utilisateur::estUnClient() {
    return false;
}

bool Utilisateur::estUnAdmin() {
    return false;
}

bool Utilisateur::estUnPersonnel() {
    return false;
}

bool Utilisateur::estUnIngenieur() {
    return false;
}

QString Utilisateur::toString()
{
    return "Utilisateur = {\n\
            \tid: '" + id + "',\n\
            \tnom: '" + nom + "'\n\
            \tprenom: '" + prenom + "'\n\
            \tmdp: '" + mdp + "'\n\
            \tmail: '" + mail + "'\n}";
}

bool Utilisateur::estUnTechnicien() {
    return false;
}
