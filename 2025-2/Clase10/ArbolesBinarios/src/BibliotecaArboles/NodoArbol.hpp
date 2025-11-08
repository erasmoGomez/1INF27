//
// Created by Erasmo on 7/11/25.
//

#ifndef ARBOLESBINARIOS_NODOARBOL_HPP
#define ARBOLESBINARIOS_NODOARBOL_HPP
#include "ElementoArbol.hpp"
struct NodoArbol{
    struct ElementoArbol elemento;
    struct NodoArbol* izq;
    struct NodoArbol* der;
};
#endif //ARBOLESBINARIOS_NODOARBOL_HPP
