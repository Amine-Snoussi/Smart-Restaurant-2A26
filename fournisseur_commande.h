#ifndef Fournisseur_commande_H
#define Fournisseur_commande_H

#include <QMainWindow>
#include "fourn.h"
#include "comd.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Fournisseur_commande; }
QT_END_NAMESPACE

class Fournisseur_commande : public QMainWindow
{
    Q_OBJECT

public:
    Fournisseur_commande(QWidget *parent = nullptr);
    ~Fournisseur_commande();

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


    void on_le_recherche_2_textChanged(const QString &arg1);

    void on_tri_fournisseur_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Fournisseur_commande *ui;
    fourn FO;
    comd co;
};
#endif // Fournisseur_commande_H
