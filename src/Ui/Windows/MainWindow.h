//
// Created by fernu on 12/23/23.
//

#ifndef BANCO_PRUEBAS_MAINWINDOW_H
#define BANCO_PRUEBAS_MAINWINDOW_H

// STD Libraries
#include <iostream>
#include <string>
#include <utility>
#include <chrono>
#include <thread>
#include <cmath>

// QT Libraries
#include <QMainWindow>
#include <QString>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QCoreApplication>
#include <QTimer>
#include <QThread>
#include <QLineEdit>

// Components
#include "../Components/LinearChart.h"
#include "../Components/Button.h"

// Tools and own headers
#include "../../Tools/Uuid.h"
#include "../../Tools/SerialReader.h"

class MainWindow : public QMainWindow {
private:
    int width, height;
    double empuje;
    std::string title;
    int time;
    bool isInit;
    QTimer *timer{};
    SerialReader *serialReader{};
public:

     MainWindow(int w, int h, std::string title) :
     width(w), height(h), title(std::move(title)),
     isInit(false),time(0), empuje(0)
     {
        this->setMinimumSize(this->width, this->height);
        this->setMaximumSize(this->width, this->height);
        this->setWindowTitle(QString::fromStdString(this->title));
        this->setStyle();
        this->checkIsInit();

        char *portName = (char *)"/dev/ttyUSB0";
        this->serialReader = new SerialReader(portName, 9600);
     }

    ~MainWindow() override {
        std::cout<<"Finalizando aplicación..."<<std::endl;
    }

    void Resize(int w, int h);
    void setStyle();

    // Functionalities
    void setTime(QWidget &parent, QLabel &title);
    void updateTime(QWidget &parent);
    void updateChart(QWidget &parent, LinearChart &linearChart);
    static void setMotorPort(QWidget &parent);
    void callSerialRead(QWidget &parent);
    void checkIsInit();
    float auxEmpuje(double Time);

    // Getters and Setters
    std::string getTitle();
    void setTitle(std::string wTitle);

public slots:
    void closeWindow();
};


#endif //BANCO_PRUEBAS_MAINWINDOW_H
