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

void LinearChart::exportToCSV(int Time) {
    std::ofstream engine;
    std::string data;

    QString filePath = QFileDialog::getSaveFileName(this, "Guardar archivo", QDir::homePath(), "Archivos de texto (*.txt);;Todos los archivos (*.*)");

    // filePath contiene la ruta seleccionada por el usuario
    if (!filePath.isEmpty()) {
        // Realiza acciones con la ruta del archivo seleccionado
        qDebug() << "Archivo seleccionado:" << filePath;
    } else {
        // El usuario canceló la selección
        qDebug() << "Selección cancelada por el usuario.";
    }

    for(int i=0;i<Time;i++){
        data+= std::to_string(this->series->at(i).x()) + ", " + std::to_string(this->series->at(i).y()) + "\n";
    }

    engine.open("../src/DataScience/Engine/Prueba.cvs", std::fstream::out);
    engine<<"Antares AeroSpace\n";
    engine<<data;
    engine.close();
}

void LinearChart::exportToEngine(int Time) {
    std::ofstream engine;
    std::string data;

    for(int i=0;i<Time;i++){
        data+= std::to_string(this->series->at(i).x() / 10.0) + " " + std::to_string(this->series->at(i).y()) + "\n";
    }

    engine.open("../src/DataScience/Engine/Prueba.eng", std::fstream::out);
    engine << "MS1-41  15  120  P  0.02  0.060  Antares\n";
    engine << data;
    engine.close();
}