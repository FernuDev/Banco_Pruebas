//
// Created by fernudev on 12/23/24.
//

#ifndef STATUSLED_H
#define STATUSLED_H

#include <QLabel>
#include <QWidget>
#include <QGraphicsDropShadowEffect>


class StatusLed : public QLabel{
    private:
    QGraphicsDropShadowEffect* shadow;
    public:
    StatusLed(QWidget *parent = nullptr);
    void setActive();
    void setInactive();
};



#endif //STATUSLED_H
