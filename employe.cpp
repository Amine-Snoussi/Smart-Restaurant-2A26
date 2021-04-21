#include "employe.h"
#include<QTableView>
#include<QPainter>
#include<QPdfWriter>
#include <QFileDialog>
#include <QFile>
EMPLOYE::  EMPLOYE(int id,QString nom,QString pren,int tel,QString datee,int salaire) // constructeur
{
this->id=id;
    this->nom=nom;
    this->pren=pren;
    this->tel=tel;
    this->datee=datee;
    this->salaire=salaire;
}

bool EMPLOYE::ajouter()
 {
 QSqlQuery query;
     //QString id= QString::number(ID);
 query.prepare("INSERT INTO EMP (id,pren,nom,num,datee,salaire) "
                     "VALUES (:id, :pren, :nom,:tel ,:datee,:salaire)");
     query.bindValue(":id",id);
     query.bindValue(":pren",nom);
     query.bindValue(":nom",pren);
     query.bindValue(":tel",tel);
     query.bindValue(":datee",datee);
     query.bindValue(":salaire",salaire);
     return    query.exec();
 }


QSqlQueryModel * EMPLOYE ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from EMP");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("pren "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("num "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("datee "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire "));

        return model;
}
bool EMPLOYE :: supprimer(int id)
{
    QString ident1= QString ::number(id);
    QSqlQuery query;
    query.prepare("Delete from EMP where id = :id ");
    query.bindValue(":id",ident1);
    return    query.exec();

}
QSqlQueryModel * EMPLOYE ::afficheroncombo()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from EMP");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

        return model;
}

bool EMPLOYE::modifier(int id,int salaire, int tel)
{

    QSqlQuery query;

    query.prepare("UPDATE EMP SET salaire= :salaire, num= :tel where id= :id ");
    query.bindValue(":id", id);
    query.bindValue(":salaire", salaire);
    query.bindValue(":tel",tel);
          return    query.exec();
}
