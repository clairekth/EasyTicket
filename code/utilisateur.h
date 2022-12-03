#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QString>
#include <QVector>
#include <QDebug>

class Utilisateur
{
public:
    Utilisateur();

    Utilisateur(const QString &id,
                const QString &mdp,
                const QString &nom,
                const QString &prenom,
                const QString &email);

    virtual ~Utilisateur();

    virtual QString toString() const = 0;

    virtual QString getNom() const;

    virtual QString getPrenom() const;

protected:
    QString id, nom, prenom, email, mdp;
    QVector<QString> liste_tickets;
};

#endif // UTILISATEUR_H
