//
// Created by fernudev on 12/23/24.
//

#include "GraphView.h"

GraphView::GraphView(QWidget *parent) {

    this->setParent(parent);

    this->presion = new QLabel();
    this->presionPix = new QPixmap("./assets/presion.png");
    this->presion->setPixmap(*this->presionPix);

    this->empuje = new QLabel();
    this->empujePix = new QPixmap("./assets/empuje.png");
    this->empuje->setPixmap(*this->empujePix);

    this->layout = new QVBoxLayout();
    this->layout->addWidget(presion);
    this->layout->addWidget(empuje);
    this->setLayout(layout);
}
