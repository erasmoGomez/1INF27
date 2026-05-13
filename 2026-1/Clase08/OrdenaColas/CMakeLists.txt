cmake_minimum_required(VERSION 4.0)
project(OrdenaColas)

set(CMAKE_CXX_STANDARD 20)

add_executable(OrdenaColas main.cpp
        Librerias/FuncionesColas.cpp
        Librerias/FuncionesColas.hpp
        Librerias/Estructuras.hpp
        Librerias/Utils.hpp)
