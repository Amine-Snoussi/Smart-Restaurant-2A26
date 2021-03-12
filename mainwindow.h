#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajouter_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_Supprimer_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_Modifier_clicked();

    void on_Quitter_clicked();

private:
    Ui::MainWindow *ui;
     EMPLOYE emp;
};
#endif // MAINWINDOW_H
