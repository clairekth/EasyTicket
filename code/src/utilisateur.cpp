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

void Utilisateur::setNom(const QString &value)
{
    nom = value;
}

QString Utilisateur::getPrenom() const
{
    return prenom;
}

void Utilisateur::setPrenom(const QString &value)
{
    prenom = value;
}

QString Utilisateur::getMDP() const
{
    return mdp;
}

void Utilisateur::setMDP(const QString &value)
{
    mdp = value;
}

QString Utilisateur::getMail() const
{
    return mail;
}

void Utilisateur::setMail(const QString &value)
{
    mail = value;
}

QString Utilisateur::getID() const
{
    return id;
}

void Utilisateur::setID(const QString &value)
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
