#include "reservation.h"

int reservation::getId() const
{
    return id;
}

void reservation::setId(int value)
{
    id = value;
}

int reservation::getId_client() const
{
    return id_client;
}

void reservation::setId_client(int value)
{
    id_client = value;
}

int reservation::getNt() const
{
    return nt;
}

void reservation::setNt(int value)
{
    nt = value;
}

int reservation::getNp() const
{
    return np;
}

void reservation::setNp(int value)
{
    np = value;
}

QString reservation::getVille() const
{
    return ville;
}

void reservation::setVille(const QString &value)
{
    ville = value;
}

QString reservation::getDate() const
{
    return date;
}

void reservation::setDate(const QString &value)
{
    date = value;
}

QString reservation::getHeure() const
{
    return heure;
}

void reservation::setHeure(const QString &value)
{
    heure = value;
}

bool reservation::ajouter()
{
    QSqlQuery query;
    query.prepare("insert into reservation (ID_RESERVATION, ID_CLIENT, nt, np, ville, datee, heure) values (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(QString::number(autoId()));
    query.addBindValue(QString::number(this->id_client));
    query.addBindValue(QString::number(this->nt));
    query.addBindValue(QString::number(this->np));
    query.addBindValue(this->ville);
    query.addBindValue(this->date);
    query.addBindValue(this->heure);

    return query.exec();
}

bool reservation::modifier()
{
    QSqlQuery query;
    query.prepare("update reservation set ID_CLIENT = ?, nt = ?, np = ?, datee = ?, heure = ? where ID_RESERVATION = ?");
    query.addBindValue(QString::number(this->id_client));
    query.addBindValue(QString::number(this->nt));
    query.addBindValue(QString::number(this->np));
    query.addBindValue(this->date);
    query.addBindValue(this->heure);
    query.addBindValue(QString::number(this->id));

    return query.exec();
}

bool reservation::supprilmer()
{
    QSqlQuery query;
    query.prepare("delete from reservation where ID_RESERVATION = ? ");
    query.addBindValue(QString::number(this->id));

    return query.exec();
}

QSqlQueryModel *reservation::afficher()
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    modal->setQuery("select * from reservation");
    return modal;
}

QSqlQueryModel *reservation::search(QString __input__)
{
    QSqlQuery query;
    query.prepare("select * from reservation where nt like ? or np like ? or ville like ? or datee like ? or heure like ?");
    query.addBindValue("%"+__input__+"%");
    query.addBindValue("%"+__input__+"%");
    query.addBindValue("%"+__input__+"%");
    query.addBindValue("%"+__input__+"%");
    query.addBindValue("%"+__input__+"%");
    query.exec();
    QSqlQueryModel * modal=new QSqlQueryModel();
    modal->setQuery(query);
    return modal;
}

void reservation::sendmail()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("amine.snoussi@esprit.tn");
    smtp.setPassword("191JMT1473");

    MimeMessage message;

    EmailAddress sender("amine.snoussi@esprit.tn", "amine");
    message.setSender(&sender);

    EmailAddress to("amine.snoussi@esprit.tn", "amine");
    message.addRecipient(&to);

    message.setSubject(" reservation ajouter ");

    MimeText text;
    text.setText("reservation: "+this->ville+" "+this->date );

    message.addPart(&text);

        if (!smtp.connectToHost()) {
            qDebug() << "Failed to connect to host!" << endl;
        }

        if (!smtp.login()) {
            qDebug() << "Failed to login!" << endl;
        }

        if (!smtp.sendMail(message)) {
            qDebug() << "Failed to send mail!" << endl;
        }

    smtp.quit();
}

reservation::reservation()
{

}

reservation::reservation(int _0, int _1, int _2, int _3, QString _4, QString _5, QString _6)
{
    this->id = _0;
    this->id_client = _1;
    this->nt = _2;
    this->np = _3;
    this->ville = _4;
    this->date = _5;
    this->heure = _6;
}

int reservation::autoId()
{
    QSqlQuery query;
    query.exec("select id_reservation from reservation order by id_client asc");
    int x = 0;
    while (query.next()) {
        x = query.value(0).toInt();
    }
    x++;
    return x;
}
