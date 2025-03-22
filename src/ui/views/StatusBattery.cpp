//
// Created by fernudev on 3/21/25.
//

#include "StatusBattery.h"

StatusBattery::StatusBattery(QWidget* parent)
{
    if (parent) { setParent(parent); }

    setStyleSheet("background-color: #1D1D1D; border-radius: 10px;");

    // Inicializando los datos generales

    // Title
    this->title = new QLabel("Estatus");
    this->title->setAlignment(Qt::AlignCenter);
    this->title->setStyleSheet("font-size: 20px; border-bottom: 1px solid gray");
    this->title->setMaximumHeight(20);

    // Etiqueta y barra de batería
    this->labelBattery = new QLabel("Porcentaje de batería: 50%");
    this->labelBattery->setAlignment(Qt::AlignCenter);
    this->labelBattery->setStyleSheet("color: white; font-size: 14px;");

    this->progressBarBattery = new QProgressBar();
    this->progressBarBattery->setValue(50);
    this->progressBarBattery->setRange(0, 100);
    this->progressBarBattery->setTextVisible(false); // Ocultar texto dentro de la barra
    this->progressBarBattery->setStyleSheet(
        "QProgressBar::chunk { background-color: #3F8B1B; }"
    );

    // Etiqueta y barra de señal
    this->labelSignal = new QLabel("Intensidad de señal: 50%");
    this->labelSignal->setAlignment(Qt::AlignCenter);
    this->labelSignal->setStyleSheet("color: white; font-size: 14px;");

    this->progressBarSignal = new QProgressBar();
    this->progressBarSignal->setValue(50);
    this->progressBarSignal->setRange(0, 100);
    this->progressBarSignal->setTextVisible(false);
    this->progressBarSignal->setStyleSheet(
        "QProgressBar::chunk { background-color: #3F8B1B; }"
    );

    // Conexiones para actualizar los labels cuando cambie el progreso
    connect(this->progressBarBattery, &QProgressBar::valueChanged, this, [&](int value) {
        this->labelBattery->setText(QString("Porcentaje de batería: %1%").arg(value));
    });

    connect(this->progressBarSignal, &QProgressBar::valueChanged, this, [&](int value) {
        this->labelSignal->setText(QString("Intensidad de señal: %1%").arg(value));
    });

    // Layout
    this->layout = new QVBoxLayout();
    this->layout->addWidget(this->title, 0, Qt::AlignHCenter);

    this->layout->addWidget(this->labelBattery);
    this->layout->addWidget(this->progressBarBattery);

    this->layout->addWidget(this->labelSignal);
    this->layout->addWidget(this->progressBarSignal);

    this->setLayout(layout);
    this->setMaximumSize(240, 204);
}
