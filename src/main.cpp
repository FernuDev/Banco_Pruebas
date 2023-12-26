#include <iostream>
#include <QApplication>

#include "./Ui/Windows/MainWindow.h"

int main(int argc, char **argv){

    auto *app = new QApplication(argc, argv);
    std::cout<<"Hola Mundo"<<std::endl;

    auto *mainWindow = new MainWindow(1820, 980, "Banco Pruebas");

    mainWindow->show();

    return QApplication::exec();
}