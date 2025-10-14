//
// Created by Erasmo on 19/09/25.
//

#ifndef STACK_FUNCIONESPILA_HPP
#define STACK_FUNCIONESPILA_HPP
#include "Utils.hpp"
#include "Pila.hpp"

void construir(struct Pila & pilaTAD);
bool esPilaVacia(const struct Pila & pilaTAD);
void apilar(struct Pila & pilaTAD, const struct ElementoPila & elemento);
struct ElementoPila desapilar(struct Pila & pilaTAD);
void imprimir(const struct Pila & pilaTAD);


#endif //STACK_FUNCIONESPILA_HPP
