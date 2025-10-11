cmake_minimum_required(VERSION 3.31)
project(PilasLaberinto)

set(CMAKE_CXX_STANDARD 20)

add_executable(PilasLaberinto main.cpp
        src/Pila.cpp
        src/Pila.hpp
        src/Lista.hpp
        src/Nodo.hpp
        src/Posicion.hpp
        src/FuncionesPilas.hpp
        src/FuncionesLista.hpp
        src/FuncionesLaberinto.cpp
        src/FuncionesLaberinto.hpp
        src/FuncionesPosicion.cpp
        src/FuncionesLista.cpp)
