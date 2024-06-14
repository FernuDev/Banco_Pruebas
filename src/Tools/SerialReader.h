//
// Created by fernu on 1/5/24.
//

#ifndef BANCO_PRUEBAS_SERIALREADER_H
#define BANCO_PRUEBAS_SERIALREADER_H

#include <iostream>
#include <string>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QString>
#include <QByteArray>

#ifdef __linux__

// GNU/Linux Headers
#include <cerrno> // Contains Error integer and strerror() function
#include <unistd.h> // write(), read(), open(), close(), functions
#include <termios.h> // Contains POSIX terminal control definitions
#include <fcntl.h> // Contains file controls like O_RDWR

#endif

class SerialReader {
private:
    QSerialPort *port{};
public:
    SerialReader(){

        const auto serialPortInfos = QSerialPortInfo::availablePorts();

        for(const QSerialPortInfo &portInfo : serialPortInfos){
            if(portInfo.portName() == "ttyUSB0" && portInfo.manufacturer() == "Silicon Labs"){
                std::cout << "\n"<< "Port: " << portInfo.portName().toStdString() << "\n";
                std::cout << "Location: " << portInfo.systemLocation().toStdString() << "\n";
                std::cout << "Serial number: " << portInfo.serialNumber().toStdString() << "\n";
                std::cout << "Manufacturer: " << portInfo.manufacturer().toStdString() << "\n";
                std::cout << "Description: " << portInfo.description().toStdString() << "\n";

                this->port = new QSerialPort();
                this->port->setPortName(portInfo.portName());
                this->port->setFlowControl(QSerialPort::NoFlowControl);
                this->port->setParity(QSerialPort::NoParity);
                this->port->setBaudRate(QSerialPort::Baud9600);
                this->port->setDataBits(QSerialPort::Data8);

                if(this->port->open(QIODevice::ReadWrite)) {
                    std::cout << "Puerto abierto correctamente" << "\n";
                }else{
                    std::cout << "Error al abrir el puerto\n";
                }
            }
        }
    }

    float readFromSerial();
};


#endif //BANCO_PRUEBAS_SERIALREADER_H
