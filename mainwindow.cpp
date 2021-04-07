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
#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

ui->setupUi(this);
refrech();

}

MainWindow::~MainWindow()
{
    qDebug()<<"MainWindow: Deleting";
    delete ui;
}

void MainWindow::refrech()
{
    ui->tabClient->setModel(client.afficher());
    ui->tabReservation->setModel(R.afficher());
}



void MainWindow::on_pushButton_clicked()
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

void MainWindow::on_pushButton_7_clicked()
{
    Client cl(ui->id_client_modif_3->text().toInt(), ui->nom_modif_4->text(), ui->prenom_modif_5->text(), ui->le_email_2->text(), ui->le_adresse_2->text(), ui->le_ville_2->text(), ui->sb_codePostal_2->text().toInt(), ui->le_tel_2->text());
    bool test=cl.ajouter();
    if(test)
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

void MainWindow::on_button_modifierReservation_3_clicked()
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

void MainWindow::on_button_supprimerReservation_3_clicked()
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

void MainWindow::on_lineEdit_21_textChanged(const QString &arg1)
{
    ui->tabClient->setModel(client.search(arg1));
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    ui->tabReservation->setModel(R.search(arg1));
}

void MainWindow::on_button_modifierReservation_clicked()
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

void MainWindow::on_button_supprimerReservation_clicked()
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
