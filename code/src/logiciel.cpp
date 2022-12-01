#include "logiciel.h"

Logiciel::Logiciel()
{
}

Logiciel::Logiciel(QString id_logiciel, QString nom) :
    id_logiciel(id_logiciel), nom(nom)
{}

QString Logiciel::getNom()
{
    return nom;
}

QString Logiciel::getID()
{
    return id_logiciel;
}
