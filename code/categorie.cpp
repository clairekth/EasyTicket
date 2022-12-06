#include "categorie.h"

Categorie::Categorie()
{

}

Categorie::Categorie(const int id_categorie, const QString &nom_categorie):
    id_categorie(id_categorie), nom_categorie(nom_categorie)
{

}

Categorie::~Categorie()
{
}

int Categorie::getId() const
{
    return id_categorie;
}

QString Categorie::getNom() const
{
    return nom_categorie;
}
