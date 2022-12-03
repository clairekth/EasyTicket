#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QString>

class Categorie
{
public:
    Categorie();

    Categorie(int id_categorie, QString nom_categorie);

    ~Categorie();

    int getId() const;

    QString getNom() const;

private:
    int id_categorie;
    QString nom_categorie;
};

#endif // CATEGORIE_H
