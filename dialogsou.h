#ifndef DIALOGSOU_H
#define DIALOGSOU_H
#include "livraison.h"
#include "reclamation.h"
#include "statelivrec.h"

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialogsou; }
QT_END_NAMESPACE

class Dialogsou : public QDialog
{
    Q_OBJECT

public:
    Dialogsou(QWidget *parent = nullptr);
    ~Dialogsou();

private slots:
    void on_Ajouter_clicked();

    void on_supprimer_clicked();
    void on_modifier_2_clicked();

    void on_button_tri_clicked();

    void on_imprimer_clicked();

    void on_PDF_clicked();

    void on_tabWidget_2_tabBarClicked(int index);

    void on_ajouter1_clicked();

    void on_affichage2_tabBarClicked(int index);

    void on_le_recherche_2_textChanged(const QString &arg1);

    void on_button_tri_2_clicked();

    void on_supprimer_2_clicked();

    void on_imprimer_2_clicked();

    void on_PDF_2_clicked();

    void on_modifier3_clicked();


    void on_Ajouter_2_clicked();

    void on_id_liv_currentIndexChanged(int index);

    void on_modifier_4_clicked();

    void on_i_reccombo_currentIndexChanged(int index);

    void on_id_reccombosup_currentIndexChanged(int index);

    void on_supprimer_3_clicked();

    void on_PDF_3_clicked();

    void on_pushButton_clicked();

    void on_pdff_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_rech_textChanged(const QString &arg1);

    void on_lineEdit_rech_2_textChanged(const QString &arg1);

private:
    Ui::Dialogsou *ui;
    livraison l;
    reclamation r;
    statelivrec *stat_liv;
};
#endif // DIALOGSOU_H
