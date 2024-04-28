//
// Created by fernudev on 4/28/24.
//

#ifndef BANCO_PRUEBAS_LOGIN_H
#define BANCO_PRUEBAS_LOGIN_H

#include <QLabel>
#include <QPixmap>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>

#include <string>

class Login : public QMainWindow{

    // Personal Data
    std::string email;
    std::string password;

    // Components
    QWidget *centralWidget;

    // Image login components
    QLabel *img{};

    // Login Form components
    QWidget *login{};
    QVBoxLayout *login_layout{};

    QWidget *login_input{};
    QVBoxLayout *login_input_layout{};
    QLabel *login_title{};
    QPushButton *login_btn{};
    QLineEdit *login_email{};
    QLineEdit *login_password{};

    // General Layout
    QHBoxLayout *general_layout{};

public:
    Login();
    void setImage();
    void setLoginForm();
    void setGlobalLayout();
    QPushButton *getLoginBtn();
};


#endif //BANCO_PRUEBAS_LOGIN_H
