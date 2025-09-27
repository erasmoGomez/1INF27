cmake_minimum_required(VERSION 3.31)
project(HanoiPilas)

set(CMAKE_CXX_STANDARD 20)

add_executable(HanoiPilas main.cpp
        src/Hanoi.cpp
        src/Hanoi.hpp
        src/Pila.cpp
        src/Pila.hpp
        src/FuncionesPila.hpp)
