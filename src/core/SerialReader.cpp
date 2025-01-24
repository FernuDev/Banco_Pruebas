//
// Created by fernudev on 12/22/24.
//

#include "SerialReader.h"

float SerialReader::readFromSerial() const {
    if (port->isOpen()) {
        QByteArray data = port->readAll();
        return data.toFloat();
    } else {
        port->open(QIODevice::ReadOnly);
        return 0.0;
    }
}

QString SerialReader::getPortName() const {
    return portName;
}
QString SerialReader::getSerialNumber() const {
    return serialNumber;
}
QString SerialReader::getLocation() const {
    return location;
};
QString SerialReader::getManufacturer() const {
    return manufacturer;
};
QString SerialReader::getDescription() const {
    return description;
};
