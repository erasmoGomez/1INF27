cmake_minimum_required(VERSION 3.31)
project(Pilas)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pilas main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/ElementoPila.hpp
        src/FuncionesPila.hpp
        src/NodoPila.hpp
        src/FuncionesPila.cpp
        src/Pila.hpp
        src/Utils.hpp)
