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

// Core Components
#include "../core/SerialReader.h"

class MainWindow : public QMainWindow {
    private:
        QWidget* centralWidget;
        QHBoxLayout* layout;
        QVBoxLayout* infoLayout;
        QWidget* infoWidget;

        SerialReader* serialReader{};
    public:
    MainWindow();
};



#endif //MAINWINDOW_H
