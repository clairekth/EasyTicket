#include "utilisateur.h"

Utilisateur::Utilisateur()
{

}

Utilisateur::Utilisateur(const QString &id, const QString &nom, const QString &prenom, const QString &email, const QString &mdp):
    id(id),
    nom(nom),
    prenom(prenom),
    email(email),
    mdp(mdp)
{
    liste_tickets = QVector<QString>();
}

Utilisateur::~Utilisateur()
{
    qDebug() << "Destruction  client\n";
}

QString Utilisateur::toString() const
{
    return "Merde";
}
