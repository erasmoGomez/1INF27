//
// Created by erasmo on 11/28/25.
//

#ifndef ELIMINANODO_FUNCIONES_HPP
#define ELIMINANODO_FUNCIONES_HPP
#include "Utils.hpp"
#include "Pila.hpp"

Nodo *crearNodo(int cod);

Nodo *insertarABB(Nodo *raiz, int cod);

void imprimirInOrden(Nodo *raiz);

void eliminarHijosUnicos(Nodo *raiz);

void liberarABB(Nodo *raiz);

#endif //ELIMINANODO_FUNCIONES_HPP
