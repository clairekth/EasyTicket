#ifndef LOGICIEL_H
#define LOGICIEL_H

#include <QString>

class Logiciel
{
public:
    Logiciel();

    Logiciel(int id_logiciel, QString nom_logiciel);

    ~Logiciel();

    int getId() const;

    QString getNom() const;

private:
    int id_logiciel;
    QString nom_logiciel;
};

#endif // LOGICIEL_H
