
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "comd.h"
#include<QPrinter>
#include<QPrintDialog>
#include<QTableView>
#include <QFileDialog>
#include <QFile>
#include <QtDebug>
#include <QApplication>
#include <QMessageBox>
#include "fourn.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  ui->tabfournisseur->setModel(FO.afficher());
  ui->comboBox_2->setModel(FO.afficheroncombo());
  ui->comboBox_4->setModel(FO.afficheroncombo());
  ui->cb_matF->setModel(FO.afficheroncombo());
 ui->tabachat->setModel(co.affichercmd());
  ui->numcmd_combo->setModel(co.afficheroncombocmd());
  ui->numcmd_combo_2->setModel(co.afficheroncombocmd());

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()//button ajouter
{
    fourn f(ui->le_matricule->text().toInt(),ui->le_adresse->text(),ui->le_numero->text().toInt(),ui->le_rib->text().toInt(),ui->le_nom->text(),ui->le_nom_3->text(),ui->date_fourniseur->text());
    f.ajouter();
 ui->tabfournisseur->setModel(FO.afficher());
 ui->tabfournisseur->setModel(FO.afficher());
 ui->comboBox_2->setModel(FO.afficheroncombo());
 ui->comboBox_4->setModel(FO.afficheroncombo());
 ui->cb_matF->setModel(FO.afficheroncombo());
ui->tabachat->setModel(co.affichercmd());
 ui->numcmd_combo->setModel(co.afficheroncombocmd());
 ui->numcmd_combo_2->setModel(co.afficheroncombocmd());
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    int a;
        a=index;
        index=a;
        ui->comboBox_2->currentText();
}

void MainWindow::on_pb_modifier_2_clicked()
{
    bool    test=FO.modifier(ui->comboBox_2->currentText().toInt(),ui->le_rib_2->text().toInt(), ui->le_numero_2->text().toInt()) ;
          if (test)
          {
                ui->tabfournisseur->setModel(FO.afficher());
                ui->tabfournisseur->setModel(FO.afficher());
                ui->comboBox_2->setModel(FO.afficheroncombo());
                ui->comboBox_4->setModel(FO.afficheroncombo());
                ui->cb_matF->setModel(FO.afficheroncombo());
               ui->tabachat->setModel(co.affichercmd());
                ui->numcmd_combo->setModel(co.afficheroncombocmd());
                ui->numcmd_combo_2->setModel(co.afficheroncombocmd());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void MainWindow::on_comboBox_4_currentIndexChanged(int index)
{
    int a;
        a=index;
    ui->comboBox_4->currentText();//combo mt3 supprimer
}

void MainWindow::on_pb_supprimer_clicked()
{
    bool test=FO.supprimer(ui->comboBox_4->currentText().toInt());
    if(test)
    {  ui->tabfournisseur->setModel(FO.afficher());
        ui->comboBox_2->setModel(FO.afficheroncombo());
        ui->comboBox_4->setModel(FO.afficheroncombo());
        ui->cb_matF->setModel(FO.afficheroncombo());
       ui->tabachat->setModel(co.affichercmd());
        ui->numcmd_combo->setModel(co.afficheroncombocmd());
        ui->numcmd_combo_2->setModel(co.afficheroncombocmd());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}

void MainWindow::on_pb_ajoutercommande_clicked()
{
    comd c(ui->le_numcommande->text().toInt(),ui->le_quantite->text().toInt(),ui->le_prix->text().toInt(),ui->le_description->text(),ui->cb_matF->currentText().toInt(),ui->dateEdit_2->text(),ui->cb_produitcommande->currentText());
       bool test= c.ajoutercmd();
        ui->tabachat->setModel(co.affichercmd());
        ui->comboBox_2->setModel(FO.afficheroncombo());
        ui->comboBox_4->setModel(FO.afficheroncombo());
        ui->cb_matF->setModel(FO.afficheroncombo());
       ui->tabachat->setModel(co.affichercmd());
        ui->numcmd_combo->setModel(co.afficheroncombocmd());
        ui->numcmd_combo_2->setModel(co.afficheroncombocmd());
}

void MainWindow::on_cb_matF_currentIndexChanged(int index)
{
     ui->cb_matF->currentText();
}

void MainWindow::on_numcmd_combo_currentIndexChanged(int index)
{
    ui->numcmd_combo->currentText();

}

void MainWindow::on_numcmd_combo_2_currentIndexChanged(int index)
{
       ui->numcmd_combo_2->currentText();
}

void MainWindow::on_pb_modifier_5_clicked()
{
    bool    test=co.modifiercmd(ui->numcmd_combo->currentText().toInt(),ui->le_quantite_3->text().toInt(),ui->le_prix_3->text().toInt()) ;
          if (test)
          {
              ui->tabfournisseur->setModel(FO.afficher());
              ui->comboBox_2->setModel(FO.afficheroncombo());
              ui->comboBox_4->setModel(FO.afficheroncombo());
              ui->cb_matF->setModel(FO.afficheroncombo());
             ui->tabachat->setModel(co.affichercmd());
              ui->numcmd_combo->setModel(co.afficheroncombocmd());
              ui->numcmd_combo_2->setModel(co.afficheroncombocmd());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    bool test=co.supprimercmd(ui->numcmd_combo_2->currentText().toInt());
    if(test)
    {   ui->tabfournisseur->setModel(FO.afficher());
        ui->comboBox_2->setModel(FO.afficheroncombo());
        ui->comboBox_4->setModel(FO.afficheroncombo());
        ui->cb_matF->setModel(FO.afficheroncombo());
       ui->tabachat->setModel(co.affichercmd());
        ui->numcmd_combo->setModel(co.afficheroncombocmd());
        ui->numcmd_combo_2->setModel(co.afficheroncombocmd());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    co.genererPDFcmd();
}


void MainWindow::on_le_recherche_2_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox->currentText()=="numcmd"
            ){
        query->prepare("SELECT * FROM cmd WHERE numcmd LIKE'"+arg1+"%'");//
query->exec();
    model->setQuery(*query);
ui->tabachat->setModel(model);


    }
    else {
        if(ui->comboBox->currentText()=="prix"){
            query->prepare("SELECT * FROM cmd WHERE prix LIKE'"+arg1+"%'");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tabachat->setModel(model);
        }
        else{
            if(ui->comboBox->currentText()=="date")
                query->prepare("SELECT * FROM cmd WHERE datee LIKE'"+arg1+"%'");//+tri
        query->exec();
            model->setQuery(*query);
        ui->tabachat->setModel(model);
            }

        }
}

void MainWindow::on_tri_fournisseur_clicked()
{
    QString colone=ui->colone_tri->currentText();
        QString ordre=ui->ordre_tri->currentText();
        fourn F;
        ui->tabfournisseur->setModel(F.tri(colone,ordre));
}

void MainWindow::on_pushButton_clicked()
{
    QPrinter  printer;
        printer.setPrinterName("test");
        QPrintDialog dialog(&printer,this);
        if (dialog.exec()==QDialog::Rejected) return;
}

void MainWindow::on_pushButton_3_clicked()
{
    QTableView *table;
               table = ui->tabfournisseur;

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
                       if (model->headerData(i+3, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
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
