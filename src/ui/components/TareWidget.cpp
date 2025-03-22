//
// Created by fernudev on 3/21/25.
//

#include "TareWidget.h"

TareWidget::TareWidget(QWidget* parent) : QWidget(parent) {
    // Establecer fondo oscuro
    this->setStyleSheet("background-color: #1D1D1D; border-radius: 10px;");

    // Título
    titleLabel = new QLabel("Tara");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("color: white; font-size: 24px; font-weight: bold;");

    // Línea divisoria
    QFrame* separator = new QFrame();
    separator->setFrameShape(QFrame::HLine);
    separator->setStyleSheet("border: 2px solid gray;");

    // Botón "Tarear"
    tareButton = new QPushButton("Tarear");
    tareButton->setFixedWidth(195);
    tareButton->setStyleSheet(
        "QPushButton {"
        "   background-color: transparent;"
        "   color: white;"
        "   font-size: 16px;"
        "   border: 2px solid #3F8B1B;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #3F8B1B;"
        "}"
    );

    // Etiqueta de valor
    valueLabel = new QLabel("Valor (kg):   <b>0.0023</b>");
    valueLabel->setStyleSheet("color: white; font-size: 14px;");

    // Etiqueta de factor de conversión
    conversionFactorLabel = new QLabel("Factor Conversión:   <span style='color: gray;'>0.0023</span>");
    conversionFactorLabel->setStyleSheet("color: white; font-size: 14px;");

    // Layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(separator);
    mainLayout->addWidget(tareButton, 0, Qt::AlignCenter);
    mainLayout->addWidget(valueLabel);
    mainLayout->addWidget(conversionFactorLabel);

    setMaximumWidth(240);
    setLayout(mainLayout);
}