//
// Created by Erasmo on 3/10/25.
//

#ifndef COLAPRIORIDAD_COLAPRIORIDAD_HPP
#define COLAPRIORIDAD_COLAPRIORIDAD_HPP

#include "Elemento.hpp"

struct NodoCola {
    Elemento elem;
    NodoCola *sig;
};

struct ColaPrioridad {
    // Lista única con 3 segmentos: [P1][P2][P3]
    NodoCola *head;   // frente total
    NodoCola *tail;   // final total

    // Fronteras de prioridad
    NodoCola *last1;  // último nodo de P1 (nullptr si no hay P1)
    NodoCola *last2;  // último nodo de P2 (nullptr si no hay P2)

    // Tamaños por prioridad (opcional pero útil)
    int size1;
    int size2;
    int size3;
};

// Construcción / destrucción
void construir(ColaPrioridad &cp);

void destruir(ColaPrioridad &cp);

// Estado
bool esVacia(const ColaPrioridad &cp);

int sizeTotal(const ColaPrioridad &cp);

// Encolar por prioridad: prio = 1, 2 o 3
void encolar(ColaPrioridad &cp, const Elemento &e, int prio);

// Desencolar del frente (respeta P1->P2->P3 implícitamente)
Elemento desencolar(ColaPrioridad &cp); // PRE: !esVacia(cp)

// Ver frente sin quitar (PRE: !esVacia(cp))
const Elemento &frente(const ColaPrioridad &cp);

#endif //COLAPRIORIDAD_COLAPRIORIDAD_HPP
