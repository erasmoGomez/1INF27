cmake_minimum_required(VERSION 3.31)
project(MergeSort)

set(CMAKE_CXX_STANDARD 20)

add_executable(MergeSort main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
