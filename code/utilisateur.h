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
                const QString &nom = QString::fromStdString("Oui"),
                const QString &prenom = "Oui",
                const QString &email = "oui-oui.easyticket.fr");

    virtual ~Utilisateur();

    virtual QString toString() const;

protected:
    QString id, nom, prenom, email, mdp;
    QVector<QString> liste_tickets;
};

#endif // UTILISATEUR_H
