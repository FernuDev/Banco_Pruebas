#include <iostream>
#include <QApplication>

#include "./Banco_Pruebas.h"

int main(int argc, char **argv){

    auto *app = new QApplication(argc, argv);

    auto *Banco = new Banco_Pruebas();


    return QApplication::exec();
}
