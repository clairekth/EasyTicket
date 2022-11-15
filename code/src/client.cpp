#include "client.h"

Client::Client()
{
}

Client::Client(
        std::string id_u,
        std::string n,
        std::string p,
        std::string motdepasse,
        std::string email) :
    Utilisateur(id_u,n,p,motdepasse,email)
{

}

bool Client::estUnClient(){
    return true;
}
