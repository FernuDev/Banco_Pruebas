//
// Created by fernudev on 12/23/24.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <string>

class Button final : public QPushButton {
private:
    QGraphicsDropShadowEffect* shadow;
public:
    explicit Button(QWidget* parent = nullptr);
};



#endif //BUTTON_H
