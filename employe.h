#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class EMPLOYE
{
    QString nom,pren,datee;
    int id,salaire,tel;
public:
    //const
    EMPLOYE(){}
    EMPLOYE(int,QString,QString,int,QString,int);
    //getter
    QString getnom(){return nom;}
    QString getpren(){return pren;}
    QString getdate(){return datee;}
    int getid(){return id;}
    int getsalaire(){return salaire;}
   // int getnbreheure(){return nbrheure;}
    //SETTER
    void setnom(QString n){nom=n;}
    void setpren(QString p){pren=p;}
    void setdate(QString d){datee=d;}
    void setid(int i){id=i;}
    void setsalaire(int s){salaire=s;}
//    void setnbrheure(int nbr){nbrheure=nbr;}
    //fonction

    bool ajouter();
    QSqlQueryModel * afficher();
      QSqlQueryModel * afficheroncombo();
    bool modifier(int id,int salaire, int tel);
    bool supprimer(int);

};

#endif // EMPLOYE_H
