//
// Created by fernudev on 3/21/25.
//

#ifndef TAREWIDGET_H
#define TAREWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>


class TareWidget : public QWidget{
public:
    explicit TareWidget(QWidget* parent = nullptr);

private:
    QLabel* titleLabel;
    QPushButton* tareButton;
    QLabel* valueLabel;
    QLabel* conversionFactorLabel;
};



#endif //TAREWIDGET_H
