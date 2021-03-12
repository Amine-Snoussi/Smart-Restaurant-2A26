#include "connexion.h"

connexion::connexion()
{

}
bool connexion::create_cnx(){

    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("proj");
    db.setUserName("balha");
    db.setPassword("esprit18");
    if(db.open())
        test=true;
    return test;
}

void connexion::close_cnx(){db.close();}
