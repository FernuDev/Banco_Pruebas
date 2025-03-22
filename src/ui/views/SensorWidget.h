#ifndef SENSORWIDGET_H
#define SENSORWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>

class SensorWidget : public QWidget {
    Q_OBJECT

public:
    explicit SensorWidget(QWidget* parent = nullptr);

private:
    QLabel* titleLabel;
    QLabel* pressureLabel;
    QLabel* thrustLabel;
    QLabel* ispLabel;
    QLabel* pressureUnitLabel;
    QLabel* thrustUnitLabel;
    QLabel* ispUnitLabel;
    QPushButton* exportButton;
    QPushButton* resetButton;
};

#endif // SENSORWIDGET_H
