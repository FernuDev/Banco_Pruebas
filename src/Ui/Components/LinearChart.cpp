//
// Created by fernu on 12/27/23.
//

#include "LinearChart.h"


void LinearChart::appendSeries(double x, double y) {
    this->series->append(x, y);
}

void LinearChart::appendSeries(double x, double y, int time) {

    this->Data.insert({x,y});
    this->setMin();
    this->setMax();

    this->series->append(x, y);
    this->axisX->setRange(0, (time/100.0)+0.5);
    this->axisY->setRange(this->getMin() - 5, this->getMax() + 10);


}

void LinearChart::setMin() {
    auto Min = std::min_element(std::begin(this->Data), std::end(this->Data),
                                [=](const auto &l, const auto &r){
                                        return l.second < r.second;
    });

    std::cout<<"Min: "<<std::to_string(Min->second)<<std::endl;
    this->min = Min->second;
}

float LinearChart::getMin() const {
    return this->min;
}

void LinearChart::setMax() {
    auto Max = std::max_element(std::begin(this->Data), std::end(this->Data),
                                [=](const auto &l, const auto &r){
                                return l.second < r.second;
    });

    std::cout<<"Max: "<<std::to_string(Max->second)<<std::endl;
    this->max = Max->second;
}

float LinearChart::getMax() const{
    return this->max;
}


void LinearChart::setLineSeries(QLineSeries *Series) {
    this->series = Series;
}

void LinearChart::setData(int Time) {
    for(int i=0;i<Time;i++){
        this->Data.insert({this->series->at(i).x() / 10.0, this->series->at(i).y()});
    }
}

std::map<float, float> LinearChart::getData() {
    return this->Data;
}

// Exports

void LinearChart::exportToCSV(int Time) {
    std::ofstream engine;
    std::string data;

    QString Path = QFileDialog::getExistingDirectory(this, "Guardar prueba", QDir::homePath());
    // filePath contiene la ruta seleccionada por el usuario
    if (!Path.isEmpty()) {
        // Realiza acciones con la ruta del archivo seleccionado
        //this->setData(Time);

        for(auto item : this->Data) {
            data += std::to_string(item.first) + "," + std::to_string(item.second) + "\n";
        }

        auto *uid = new uuid::UUID();

        std::string filePath = Path.toStdString() + "/" + uid->generate_uid() + "-EngineTest.cvs";

        engine.open(filePath, std::fstream::out);
        engine<<"Time,Trust\n";
        engine<<data;
        engine.close();

        delete uid;
    } else {
        // El usuario canceló la selección
        std::cout << "Selección cancelada por el usuario.";
    }

}

void LinearChart::exportToEngine(int Time) {
    std::ofstream engine;
    std::string data;

    QString path = QFileDialog::getExistingDirectory(this, "Guardar Motor", QDir::homePath());

    if(!path.isEmpty()){
        //this->setData(Time);

        for(int i=0;i<Time;i++){
            data+= std::to_string(this->series->at(i).x()/10.0) + " " + std::to_string(this->series->at(i).y()) + "\n";
        }

        auto *uid = new uuid::UUID();

        std::string filePath = path.toStdString() + "/" + uid->generate_uid() + "-Motor.eng";

        engine.open(filePath, std::fstream::out);
        engine << "MS1-41  15  120  P  0.02  0.060  Antares\n";
        engine << data;
        engine.close();

        delete uid;
    }else {
        std::cout<<"Selección cancelada"<<std::endl;
    }
}