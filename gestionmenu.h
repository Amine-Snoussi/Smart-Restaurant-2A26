#ifndef GESTIONMENU_H
#define GESTIONMENU_H
#include <QString>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"

class gestionmenu
{


public:
    gestionmenu();
    gestionmenu(int,QString,QString,QString,float);
    //setters
    //void setid_

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int ID_MENU) ;
    bool modifier();
    QSqlQueryModel *recherche(QString a);
    QSqlQueryModel *tri();



private:
int ID_MENU;
QString specialite,categorie, nom_plat;
float prix;
};

#endif // GESTIONMENU_H




