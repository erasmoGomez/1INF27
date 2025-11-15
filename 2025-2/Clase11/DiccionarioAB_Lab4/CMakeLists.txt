cmake_minimum_required(VERSION 3.31.6)
project(DiccionarioAB_Lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(DiccionarioAB_Lab4 main.cpp
        BibliotecaArbolBinario/ElementoArbolBinario.h
        BibliotecaArbolBinario/ArbolBinario.h
        BibliotecaArbolBinario/NodoArbolBinario.h
        BibliotecaArbolBinario/funcionesArbolBinario.cpp
        BibliotecaArbolBinario/funcionesArbolBinario.h
                                                    )
