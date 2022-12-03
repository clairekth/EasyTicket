#include "systeme.h"


Systeme::Systeme()
{
}

Systeme::Systeme(int id_systeme, QString nom_systeme) :
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
