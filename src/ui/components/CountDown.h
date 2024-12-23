//
// Created by fernudev on 12/23/24.
//

#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Button.h"

class CountDown : public QWidget{
    private:
    QWidget* time;
    QLabel* minute;
    QLabel* separate;
    QLabel* seconds;
    QHBoxLayout* timeLayout;

    QWidget* timer;
    QLabel* title;
    QVBoxLayout* timerLayout;

    QWidget* btnWidget;
    Button* startBtn;
    Button* stopBtn;
    QHBoxLayout* btnLayout;

    QHBoxLayout* countDownLayout;

    public:
    explicit CountDown(QWidget *parent = nullptr);
};



#endif //COUNTDOWN_H
