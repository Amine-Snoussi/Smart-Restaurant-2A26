#include "fourn.h"
fourn::fourn()
{


}
fourn::fourn(int mat,QString adr,int num,int rib,QString nom ,QString prod,QString dat)
{
this->mat=mat;
    this->adr=adr;
    this->num=num;
    this->num=num;
    this->rib=rib;
    this->nom=nom;
    this->prod=prod;
    this->dat=dat;
}

bool fourn::ajouter()
{
QSqlQuery query;
    //QString id= QString::number(ID);
    query.prepare("INSERT INTO FOUR (mat,adr,num,rib,nom,prod,dat) "
                        "VALUES (:mat, :adr, :num,:rib ,:nom,:prod,:dat)");
    query.bindValue(":mat",mat);
    query.bindValue(":adr",adr);
    query.bindValue(":num",num);
    query.bindValue(":rib",rib);
    query.bindValue(":nom",nom);
    query.bindValue(":prod",prod);
     query.bindValue(":dat",dat);


    return    query.exec();

}

QSqlQueryModel * fourn ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FOUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("mat"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adr "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("rib "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("prod "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("dat "));

        return model;
}

bool fourn::modifier(int id , int rib ,int num)
{

    QSqlQuery query;
//QString idc=QString::number(id);
    query.prepare("UPDATE FOUR SET num= :num, rib= :rib where mat= :mat ");
    query.bindValue(":mat", id);
    query.bindValue(":rib", rib);
    query.bindValue(":num",num);

            return    query.exec();

}

QSqlQueryModel * fourn ::afficheroncombo()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FOUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

        return model;
}

bool fourn :: supprimer(int idd)
{
   // QString ident1= QString ::number(idd);
    QSqlQuery query;
    query.prepare("Delete from FOUR where mat = :mat ");
    query.bindValue(":mat",idd);
    return    query.exec();

}
