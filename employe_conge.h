#ifndef Employe_conge_H
#define Employe_conge_H

#include <QMainWindow>
#include "employe.h"
#include "cong.h"
#include "arduino_emp_conge.h"
#include "dialogstatemp.h"
#include "statelivrec.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Employe_conge; }
QT_END_NAMESPACE

class Employe_conge : public QMainWindow
{
    Q_OBJECT

public:
    Employe_conge(QWidget *parent = nullptr);
    ~Employe_conge();

private slots:
     void alert();
    void on_Ajouter_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_Supprimer_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_Modifier_clicked();


    void on_le_rech_textChanged(const QString &arg1);

    void on_comboBox_emplo_currentIndexChanged(int index);


    void on_Ajouter_conge_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_Supprimer_conge_clicked();

    void on_Modifier_conge_clicked();

    void on_Imprimer_clicked();

    void on_Pdf_conge_clicked();




    void on_pushButton_clicked();

    void on_button_tri_clicked();

    void on_pushButton_2_clicked();

    void on_Quitter_clicked();

private:
    Ui::Employe_conge *ui;
     EMPLOYE emp;
     cong co;
       statelivrec *stat_liv;
      arduino_emp_conge A;
      QByteArray data;
      bool check;
};
#endif // Employe_conge_H
