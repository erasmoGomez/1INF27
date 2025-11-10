//
// Created by Erasmo on 10/11/25.
//

#ifndef INC_2022_2_P1_CROMOSOMAS_FUNCIONES_HPP
#define INC_2022_2_P1_CROMOSOMAS_FUNCIONES_HPP

#include "./BibliotecaArboles/NodoArbol.hpp"
#include "FuncionesArbol.hpp"

int contar_combinaciones(ArbolBinario &arbol, int peso);

int contar_combinaciones_recursivo(NodoArbol *&nodo, int peso);

#endif //INC_2022_2_P1_CROMOSOMAS_FUNCIONES_HPP
