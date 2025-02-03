//
// Created by fernudev on 1/23/25.
//

#include "StatusConnection.h"

#include <QApplication>

StatusConnection::StatusConnection(QWidget *parent) {
    if (parent) { setParent(parent); }

    setStyleSheet("background-color: #1D1D1D;");

    // Generando el titulo del componente
    this->statusTitle = new QLabel("Estatus Conexión");
    this->statusTitle->setStyleSheet("font-size: 24px; border-bottom: 2px solid white;");
    this->statusTitle->setAlignment(Qt::AlignCenter);
    this->statusTitle->setMaximumWidth(259);

    // Generando widgets de información
    this->statusWidget = new QWidget();

    this->resetConnection = new Button();
    this->resetConnection->setText("Reinicio de Conexión");

    // Generando labels
    this->statusWidgetInformation = new QWidget();

    this->serialPortWidget = new QWidget();
    this->baundRateWidget = new QWidget();
    this->fabricanteWidget = new QWidget();
    this->descriptionWidget = new QWidget();

    this->serialPortWidgetLayout = new QHBoxLayout();
    this->baundRateWidgetLayout = new QHBoxLayout();
    this->fabricanteWidgetLayout = new QHBoxLayout();
    this->descriptionWidgetLayout = new QHBoxLayout();

    this->serialPortLabel = new QLabel("Port:");
    this->baundRateLabel = new QLabel("Baud Rate:");
    this->fabricanteLabel = new QLabel("Fabricante:");
    this->descriptionLabel = new QLabel("Description:");

    this->serialPort = new QLabel("");
    this->baundRate = new QLabel("");
    this->fabricante = new QLabel("");
    this->description = new QLabel("");

    // Agregando los labels a la tabla
    this->serialPortWidgetLayout->addWidget(this->serialPortLabel);
    this->serialPortWidgetLayout->addWidget(this->serialPort);
    this->serialPortWidgetLayout->setContentsMargins(0,0,0,0);
    this->serialPortWidget->setLayout(this->serialPortWidgetLayout);

    this->baundRateWidgetLayout->addWidget(this->baundRateLabel);
    this->baundRateWidgetLayout->addWidget(this->baundRate);
    this->baundRateWidgetLayout->setContentsMargins(0,0,0,0);
    this->baundRateWidget->setLayout(this->baundRateWidgetLayout);

    this->fabricanteWidgetLayout->addWidget(this->fabricanteLabel);
    this->fabricanteWidgetLayout->addWidget(this->fabricante);
    this->fabricanteWidgetLayout->setContentsMargins(0,0,0,0);
    this->fabricanteWidget->setLayout(this->fabricanteWidgetLayout);

    this->descriptionWidgetLayout->addWidget(this->descriptionLabel);
    this->descriptionWidgetLayout->addWidget(this->description);
    this->descriptionWidgetLayout->setContentsMargins(0,0,0,0);
    this->descriptionWidget->setLayout(this->descriptionWidgetLayout);


    // Configurando los widgets de la informacion
    this->infoLayout = new QVBoxLayout();
    this->infoLayout->addWidget(this->serialPortWidget);
    this->infoLayout->addWidget(this->baundRateWidget);
    this->infoLayout->addWidget(this->fabricanteWidget);
    this->infoLayout->addWidget(this->descriptionWidget);
    this->infoLayout->setSpacing(0);

    this->infoLayout->setContentsMargins(0,0,0,0);
    this->statusWidgetInformation->setLayout(this->infoLayout);

    // Widget de boton e informacion
    this->statusWidget = new QWidget();
    this->horizontalLayout = new QHBoxLayout();

    this->horizontalLayout->addWidget(this->resetConnection);
    this->horizontalLayout->addWidget(this->statusWidgetInformation);

    this->horizontalLayout->setSpacing(40);
    this->statusWidget->setLayout(this->horizontalLayout);

    this->layout = new QVBoxLayout();

    this->layout->addWidget(this->statusTitle, 0, Qt::AlignHCenter);
    this->layout->addWidget(this->statusWidget);

    this->setLayout(layout);
    this->setMaximumSize(528,204);
}
