#include "client.h"

Client::Client()
{

}

Client::Client(const QString id, const QString mdp,  const QString nom, const QString prenom, const QString email):
    Utilisateur(id, nom, prenom, email, mdp)
{

}

Client::~Client()
{
    qDebug() << "Destruction  client\n";
}

QString Client::toString() const
{
    return "Client : " + nom + ", " + prenom + " tickets";
}