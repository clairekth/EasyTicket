#include "categorie.h"

Categorie::Categorie()
{
}

Categorie::Categorie(std::string id_categorie, std::string nom_categorie):
    id_categorie(id_categorie), nom_categorie(nom_categorie)
{}

std::string Categorie::get_nom_categorie()
{
    return nom_categorie;
}
