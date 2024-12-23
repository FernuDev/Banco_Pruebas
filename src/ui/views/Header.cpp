//
// Created by fernudev on 12/22/24.
//

#include "Header.h"

Header::Header(QWidget *parent) {

    this->setParent(parent);

    // Configurando imagen
    this->logoPix = new QPixmap("./assets/Logo.png");
    this->logo = new QLabel();
    this->logo->setPixmap(*this->logoPix);

    this->title = new QLabel("Programa Aeroespacial | Antares Aerospace");
    this->title->setStyleSheet("font-size: 20px;");

    this->subTitle = new QLabel("Banco de Pruebas Macho V3");
    this->subTitle->setStyleSheet("font-size: 20px;");

    // Configuramos el texto del header
    this->headerText = new QWidget();
    this->headerLayoutText = new QVBoxLayout();

    this->headerLayoutText->addWidget(this->title);
    this->headerLayoutText->addWidget(this->subTitle);

    this->headerText->setLayout(this->headerLayoutText);

    this->headerLayout = new QHBoxLayout();

    this->headerLayout->addWidget(this->logo);
    this->headerLayout->addWidget(this->headerText);

    this->setLayout(this->headerLayout);

    this->setMaximumHeight(100);
}
