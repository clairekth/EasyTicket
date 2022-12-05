#include "logiciel.h"

Logiciel::Logiciel()
{

}

Logiciel::Logiciel(const int id_logiciel, const QString &nom_logiciel) :
    id_logiciel(id_logiciel), nom_logiciel(nom_logiciel)
{

}

Logiciel::~Logiciel()
{

}

QString Logiciel::getNom() const
{
    return nom_logiciel;
}

int Logiciel::getId() const
{
    return id_logiciel;
}
