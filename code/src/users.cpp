#include "users.h"

#include <string>

Users::Users()
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

std::string Users::getId() const
{
    return id;
}

void Users::setId(const std::string &value)
{
    id = value;
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
