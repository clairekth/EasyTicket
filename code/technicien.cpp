#include "technicien.h"

Technicien::Technicien()
{

}

Technicien::Technicien(const QString &id, const QString &nom, const QString &prenom, const QString &email):
    Personnel(id,nom,prenom,email)
{

}

Technicien::~Technicien()
{

}

bool Technicien::estUnTechnicien()
{
    return true;
}

QString Technicien::toString() const
{
    return "Technicien : " + nom + ", " + prenom;

}
