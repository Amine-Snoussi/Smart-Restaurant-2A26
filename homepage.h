#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include "client_reservation.h"
#include "dialogsou.h"
#include "employe_conge.h"
#include "menu_ingredient.h"
#include "fournisseur_commande.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HomePage; }
QT_END_NAMESPACE

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    HomePage(QWidget *parent = nullptr);
    ~HomePage();

private slots:
    void on_clients_reservations_clicked();

    void on_menu_ingredients_clicked();

    void on_employe_conge_clicked();

    void on_fournisseur_commande_clicked();

    void on_livraison_reclamation_clicked();

private:
    Ui::HomePage *ui;
    Client_reservation *Client_reservation;
    Dialogsou *Dialogsou;
    Employe_conge *Employe_conge;
    Menu_ingredient *Menu_ingredient;
    Fournisseur_commande *Fournisseur_commande;


};
#endif // HOMEPAGE_H
