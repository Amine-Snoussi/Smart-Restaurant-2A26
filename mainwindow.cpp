#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QTableView>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableView->setModel(emp.afficher());
    ui->comboBox->setModel(emp.afficheroncombo());
    ui->comboBox_2->setModel(emp.afficheroncombo());
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_Ajouter_clicked()
{
        EMPLOYE e(ui->lineEdit_ID->text().toInt(),ui->lineEdit_nom->text(),ui->lineEdit_prenom->text(),ui->lineEdit_numtelephone->text().toInt(),ui->lineEdit_Date->text(),ui->lineEdit_salaire->text().toInt());
       bool test= e.ajouter();

        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


        if (test)
        {ui->tableView->setModel(emp.afficher());//actualisation taa afficher
            notifyIcon->showMessage("GESTION DES  EMPLYOES ","Liste employe pret dans PDF",QSystemTrayIcon::Information,15000);
                    QMessageBox::information(nullptr,QObject::tr("ok"),
                                             QObject::tr("ajout succful .\n"),
                            QMessageBox::Cancel);
                }

                else
                    QMessageBox::critical(nullptr,QObject::tr("ajout not open"),
                                            QObject::tr("click cancel to exist"),
                                            QMessageBox::Cancel);



         ui->tableView->setModel(emp.afficher());


}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    int a;
        a=index;
    ui->comboBox->currentText();
}

void MainWindow::on_Supprimer_clicked()
{
    bool test=emp.supprimer(ui->comboBox->currentText().toInt());
    if(test)
    {ui->tableView->setModel(emp.afficher());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    int a;
        a=index;
        index=a;
        ui->comboBox->currentText();
}

void MainWindow::on_Modifier_clicked()
{
    bool    test=emp.modifier(ui->comboBox_2->currentText().toInt(),ui->lineEdit_salaire_2->text().toInt(),ui->lineEdit_numtelephone_2->text().toInt()) ;
          if (test)
          {
                ui->tableView->setModel(emp.afficher());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}


