//
// Created by fernudev on 4/28/24.
//

#include "Banco_Pruebas.h"

void Banco_Pruebas::login() {
    auto *login_btn = this->login_screen->getLoginBtn();

    connect(login_btn, &QPushButton::clicked, this, [=](){
       this->login_screen->close();
       this->main_window->show();
    });

}
