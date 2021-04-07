#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fourn.h"
#include "comd.h"
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
    void on_pb_ajouter_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pb_modifier_2_clicked();

    void on_comboBox_4_currentIndexChanged(int index);

    void on_pb_supprimer_clicked();

    void on_pb_ajoutercommande_clicked();

    void on_cb_matF_currentIndexChanged(int index);

    void on_numcmd_combo_currentIndexChanged(int index);

    void on_numcmd_combo_2_currentIndexChanged(int index);

    void on_pb_modifier_5_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_2_clicked();

    void on_le_recherche_textChanged(const QString &arg1);

    void on_le_recherche_2_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    fourn FO;
    comd co;
};
#endif // MAINWINDOW_H
