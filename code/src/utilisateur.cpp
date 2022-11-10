#include "Utilisateur.h"

#include <string>
#include "admin.h"

Utilisateur::Utilisateur()
{
}

Utilisateur::Utilisateur(std::string id_u, std::string n, std::string p, std::string motdepasse, std::string email) :
    id(id_u), nom(n), prenom(p), mdp(motdepasse), mail(email)
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
    return id_users;
}

void Utilisateur::setId_users(const std::string &value)
{
    id_users = value;
}

bool Utilisateur::estUnClient(Utilisateur *utilisateur){
    return dynamic_cast<Client*>(utilisateur) != nullptr;
}

bool Utilisateur::estUnAdmin(Utilisateur *utilisateur){
    return dynamic_cast<Admin*>(utilisateur) != nullptr;
}

bool Utilisateur::estUnPersonnel(Utilisateur *utilisateur){
    return dynamic_cast<Personnel*>(utilisateur) != nullptr;
}
