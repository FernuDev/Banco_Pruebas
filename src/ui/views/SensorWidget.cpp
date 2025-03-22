#include "SensorWidget.h"

SensorWidget::SensorWidget(QWidget* parent) : QWidget(parent) {
    // Establecer fondo oscuro y bordes redondeados globalmente
    this->setStyleSheet("QWidget { background-color: #1D1D1D; border-radius: 10px; }");

    // Título
    titleLabel = new QLabel("<b>Sensores</b>");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("color: white; font-size: 24px; font-weight: bold;");

    // Línea divisoria
    QFrame* separator = new QFrame();
    separator->setFrameShape(QFrame::HLine);
    separator->setStyleSheet("border: 2px solid gray;");

    // Datos principales
    pressureLabel = new QLabel("<b>230.43</b>");
    pressureLabel->setStyleSheet("color: white; font-size: 22px;");
    thrustLabel = new QLabel("<b>14.3</b>");
    thrustLabel->setStyleSheet("color: white; font-size: 22px;");
    ispLabel = new QLabel("<b>310.22</b>");
    ispLabel->setStyleSheet("color: white; font-size: 22px;");

    // Unidades
    pressureUnitLabel = new QLabel("Presión<br>(Pa)");
    pressureUnitLabel->setStyleSheet("color: gray; font-size: 12px;");
    thrustUnitLabel = new QLabel("Empuje<br>(kN)");
    thrustUnitLabel->setStyleSheet("color: gray; font-size: 12px;");
    ispUnitLabel = new QLabel("Impulso específico<br>(Ns)");
    ispUnitLabel->setStyleSheet("color: gray; font-size: 12px;");

    // Layout para los valores y unidades
    auto* pressureLayout = new QVBoxLayout();
    pressureLayout->addWidget(pressureLabel, 0, Qt::AlignCenter);
    pressureLayout->addWidget(pressureUnitLabel, 0, Qt::AlignCenter);

    auto* thrustLayout = new QVBoxLayout();
    thrustLayout->addWidget(thrustLabel, 0, Qt::AlignCenter);
    thrustLayout->addWidget(thrustUnitLabel, 0, Qt::AlignCenter);

    auto* ispLayout = new QVBoxLayout();
    ispLayout->addWidget(ispLabel, 0, Qt::AlignCenter);
    ispLayout->addWidget(ispUnitLabel, 0, Qt::AlignCenter);

    auto* valuesLayout = new QHBoxLayout();
    valuesLayout->addLayout(pressureLayout);
    valuesLayout->addLayout(thrustLayout);
    valuesLayout->addLayout(ispLayout);

    // Botón Exportar
    exportButton = new QPushButton("Exportar Prueba");
    exportButton->setStyleSheet(
        "QPushButton {"
        "   background-color: transparent;"
        "   color: white;"
        "   font-size: 14px;"
        "   border: 2px solid #3F8B1B;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #3F8B1B;"
        "}"
    );

    // Botón Reiniciar
    resetButton = new QPushButton("Reiniciar");
    resetButton->setStyleSheet(
        "QPushButton {"
        "   background-color: transparent;"
        "   color: white;"
        "   font-size: 14px;"
        "   border: 2px solid #B22222;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #B22222;"
        "}"
    );

    // Layout de botones
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(exportButton);
    buttonsLayout->addWidget(resetButton);

    // Widget auxiliar para envolver los layouts
    QWidget* containerWidget = new QWidget();
    QVBoxLayout* containerLayout = new QVBoxLayout();
    containerLayout->addWidget(titleLabel);
    containerLayout->addWidget(separator);
    containerLayout->addLayout(valuesLayout);
    containerLayout->addLayout(buttonsLayout);
    containerWidget->setLayout(containerLayout);

    // Layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(containerWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);  // Elimina márgenes adicionales
    mainLayout->setSpacing(10); // Ajusta el espacio entre los elementos

    // Establecer que el widget ocupe todo el espacio disponible
    this->setLayout(mainLayout);
}
