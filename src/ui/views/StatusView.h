//
// Created by fernudev on 12/23/24.
//

#ifndef STATUSVIEW_H
#define STATUSVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

#include "../components/StatusLed.h"

class StatusView : public QWidget{
private:
    StatusLed* standBy{};
    StatusLed* countDown{};
    StatusLed* prueba{};
    StatusLed* finPrueba{};

    QHBoxLayout* layout{};
public:
    explicit StatusView(QWidget *parent = nullptr);
};



#endif //STATUSVIEW_H
