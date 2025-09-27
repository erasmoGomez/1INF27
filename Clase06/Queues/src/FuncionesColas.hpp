//
// Created by Erasmo on 26/09/25.
//

#ifndef QUEUES_FUNCIONESCOLAS_HPP
#define QUEUES_FUNCIONESCOLAS_HPP

#include "Cola.hpp"

void construir(struct Cola &cola);

bool esColaVacia(const struct Cola &cola);

void encolar(struct Cola &cola, const struct ElementoCola &e);

void imprimir(const struct Cola &cola);

#endif //QUEUES_FUNCIONESCOLAS_HPP
