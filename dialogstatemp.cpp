#include "dialogstatemp.h"
#include "ui_dialogstatemp.h"

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSqlQuery>



dialogstatemp::dialogstatemp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogstatemp)
{

    QPieSeries *series =new QPieSeries ;

    QList<qreal> list= stat_emp();
     QList<QString> list2=stat_emp_nom();

     for(int i=0 ;i<list.size();i++)
     {
          series->append(list2[i],list[i]);

     }
       QChart *chart =new QChart;
       chart->addSeries(series);
        chart->setTitle("STATS des emp");
        QChartView *chartview= new QChartView(chart);
         chartview->setParent(ui->horizontalFrame);
}


dialogstatemp::~dialogstatemp()
{
    delete ui;
}
QList<qreal> dialogstatemp::stat_emp()
{
    QList<qreal> list ;
    QSqlQuery query;
    query.prepare("select salaire,count(salaire) from EMP group by salaire");
    query.exec();
    while(query.next())
    {list.append(query.value(1).toInt());}

    return list;
}

QList<QString> dialogstatemp::stat_emp_nom()
{QList<QString> list ;
    QSqlQuery query;
    query.prepare("select salaire,count(salaire) from emp group by salaire");
    query.exec();
    while(query.next())
    {list.append(query.value(0).toString());}

  return list;

}
