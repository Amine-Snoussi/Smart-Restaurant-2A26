#include "connection.h"
#include "client.h"
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("ProjetQT");//ProjetQT
db.setUserName("amine");//amine
db.setPassword("amine");//amine

if (db.open())
test=true;





    return  test;
}
