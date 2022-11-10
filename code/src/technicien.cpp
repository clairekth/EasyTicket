#include "technicien.h"

Technicien::Technicien()
{

}

Technicien::Technicien(std::string id_u, std::string n, std::string p, std::string motdepasse, std::string email, std::vector<Categorie> liste_categorie) :
    id(id_u), nom(n), prenom(p), mdp(motdepasse), mail(email), categories(liste_categorie)
{

}

bool Technicien::estUnTechnicien(){
    return true;
}
