//
// Created by fernudev on 12/22/24.
//

#ifndef HEADER_H
#define HEADER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>

class Header final : public QWidget{

    QLabel *title;
    QLabel *subTitle;
    QLabel *logo;
    QPixmap *logoPix;

    QWidget *headerText;
    QVBoxLayout *headerLayoutText;
    QHBoxLayout *headerLayout;

public:
    explicit Header(QWidget *parent = nullptr);
};



#endif //HEADER_H
