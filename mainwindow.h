#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "gestionmenu.h"
#include "gestioningredient.h"
#include<QTimer>

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
    void on_pushButton_2_ajouter_clicked();

    void on_pushButton_3_modifier_clicked();

    void on_pushButton_4_supp_clicked();

    void on_pushButton_historique_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    gestionmenu menu;
    gestioningredient ingredient;

};
#endif // MAINWINDOW_H







