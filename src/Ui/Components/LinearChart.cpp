//
// Created by fernu on 12/27/23.
//

#include "LinearChart.h"


void LinearChart::appendSeries(double x, double y) {
    this->series->append(x, y);
}

void LinearChart::appendSeries(double x, double y, int time) {
    this->axisX->setRange(0, time + 10);
    this->series->append(x, y);
}

void LinearChart::setLineSeries(QLineSeries *Series) {
    this->series = Series;
}