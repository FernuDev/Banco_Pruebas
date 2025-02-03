//
// Created by fernudev on 12/22/24.
//

#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <iostream>
#include <string>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QString>

class SerialReader {
private:
    QSerialPort *port{};

    QString portName;
    QString location;
    QString serialNumber;
    QString manufacturer;
    QString description;
public:
    SerialReader() {
        const auto serialPortInfos = QSerialPortInfo::availablePorts();

        for (const QSerialPortInfo &serialPortInfo : serialPortInfos) {
            if (serialPortInfo.portName() == "ttyUSB0" && serialPortInfo.manufacturer() == "Silicon Labs") {
                std::cout << "Serial port found" << std::endl;
                std::cout << "\nPort " << serialPortInfo.portName().toStdString();
                std::cout << "\nLocation: " << serialPortInfo.systemLocation().toStdString();
                std::cout << "\nSerial Number: " << serialPortInfo.serialNumber().toStdString();
                std::cout << "\nManufacturer: " << serialPortInfo.manufacturer().toStdString();
                std::cout << "\nDescription: " << serialPortInfo.description().toStdString();

                // Configurando el puerto base definido como la ESP32
                this->port = new QSerialPort();
                this->port->setPortName(serialPortInfo.portName());
                this->port->setFlowControl(QSerialPort::NoFlowControl);
                this->port->setBaudRate(QSerialPort::Baud9600);
                this->port->setParity(QSerialPort::NoParity);
                this->port->setDataBits(QSerialPort::Data8);

                this->portName = serialPortInfo.portName();
                this->location = serialPortInfo.systemLocation();
                this->serialNumber = serialPortInfo.serialNumber();
                this->manufacturer = serialPortInfo.manufacturer();
                this->description = serialPortInfo.description();

                if (this->port->open(QIODevice::ReadWrite)) {
                    std::cout << "\nPuerto serial abierto correctamente" << std::endl;
                } else {
                    std::cout << "\nError al abrir el puerto" << std::endl;
                }

                return;
            }
        }

        std::cout << "No se econtró ninguna placa ESP32 conectada " << std::endl;

    };

    [[nodiscard]] float readFromSerial() const;
    [[nodiscard]] QString getPortName() const;
    [[nodiscard]] QString getSerialNumber() const;
    [[nodiscard]] QString getLocation() const;
    [[nodiscard]] QString getManufacturer() const;
    [[nodiscard]] QString getDescription() const;
};



#endif //SERIALREADER_H
