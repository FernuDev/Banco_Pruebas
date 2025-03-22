//
// Created by fernudev on 12/23/24.
//

#include "StatusView.h"

StatusView::StatusView(QWidget *parent) {
    if (parent) {setParent(parent);}

    setStyleSheet("background-color: #1D1D1D;");

    // Inicializando los leds de estaztus
    this->standBy = new StatusLed();
    this->standBy->setText("Standby");

    this->countDown = new StatusLed();
    this->countDown->setText("CountDown");

    this->prueba = new StatusLed();
    this->prueba->setText("Prueba");

    this->finPrueba = new StatusLed();
    this->finPrueba->setText("FinPrueba");

    // Inicializando el box layout horizontal
    this->layout = new QHBoxLayout();

    // Agregamos los distintos leds a el layout

    this->layout->addWidget(this->standBy);
    this->layout->addWidget(this->countDown);
    this->layout->addWidget(this->prueba);
    this->layout->addWidget(this->finPrueba);

    this->layout->setSpacing(30);
    this->setMaximumHeight(50);

    this->setLayout(layout);

}
