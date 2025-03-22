#include "MainWindow.h"
#include "views/GraphView.h"
#include "views/StatusConnection.h"

MainWindow::MainWindow() {
    // Configuramos el tamaño inicial de la ventana y el título de la misma
    this->setFixedSize(1821, 900);
    this->setWindowTitle("Banco de Pruebas V3");

    // Iniciamos la apertura del puerto serial
    this->serialReader = new SerialReader();

    // General layout
    this->centralWidget = new QWidget();
    this->setCentralWidget(this->centralWidget);

    // Generando el header
    auto *header = new Header();
    auto *countDown = new CountDown();
    auto *statusView = new StatusView();
    auto *statusConnection = new StatusConnection();
    auto *statusBattery = new StatusBattery();
    auto *sensorWidget = new SensorWidget();
    auto *taraWidget = new TareWidget();

    // Content and information layout
    this->infoLayout = new QVBoxLayout();
    this->infoWidget = new QWidget();

    this->layout = new QVBoxLayout();  // Cambié QHBoxLayout a QVBoxLayout para que los gráficos estén arriba y abajo

    this->infoLayout->addWidget(header);
    this->infoLayout->addWidget(countDown);
    this->infoLayout->addWidget(statusView);

    // Connection section
    this->statusConnectionWidget = new QWidget();
    this->statusConnectionLayout = new QHBoxLayout();
    statusConnectionLayout->addWidget(statusBattery);
    statusConnectionLayout->addWidget(statusConnection);
    statusConnectionWidget->setLayout(statusConnectionLayout);
    this->infoLayout->addWidget(statusConnectionWidget);

    // Sensor and tara section
    this->sensorTaraWidget = new QWidget();
    this->sensorTaraLayout = new QHBoxLayout();
    sensorTaraLayout->addWidget(taraWidget);
    sensorTaraLayout->addWidget(sensorWidget);
    sensorTaraWidget->setLayout(sensorTaraLayout);
    this->infoLayout->addWidget(sensorTaraWidget);

    // FINAL SETTINGS
    this->infoWidget->setLayout(infoLayout);

    // Crear dos instancias de GraphView
    auto *graphViewTop = new GraphView();  // Gráfico superior
    auto *graphViewBottom = new GraphView();  // Gráfico inferior

    // Ajustar los títulos de los gráficos si es necesario
    graphViewTop->setChartTitle("Empuje (N)");
    graphViewBottom->setChartTitle("Presion (Pa)");

    // Añadir los gráficos a la layout principal (uno encima del otro)
    this->layout->addWidget(graphViewTop);   // Añadir gráfico superior
    this->layout->addWidget(graphViewBottom);  // Añadir gráfico inferior

    // Añadir infoWidget y el layout de los gráficos a la ventana principal
    this->centralLayout = new QHBoxLayout();  // Se mantiene QHBoxLayout para colocar la sección de info y gráficos
    this->centralLayout->addWidget(infoWidget);  // Añadir infoWidget
    this->centralLayout->addLayout(this->layout);  // Añadir layout con los gráficos

    this->centralWidget->setLayout(this->centralLayout);

    setStyleSheet("background-color: #2D2D2D;");
    this->show();
}
