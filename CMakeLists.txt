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

file(COPY ${CMAKE_SOURCE_DIR}/src/Ui/Img DESTINATION ${CMAKE_BINARY_DIR} )

add_executable(Banco_Pruebas
        src/main.cpp
        src/Ui/Windows/MainWindow.cpp
        src/Ui/Windows/MainWindow.h
        src/Ui/Components/LinearChart.cpp
        src/Ui/Components/LinearChart.h
        src/Ui/Components/Button.cpp
        src/Ui/Components/Button.h
        src/Tools/Uuid.h
        src/Tools/SerialReader.h
        src/Tools/SerialReader.cpp
        src/Tools/SerialReader.cpp
        src/Tools/Motor.cpp
        src/Tools/Motor.h
        src/Ui/Windows/Login.cpp
        src/Ui/Windows/Login.h
        src/Ui/Windows/Login.h
        src/Banco_Pruebas.cpp
        src/Banco_Pruebas.h
)

target_link_libraries(Banco_Pruebas PUBLIC 
                    Qt6::Widgets
                    Qt6::Core   
                    Qt6::Gui
                    Qt6::Charts
                    Qt6::SerialPort
                    )