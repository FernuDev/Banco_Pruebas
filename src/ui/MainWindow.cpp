//
// Created by fernudev on 12/22/24.
//

#include "MainWindow.h"

MainWindow::MainWindow() {

    // Configuramos el tamaño inicial de la ventana y el titulo de la misma
    this->setFixedSize(1821,900);
    this->setWindowTitle("Banco de Pruebas V3");

    // General layout
    this->centralWidget = new QWidget();
    this->setCentralWidget(this->centralWidget);

    // Generando el header
    auto *header = new Header();
    auto *graphView = new GraphView();
    auto *countDown = new CountDown();

    // Content and information layout

    this->infoLayout = new QVBoxLayout();
    this->infoWidget = new QWidget();

    this->layout = new QHBoxLayout();

    this->infoLayout->addWidget(header);
    this->infoLayout->addWidget(countDown);

    this->infoWidget->setLayout(infoLayout);

    this->layout->addWidget(infoWidget);
    this->layout->addWidget(graphView);

    this->centralWidget->setLayout(this->layout);

    this->show();
}
