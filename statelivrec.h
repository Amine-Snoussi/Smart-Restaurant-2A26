#ifndef STATELIVREC_H
#define STATELIVREC_H

#include <QDialog>
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
namespace Ui {
class statelivrec;
}

class statelivrec : public QDialog
{
    Q_OBJECT

public:
    explicit statelivrec(QWidget *parent = nullptr);
    ~statelivrec();
    QList<qreal> stat_liv();
    QList <QString> stat_liv_nom();

private:
    Ui::statelivrec *ui;
};

#endif // STATELIVREC_H
