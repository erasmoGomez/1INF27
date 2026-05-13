cmake_minimum_required(VERSION 4.0)
project(FusionarPilas)

set(CMAKE_CXX_STANDARD 20)

add_executable(FusionarPilas main.cpp
		BibliotecaPila/Pila.h
		BibliotecaPila/funcionesPila.cpp
		BibliotecaPila/funcionesPila.h
		BibliotecaPila/NodoPila.h
		BibliotecaPila/ElementoPila.h
		funciones.cpp
		funciones.h)
