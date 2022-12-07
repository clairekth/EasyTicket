#include "ingenieur.h"

Ingenieur::Ingenieur()
{

}

Ingenieur::Ingenieur(const QString &id, const QString &nom, const QString &prenom, const QString &email):
    Personnel(id,nom,prenom,email)
{

}

Ingenieur::~Ingenieur()
{

}

bool Ingenieur::estUnIngenieur()
{
    return true;
}

QString Ingenieur::toString() const
{
    return "Ingenieur : " + nom + ", " + prenom;

}
