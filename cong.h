#ifndef CONG_H
#define CONG_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>

class cong
{
    QString datedeb,datefin;
    int idco,idem;
public:
    //const
    cong(){};
    cong(int,int,QString,QString);
    //fonction

    bool ajouterc();
    QSqlQueryModel * afficherc();
      QSqlQueryModel * afficheroncomboc();
    bool modifierc(int id,QString datedeb, QString datefin);
    bool supprimerc(int);
     void genererPDF();
      QSqlQueryModel* tri(QString,QString);

};

#endif // CONG_H
