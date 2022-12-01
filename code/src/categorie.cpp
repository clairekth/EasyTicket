#include "categorie.h"

Categorie::Categorie()
{
}

Categorie::Categorie(QString id_categorie, QString nom_categorie):
    id_categorie(id_categorie), nom_categorie(nom_categorie)
{}

QString Categorie::getNom()
{
    return nom_categorie;
}

QString Categorie::getID()
{
    return id_categorie;
}


