#include "systeme.h"

Systeme::Systeme()
{
}

Systeme::Systeme(int id_systeme, QString nom) :
    id_systeme(id_systeme), nom(nom)
{}

QString Systeme::getNom() const
{
    return nom;
}

void Systeme::setNom(const QString &value)
{
    nom = value;
}

int Systeme::getId_systeme() const
{
    return id_systeme;
}

void Systeme::setId_systeme(const int &value)
{
    id_systeme = value;
}
