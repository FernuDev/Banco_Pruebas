//
// Created by fernudev on 12/23/24.
//

#include "CountDown.h"

CountDown::CountDown(QWidget* parent) {
    if (parent) { setParent(parent); }

    setStyleSheet("background-color: #1D1D1D;");
    setMaximumHeight(200);

    this->time = new QWidget();

    this->minute = new QLabel("00");
    this->minute->setStyleSheet("font-size: 90px; border: 2px solid white; border-radius: 15px;");

    this->separate = new QLabel(":");
    this->separate->setStyleSheet("font-size: 90px;");
    this->separate->setAlignment(Qt::AlignCenter);

    this->seconds = new QLabel("00");
    this->seconds->setStyleSheet("font-size: 90px; border: 2px solid white; border-radius: 15px;");

    this->timeLayout = new QHBoxLayout();
    this->timeLayout->addWidget(minute);
    this->timeLayout->addWidget(separate);
    this->timeLayout->addWidget(seconds);

    this->timeLayout->setSpacing(0);

    this->time->setLayout(this->timeLayout);

    this->timer = new QWidget();
    this->title = new QLabel("Count Down");
    this->title->setStyleSheet("font-size: 35px; border-bottom: 1px solid white;");
    this->title->setAlignment(Qt::AlignCenter);
    this->timerLayout = new QVBoxLayout();

    // Buttons
    this->btnWidget = new QWidget();

    this->startBtn = new Button();
    this->startBtn->setText("Inicio de \nCuenta");

    this->stopBtn = new Button();
    this->stopBtn->setText("Paro de \nemergencia");

    this->btnLayout = new QHBoxLayout();

    this->btnLayout->addWidget(startBtn);
    this->btnLayout->addWidget(stopBtn);
    this->btnLayout->setSpacing(20);

    this->btnWidget->setLayout(this->btnLayout);

    this->timerLayout->addWidget(title);
    this->timerLayout->addWidget(btnWidget);

    this->timer->setLayout(this->timerLayout);

    this->countDownLayout = new QHBoxLayout();
    this->countDownLayout->addWidget(time);
    this->countDownLayout->addWidget(timer);


    this->setLayout(this->countDownLayout);
}