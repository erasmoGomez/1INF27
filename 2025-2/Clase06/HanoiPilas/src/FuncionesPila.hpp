//
// Created by Erasmo on 26/09/25.
//

#ifndef HANOIPILAS_FUNCIONESPILA_HPP
#define HANOIPILAS_FUNCIONESPILA_HPP

#include "Pila.hpp"

// Construcción / consulta
void construir(struct Pila &pilaTAD);

bool esPilaVacia(const struct Pila &pilaTAD);

// Operaciones básicas
void apilar(struct Pila &pilaTAD, const struct ElementoPila &elemento);

struct ElementoPila desapilar(struct Pila &pilaTAD);

// Utilitarios
void imprimir(const struct Pila &pilaTAD);

// (Opcional pero útil) cima y destruir
ElementoPila cima(const struct Pila &pilaTAD);

void destruir(struct Pila &pilaTAD);

#endif //HANOIPILAS_FUNCIONESPILA_HPP
