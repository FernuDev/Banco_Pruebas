#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>

class GraphView : public QWidget
{
    Q_OBJECT

public:
    explicit GraphView(QWidget *parent = nullptr);
    void addTestData() const;
    void setLineColor(const QColor& color) const;
    void setChartTitle(const QString& title) const;

private:
    QChart *chart;
    QLineSeries *seriesRed;  // Solo la serie roja
    QValueAxis *axisX;
    QValueAxis *axisY;
};

#endif // GRAPHVIEW_H
