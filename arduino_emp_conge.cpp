#include "arduino_emp_conge.h"
#include <QDebug>

arduino_emp_conge::arduino_emp_conge()
{
   data="";
   arduino_port_name="";
   arduino_is_available=false;
   serial= new QSerialPort;

}
QString arduino_emp_conge::getarduino_port_name()// yakra bih l port eli fih l carta
{
    return arduino_port_name;
}

QSerialPort *arduino_emp_conge::getserial()// ken fama des donnés fel port serie yakrahom
{
    return serial;
}

int arduino_emp_conge::connect_arduino() // pour verifier si la carte arduino est bien connecté
{
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()== arduino_uno_producy_id)

         {
        arduino_is_available=true;
        arduino_port_name=serial_port_info.portName();
        }}}
        qDebug()<<"arduino_port_name is :"<< arduino_port_name;
        if(arduino_is_available){
            serial->setPortName(arduino_port_name);
            if (serial->open(QSerialPort::ReadWrite)){
               serial->setBaudRate(QSerialPort::Baud9600);
               serial->setDataBits(QSerialPort::Data8);
               serial->setParity(QSerialPort::NoParity);
               serial->setStopBits(QSerialPort::OneStop);
               serial->setFlowControl(QSerialPort::NoFlowControl);
               return 0;
            }return 1 ;
        }



    return -1 ;



    }
int arduino_emp_conge::close_arduino()// tsaker l'arduino
{
    if(serial->isOpen())
    {
    serial->close();
    return 0;
    }return 1;

}
int arduino_emp_conge::write_to_arduino(QByteArray d )// bech nabaathou données mel qt lel arduino
{
    if (serial->isWritable())
    {
        serial->write(d);
    }
    else
        qDebug()<<"error en ecriture";
}
QByteArray arduino_emp_conge::read_from_arduino()// bech nakraw mel arduino
{
    if(serial->isReadable())
    {
        data=serial->readAll();
        return data;
    }

}
