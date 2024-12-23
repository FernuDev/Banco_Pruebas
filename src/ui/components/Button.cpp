#include "Button.h"

Button::Button(QWidget* parent) {
    if (parent) {
        setParent(parent);
    }

    setStyleSheet("background-color: #1D1D1D; font-size: 20px; border-radius: 5px; padding: 20px 15px;");

    this->shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(25);
    shadow->setOffset(0, 0);
    shadow->setColor(QColor(63,139,27,100));

    setGraphicsEffect(shadow);
}
