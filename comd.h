#ifndef COMD_H
#define COMD_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class comd
{
    QString descc,datee,produit;
    int numcmd,qte,prix,idf;
public:
    comd();
    comd(int,int,int,QString,int,QString,QString);

    bool ajoutercmd();
    QSqlQueryModel * affichercmd();
    bool modifiercmd(int ided,int tel, int prix);
    QSqlQueryModel * afficheroncombocmd();
    bool  recherchercmd(int id  );
    QSqlQueryModel * trides();
       QSqlQueryModel * triasc();


    bool supprimercmd(int);
    void genererPDFcmd();

};

#endif // COMD_H
