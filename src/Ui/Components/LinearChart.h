//
// Created by fernu on 12/27/23.
//

#ifndef BANCO_PRUEBAS_LINEARCHART_H
#define BANCO_PRUEBAS_LINEARCHART_H

#include <QWidget>
#include <QLineSeries>
#include <QPen>
#include <QValueAxis>
#include <QChartView>
#include <QFileDialog>
#include <fstream>
#include <iostream>

// Tools and Own headers

#include "../../Tools/Uuid.h"


class LinearChart : public QChartView {
private:
    QChart *chart;
    QLineSeries *series;
    QValueAxis *axisX, *axisY;
    QPen *pen;
public:
    explicit LinearChart(QWidget *parent){
        this->setParent(parent);

        // Initializing values
        this->series = new QLineSeries(this);
        this->series->setUseOpenGL(false); // Fading the line

        // Pen fot modify the line width and color

        this->pen = new QPen();
        this->pen->setWidth(4);
        this->pen->setColor("#257e95");

        // Setting the default pen
        this->series->setPen(*pen);

        // Custom axis initialize

        this->axisX = new QValueAxis;
        this->axisY = new QValueAxis;

        // Axis decorations

        this->axisX->setTitleBrush(QBrush(Qt::white));
        this->axisY->setTitleBrush(QBrush(Qt::white));
        this->axisX->setLabelsBrush(QBrush(Qt::white));
        this->axisY->setLabelsBrush(QBrush(Qt::white));
        this->axisX->setGridLineVisible(false);
        this->axisY->setGridLineVisible(false);

        // Establishment limits for axis
        this->axisX->setRange(-10, 10);
        this->axisX->setTitleText("Tiempo [ds]");
        this->axisY->setRange(-5, 5);
        this->axisY->setTitleText("Empuje [N]");

        // Config the chart

        this->chart = new QChart();
        this->chart->addSeries(this->series);
        this->chart->setTitle("Empuje-Tiempo");
        this->chart->addAxis(this->axisX, Qt::AlignBottom);
        this->chart->addAxis(this->axisY, Qt::AlignLeft);
        this->chart->setBackgroundBrush(QBrush(QColor(0,0,0,0)));
        this->chart->setTitleBrush(QBrush(Qt::white));

        this->series->attachAxis(this->axisX);
        this->series->attachAxis(this->axisY);

        this->setRenderHint(QPainter::Antialiasing);
        this->setStyleSheet("color:white");
        this->setChart(this->chart);

        this->show();
    };
    void appendSeries(double x, double y);
    void appendSeries(double x, double y, int time);
    void setLineSeries(QLineSeries *Series);
    void exportToCSV(int Time);
    void exportToEngine(int Time);
};


#endif //BANCO_PRUEBAS_LINEARCHART_H
