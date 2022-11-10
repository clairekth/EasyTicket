#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "personnel.h"
#include "categorie.h"

class Technicien : public Personnel
{
private :
    std::vector<Categorie> categories;

public:
    Technicien();
    Technicien(
            std::string id_u,
            std::string n,
            std::string p,
            std::string motdepasse,
            std::string email,
            std::vector<Categorie> liste_categories);



    bool estUnTechnicien();
};

#endif // TECHNICIEN_H
