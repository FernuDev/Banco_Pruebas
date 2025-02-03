//
// Created by fernudev on 1/23/25.
//

#ifndef STATUSCONNECTION_H
#define STATUSCONNECTION_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "../components/Button.h"

class StatusConnection : public QWidget{
private:
    QLabel *statusTitle;
    Button *resetConnection;
    QWidget *statusWidget;

    QVBoxLayout *layout;
    QHBoxLayout *horizontalLayout;

    // Status serial port
    QWidget *statusWidgetInformation;

    QLabel *serialPortLabel;
    QLabel *baundRateLabel;
    QLabel *fabricanteLabel;
    QLabel *descriptionLabel;

    QWidget *serialPortWidget;
    QWidget *baundRateWidget;
    QWidget *fabricanteWidget;
    QWidget *descriptionWidget;

    QHBoxLayout *serialPortWidgetLayout;
    QHBoxLayout *baundRateWidgetLayout;
    QHBoxLayout *fabricanteWidgetLayout;
    QHBoxLayout *descriptionWidgetLayout;

    QLabel *serialPort;
    QLabel *baundRate;
    QLabel *fabricante;
    QLabel *description;

    QVBoxLayout *infoLayout;

public:
    StatusConnection(QWidget *parent = nullptr);
    void restoreConnection();
};



#endif //STATUSCONNECTION_H
