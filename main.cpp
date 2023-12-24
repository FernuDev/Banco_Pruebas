#include <iostream>
#include <QApplication>
#include <QMainWindow>

int main(int arc, char **argv){

    auto *app = new QApplication(arc, argv);
    std::cout<<"Hola Mundo"<<std::endl;

    return QApplication::exec();
}