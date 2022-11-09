#include "systeme.h"

Systeme::Systeme()
{

}

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
