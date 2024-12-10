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

# file(COPY ${CMAKE_SOURCE_DIR}/src/Ui/Img DESTINATION ${CMAKE_BINARY_DIR} )

add_executable(Banco_Pruebas
        src/main.cpp
)

target_link_libraries(Banco_Pruebas PUBLIC 
                    Qt6::Widgets
                    Qt6::Core   
                    Qt6::Gui
                    Qt6::Charts
                    Qt6::SerialPort
                    )