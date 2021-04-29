#include "client.h"
#include <QMessageBox>
#include <QPixmap>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include "client_reservation.h"
#include "ui_client_reservation.h"

QT_CHARTS_USE_NAMESPACE




Client_reservation::Client_reservation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client_reservation)
{

ui->setupUi(this);
refrech();

}

Client_reservation::~Client_reservation()
{
    qDebug()<<"Client_reservation: Deleting";
    delete ui;
}

void Client_reservation::refrech()
{
    ui->tabClient->setModel(client.afficher());
    ui->tabReservation->setModel(R.afficher());
}



void Client_reservation::on_pushButton_clicked()
{
  reservation r(0,ui->lineEdit_2->text().toInt(), ui->spinBox->text().toInt(), ui->spinBox_2->text().toInt(), ui->lineEdit_3->text(), ui->dateEdit->text(), ui->timeEdit->text());
  bool test=r.ajouter();
  if(test)
{
      r.sendmail();
    refrech();
QMessageBox::information(nullptr, QObject::tr("ajouter une reservation"),
                  QObject::tr("reservation ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("ajouter une reservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Client_reservation::on_pushButton_7_clicked()
{
    Client cl(ui->id_client_modif_3->text().toInt(), ui->nom_modif_4->text(), ui->prenom_modif_5->text(), ui->le_email_2->text(), ui->le_adresse_2->text(), ui->le_ville_2->text(), ui->sb_codePostal_2->text().toInt(), ui->le_tel_2->text());
    bool test=cl.ajouter();
   if (cl.testmail(ui->le_email_2->text())==false)
                           {

                               QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP MAIL!!!!") ;
                               QMessageBox::critical(0, qApp->tr("Ajout"),

                                               qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

                           }
    else if (cl.testnumber(ui->le_tel_2->text())==false)
                     {

                         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP NUMERO !!!!") ;
                         QMessageBox::critical(0, qApp->tr("Ajout"),

                                         qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

                     }
    else {
        if (test)
  {
        cl.sendmail();
    refrech();
  QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                    QObject::tr("client ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void Client_reservation::on_button_modifierReservation_3_clicked()
{
    Client cl(ui->id_client_modif->text().toInt(), ui->nom_modif->text(), ui->prenom_modif_2->text(), ui->le_email_modif->text(), ui->le_adresse_modif->text(), ui->le_ville_modif->text(), ui->sb_codePostal_modif->text().toInt(), ui->le_tel_modif->text());
    bool test=cl.modifier();
    if(test)
  {
    refrech();
  QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                    QObject::tr("client modifie.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void Client_reservation::on_button_supprimerReservation_3_clicked()
{
    Client cl;
    bool test=cl.supprimer(ui->lineEdit_20->text().toInt());
    if(test)
  {
    refrech();
  QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprime.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void Client_reservation::on_lineEdit_21_textChanged(const QString &arg1)
{
    ui->tabClient->setModel(client.search(arg1));
}

void Client_reservation::on_lineEdit_4_textChanged(const QString &arg1)
{
    ui->tabReservation->setModel(R.search(arg1));
}

void Client_reservation::on_button_modifierReservation_clicked()
{
    reservation r(ui->lineEdit_5->text().toInt(),ui->lineEdit_6->text().toInt(), ui->spinBox_3->text().toInt(), ui->spinBox_4->text().toInt(), "", ui->dateEdit_2->text(), ui->timeEdit_2->text());
    bool test=r.modifier();
    if(test)
  {
      refrech();
  QMessageBox::information(nullptr, QObject::tr("Modifier une reservation"),
                    QObject::tr("reservation modifie.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void Client_reservation::on_button_supprimerReservation_clicked()
{
    reservation r;
    r.setId(ui->lineEdit_7->text().toInt());
    bool test=r.supprilmer();
    if(test)
  {
      refrech();
  QMessageBox::information(nullptr, QObject::tr("supprimer une reservation"),
                    QObject::tr("reservation supprime.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void Client_reservation::on_button_statistiques_clicked()
{

    QSqlQueryModel * model= new QSqlQueryModel();
                        model->setQuery("select * from reservation where np < 5 ");
                        float salaire=model->rowCount();
                        model->setQuery("select * from reservation where np  between 5 and 10 ");
                        float salairee=model->rowCount();
                        model->setQuery("select * from reservation where np>10 ");
                        float salaireee=model->rowCount();
                        float total=salaire+salairee+salaireee;
                        QString a=QString("moins de 5 Personnes "+QString::number((salaire*100)/total,'f',2)+"%" );
                        QString b=QString("entre 5 et 10 Personnes "+QString::number((salairee*100)/total,'f',2)+"%" );
                        QString c=QString("+10 Personnes "+QString::number((salaireee*100)/total,'f',2)+"%" );
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
                        chart->addSeries(series);
                        chart->setTitle("Pourcentage Par Personnes qui vont participer :Nombre Des Reservations "+ QString::number(total));
                        chart->legend()->hide();
                        // Used to display the chart
                        QChartView *chartView = new QChartView(chart);
                        chartView->setRenderHint(QPainter::Antialiasing);
                        chartView->resize(1000,500);
                        chartView->show();




}
