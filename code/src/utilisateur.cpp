#include "utilisateur.h"
#include <string>
#include "admin.h"
#include "client.h"
#include "personnel.h"

Utilisateur::Utilisateur()
{
}

Utilisateur::Utilisateur(std::string id, std::string n, std::string p, std::string mdp, std::string email) :
    id(id), nom(n), prenom(p), mdp(mdp), mail(email)
{
}

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

bool Utilisateur::estUnClient(){
    return false;
}

bool Utilisateur::estUnAdmin(){
    return false;
}

bool Utilisateur::estUnPersonnel(){
    return false;
}
