#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "gestionmenu.h"
#include<QDateTime>
#include<QTimer>
#include<QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); ui->tableView->setModel(menu.afficher()) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_ajouter_clicked()
{
    /*sound*/
     /*  QMediaPlayer *player = new QMediaPlayer;

       player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
       player->setVolume(100);
       player->play();*/


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

void MainWindow::on_pushButton_3_modifier_clicked()
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

void MainWindow::on_pushButton_4_supp_clicked()
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


void MainWindow::on_pushButton_historique_clicked()
{

    ui->tableView->setModel(menu.afficher());
}
