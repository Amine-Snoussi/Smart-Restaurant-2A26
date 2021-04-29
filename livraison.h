#ifndef LIVRAISON_H
#define LIVRAISON_H
#include <QString>
#include <QSqlQueryModel>


class livraison
{
public:
    livraison(int,QString,int,QString,int,QString);
    void setnum_com(int);
    void setproduit(QString n);
    void setquantite(int);
    void setlivreur(QString n);
    void settotal(int);
    void setdate_arrivee(QString n);
    int getnum_com();
    QString getproduit();
    int getquantite();
    QString getlivreur();
    int gettotal();
    QString getdate_arrivee();



    bool supprimer(int);
    bool ajouter();
    bool modifier();
    bool supprimer();

    bool rechercher(int);

    QSqlQueryModel* afficher();
    bool rechercher(QString,QString);
    QSqlQueryModel* tri(QString,QString);
    void genererPDFl();

    livraison();

private:
    int num_com,quantite,total;
    QString produit,livreur,date_arrivee;
};

#endif // LIVRAISON_H
