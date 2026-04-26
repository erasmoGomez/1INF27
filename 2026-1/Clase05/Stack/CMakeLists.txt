cmake_minimum_required(VERSION 3.31)
project(Stack)

set(CMAKE_CXX_STANDARD 20)

add_executable(Stack main.cpp
        src/Utils.hpp
        src/ElementoPila.hpp
        src/NodoPila.hpp
        src/Pila.hpp
        src/FuncionesPila.cpp
        src/FuncionesPila.hpp)
