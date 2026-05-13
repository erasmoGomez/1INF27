cmake_minimum_required(VERSION 3.31)
project(ReiniciaCola)

set(CMAKE_CXX_STANDARD 20)

add_executable(ReiniciaCola main.cpp
        Biblioteca/ElementoCola.h
        Biblioteca/funcionesCola.cpp
        Biblioteca/funcionesCola.h
        Biblioteca/NodoCola.h
        Biblioteca/ElementoPila.h
        Biblioteca/funcionesPila.cpp
        Biblioteca/funcionesPila.h
        Biblioteca/NodoPila.h
        Biblioteca/Pila.h
        Biblioteca/Elemento.h)
