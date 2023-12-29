//
// Created by fernu on 12/28/23.
//

#ifndef BANCO_PRUEBAS_UUID_CPP
#define BANCO_PRUEBAS_UUID_CPP

#include <random>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>

namespace uuid {
    class UUID {
    private:
        static std::random_device              rd;
    public:
        std::string generate_uid(){
            auto now = std::chrono::system_clock::now();
            auto time_t = std::chrono::system_clock::to_time_t(now);

            std::tm tm_time = *std::localtime(&time_t);

            std::stringstream ss;

            ss << std::put_time(&tm_time, "%Y-%m-%d-%H:%M:%S");

            return ss.str();
        }
    };


}

#endif //BANCO_PRUEBAS_UUID_CPP
