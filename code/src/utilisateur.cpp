#include "utilisateur.h"
#include <string>


Utilisateur::Utilisateur()
{
}

Utilisateur::Utilisateur(std::string id, std::string n, std::string p, std::string mdp, std::string mail) :
    id(id), nom(n), prenom(p), mdp(mdp), mail(mail) {}

Utilisateur::~Utilisateur() {}

std::string Utilisateur::getNom() const
{
    return nom;
}

void Utilisateur::setNom(const std::string &value)
{
    nom = value;
}

std::string Utilisateur::getPrenom() const
{
    return prenom;
}

void Utilisateur::setPrenom(const std::string &value)
{
    prenom = value;
}

std::string Utilisateur::getMDP() const
{
    return mdp;
}

void Utilisateur::setMDP(const std::string &value)
{
    mdp = value;
}

std::string Utilisateur::getMail() const
{
    return mail;
}

void Utilisateur::setMail(const std::string &value)
{
    mail = value;
}

std::string Utilisateur::getID() const
{
    return id;
}

void Utilisateur::setID(const std::string &value)
{
    id = value;
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

std::string Utilisateur::toString()
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
