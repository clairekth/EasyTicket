#include "utilisateur.h"

#include <string>
#include "admin.h"
#include "client.h"
#include "personnel.h"

Utilisateur::Utilisateur()
{
}

Utilisateur::Utilisateur(std::string id_user, std::string n, std::string p, std::string motdepasse, std::string email) :
    id_user(id_user), nom(n), prenom(p), mdp(motdepasse), mail(email)
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

std::string Utilisateur::getMdp() const
{
    return mdp;
}

void Utilisateur::setMdp(const std::string &value)
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

std::string Utilisateur::getId_users() const
{
    return id_user;
}

void Utilisateur::setId_users(const std::string &value)
{
    id_user = value;
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
