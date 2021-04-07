#ifndef RECLAMATION_H
#define RECLAMATION_H
#include<QString>
#include <QString>
#include <QSqlQueryModel>


class reclamation
{
public:
    reclamation();
    reclamation(int,int,QString,QString);
    QSqlQueryModel* afficher();
     QSqlQueryModel * afficheroncombo();
       QSqlQueryModel * afficheroncomboidrec();
    bool supprimer(int);
    bool ajouter();
   bool modifier(int,QString,QString);
    bool rechercher(int id);
    QSqlQueryModel* tri(QString,QString);
    void genererPDFr();



private:
    QString date_panne,descc;
    int idrec,idliv;
};

#endif // RECLAMATION_H
