#ifndef Menu_ingredient_H
#define Menu_ingredient_H

#include <QMainWindow>
#include "gestionmenu.h"
#include "gestioningredient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu_ingredient; }
QT_END_NAMESPACE

class Menu_ingredient : public QMainWindow
{
    Q_OBJECT

public:
    Menu_ingredient(QWidget *parent = nullptr);
    ~Menu_ingredient();

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
    Ui::Menu_ingredient *ui;
    gestionmenu menu;
    gestioningredient ingredient;
};
#endif // Menu_ingredient_H
