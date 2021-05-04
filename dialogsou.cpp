#include "dialogsou.h"
#include "ui_dialogsou.h"
#include "livraison.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QtPrintSupport/QPrintDialog>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include "statelivrec.h"

Dialogsou::Dialogsou(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialogsou)
{
    ui->setupUi(this);
        ui->tableView->setModel(l.afficher());
    ui->tableView_rec->setModel(r.afficher());

      ui->id_liv->setModel(r.afficheroncombo());
      ui->i_reccombo->setModel(r.afficheroncomboidrec());
      ui->id_reccombosup->setModel(r.afficheroncomboidrec());

}


Dialogsou::~Dialogsou()
{
    delete ui;
}


void Dialogsou::on_Ajouter_clicked()
{

         int num_com=ui->num_com->text().toInt();
         QString produit=ui->produit->currentText();
         int quantite=ui->quantite->text().toInt();
         QString livreur=ui->livreur->text();
         int total=ui->total->text().toInt();
         QString date_arrivee=ui->date_arrivee->text();

   livraison L(num_com,produit,quantite,livreur,total,date_arrivee);

    bool test=L.ajouter();

    QMessageBox msgBox;

    if(test)
      {
        ui->id_liv->setModel(r.afficheroncombo());
        ui->i_reccombo->setModel(r.afficheroncomboidrec());
        ui->id_reccombosup->setModel(r.afficheroncomboidrec());
        msgBox.setText("Ajout avec succes.");
        //ui->tableView->setModel(L.afficher());
      }
    else
   {
        msgBox.setText("Echec d'ajout");
        msgBox.exec();

   }
}

void Dialogsou::on_supprimer_clicked()
{
    int num_com =ui->le_supprimer->text().toInt();
         livraison L;
         L.setnum_com(num_com);
         QMessageBox msg;
         if(L.supprimer())

         {  ui->tableView->setModel(l.afficher());
             ui->id_liv->setModel(r.afficheroncombo());
             ui->i_reccombo->setModel(r.afficheroncomboidrec());
             ui->id_reccombosup->setModel(r.afficheroncomboidrec());

             msg.setText("suppression avec succés");
             ui->id_liv->setModel(r.afficheroncombo());


         }
         else
         {
             msg.setText("echec de suppression");
         }
         msg.exec();
}

void Dialogsou::on_modifier_2_clicked()
{
    int num_com,quantite,total;
   QString produit,livreur,date_arrivee;

   num_com=ui->num_com_2->text().toInt();
   produit=ui->produit_2->currentText();
   quantite=ui->quantite_2->text().toInt();
   livreur=ui->livreur_2->text();
   total=ui->total_2->text().toInt();
   date_arrivee=ui->date_arrivee_2->text();

   livraison L(num_com,produit,quantite,livreur,total,date_arrivee);

   QMessageBox msgBox;
       if (L.modifier())
       { ui->tableView->setModel(l.afficher());
           ui->id_liv->setModel(r.afficheroncombo());
           ui->i_reccombo->setModel(r.afficheroncomboidrec());
           ui->id_reccombosup->setModel(r.afficheroncomboidrec());


             msgBox.setText("Le Document a été modifié.");



       }

       else
       {
           msgBox.setText("échec de modification.");
       }
       msgBox.exec();

}

void Dialogsou::on_button_tri_clicked()
{
    QString colone=ui->colone_tri->currentText();
        QString ordre=ui->ordre_tri->currentText();
        livraison L;
        ui->tableView->setModel(L.tri(colone,ordre));
}









void Dialogsou::on_tabWidget_2_tabBarClicked(int index)
{
    livraison L;
    if (index==1)
         ui->tableView->setModel(L.afficher());

}






void Dialogsou::on_id_liv_currentIndexChanged(int index)
{
    ui->id_liv->currentText();
}

void Dialogsou::on_Ajouter_2_clicked()
{
    reclamation r(ui->id_rec->text().toInt(),ui->id_liv->currentText().toInt(),ui->descc->text(),ui->date_pan->text());
       bool test= r.ajouter();
          ui->tableView_rec->setModel(r.afficher());
       ui->id_liv->setModel(r.afficheroncombo());
       ui->i_reccombo->setModel(r.afficheroncomboidrec());
       ui->id_reccombosup->setModel(r.afficheroncomboidrec());


}
void Dialogsou::on_i_reccombo_currentIndexChanged(int index)
{
    ui->i_reccombo->currentText();
}
void Dialogsou::on_modifier_4_clicked()
{
    bool    test=r.modifier(ui->i_reccombo->currentText().toInt(),ui->total_5->text(),ui->date_pan->text()) ;
          if (test)
          {

                ui->tableView_rec->setModel(r.afficher());
                ui->id_liv->setModel(r.afficheroncombo());
                ui->i_reccombo->setModel(r.afficheroncomboidrec());
                ui->id_reccombosup->setModel(r.afficheroncomboidrec());

              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}



void Dialogsou::on_id_reccombosup_currentIndexChanged(int index)
{
     ui->id_reccombosup->currentText();
}

void Dialogsou::on_supprimer_3_clicked()
{
    bool test=r.supprimer(ui->id_reccombosup->currentText().toInt());
    if(test)
    {ui->tableView_rec->setModel(r.afficher());
        ui->id_liv->setModel(r.afficheroncombo());
        ui->i_reccombo->setModel(r.afficheroncomboidrec());
        ui->id_reccombosup->setModel(r.afficheroncomboidrec());
        //actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}

void Dialogsou::on_PDF_3_clicked()
{
    r.genererPDFr();
}


void Dialogsou::on_pdff_clicked()
{
    r.genererPDFr();
}


void Dialogsou::on_lineEdit_rech_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox_rech->currentText()=="num_cmd"
            ){
        query->prepare("SELECT * FROM livraison WHERE num_com LIKE'"+arg1+"%'");//
query->exec();
    model->setQuery(*query);
ui->tableView->setModel(model);


    }
    else {
        if(ui->comboBox_rech->currentText()=="livreur"){
            query->prepare("SELECT * FROM livraison WHERE livreur LIKE'"+arg1+"%'");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
        }
        else{
            if(ui->comboBox_rech->currentText()=="date")
                query->prepare("SELECT * FROM livraison WHERE date_arrivee LIKE'"+arg1+"%'");//+tri
        query->exec();
            model->setQuery(*query);
        ui->tableView->setModel(model);
            }

        }
}

void Dialogsou::on_pushButton_clicked()
{
    stat_liv=new statelivrec(this);
    stat_liv->show();
}


