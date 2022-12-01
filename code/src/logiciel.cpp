#include "logiciel.h"

Logiciel::Logiciel()
{
}

Logiciel::Logiciel(int id_logiciel, QString nom) :
    id_logiciel(id_logiciel), nom(nom)
{}

QString Logiciel::getNom()
{
    return nom;
}

int Logiciel::getID()
{
    return id_logiciel;
}
