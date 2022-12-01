#include "systeme.h"

Systeme::Systeme()
{
}

Systeme::Systeme(QString id_systeme, QString nom) :
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

QString Systeme::getId_systeme() const
{
    return id_systeme;
}

void Systeme::setId_systeme(const QString &value)
{
    id_systeme = value;
}
