#include "gestioningredient.h"


#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
gestioningredient::gestioningredient()
{

}
gestioningredient::gestioningredient(int ID_INGREDIENT, QString nom_produit,QString quantite )
{
    this->ID_INGREDIENT=ID_INGREDIENT;
    this->nom_produit=nom_produit ;
    this->quantite =quantite ;


}

bool gestioningredient::ajouter()
{


    QString res=QString::number(ID_INGREDIENT);
    QSqlQuery query;
    query.prepare("INSERT INTO INGREDIENT ( ID_INGREDIENT,NOM_PRODUIT,QUANTITE) "
                        "VALUES (:id_ingredient,:nom_produit,:quantite)");
    query.bindValue(":id_ingredient", res);
    query.bindValue(":nom_produit", nom_produit);
    query.bindValue(":quantite", quantite);


    return    query.exec();
}

QSqlQueryModel *gestioningredient::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel;


    model->setQuery("select * from INGREDIENT"); //selection de la table à afficher
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_INGREDIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_PRODUIT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("QUANTITE"));


    return model;


}

bool gestioningredient::supprimer(int id)
{  //supprimer suvant l'id
    QSqlQuery query ;
    QString res=QString::number(id);
    query.prepare("delete from menu where ID_INGREDIENT=:id");
    query.bindValue(":id",res);
    return query.exec();

}

bool gestioningredient::modifier()
{


        QSqlQuery query;
        query.prepare("update INGREDIENT set ID_INGREDIENT=:id_ingredient, NOM_PRODUIT=:nom_produit,QUANTITE=:quantite where ID_INGREDIENT = :id_ingredient");
        query.bindValue(":id_ingredient", ID_INGREDIENT);
        query.bindValue(":nom_produit",nom_produit);
        query.bindValue(":quantite", quantite);


        return query.exec();

}
QSqlQueryModel *gestioningredient::recherche(QString a)
{
    QSqlQueryModel * model = new QSqlQueryModel;


    model->setQuery("select * from INGREDIENT WHERE NOM_PRODUIT LIKE '%"+a+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_INGREDIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_PRODUIT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("QUANTITE"));

    return model;


}

QSqlQueryModel *gestioningredient::tri()
{
    QSqlQueryModel * model = new QSqlQueryModel;


    model->setQuery("select * from INGREDIENT ORDER BY QUANTITE"); //selection de la table à afficher
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_INGREDIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_PRODUIT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("QUANTITE"));


    return model;


}



