#include "reclamation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QPainter>
#include<QPdfWriter>
reclamation::reclamation()
{

}
reclamation::reclamation(int idrec,int idliv,QString descc,QString date_panne)
{
this->idrec =idrec;
this->idliv =idliv;
this->date_panne =date_panne;
this->descc =descc;
}

bool reclamation::ajouter()
{

    QSqlQuery query;


  query.prepare("INSERT INTO recla (IDREC,IDLIV,DATE_PANNE,DESCC) "
                "VALUES (:IDREC, :IDLIV, :DATE_PANNE, :DESCC)");
  query.bindValue(":IDREC", idrec);
  query.bindValue(":IDLIV", idliv);
  query.bindValue(":DATE_PANNE",date_panne);
  query.bindValue(":descc",descc);

     return query.exec();

}



QSqlQueryModel* reclamation::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM recla");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDREC"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDLIV"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PANNE"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCC"));
  return  model;
}


/*bool  reclamation::rechercher(int IDREC)
{
    QSqlQuery query;
               query.prepare("Select * from recla where IDREC= :IDREC");
               query.bindValue(":IDREC", IDREC);
               query.exec();
                QSqlQueryModel * model = new QSqlQueryModel();
              model->setQuery(query);
              if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
           return  true;
}*/


bool reclamation::modifier(int idrec,QString descc,QString date_panne)
{
    QSqlQuery query;


         query.prepare("update recla set descc=:descc, date_panne=:date_panne "
                       "where idrec=:idrec");

         query.bindValue(":idrec", idrec);
         query.bindValue(":descc", descc);
         query.bindValue(":date_panne",date_panne);
        return query.exec();


}

bool reclamation::supprimer(int idrec)
{
    QSqlQuery query;
            query.prepare("select * from recla where idrec=:idrec");
            query.bindValue(":idrec", idrec);
            query.exec();
            if (query.next())
            {
             query.prepare(" Delete from recla where idrec=:idrec");
             query.bindValue(":idrec", idrec);

                    query.exec();
                 return true;

            }

             return false;
}
QSqlQueryModel * reclamation ::afficheroncombo()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from livraison");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_com"));

        return model;
}
QSqlQueryModel*  reclamation::tri(QString colone, QString ordre)
{
QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("select * from livraison order by "+colone+" "+ordre+"");
return model;
}

QSqlQueryModel * reclamation ::afficheroncomboidrec()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from recla");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idrec"));

        return model;
}
void  reclamation::genererPDFr(){
                     QPdfWriter pdf("C:\\Users\\Mohamed Aziz Sebihi\\Desktop\\sou\\pdf.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 50));
                         painter.drawText(1100,1200,"Liste Des reclamation");
                         painter.setPen(Qt::red);
                         painter.setFont(QFont("Arial", 15));
                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial", 9));
                         painter.drawText(200,3300,"id ");
                         painter.drawText(1300,3300,"idliv");
                         painter.drawText(2400,3300,"desc");
                            painter.drawText(3500,3300,"date");


                         QSqlQuery query;
                         query.prepare("select * from recla");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(1).toString());
                             painter.drawText(2400,i,query.value(2).toString());
                             painter.drawText(3500,i,query.value(3).toString());



                            i = i + 500;
                         }}
