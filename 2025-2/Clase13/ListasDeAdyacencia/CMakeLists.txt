cmake_minimum_required(VERSION 3.31.6)
project(ListasDeAdyacencia)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListasDeAdyacencia main.cpp
        BibliotecaLista/Lista.h
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/NodoLista.h)
