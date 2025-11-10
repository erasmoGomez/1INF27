cmake_minimum_required(VERSION 3.31)
project(ArbolesBinariosRecNiveles)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArbolesBinarios main.cpp
        src/BibliotecaArboles/ElementoArbol.hpp
        src/BibliotecaArboles/NodoArbol.hpp
        src/BibliotecaArboles/ArbolBinario.hpp
        src/FuncionesArbol.cpp
        src/FuncionesArbol.hpp
        src/Utils.hpp
        src/BibliotecaCola/NodoCola.hpp
        src/BibliotecaCola/Cola.hpp
        src/FuncionesCola.cpp
        src/FuncionesCola.hpp)
