cmake_minimum_required(VERSION 4.0.2)
project(CuadrigasFinal)

set(CMAKE_CXX_STANDARD 20)

add_executable(CuadrigasFinal main.cpp
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/Lista.h
        BibliotecaLista/NodoLista.h)
