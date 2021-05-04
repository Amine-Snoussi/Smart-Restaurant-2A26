#ifndef DIALOGSTATEMP_H
#define DIALOGSTATEMP_H


#include <QDialog>
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
namespace Ui {
class dialogstatemp;
}

class dialogstatemp : public QDialog
{
    Q_OBJECT

public:
    explicit dialogstatemp(QWidget *parent = nullptr);
    ~dialogstatemp();
    QList<qreal> stat_emp();
    QList <QString> stat_emp_nom();

private:
  Ui::dialogstatemp *ui;
};

#endif // DIALOGSTATEMP_H
