cmake_minimum_required(VERSION 3.31)
project(ColaPrioridad)

set(CMAKE_CXX_STANDARD 20)

add_executable(ColaPrioridad main.cpp
        src/Elemento.hpp
        src/ColaPrioridad.cpp
        src/ColaPrioridad.hpp
        src/Utils.hpp)
