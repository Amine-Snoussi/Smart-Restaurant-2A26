#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection.h"

class Client
{
public:
    Client();
    Client(int,QString,QString,QString,QString,QString,int,QString);
    //setters
    void setid_Client(int id_client){this->id_client=id_client;}
    void setnom(QString Nom){Nom=nom;}
    void setprenom(QString Prenom){Prenom=prenom;}
    void setEmail(QString mail){Email=mail;}
    void setadresse(QString adresse){this->adresse=adresse;}
    void setville(QString ville){this->ville=ville;}
    void setcodePostal(int codePostal){this->codePostal=codePostal;}
    void setnumTel(QString numTel){this->numTel=numTel;}
    //getters
    int getid_Client(){return  id_client;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getEmail(){return Email;}
    QString getadresse(){return adresse;}
    QString getville(){return ville;}
    int getcodePostal(){return  codePostal;}
    QString getnumTel(){return numTel;}
    //CRUD
    QSqlQueryModel * afficher();
    bool ajouter();
    bool modifier();
    bool supprimer(int id_clientSelectionne);
    int autoId();
    void sendmail();
    QSqlQueryModel * search(QString);
   // -- propriétés
   int  id_client;
   QString  nom;
   // -- constructeur, destructeur virtuel





private:
    QString prenom;
    QString Email;
    QString adresse;
    QString ville;
    int codePostal;
    QString numTel;


};

#endif // CLIENT_H
