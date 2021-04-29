#include "Menu_ingredient.h"
#include "ui_Menu_ingredient.h"
#include <QMessageBox>
#include "gestionmenu.h"
#include "gestioningredient.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QDesktopServices>
#include <QUrl>
#include <QPainter>
#include <QPdfWriter>

QT_CHARTS_USE_NAMESPACE


Menu_ingredient::Menu_ingredient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu_ingredient)
{

    ui->setupUi(this);
    ui->tableView->setModel(menu.afficher()) ;
    ui->tableView_2->setModel(ingredient.afficher());

}

Menu_ingredient::~Menu_ingredient()
{
    delete ui;
}






void Menu_ingredient::on_pushButton_3_modifier_clicked()
{
    int ID_MENU =ui->lineEdit->text().toInt();
    QString SPECIALITE =ui->lineEdit_2->text();
    QString CATEGORIE =ui->lineEdit_3->text();
    QString NOM_PLAT =ui->lineEdit_4->text();
    float PRIX =ui->lineEdit_5->text().toFloat();

    gestionmenu menu (ID_MENU,SPECIALITE,CATEGORIE, NOM_PLAT,  PRIX);
    {
    bool test=menu.modifier();
     if (test)
     {   ui->tableView->setModel(menu.afficher());
         QMessageBox::information(nullptr,QObject::tr("ok"),
                 QObject::tr("modification effectue\n"
                             "Clich cancel to exit ."),QMessageBox::Cancel );
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                     QObject::tr("connection failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     ui->lineEdit->setText("");
     ui->lineEdit_2->setText("");
     ui->lineEdit_3->setText("");
     ui->lineEdit_4->setText("");
     ui->lineEdit_5->setText("");

}
}

void Menu_ingredient::on_pushButton_4_supp_clicked()
{
    int ID=ui->lineEdit->text().toInt();


    bool test=menu.supprimer(ID);
    if (test)
    {  ui->tableView->setModel(menu.afficher()) ;
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("suppression effectue\n"
                            "Clich cancel to exit ."),QMessageBox::Cancel );
    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                    QObject::tr("suprfailed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void Menu_ingredient::on_pushButton_historique_clicked()
{

    ui->tableView->setModel(menu.afficher());
}

void Menu_ingredient::on_pushButton_2_clicked()
{

    int ID_INGREDIENT =ui->lineEdit_6->text().toInt();
    QString NOM_PRODUIT =ui->lineEdit_7->text();
    QString QUANTITE =ui->lineEdit_8->text();


    gestioningredient ingredient (ID_INGREDIENT,NOM_PRODUIT,QUANTITE);
    bool test = ingredient.ajouter();
    if (test)
    {   ui->tableView_2->setModel(ingredient.afficher()) ;
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectue\n"
                            "Clich cancel to exit ."),QMessageBox::Cancel );
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void Menu_ingredient::on_pushButton_3_clicked()
{

        int ID_INGREDIENT =ui->lineEdit_6->text().toInt();
        QString NOM_PRODUIT=ui->lineEdit_7->text();
        QString QUANTITE =ui->lineEdit_8->text();


        gestioningredient ingredient (ID_INGREDIENT,NOM_PRODUIT,QUANTITE);
        {
        bool test=ingredient.modifier();
         if (test)
         {   ui->tableView_2->setModel(ingredient.afficher());
             QMessageBox::information(nullptr,QObject::tr("ok"),
                     QObject::tr("modification effectue\n"
                                 "Click cancel to exit ."),QMessageBox::Cancel );
         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                         QObject::tr("connection failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         ui->lineEdit_6->setText("");
         ui->lineEdit_7->setText("");
         ui->lineEdit_8->setText("");


    }

}
void Menu_ingredient::on_pushButton_4_clicked(){


    int ID=ui->lineEdit_6->text().toInt();


    bool test=ingredient.supprimer(ID);
    if (test)
    {  ui->tableView_2->setModel(ingredient.afficher()) ;
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("suppression effectue\n"
                            "Clich cancel to exit ."),QMessageBox::Cancel );
    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                    QObject::tr("suprfailed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}





void Menu_ingredient::on_Ajouter_Button_clicked(){

    /*sound*/
         /*  QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
           player->setVolume(100);
           player->play();*/
    qInfo( "hzee" );

        int ID_MENU =ui->lineEdit->text().toInt();
        QString SPECIALITE =ui->lineEdit_2->text();
        QString CATEGORIE =ui->lineEdit_3->text();
        QString NOM_PLAT =ui->lineEdit_4->text();
        float PRIX =ui->lineEdit_5->text().toFloat();

        gestionmenu menu (ID_MENU,SPECIALITE,CATEGORIE, NOM_PLAT,PRIX);
        bool test = menu.ajouter();
        if (test)
        {   ui->tableView->setModel(menu.afficher()) ;
            QMessageBox::information(nullptr,QObject::tr("ok"),
                    QObject::tr("ajout effectue\n"
                                "Clich cancel to exit ."),QMessageBox::Cancel );
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not ok "),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}



void Menu_ingredient::on_recherche1_textChanged(const QString &arg1)
{
    QString a=ui->recherche1->text();
    ui->tableView->setModel(menu.recherche(a)) ;



}

void Menu_ingredient::on_recherche1_2_textChanged(const QString &arg1)
{
    QString a=ui->recherche1_2->text();
    ui->tableView_2->setModel(ingredient.recherche(a)) ;
}

void Menu_ingredient::on_button_tri_2_clicked()
{
    ui->tableView_2->setModel(ingredient.tri()) ;

}

void Menu_ingredient::on_button_tri_clicked()
{
    ui->tableView->setModel(menu.tri()) ;

}

void Menu_ingredient::on_button_stat_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                    model->setQuery("select * from ingredient QUANTITE PRIX < 10 ");
                    float salaire=model->rowCount();
                    model->setQuery("select * from ingredient where QUANTITE  between 10 and 50 ");
                    float salairee=model->rowCount();
                    model->setQuery("select * from ingredient where QUANTITE>50 ");
                    float salaireee=model->rowCount();
                    float total=salaire+salairee+salaireee;
                    QString a=QString("moins de 10 "+QString::number((salaire*100)/total,'f',2)+"%" );
                    QString b=QString("entre 10 et 50  "+QString::number((salairee*100)/total,'f',2)+"%" );
                    QString c=QString("+50"+QString::number((salaireee*100)/total,'f',2)+"%" );
                    QPieSeries *series = new QPieSeries();
                    series->append(a,salaire);
                    series->append(b,salairee);
                    series->append(c,salaireee);
            if (salaire!=0)
            {QPieSlice *slice = series->slices().at(0);
             slice->setLabelVisible();
             slice->setPen(QPen());}
            if ( salairee!=0)
            {
                     // Add label, explode and define brush for 2nd slice
                     QPieSlice *slice1 = series->slices().at(1);
                     //slice1->setExploded();
                     slice1->setLabelVisible();
            }
            if(salaireee!=0)
            {
                     // Add labels to rest of slices
                     QPieSlice *slice2 = series->slices().at(2);
                     //slice1->setExploded();
                     slice2->setLabelVisible();
            }
                    // Create the chart widget
                    QChart *chart = new QChart();
                    // Add data to chart with title and hide legend
                    chart->addSeries(series);
                    chart->setTitle("Pourcentage Par Quantite de ingredients :Nombre Des ingredients "+ QString::number(total));
                    chart->legend()->hide();
                    // Used to display the chart
                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(1000,500);
                    chartView->show();
}

void Menu_ingredient::on_button_stat_clicked()
{

    QSqlQueryModel * model= new QSqlQueryModel();
                    model->setQuery("select * from menu where PRIX < 10 ");
                    float salaire=model->rowCount();
                    model->setQuery("select * from menu where PRIX  between 10 and 50 ");
                    float salairee=model->rowCount();
                    model->setQuery("select * from menu where PRIX>50 ");
                    float salaireee=model->rowCount();
                    float total=salaire+salairee+salaireee;
                    QString a=QString("moins de 10Dinars "+QString::number((salaire*100)/total,'f',2)+"%" );
                    QString b=QString("entre 10Dinars et 50Dinars  "+QString::number((salairee*100)/total,'f',2)+"%" );
                    QString c=QString("+50Dinars"+QString::number((salaireee*100)/total,'f',2)+"%" );
                    QPieSeries *series = new QPieSeries();
                    series->append(a,salaire);
                    series->append(b,salairee);
                    series->append(c,salaireee);
            if (salaire!=0)
            {QPieSlice *slice = series->slices().at(0);
             slice->setLabelVisible();
             slice->setPen(QPen());}
            if ( salairee!=0)
            {
                     // Add label, explode and define brush for 2nd slice
                     QPieSlice *slice1 = series->slices().at(1);
                     //slice1->setExploded();
                     slice1->setLabelVisible();
            }
            if(salaireee!=0)
            {
                     // Add labels to rest of slices
                     QPieSlice *slice2 = series->slices().at(2);
                     //slice1->setExploded();
                     slice2->setLabelVisible();
            }
                    // Create the chart widget
                    QChart *chart = new QChart();
                    // Add data to chart with title and hide legend
                    chart->addSeries(series);
                    chart->setTitle("Pourcentage Par Prix de menu :Nombre Des Menus "+ QString::number(total));
                    chart->legend()->hide();
                    // Used to display the chart
                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(1000,500);
                    chartView->show();
}

void Menu_ingredient::on_button_stat_3_clicked()
{
    QPdfWriter pdf("PdfMenu.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::blue);
                          painter.setFont(QFont("Arial", 30));
                          painter.drawText(2300,1200,"Liste Des Menu");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 50));
                         // painter.drawText(1100,2000,afficheDC);
                          painter.drawRect(1500,200,7300,2600);
                          //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(300,3300,"ID_MENU");
                          painter.drawText(2300,3300,"SPECIALITE");
                          painter.drawText(4300,3300,"CATEGORIE");
                          painter.drawText(6300,3300,"NOM_PLAT");
                          painter.drawText(8300,3300,"PRIX");




                          QSqlQuery query;
                          query.prepare("select * from menu");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(300,i,query.value(0).toString());
                              painter.drawText(2300,i,query.value(1).toString());
                              painter.drawText(4300,i,query.value(2).toString());
                              painter.drawText(6300,i,query.value(3).toString());
                              painter.drawText(8300,i,query.value(4).toString());




                             i = i +500;
                          }
                          int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                              if (reponse == QMessageBox::Yes)
                              {
                                  QDesktopServices::openUrl(QUrl::fromLocalFile("PdfMenu.pdf"));

                                  painter.end();
                              }
                              if (reponse == QMessageBox::No)
                              {
                                   painter.end();
                              }
}
