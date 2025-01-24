//
// Created by fernudev on 1/23/25.
//

#ifndef STATUSCONNECTION_H
#define STATUSCONNECTION_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "../components/Button.h"

class StatusConnection : public QWidget{
private:
    QLabel *statusTitle;
    Button *resetConnection;

    // Status serial port
    QLabel *serialPort{};
    QLabel *baundRate{};
    QLabel *fabricante{};
    QLabel *description{};
};



#endif //STATUSCONNECTION_H
