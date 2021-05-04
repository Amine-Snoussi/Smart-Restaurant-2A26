#ifndef GESTIONINGREDIENT_H
#define GESTIONINGREDIENT_H


#include <QString>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"

class gestioningredient
{


public:
    gestioningredient();
    gestioningredient(int,QString,QString);
    //setters
    //void setid_

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int ID_INGREDIENT) ;
    bool modifier();
    QSqlQueryModel *recherche(QString a);
    QSqlQueryModel *tri();



private:
int ID_INGREDIENT;
QString nom_produit,quantite;
};



#endif // GESTIONINGREDIENT_H
