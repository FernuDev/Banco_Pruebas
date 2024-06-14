//
// Created by fernu on 1/5/24.
//
#include "SerialReader.h"

float SerialReader::readFromSerial() {
    if(port->isOpen()){
        QByteArray data = port->readAll();
        return data.toFloat();
    }else {
        port->open(QIODevice::ReadOnly);
        return 0.0;
    }
    return 0.0;
}