cmake_minimum_required(VERSION 3.31)
project(LinkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(LinkedList main.cpp
        src/NodoLista.hpp
        src/Elemento.hpp
        src/Lista.hpp
        src/BibliotecaLista.cpp
        src/BibliotecaLista.hpp
        src/Utils.hpp)
