#include "gestionmenu.h"
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>

gestionmenu::gestionmenu()
{

}
gestionmenu::gestionmenu(int ID_MENU , QString  specialite,QString categorie ,QString nom_plat, float prix)
{
    this->ID_MENU=ID_MENU;
    this->specialite=specialite ;
    this->categorie=categorie;
    this->nom_plat=nom_plat;
    this->prix=prix;

}

bool gestionmenu::ajouter()
{

    QString res=QString::number(prix);

    QSqlQuery query;
    query.prepare("INSERT INTO MENU (ID_MENU,SPECIALITE,CATEGORIE,NOM_PLAT,PRIX) "
                        "VALUES (:id_menu,:specialite,:categorie,:nom_plat,:prix)");
    query.bindValue(":id_menu", ID_MENU);
    query.bindValue(":specialite", specialite);
    query.bindValue(":categorie", categorie);
    query.bindValue(":nom_plat", nom_plat);
    query.bindValue(":prix", res);


    return    query.exec();
}

QSqlQueryModel *gestionmenu::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel;


    model->setQuery("select * from MENU"); //selection de la table à afficher
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_MENU"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("SPECIALITE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("CATEGORIE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM_PLAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));

    return model;


}



QSqlQueryModel *gestionmenu::recherche(QString a)
{
    QSqlQueryModel * model = new QSqlQueryModel;


    model->setQuery("select * from MENU WHERE SPECIALITE LIKE '%"+a+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_MENU"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("SPECIALITE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("CATEGORIE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM_PLAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));

    return model;


}

bool gestionmenu::supprimer(int id)
{  //supprimer suvant l'id
    QSqlQuery query ;
    QString res=QString::number(id);
    query.prepare("delete from menu where ID_MENU=:id");
    query.bindValue(":id",res);
    return query.exec();

}

bool gestionmenu::modifier()
{


        QSqlQuery query;
        QString res=QString::number(prix);
        query.prepare("update MENU set ID_MENU=:id_menu, SPECIALITE=:specialite,CATEGORIE=:categorie,NOM_PLAT=:nom_plat ,PRIX=:prix  where ID_MENU = :id_menu");
        query.bindValue(":id_menu", ID_MENU);
        query.bindValue(":specialite",specialite);
        query.bindValue(":categorie", categorie);
        query.bindValue(":nom_plat", nom_plat);
        query.bindValue(":prix", res);

        return query.exec();

}


QSqlQueryModel *gestionmenu::tri()
{
    QSqlQueryModel * model = new QSqlQueryModel;


    model->setQuery("select * from MENU ORDER BY PRIX"); //selection de la table à afficher
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_MENU"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("SPECIALITE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("CATEGORIE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM_PLAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));

    return model;


}
