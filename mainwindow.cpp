#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QTableView>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include<QPdfWriter>
#include <QFileDialog>
#include <QFile>
#include <QtDebug>
#include "statelivrec.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableView->setModel(emp.afficher());
    ui->tableView_2->setModel(co.afficherc());

    ui->comboBox->setModel(emp.afficheroncombo());
    ui->comboBox_2->setModel(emp.afficheroncombo());
    ui->comboBox_emplo->setModel(emp.afficheroncombo());

    ui->comboBox_3->setModel(co.afficheroncomboc());
    ui->comboBox_4->setModel(co.afficheroncomboc());
    int ret=A.connect_arduino();
             switch(ret){
             case(0):qDebug()<< "arduino is availble and connected to :"<< A.getarduino_port_name();
                 break;
             case(1):qDebug()<< "arduino is availble but not connected to :"<< A.getarduino_port_name();
                 break;
             case(-1):qDebug()<< "arduino is not availble";
             }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(alert()));
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::alert(){

    data=A.read_from_arduino();
    QString DataAsString = QString(data);
    qDebug()<< data;
    if (data=="1"){
           A.write_to_arduino("1");
    }
    if (data=="0"){
           A.write_to_arduino("0");
    }
    if(data=="1"){
            check=!check;
       }
    if (data=="1"){
        QMessageBox::critical(nullptr, QObject::tr("INVITE"),
                    QObject::tr("THE GAZ IS DETECTED ! .\n"
                                "Please check your GAZ ."), QMessageBox::Ok);

    }

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



         ui->tableView->setModel(emp.afficher());//actualisation tab afficher emp
          ui->comboBox->setModel(emp.afficheroncombo());//actualisation combo supprimer
           ui->comboBox_2->setModel(emp.afficheroncombo());//actualisation combo afficher



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



void MainWindow::on_le_rech_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
                QSqlQuery   *query= new QSqlQuery();
        if(ui->comboBox_recherche->currentText()=="Nom"
                ){
            query->prepare("SELECT * FROM EMP WHERE NOM LIKE'"+arg1+"%'");//
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);


        }
        else {
            if(ui->comboBox_recherche->currentText()=="Prenom"){
                query->prepare("SELECT * FROM EMP WHERE PREN LIKE'"+arg1+"%'");//+tri
        query->exec();
            model->setQuery(*query);
        ui->tableView->setModel(model);
            }
            else{
                if(ui->comboBox_recherche->currentText()=="Id"){
                    query->prepare("SELECT * FROM EMP WHERE id LIKE'"+arg1+"%'");//+tri
            query->exec();
                model->setQuery(*query);
            ui->tableView->setModel(model);
                }
            }

            }
}

void MainWindow::on_comboBox_emplo_currentIndexChanged(int index)
{
    int a;
        a=index;
    ui->comboBox_emplo->currentText();
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////*/
void MainWindow::on_Ajouter_conge_clicked()
{
    cong c(ui->lineEdit_id_conge->text().toInt(),ui->comboBox_emplo->currentText().toInt(),ui->lineEdit_datedebut->text(),ui->lineEdit_datefin->text());
   bool test= c.ajouterc();
    ui->tableView_2->setModel(co.afficherc());
    ui->comboBox_3->setModel(co.afficheroncomboc());
     ui->comboBox_4->setModel(co.afficheroncomboc());

}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    int a;
        a=index;
    ui->comboBox_3->currentText();
}

void MainWindow::on_Supprimer_conge_clicked()
{

    bool test=co.supprimerc(ui->comboBox_3->currentText().toInt());
    if(test)
    {ui->tableView_2->setModel(co.afficherc());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
             ui->comboBox_3->setModel(co.afficheroncomboc());
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}

void MainWindow::on_Modifier_conge_clicked()
{
    bool    test=co.modifierc(ui->comboBox_4->currentText().toInt(),ui->lineEdit_datedebut_2->text(),ui->lineEdit_datefin_2->text()) ;
          if (test)
          {
                ui->tableView_2->setModel(co.afficherc());

              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);
          }
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void MainWindow::on_Imprimer_clicked()//excel
{ QTableView *table;
    table = ui->tableView;

    QString filters("CSV files (.csv);;All files (.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                       filters, &defaultFilter);
    QFile file(fileName);

    QAbstractItemModel *model =  table->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QStringList strList;
        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
        QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
    }

}

void MainWindow::on_Pdf_conge_clicked()
{
 co.genererPDF();
}





void MainWindow::on_pushButton_clicked()
{
    stat_liv=new statelivrec(this);
    stat_liv->show();
}

void MainWindow::on_button_tri_clicked()
{
    QString colone=ui->colone_tri->currentText();
        QString ordre=ui->ordre_tri->currentText();
        cong c;
        ui->tableView_2->setModel(c.tri(colone,ordre));
}
