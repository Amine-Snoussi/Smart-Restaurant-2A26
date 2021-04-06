#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestionmenu.h"
#include "gestioningredient.h"

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

    void on_pushButton_3_modifier_clicked();

       void on_pushButton_4_supp_clicked();

       void on_pushButton_historique_clicked();

       void on_pushButton_2_clicked();

       void on_pushButton_3_clicked();

       void on_pushButton_4_clicked();

       void on_Ajouter_Button_clicked();

       void on_recherche1_textChanged(const QString &arg1);

       void on_recherche1_2_textChanged(const QString &arg1);

       void on_button_tri_2_clicked();

       void on_button_tri_clicked();

       void on_button_stat_2_clicked();

       void on_button_stat_clicked();

       void on_button_stat_3_clicked();

private:
    Ui::MainWindow *ui;
    gestionmenu menu;
    gestioningredient ingredient;
};
#endif // MAINWINDOW_H
