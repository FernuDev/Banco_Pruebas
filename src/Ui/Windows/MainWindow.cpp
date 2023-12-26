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

    series->setUseOpenGL(true);

    // Pen for modify the line width and color
    auto *pen = new QPen();
    pen->setWidth(4);
    pen->setColor("#257e95");
    series->setPen(*pen);

    // Custom axes
    auto *axisX = new QValueAxis;
    auto *axisY = new QValueAxis;

    // Establishment limits for axis
    axisX->setRange(-10, 110);
    axisX->setTitleText("Tiempo [ds]");
    axisY->setRange(-5, 5);
    axisY->setTitleText("Empuje [N]");

    axisX->setTitleBrush(QBrush(Qt::white));
    axisY->setTitleBrush(QBrush(Qt::white));
    axisX->setLabelsBrush(QBrush(Qt::white));
    axisY->setLabelsBrush(QBrush(Qt::white));
    axisX->setGridLineVisible(false);
    axisY->setGridLineVisible(false);

    auto *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Empuje-Tiempo");
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->setBackgroundBrush(QBrush(QColor(0,0,0,0)));
    chart->setTitleBrush(QBrush(Qt::white));

    series->attachAxis(axisX);
    series->attachAxis(axisY);
    
    auto *chartView = new QChartView(chart, contentWidget);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setGeometry(75, 240, 880, 520);
    chartView->setStyleSheet("color: white");

    // Buttons

    // Exit button
    auto *exitBtn = new QPushButton(sideBar);
    exitBtn->setText("X");
    exitBtn->setGeometry(90, 900, 100, 30);

    // Connection to the actions in the button
    connect(exitBtn, &QPushButton::clicked, this, &MainWindow::closeWindow);


    // Timer

    auto *timeTitle = new QLabel(contentWidget);
    timeTitle->setTextFormat(Qt::MarkdownText);
    timeTitle->setText("# 0");
    timeTitle->setGeometry(950, 20, 100, 50);
    timeTitle->setAlignment(Qt::AlignCenter);

   this->setTime(*contentWidget, *timeTitle, *series, *axisX, *axisY);
}

// Functionalities

void MainWindow::setTime(QWidget &parent, QLabel &timeTitle, QLineSeries &series, QValueAxis &axisX, QValueAxis &axisY) {
    auto *timer = new QTimer(&parent);

    connect(timer, &QTimer::timeout, &parent, [=, &timeTitle, &series, &axisX, &axisY]() mutable {
       this->time += 1;
       axisX.setRange(0, this->time + 10);
       series.append(this->time, qSin(this->time / 10.0));
       timeTitle.setText("# "+QString::number(this->time));
    });

    timer->setInterval(10);
    timer->start();
}

// Getters and Setters

std::string MainWindow::getTitle() {
    return this->title;
}

void MainWindow::setTitle(std::string title) {
    this->title = std::move(title);
    this->setWindowTitle(QString::fromStdString(this->title));
}

void MainWindow::closeWindow() {
    this->close();
}




