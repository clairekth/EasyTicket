
#include "personnel.h"

Personnel::Personnel()
{

}

Personnel::Personnel(const QString &id, const QString& mdp, const QString &nom, const QString &prenom, const QString &email):
    Utilisateur(id,mdp,nom,prenom,email)
{

}

Personnel::~Personnel()
{

}

QString Personnel::toString() const
{
    return "Personnel" + prenom +", " + nom;
}

bool Personnel::estUnPersonnel()
{
    return true;
}

bool Personnel::estUnIngenieur()
{
    return false;
}
