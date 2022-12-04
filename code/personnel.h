#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "utilisateur.h"

class Personnel: public Utilisateur
{
public:
    Personnel();
    Personnel(const QString id,
              const QString mdp,
              const QString nom,
              const QString prenom,
              const QString email);
    virtual ~Personnel();
    virtual QString toString() const;
    virtual bool estUnIngenieur();
};

#endif // PERSONNEL_H
