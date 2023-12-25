//
// Created by fernu on 12/23/23.
//

#include "MainWindow.h"

#include <utility>


void MainWindow::Resize(float w, float h) {
    this->resize(w, h);
}

void MainWindow::setStyle(){

    //border: 2px solid red

    this->setStyleSheet("background-color: #28282C; color: white");
    auto *centralWidget = new QWidget(this);
    centralWidget->resize(this->width, this->height);

    auto *sideBar = new QWidget(centralWidget);
    sideBar->setGeometry(0, 0, 300, this->height);
    sideBar->setStyleSheet("background-color: #383949");

    auto *contentWidget = new QWidget(centralWidget);
    contentWidget->setGeometry(300, 0, this->width-300, this->height);

    // Widget titles
    auto *sideTitle = new QLabel(sideBar);
    sideTitle->setTextFormat(Qt::TextFormat::MarkdownText);
    sideTitle->setText("# Menu Bar");
    sideTitle->setGeometry(75, 20, 150,50);
    sideTitle->setStyleSheet("font-size: 14px");
    sideTitle->setAlignment(Qt::AlignCenter);

    auto *contentTitle = new QLabel(contentWidget);
    contentTitle->setText("# Antares Banco de Pruebas");
    contentTitle->setGeometry(75, 20, 500,50);
    contentTitle->setStyleSheet("font-size: 16px");
    contentTitle->setTextFormat(Qt::TextFormat::MarkdownText);
    contentTitle->setAlignment(Qt::AlignCenter);

    // Example of QtChart

    auto *series = new QLineSeries(contentWidget);
    series->append(0,6);
    series->append(2,4);
    series->append(3,8);
    series->append(7,4);

    // Pen for modify the line width and color
    auto *pen = new QPen();


    auto *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Ejemplo de line chart");
    chart->createDefaultAxes();

    auto *chartView = new QChartView(chart, contentWidget);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setGeometry(75, 240, 780, 420);


    // Buttons

    auto *exitBtn = new QPushButton(sideBar);
    exitBtn->setText("X");
}


// Getters and Setters

std::string MainWindow::getTitle() {
    return this->title;
}

void MainWindow::setTitle(std::string title) {
    this->title = std::move(title);
    this->setWindowTitle(QString::fromStdString(this->title));
}



