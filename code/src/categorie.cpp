#include "categorie.h"

Categorie::Categorie()
{
}

Categorie::Categorie(int id_categorie, QString nom_categorie):
    id_categorie(id_categorie), nom_categorie(nom_categorie)
{}

QString Categorie::getNom()
{
    return nom_categorie;
}

int Categorie::getID()
{
    return id_categorie;
}


