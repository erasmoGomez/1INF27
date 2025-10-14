cmake_minimum_required(VERSION 3.31)
project(Queues)

set(CMAKE_CXX_STANDARD 20)

add_executable(Queues main.cpp
        src/Cola.cpp
        src/Cola.hpp
        src/FuncionesColas.cpp
        src/FuncionesColas.hpp
        src/NodoCola.hpp
        src/ElementoCola.hpp
        src/Utils.hpp)
