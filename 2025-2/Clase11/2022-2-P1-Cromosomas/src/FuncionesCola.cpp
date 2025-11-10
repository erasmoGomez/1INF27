//
// Created by Erasmo on 10/11/25.
//

#include "FuncionesCola.hpp"
void construir_cola(Cola &cola) {
    cola.frente = nullptr;
    cola.final = nullptr;
}

bool esColaVacia(Cola &cola) {
    return cola.frente == nullptr;
}

void encolar(Cola &cola, NodoArbol* nodo) {
    NodoCola* nuevo = new NodoCola;
    nuevo->nodo = nodo;
    nuevo->siguiente = nullptr;

    if (cola.final == nullptr) { // cola vacía
        cola.frente = cola.final = nuevo;
    } else {
        cola.final->siguiente = nuevo;
        cola.final = nuevo;
    }
}

NodoArbol* desencolar(Cola &cola) {
    if (esColaVacia(cola)) return nullptr;

    NodoCola* temp = cola.frente;
    NodoArbol* nodo = temp->nodo;

    cola.frente = cola.frente->siguiente;
    if (cola.frente == nullptr) cola.final = nullptr;

    delete temp;
    return nodo;
}
