#include "GraphView.h"

GraphView::GraphView(QWidget *parent) : QWidget(parent), seriesRed(new QLineSeries), axisX(new QValueAxis), axisY(new QValueAxis)
{
    // Inicializar el gráfico
    chart = new QChart();
    chart->addSeries(seriesRed);  // Solo añadimos la serie roja

    // Configurar los ejes
    axisX->setRange(0, 10);
    axisY->setRange(-10, 10);

    // Agregar los ejes al gráfico usando addAxis
    chart->addAxis(axisX, Qt::AlignBottom);  // Eje X en la parte inferior
    chart->addAxis(axisY, Qt::AlignLeft);    // Eje Y en la parte izquierda

    seriesRed->attachAxis(axisX);  // Asociamos la serie con el eje X
    seriesRed->attachAxis(axisY);  // Asociamos la serie con el eje Y

    // Crear el QChartView y añadirlo al layout
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Configurar el fondo del gráfico a color #1D1D1D
    chart->setBackgroundBrush(QBrush(QColor("#1D1D1D")));  // Fondo del gráfico en #1D1D1D
    chartView->setBackgroundBrush(QBrush(QColor("#1D1D1D")));  // Fondo del chartview en #1D1D1D

    chartView->setRenderHint(QPainter::Antialiasing);

    // Layout para contener el gráfico
    auto *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    setLayout(layout);

    // Añadir datos de prueba
    addTestData();

    // Configurar la apariencia de los ejes
    axisX->setLabelsBrush(QBrush(Qt::white));  // Etiquetas blancas para el eje X
    axisY->setLabelsBrush(QBrush(Qt::white));  // Etiquetas blancas para el eje Y

    // Configurar el título del gráfico y su color
    chart->setTitle("Gráfico de Prueba");
    chart->setTitleBrush(QBrush(Qt::white));  // Título en blanco

    // Establecer el color de las líneas de la cuadrícula
    axisX->setGridLineVisible(false); // No mostrar las líneas verticales
    axisY->setGridLineVisible(true);  // Mostrar las líneas horizontales
}

void GraphView::addTestData() const
{
    // Añadir algunos datos de prueba (en este caso, usando la función seno)
    for (double i = 0; i <= 10; i += 0.1) {
        double yRed = 10 * sin(i);  // Generando valores de prueba para la serie roja
        seriesRed->append(i, yRed);
    }

    // Ajustar los rangos de los ejes en función de los datos
    axisX->setRange(0, 10);
    axisY->setRange(-10, 10);
}

void GraphView::setLineColor(const QColor& color) const
{
    // Solo configuramos el color de la línea roja
    seriesRed->setColor(color);
}

void GraphView::setChartTitle(const QString& title) const
{
    chart->setTitle(title);
}
