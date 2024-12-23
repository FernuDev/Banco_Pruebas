//
// Created by fernudev on 12/23/24.
//

#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QWidget>

class GraphView : public QWidget{
private:
    QLabel* presion;
    QLabel* empuje;
    QPixmap* presionPix;
    QPixmap* empujePix;
    QVBoxLayout* layout;
public:
    GraphView(QWidget *parent=nullptr);
};



#endif //GRAPHVIEW_H
