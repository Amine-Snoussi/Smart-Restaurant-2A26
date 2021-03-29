    #include "cong.h"


cong::cong(int idco,int idem,QString datedeb ,QString datefin)
{
    this->idco=idco;
    this->idem=idem;
    this->datedeb=datedeb;
    this->datefin=datefin;
}

bool cong::ajouterc()
 {
 QSqlQuery query;
     //QString id= QString::number(ID);
 query.prepare("INSERT INTO CONGE (idco,idem,datdeb,datfin) "
                     "VALUES (:idco, :idem, :datedeb,:datefin)");

     query.bindValue(":idco",idco);
     query.bindValue(":idem",idem);
     query.bindValue(":datedeb",datedeb);
     query.bindValue(":datefin",datefin);

     return    query.exec();
 }
QSqlQueryModel * cong ::afficherc()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CONGE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idco"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idem "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datedeb "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datefin "));

        return model;
}

bool cong :: supprimerc(int idco)
{

    QSqlQuery query;
    query.prepare("Delete from CONGE where idco = :idco ");
    query.bindValue(":idco",idco);
    return    query.exec();

}

QSqlQueryModel * cong ::afficheroncomboc()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CONGE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idco"));

        return model;
}
 bool cong::modifierc(int idco,QString datedeb, QString datefin)
{

    QSqlQuery query;

    query.prepare("UPDATE CONGE SET datdeb= :datedeb, datfin=:datefin where idco= :idco ");
    query.bindValue(":idco", idco);
    query.bindValue(":datedeb", datedeb);
    query.bindValue(":datefin",datefin);
          return    query.exec();
}
 void  cong::genererPDF(){
 //QDateTime datecreation = date.currentDateTime();
               //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                      QPdfWriter pdf("C:\\Users\\21654\\Documents\\proj\\pdf.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::red);
                          painter.setFont(QFont("Arial", 30));
                          painter.drawText(1100,1200,"Liste Des congé");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 15));
                         // painter.drawText(1100,2000,afficheDC);
                          painter.drawRect(100,100,7300,2600);
                          //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(200,3300,"IDCO");
                          painter.drawText(1300,3300,"IDEM");
                          painter.drawText(2100,3300,"DATEDEB");
                           painter.drawText(3200,3300,"DATEDEB");

                          QSqlQuery query;
                          query.prepare("select * from CONGE");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(1).toString());
                              painter.drawText(2200,i,query.value(2).toString());
                              painter.drawText(3200,i,query.value(3).toString());

                             i = i + 500;
                          }}
