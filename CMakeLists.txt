cmake_minimum_required(VERSION 3.27)

project(Banco_Pruebas
        VERSION 1.0
        DESCRIPTION "Banco de pruebas para motores Antares Aerospace"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets Charts SerialPort REQUIRED)

file(COPY ${CMAKE_SOURCE_DIR}/src/assets DESTINATION ${CMAKE_BINARY_DIR} )

add_executable(Banco_Pruebas
        src/main.cpp
        src/ui/MainWindow.cpp
        src/ui/MainWindow.h
        src/ui/components/LinearChart.cpp
        src/ui/components/LinearChart.h
        src/core/SerialReader.cpp
        src/core/SerialReader.h
        src/ui/views/Header.cpp
        src/ui/views/Header.h
        src/ui/views/GraphView.cpp
        src/ui/views/GraphView.h
        src/ui/components/CountDown.cpp
        src/ui/components/CountDown.h
        src/ui/components/Button.cpp
        src/ui/components/Button.h
        src/ui/views/StatusView.cpp
        src/ui/views/StatusView.h
        src/ui/components/StatusLed.cpp
        src/ui/components/StatusLed.h
        src/ui/views/StatusConnection.cpp
        src/ui/views/StatusConnection.h
        src/ui/views/StatusBattery.cpp
        src/ui/views/StatusBattery.h
        src/ui/views/SensorWidget.cpp
        src/ui/views/SensorWidget.h
        src/ui/components/TareWidget.cpp
        src/ui/components/TareWidget.h
)

target_link_libraries(Banco_Pruebas PUBLIC 
                    Qt6::Widgets
                    Qt6::Core   
                    Qt6::Gui
                    Qt6::Charts
                    Qt6::SerialPort
                    )