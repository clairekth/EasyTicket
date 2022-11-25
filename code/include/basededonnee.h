#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H

#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>


class BaseDeDonnee
{
public:
    BaseDeDonnee();
    ~BaseDeDonnee();

    QVector<QString> select(QString s);

private:
    QSqlDatabase my_db;
};

#endif // BASEDEDONNEE_H
