#include "connexion.h"

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{
bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("ProjetQT");
db.setUserName("Seif");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur


if (db.open()) test = true;


return test;

}
void Connexion::fermerConnexion()
{db.close();}
