#include "systeme.h"


Systeme::Systeme()
{
}

Systeme::Systeme(const int id_systeme, const QString &nom_systeme) :
    id_systeme(id_systeme), nom_systeme(nom_systeme)
{}

Systeme::~Systeme()
{

}

QString Systeme::getNom() const
{
    return nom_systeme;
}

int Systeme::getId() const
{
    return id_systeme;
}
