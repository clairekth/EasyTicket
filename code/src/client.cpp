#include "client.h"

Client::Client() {}

Client::Client(std::string id, std::string nom, std::string prenom, std::string mdp, std::string mail) :
    Utilisateur(id, nom, prenom, mdp, mail) {
}

Client::~Client() {}



bool Client::estUnClient() {
    return true;
}
