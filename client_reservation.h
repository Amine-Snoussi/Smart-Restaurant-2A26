#ifndef ESPACE_CLIENT_H
#define ESPACE_CLIENT_H
#include "client.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QObject>
#include "reservation.h"

namespace Ui {
class Client_reservation;
}

class Client_reservation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client_reservation(QWidget *parent = nullptr);
    ~Client_reservation();
    void refrech();
private slots:

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_button_modifierReservation_3_clicked();

    void on_button_supprimerReservation_3_clicked();

    void on_lineEdit_21_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_button_modifierReservation_clicked();

    void on_button_supprimerReservation_clicked();

    void on_button_statistiques_clicked();

private:
    Ui::Client_reservation *ui;
   Client client;
   reservation R;
};

#endif // ESPACE_CLIENT_H
