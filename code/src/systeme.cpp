#include "systeme.h"

Systeme::Systeme()
{
}

Systeme::Systeme(std::string id_systeme, std::string nom) :
    id_systeme(id_systeme), nom(nom)
{}

std::string Systeme::getNom() const
{
    return nom;
}

void Systeme::setNom(const std::string &value)
{
    nom = value;
}

std::string Systeme::getId_systeme() const
{
    return id_systeme;
}

void Systeme::setId_systeme(const std::string &value)
{
    id_systeme = value;
}
