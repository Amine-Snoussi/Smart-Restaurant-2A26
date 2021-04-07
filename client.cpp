#include "client.h"
#include "connection.h"
#include "src/SmtpMime"
Client::Client()
{
    id_client=0;
    nom="";
    prenom="";
    Email="nom@domaine.com";
    adresse="";
    ville="";
    codePostal=0;
    numTel="";

}

Client::Client(int id,QString Nom,QString Prenom,QString mail,QString ad,QString ville,int cp,QString tel)
{
    id_client=id;
    nom=Nom;
    prenom=Prenom;
    Email=mail;
    adresse=ad;
    this->ville=ville;
    codePostal=cp;
    numTel=tel;

}




QSqlQueryModel * Client::afficher(){

    QSqlQueryModel * modal=new QSqlQueryModel();
    modal->setQuery("SELECT *FROM CLIENT");

    return modal;

}



bool Client::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO CLIENT (ID_CLIENT,NOM,PRENOM,NUMERO,EMAIL,ADRESSE,VILLE,CODE_POSTAL,TEL) "
                        "VALUES (:id, :nom,:prenom,:n,:email,:adresse,:ville,:code_postale,:tel)");
    query.bindValue(":id",autoId());
    query.bindValue(":nom",nom );
    query.bindValue(":prenom",prenom); //remplir la valeur d'une maniere securisée
    query.bindValue(":email", Email);
    query.bindValue(":adresse",adresse);
    query.bindValue(":n",numTel);

    query.bindValue(":ville",ville);
    query.bindValue(":code_postale",codePostal);
    query.bindValue(":tel",numTel);


    return    query.exec();

}


bool Client::modifier(){

    QSqlQuery query;


    query.prepare("UPDATE CLIENT SET NOM= :nom , PRENOM= :prenom "
                  ",EMAIL= :email , ADRESSE= :adresse , VILLE= :ville , CODE_POSTAL= :code_postale ,TEL= :tel "
                  "where ID_CLIENT= :id_Client"); //remplir la valeur d'une maniere securisée
    query.bindValue(":id_Client",id_client );
    query.bindValue(":nom",nom );
    query.bindValue(":prenom",prenom);
    query.bindValue(":email", Email);
    query.bindValue(":adresse",adresse);
    query.bindValue(":ville",ville);
    query.bindValue(":code_postale",codePostal);
    query.bindValue(":tel",numTel);

    return    query.exec();


}




bool Client::supprimer (int id_clientSelectionne)
{
    QSqlQuery query;
    query.prepare("Delete from Client where ID_CLIENT = :id_Client");
    query.bindValue(":id_Client",id_clientSelectionne);
    return    query.exec();


}

int Client::autoId()
{
    QSqlQuery query;
    query.exec("select id_client from client order by id_client asc");
    int x = 0;
    while (query.next()) {
        x = query.value(0).toInt();
    }
    x++;
    return x;
}

void Client::sendmail()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("amine.snoussi@esprit.tn");
    smtp.setPassword("191JMT1473");

    MimeMessage message;

    EmailAddress sender("amine.snoussi@esprit.tn", "amine");
    message.setSender(&sender);

    EmailAddress to("amine.snoussi@esprit.tn", "amine");
    message.addRecipient(&to);

    message.setSubject(" client ajouter ");

    MimeText text;
    text.setText("client nom et prenom: "+this->nom+" "+this->prenom );

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

QSqlQueryModel *Client::search(QString __input__)
{
    QSqlQuery query;
    query.prepare("select * from client where nom like ? or prenom like ? or adresse like ? or ville like ? or email like ? or code_postal like ? or tel like ? ");
    query.addBindValue("%"+__input__+"%");
    query.addBindValue("%"+__input__+"%");
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
