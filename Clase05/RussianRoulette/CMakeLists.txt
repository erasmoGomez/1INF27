cmake_minimum_required(VERSION 3.31)
project(RussianRoulette)

set(CMAKE_CXX_STANDARD 20)

add_executable(RussianRoulette main.cpp
        src/NodoLista.hpp
        src/Elemento.hpp
        src/Lista.hpp
        src/BibliotecaLista.cpp
        src/BibliotecaLista.hpp
        src/Utils.hpp
        src/RussianRoulette.cpp
        src/RussianRoulette.hpp)

