cmake_minimum_required(VERSION 3.31)
project(RobotPerforador)

set(CMAKE_CXX_STANDARD 20)

add_executable(RobotPerforador main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
