//
// Created by fernu on 12/23/23.
//

#ifndef BANCO_PRUEBAS_MAINWINDOW_H
#define BANCO_PRUEBAS_MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include <utility>
#include <QString>
#include <QWidget>
#include <QLabel>
#include <QChart>
#include <QLineSeries>
#include <QChartView>
#include <QPen>
#include <QPushButton>
#include <QCoreApplication>
#include <QTimer>
#include <QValueAxis>

class MainWindow : public QMainWindow {
private:
    int width, height;
    std::string title;
    int time;
public:

    MainWindow(int w, int h, std::string title) : width(w), height(h), title(std::move(title)) {
        this->setMinimumSize(this->width, this->height);
        this->setMaximumSize(this->width, this->height);
        this->setWindowTitle(QString::fromStdString(this->title));

        this->time = 0;

        this->setStyle();
    }

    ~MainWindow() override {
        std::cout<<"Finalizando aplicación..."<<std::endl;
    }

    void Resize(float w, float h);
    void setStyle();
void setTime(QWidget& parent, QLabel& title, QLineSeries& series, QValueAxis& axisX, QValueAxis& axisY);
    // Getters and Setters

    std::string getTitle();
    void setTitle(std::string title);

public slots:
    void closeWindow();
};


#endif //BANCO_PRUEBAS_MAINWINDOW_H
