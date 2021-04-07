#ifndef RESERVATION_H
#define RESERVATION_H

#include <QString>
#include <src/SmtpMime>
#include <QSqlQuery>
#include <QSqlQueryModel>

class reservation
{
private:
    int id;
    int id_client;
    int nt;
    int np;
    QString ville;
    QString date;
    QString heure;

public:
    reservation();
    reservation(int, int, int, int, QString, QString, QString);
    int getId() const;
    void setId(int value);
    int getId_client() const;
    void setId_client(int value);
    int getNt() const;
    void setNt(int value);
    int getNp() const;
    void setNp(int value);
    QString getVille() const;
    void setVille(const QString &value);
    QString getDate() const;
    void setDate(const QString &value);
    QString getHeure() const;
    void setHeure(const QString &value);

    bool ajouter();
    bool modifier();
    bool supprilmer();
    QSqlQueryModel* afficher();
    QSqlQueryModel* search(QString);
    void sendmail();
    int autoId();
};

#endif // RESERVATION_H
