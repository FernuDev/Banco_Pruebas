//
// Created by fernu on 1/5/24.
//

#ifndef BANCO_PRUEBAS_SERIALREADER_H
#define BANCO_PRUEBAS_SERIALREADER_H

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <utility>

#ifdef __linux__

// GNU/Linux Headers
#include <cerrno> // Contains Error integer and strerror() function
#include <unistd.h> // write(), read(), open(), close(), functions
#include <termios.h> // Contains POSIX terminal control definitions
#include <fcntl.h> // Contains file controls like O_RDWR

#endif

class SerialReader {
private:
    char *portName;
    int bandRate;
    int serial_port;
    float empuje;

    bool connection_enabled;
public:
    SerialReader(char *port, int bandRate)
    : portName(port), bandRate(bandRate), serial_port(0), empuje(0), connection_enabled(false)
    {
        #ifdef __linux__
            int code = this->setupLinuxReader();
            if(code==0){
                std::cout << "Correct Config" << std::endl;
                connection_enabled = true;
            }else {
                std::cout << "Error Config" << std::endl;
            }
        #elif _WIN32
            std::cout<<"Working on Windows system"<<std::endl;
        #else
            std::cout<<"Sorry your SO is not supported"<<std::endl;
        #endif
            std::cout<<"Finish Config Serial Connection"<<std::endl;
    }

    int setupLinuxReader();
    bool getConnectionStatus();
    [[nodiscard]] float readFromSerial() const;
    void closePort() const;
};


#endif //BANCO_PRUEBAS_SERIALREADER_H
