//
// Created by fernudev on 12/23/24.
//

#include "StatusLed.h"

StatusLed::StatusLed(QWidget *parent) {

    if (parent) {setParent(parent);}

    setStyleSheet("background-color: #1D1D1D; font-size: 20px; border-radius: 5px; text-align:center;");

    this->shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(25);
    shadow->setOffset(0, 0);
    shadow->setColor(QColor(63,139,27,100));

    setGraphicsEffect(shadow);

    setAlignment(Qt::AlignCenter);

}

void StatusLed::setActive() {
    setStyleSheet("background-color: #3F8B1B; font-size: 20px; border-radius: 5px;");
}

void StatusLed::setInactive() {
    setStyleSheet("background-color: #1D1D1D; font-size: 20px; border-radius: 5px;");
}