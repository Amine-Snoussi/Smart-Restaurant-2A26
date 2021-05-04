#include "statelivrec.h"
#include "ui_statelivrec.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSqlQuery>



statelivrec::statelivrec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statelivrec)
{
    ui->setupUi(this);
    QPieSeries *series =new QPieSeries ;

    QList<qreal> list= stat_liv();
     QList<QString> list2=stat_liv_nom();

     for(int i=0 ;i<list.size();i++)
     {
          series->append(list2[i],list[i]);

     }
       QChart *chart =new QChart;
       chart->addSeries(series);
        chart->setTitle("STATS des liv");
        QChartView *chartview= new QChartView(chart);
         chartview->setParent(ui->horizontalFrame);
}


statelivrec::~statelivrec()
{
    delete ui;
}
QList<qreal> statelivrec::stat_liv()
{
    QList<qreal> list ;
    QSqlQuery query;
    query.prepare("select salaire,count(salaire) from emp group by salaire");
    query.exec();
    while(query.next())
    {list.append(query.value(1).toInt());}

    return list;
}

QList<QString> statelivrec::stat_liv_nom()
{QList<QString> list ;
    QSqlQuery query;
    query.prepare("select salaire,count(salaire) from emp group by salaire");
    query.exec();
    while(query.next())
    {list.append(query.value(0).toString());}

  return list;

}
