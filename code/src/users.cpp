#include "users.h"

#include <string>

Users::Users()
{
}

Users::Users(std::string id_u, std::string n, std::string p, std::string motdepasse, std::string email) :
    id(id_u), nom(n), prenom(p), mdp(motdepasse), mail(email)
{
}

std::string Users::getNom() const
{
    return nom;
}

void Users::setNom(const std::string &value)
{
    nom = value;
}

std::string Users::getPrenom() const
{
    return prenom;
}

void Users::setPrenom(const std::string &value)
{
    prenom = value;
}

std::string Users::getMdp() const
{
    return mdp;
}

void Users::setMdp(const std::string &value)
{
    mdp = value;
}

std::string Users::getMail() const
{
    return mail;
}

void Users::setMail(const std::string &value)
{
    mail = value;
}

std::string Users::getId_users() const
{
    return id_users;
}

void Users::setId_users(const std::string &value)
{
    id_users = value;
}

bool Users::estUnClient(){
    return false;
}

bool Users::estUnAdmin(){
    return false;
}

bool Users::estUnPersonnel(){
    return false;
}
