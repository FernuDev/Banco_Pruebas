#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QFileDialog>
#include <QDir>
#include <fstream>
#include <iostream>
#include <map>

class LinearChart : public QChartView {
public:
    LinearChart(QWidget* parent = nullptr)
        : QChartView(parent), series(new QLineSeries), axisX(new QValueAxis), axisY(new QValueAxis) {
        // Crear gráfico
        chart = new QChart();
        chart->addSeries(series);
        chart->setAxisX(axisX, series);
        chart->setAxisY(axisY, series);

        // Ajustes iniciales
        axisX->setTitleText("Tiempo (s)");
        axisY->setTitleText("Valor");

        // Establecer título predeterminado
        chart->setTitle("Gráfico de Sensores");

        // Establecer la vista del gráfico
        setChart(chart);

        // Asegurar que el gráfico ocupe el 100% de su espacio
        setRenderHint(QPainter::Antialiasing);
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    // Método para configurar el color de la línea
    void setLineColor(const QColor& color) {
        series->setColor(color);
    }

    // Método para establecer el título del gráfico
    void setChartTitle(const QString& title) {
        chart->setTitle(title);
    }

    // Método para agregar datos de prueba
    void addTestData() {
        for (double i = 0; i <= 10; i += 0.1) {
            double y = 10 * sin(i);  // Generando valores de prueba con la función seno
            series->append(i, y);
        }

        // Establecer los rangos del eje X e Y en función de los datos
        axisX->setRange(0, 10);
        axisY->setRange(-10, 10);
    }

    // Método para exportar los datos a CSV
    void exportToCSV() {
        std::ofstream engine;
        std::string data;

        QString path = QFileDialog::getExistingDirectory(this, "Guardar prueba", QDir::homePath());

        if (!path.isEmpty()) {
            for (auto point : series->points()) {
                data += std::to_string(point.x()) + "," + std::to_string(point.y()) + "\n";
            }

            std::string filePath = path.toStdString() + "/DataExport.csv";
            engine.open(filePath, std::fstream::out);
            engine << "Time,Value\n";
            engine << data;
            engine.close();
        } else {
            std::cout << "Selección cancelada por el usuario." << std::endl;
        }
    }

private:
    QChart* chart;
    QLineSeries* series;
    QValueAxis* axisX;
    QValueAxis* axisY;
};

