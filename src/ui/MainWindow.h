//
// Created by fernudev on 12/22/24.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

// Components
#include "views/Header.h"
#include "views/GraphView.h"
#include "components/CountDown.h"
#include "views/StatusView.h"
#include "views/StatusBattery.h"
#include "views/SensorWidget.h"
#include "components/TareWidget.h"

// Core Components
#include "../core/SerialReader.h"

class MainWindow : public QMainWindow {
private:
    QWidget* centralWidget;
    QHBoxLayout* centralLayout;  // Modificado para usar un layout horizontal para la ventana principal
    QVBoxLayout* layout;         // Layout que contiene los gráficos en vertical (arriba y abajo)
    QVBoxLayout* infoLayout;     // Layout para la información (header, countdown, status, etc.)
    QWidget* infoWidget;

    QWidget *statusConnectionWidget;
    QHBoxLayout *statusConnectionLayout;

    QWidget *sensorTaraWidget;
    QHBoxLayout *sensorTaraLayout;

    SerialReader* serialReader{};

    // Nuevas instancias para los gráficos
    GraphView* graphViewTop;     // Gráfico superior
    GraphView* graphViewBottom;  // Gráfico inferior

public:
    MainWindow();
};

#endif // MAINWINDOW_H
