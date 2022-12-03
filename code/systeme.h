#ifndef SYSTEME_H
#define SYSTEME_H

#include <QString>

class Systeme
{
public:
    Systeme();

    Systeme(int id_systeme, QString nom_systeme);

    ~Systeme();

    int getId() const;

    QString getNom() const;

private:
    int id_systeme;
    QString nom_systeme;
};

#endif // SYSTEME_H
