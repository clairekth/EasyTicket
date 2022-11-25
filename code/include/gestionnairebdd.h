#ifndef GESTIONNAIREBDD_H
#define GESTIONNAIREBDD_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

class GestionnaireBDD
{
public:
    GestionnaireBDD();
    void select(QString query);

private:
    bool created;
    QSqlDatabase my_db;
};

#endif // GESTIONNAIREBDD_H
