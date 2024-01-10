//
// Created by fernu on 1/5/24.
//
#include "SerialReader.h"

const size_t BUFFER_SIZE = 256;

float SerialReader::readFromSerial() const {

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof (buffer));

    int num_bytes = read(this->serial_port, &buffer, BUFFER_SIZE);

    if(num_bytes > 0){

        float value = 0.0;
        try{
            value = std::stof(buffer);
        }catch (const std::invalid_argument &e){
            std::cerr << "Error al convertir un dato: " << e.what() << std::endl;
            value = 0.0;
        }
        std::cout<<"Empuje: "<<value<<std::endl;
        return value;

    } else if (num_bytes < 0) {
        std::cerr << "Error " << errno << " from read: " << strerror(errno) << std::endl;
    }

    return 0.0;

};

int SerialReader::setupLinuxReader() {
    std::cout<<"Working on Linux system"<<std::endl;

    size_t port_size = strlen(this->portName);

    if(port_size > 3) {
        std::cout << "Port selected: " << portName << std::endl;
        std::cout << "Connecting..." << std::endl;

        serial_port = open(this->portName, O_RDWR);

        // Checking if the port opens correctly

        if (serial_port < 0) {
            std::cout << "\nError" << errno << "from open " << portName << ", returned " << strerror(errno)
                      << std::endl;
            return 1;
        }

        // Config the port
        struct termios tty{};

        // Read in existing settings and handle any error
        if (tcgetattr(serial_port, &tty) != 0) {
            std::cout << "Error in " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
            return 1;
        }

        // Config the cflags and modes for I/O stream in the serial port
        tty.c_cflag &= ~PARENB;
        tty.c_cflag &= ~CSTOPB;
        tty.c_lflag &= ~CSIZE;
        tty.c_cflag |= CS8;
        tty.c_cflag |= CREAD | CLOCAL;

        // Config the lflags
        tty.c_lflag &= ~ICANON;
        tty.c_lflag &= ~ECHO;
        tty.c_lflag &= ~ECHOE;
        tty.c_lflag &= ~ECHONL;
        tty.c_lflag &= ~ISIG;
        tty.c_lflag &= ~(IXON|IXOFF|IXANY);
        tty.c_lflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);

        // Config the oflags
        tty.c_oflag &= ~OPOST;
        tty.c_oflag &= ~ONLCR;

        tty.c_cc[VTIME] = static_cast<cc_t>(0.1);
        tty.c_cc[VMIN] = 0;

        // Set the I/O band rate

        switch (bandRate) {
            case 9600:
                cfsetispeed(&tty, B9600);
                cfsetospeed(&tty, B9600);
                break;
            case 1200:
                cfsetispeed(&tty, B1200);
                cfsetospeed(&tty, B1200);
            default:
                cfsetispeed(&tty, B9600);
                cfsetospeed(&tty, B9600);
                break;
        }

    }
    return 0;
}

void SerialReader::closePort() const {
    close(this->serial_port);
}