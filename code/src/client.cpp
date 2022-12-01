#include "client.h"

Client::Client() {}

Client::Client(QString id, QString nom, QString prenom, QString mdp, QString mail) :
    Utilisateur(id, nom, prenom, mdp, mail) {
}

Client::~Client() {}



bool Client::estUnClient() {
    return true;
}
