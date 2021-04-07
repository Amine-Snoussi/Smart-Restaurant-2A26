#ifndef FOURN_H
#define FOURN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fourn
{
    QString adr,nom,prod,dat;
    int mat,num,rib;

public:
    fourn();
    fourn(int,QString,int,int,QString,QString,QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int id,int rib, int num);
    bool supprimer(int);
     QSqlQueryModel * afficheroncombo();
};

#endif // FOURN_H
