//
// Created by fernudev on 3/21/25.
//

#ifndef STATUSBATTERY_H
#define STATUSBATTERY_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QProgressBar>

class StatusBattery : public QWidget{
public:
    QLabel *title;
    QLabel *labelBattery;
    QLabel *labelSignal;
    QProgressBar *progressBarBattery;
    QProgressBar *progressBarSignal;
    QVBoxLayout *layout;
public:
    explicit StatusBattery(QWidget *parent = nullptr);
};



#endif //STATUSBATTERY_H
