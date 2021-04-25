#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include "cong.h"
#include "arduino.h"
#include "dialogstatemp.h"
#include "statelivrec.h"
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
     void alert();
    void on_Ajouter_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_Supprimer_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_Modifier_clicked();

    void on_Quitter_clicked();

    void on_le_rech_textChanged(const QString &arg1);

    void on_comboBox_emplo_currentIndexChanged(int index);

    void on_comboBox_activated(const QString &arg1);

    void on_Ajouter_conge_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_Supprimer_conge_clicked();

    void on_Modifier_conge_clicked();

    void on_Imprimer_clicked();

    void on_Pdf_conge_clicked();

    void on_pushButton_6_clicked();

    void on_supprimer_clicked();

    void on_Supprimer_conge_2_clicked();

    void on_pushButton_clicked();

    void on_button_tri_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
     EMPLOYE emp;
     cong co;
       statelivrec *stat_liv;
      arduino A;
      QByteArray data;
      bool check;
};
#endif // MAINWINDOW_H
