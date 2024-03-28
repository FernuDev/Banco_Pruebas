//
// Created by fernudev on 3/28/24.
//

#ifndef BANCO_PRUEBAS_MOTOR_H
#define BANCO_PRUEBAS_MOTOR_H

#include <iostream>
#include <string>
#include <utility>

class Motor {
private:
    std::string motorName;
    float diameter;
    float longitude;
    float mass;
public:
    Motor(std::string motor, float diameter, float longitude, float mass):
        motorName(std::move(motor)), diameter(diameter), longitude(longitude), mass(mass)
        {}
    Motor(){}

    float getDiameter();
    float getLongitude();
    float getMass();
    std::string getName();
};


#endif //BANCO_PRUEBAS_MOTOR_H
