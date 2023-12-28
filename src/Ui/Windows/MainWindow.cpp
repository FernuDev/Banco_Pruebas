//
// Created by fernu on 12/23/23.
//

#include "MainWindow.h"


void MainWindow::Resize(int w, int h) {
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

    // Buttons

    // Init/Stop test button
    auto *startBtn = new Button(contentWidget, "Start");
    startBtn->setGeometry(105, 90, 100, 30);
    startBtn->setStyleSheet("font-size: 16px; font-weight: regular");


    // Exit button
    auto *exitBtn = new Button(sideBar, "X");
    exitBtn->setGeometry(90, 900, 100, 30);

    // Export  CSV button
    auto *exportBtn = new Button(contentWidget, "Export CSV");
    exportBtn->setGeometry(305, 90, 100, 30 );

    // Export Engine button
    auto *export2Btn = new Button(contentWidget, "Export ENG");
    export2Btn->setGeometry(205, 90, 100, 30);

    // Using LinearChart class
    auto *linearChart = new LinearChart(contentWidget);
    linearChart->setGeometry(75, 240, 880, 520);

    // Timer

    auto *timeTitle = new QLabel(contentWidget);
    timeTitle->setTextFormat(Qt::MarkdownText);
    timeTitle->setText("# 0");
    timeTitle->setGeometry(950, 20, 100, 30);
    timeTitle->setAlignment(Qt::AlignCenter);

    // Connection to the actions in the button
    connect(exitBtn, &QPushButton::clicked, this, &MainWindow::closeWindow);
    connect(startBtn, &QPushButton::pressed, this, [=]()  {
        this->isInit = !isInit;
        startBtn->setText("Stop");
        this->checkIsInit();
    });

    // Exports buttons
    connect(exportBtn, &QPushButton::pressed, this, [=] () {
        linearChart->exportToCSV(this->time);
        std::cout<<"Export your results ..."<<std::endl;
    });

    connect(export2Btn, &QPushButton::pressed, this, [=] (){
        linearChart->exportToEngine(this->time);
        std::cout<<"Export your engine..."<<std::endl;
    });

    this->setTime(*contentWidget, *timeTitle, *linearChart);
}

// Functionalities

void MainWindow::setTime(QWidget &parent, QLabel &timeTitle, LinearChart &linearChart) {
    this->timer = new QTimer(&parent);

    connect(timer, &QTimer::timeout, &parent, [=, &timeTitle, &linearChart]() mutable{
        this->time += 1;
        linearChart.appendSeries(this->time, qSin(this->time / 10.0)*3, this->time);
        timeTitle.setText("# "+QString::number(this->time));
    });

    this->timer->setInterval(10);
}

// Inits or stops the test
void MainWindow::checkIsInit() {
    if(this->isInit) {
        this->timer->start();
    }else {
        this->timer->stop();
    }
}

// Getters and Setters

std::string MainWindow::getTitle() {
    return this->title;
}

void MainWindow::setTitle(std::string wTitle) {
    this->title = std::move(wTitle);
    this->setWindowTitle(QString::fromStdString(this->title));
}

void MainWindow::closeWindow() {
    this->close();
}




