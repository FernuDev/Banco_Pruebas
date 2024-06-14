//
// Created by fernudev on 4/28/24.
//

#ifndef BANCO_PRUEBAS_BANCO_PRUEBAS_H
#define BANCO_PRUEBAS_BANCO_PRUEBAS_H

#include "Ui/Windows/Login.h"
#include "Ui/Windows/MainWindow.h"

#include <QPushButton>
#include <QCoreApplication>
#include <QObject>

class Banco_Pruebas : public QObject {
private:
    Login *login_screen;
    MainWindow *main_window;
public:
    Banco_Pruebas(){
        this->login_screen = new Login();
        this->login_screen->setImage();
        this->login_screen->setLoginForm();
        this->login_screen->setGlobalLayout();
        this->login_screen->show();

        this->main_window = new MainWindow(1820, 980, "Banco Pruebas");

        this->login();
    }

    void login();
};


#endif //BANCO_PRUEBAS_BANCO_PRUEBAS_H
