#include "logiciel.h"

Logiciel::Logiciel()
{

}

Logiciel::Logiciel(int id_logiciel, QString nom_logiciel) :
    id_logiciel(id_logiciel), nom_logiciel(nom_logiciel)
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
