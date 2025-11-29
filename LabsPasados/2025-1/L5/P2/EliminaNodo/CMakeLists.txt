cmake_minimum_required(VERSION 4.0)
project(EliminaNodo)

set(CMAKE_CXX_STANDARD 20)

add_executable(EliminaNodo main.cpp
        src/Nodo.hpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Frame.hpp
        src/Pila.hpp)
