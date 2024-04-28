//
// Created by fernudev on 4/28/24.
//

#include "Login.h"

void Login::setImage() {
    this->img = new QLabel();
    auto img_pixmap = QPixmap("/home/fernudev/Projects/Banco_Pruebas/src/Ui/Img/rocket_launch.png").scaled(600, 650);
    this->img->setPixmap(img_pixmap);
    this->img->setScaledContents(true);
    this->img->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->img->setParent(this->centralWidget);
}

void Login::setLoginForm() {
    // Init Widgets
    this->login = new QWidget();
    this->login_input = new QWidget();

    // Init Layouts
    this->login_layout = new QVBoxLayout();
    this->login_input_layout = new QVBoxLayout();

    // Login title
    this->login_title = new QLabel();
    this->login_title->setText("Login Antares Aeroespace");
    this->login_title->setStyleSheet("font-size: 24px; font-weight: bold;");
    this->login_title->setAlignment(Qt::AlignHCenter);
    this->login_title->setMaximumHeight(50);

    // Login input
    this->login_email = new QLineEdit();
    this->login_email->setPlaceholderText("Email");
    this->login_email->setTextMargins(15, 0, 0, 0);
    this->login_email->setMaximumSize((int)(this->login->width() * 0.5), 50);
    this->login_email->setStyleSheet("border-radius: 15px;");

    this->login_password = new QLineEdit();
    this->login_password->setPlaceholderText("Password");
    this->login_password->setTextMargins(15, 0, 0, 0);
    this->login_password->setEchoMode(QLineEdit::Password);
    this->login_password->setMaximumSize((int)(this->login->width()*0.5), 50);
    this->login_password->setStyleSheet("border-radius: 15px;");


    this->login_btn = new QPushButton();
    this->login_btn->setText("Login");
    this->login_btn->setMaximumSize((int)(this->login->width()*0.5), 50);
    this->login_btn->setStyleSheet("font-size: 18px; font-weight: bold; border-radius: 15px; background-color: #592da2");
    this->login_btn->setCursor(Qt::CursorShape::PointingHandCursor);


    this->login_input_layout->addWidget(this->login_email);
    this->login_input_layout->addWidget(this->login_password);
    this->login_input_layout->addWidget(this->login_btn);
    this->login_input_layout->setAlignment(Qt::AlignHCenter);
    this->login_input_layout->setSpacing(20);

    this->login_input->setMaximumHeight(300);
    this->login_input->setLayout(this->login_input_layout);

    this->login_layout->addWidget(this->login_title);
    this->login_layout->addWidget(this->login_input);
    this->login_layout->setAlignment(Qt::AlignHCenter);
    this->login_layout->setSpacing(0);
    this->login->setLayout(this->login_layout);
}

void Login::setGlobalLayout() {
    this->general_layout = new QHBoxLayout();
    this->general_layout->addWidget(this->img);
    this->general_layout->addWidget(this->login);
    this->general_layout->setContentsMargins(0,0,0,0);
    this->general_layout->setSpacing(0);
    this->centralWidget->setLayout(this->general_layout);
}

Login::Login() {
    this->centralWidget = new QWidget();
    this->setMinimumSize(160*7, 90*7);
    this->setMaximumSize(160*7, 90*7);

    this->centralWidget->resize(this->width(), this->height());
    this->setCentralWidget(this->centralWidget);
}

QPushButton* Login::getLoginBtn() {
    return this->login_btn;
}