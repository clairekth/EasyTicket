#include "client.h"

Client::Client()
{
}


Client::Client(std::string id_u, std::string n, std::string p, std::string motdepasse, std::string email) :
    id(id_u), nom(n), prenom(p), mdp(motdepasse), mail(email)
{
}
