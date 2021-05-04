#include "homepage.h"
#include "ui_homepage.h"




HomePage::HomePage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);
}

HomePage::~HomePage()
{
    delete ui;
}


void HomePage::on_clients_reservations_clicked()
{
    Client_reservation= new class Client_reservation(this);
        Client_reservation->show();

}

void HomePage::on_menu_ingredients_clicked()
{
    Menu_ingredient= new class Menu_ingredient(this);
        Menu_ingredient->show();
}

void HomePage::on_employe_conge_clicked()
{
    Employe_conge= new class Employe_conge(this);
        Employe_conge->show();
}

void HomePage::on_fournisseur_commande_clicked()
{
    Fournisseur_commande= new class Fournisseur_commande(this);
        Fournisseur_commande->show();
}

void HomePage::on_livraison_reclamation_clicked()
{
    Dialogsou= new class Dialogsou(this);
        Dialogsou->show();
}
