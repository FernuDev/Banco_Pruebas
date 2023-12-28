//
// Created by fernu on 12/27/23.
//

#ifndef BANCO_PRUEBAS_BUTTON_H
#define BANCO_PRUEBAS_BUTTON_H

#include <QPushButton>
#include <string>
#include <QWidget>

class Button : public QPushButton{
public:
    Button(QWidget *parent, std::string &Text){
        this->setParent(parent);
        this->setText(QString::fromStdString(Text));
        this->setCursor(Qt::PointingHandCursor);
        this->setStyleSheet("font-size: 14px; font-weight: regular");
    }

    Button(QWidget *parent, QString Text) {
        this->setParent(parent);
        this->setText(Text);
        this->setCursor(Qt::PointingHandCursor);
        this->setStyleSheet("font-size: 14px; font-weight: regular");
    }

};


#endif //BANCO_PRUEBAS_BUTTON_H
