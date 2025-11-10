cmake_minimum_required(VERSION 3.31)
project(2022-2-P1-Cromosomas)

set(CMAKE_CXX_STANDARD 20)

add_executable(2022-2-P1-Cromosomas main.cpp
        src/BibliotecaArboles/ElementoArbol.hpp
        src/BibliotecaArboles/NodoArbol.hpp
        src/BibliotecaArboles/ArbolBinario.hpp
        src/FuncionesArbol.cpp
        src/FuncionesArbol.hpp
        src/Utils.hpp
        src/BibliotecaCola/NodoCola.hpp
        src/BibliotecaCola/Cola.hpp
        src/FuncionesCola.cpp
        src/FuncionesCola.hpp
        src/Funciones.cpp
        src/Funciones.hpp)
