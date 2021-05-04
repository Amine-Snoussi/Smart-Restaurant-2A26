#include "comd.h"
#include<QPainter>
#include<QPdfWriter>
comd::comd()
{

}
comd::comd(int numcmd,int qte,int prix,QString descc,int idf,QString datee,QString produit)
{
    this->numcmd=numcmd;
        this->qte=qte;
        this->prix=prix;
        this->descc=descc;
        this->idf=idf;
    this->datee=datee;
    this->produit=produit;
}
bool comd::ajoutercmd()
{
QSqlQuery query;
    //QString id= QString::number(ID);
    query.prepare("INSERT INTO cmd (numcmd,qte,prix,descc,idf,datee,produit) "
                        "VALUES (:numcmd, :qte, :prix,:descc ,:idf,:datee,:produit)");
    query.bindValue(":numcmd",numcmd);
    query.bindValue(":qte",qte);
    query.bindValue(":prix",prix);
    query.bindValue(":descc",descc);
    query.bindValue(":idf",idf);
    query.bindValue(":datee",datee);
    query.bindValue(":produit",produit);



    return    query.exec();

}
QSqlQueryModel * comd ::affichercmd()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from cmd");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numcmd"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("qte "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("descc "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("idf "));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("datee "));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("produit "));


        return model;
}

bool comd::modifiercmd(int numcmd,int qte, int prix)
{

    QSqlQuery query;
//QString idc=QString::number(id);
    query.prepare("UPDATE cmd SET qte= :qte, prix= :prix where numcmd= :numcmd ");
    query.bindValue(":numcmd", numcmd);
    query.bindValue(":qte", qte);
    query.bindValue(":prix",prix);

            return    query.exec();

}
QSqlQueryModel * comd ::afficheroncombocmd()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from cmd");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numcmd"));

        return model;
}

bool comd :: supprimercmd(int numcmd)
{
    //QString ident1= QString ::number(idd);
    QSqlQuery query;
    query.prepare("Delete from cmd where numcmd= :numcmd ");
    query.bindValue(":numcmd",numcmd);
    return    query.exec();

}
QSqlQueryModel* comd::trides()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from cmd order by prix DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ided"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("idac "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom "));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel "));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix "));



            return model;
}

/*QSqlQueryModel * comd::triasc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from cmd order by prix ASC");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ided"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("idac "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom "));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel "));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix "));

           return model;
}*/
void  comd::genererPDFcmd(){
                     QPdfWriter pdf("C:\\Users\\Mohamed Aziz Sebihi\\Desktop\\projetsebihi\\pdf.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 50));
                         painter.drawText(1100,1200,"Liste Des cmd");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 15));
                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial", 9));
                         painter.drawText(200,3300,"NUMCMD ");
                         painter.drawText(1300,3300,"QTE");
                         painter.drawText(2400,3300,"PRIX");
                            painter.drawText(3500,3300,"DESCC");
                            painter.drawText(4600,3300,"IDF");
                            painter.drawText(5700,3300,"DATE");
                            painter.drawText(6800,3300,"PRODUIT");


                         QSqlQuery query;
                         query.prepare("select * from cmd");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(1).toString());
                             painter.drawText(2400,i,query.value(2).toString());
                             painter.drawText(3500,i,query.value(3).toString());
                                   painter.drawText(4600,i,query.value(4).toString());
                                         painter.drawText(5700,i,query.value(5).toString());
                                               painter.drawText(6800,i,query.value(6).toString());



                            i = i + 500;
                         }}
