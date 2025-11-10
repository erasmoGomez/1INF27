//
// Created by Erasmo on 10/11/25.
//

#ifndef ARBOLESBINARIOSRECNIVELES_FUNCIONESCOLA_HPP
#define ARBOLESBINARIOSRECNIVELES_FUNCIONESCOLA_HPP
#include "BibliotecaCola/Cola.hpp"
void construir_cola(Cola &cola);
bool esColaVacia(Cola &cola);
void encolar(Cola &cola, NodoArbol* nodo);
NodoArbol* desencolar(Cola &cola);
#endif //ARBOLESBINARIOSRECNIVELES_FUNCIONESCOLA_HPP
