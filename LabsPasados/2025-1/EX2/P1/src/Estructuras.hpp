//
// Created by erasmo on 11/27/25.
//

#ifndef P1_ESTRUCTURAS_HPP
#define P1_ESTRUCTURAS_HPP
#include "Utils.hpp"

// ===== Árbol =====
struct Nodo {
    int dato;
    Nodo *izq;
    Nodo *der;
};

// ===== Cola para recorrido por niveles =====
struct NodoCola {
    Nodo *nodo; // apunta a un nodo del árbol
    NodoCola *siguiente;
};

struct Cola {
    NodoCola *frente;
    NodoCola *final;
};

void inicializarCola(Cola &c);

bool esColaVacia(const Cola &c);

void encolar(Cola &c, Nodo *n);

Nodo *desencolar(Cola &c);

Nodo *construirABB(int a[], int ini, int fin);

void preorden(Nodo *raiz);

void imprimir_por_nivel(Nodo *raiz);

void destruirArbol(Nodo *raiz);
#endif //P1_ESTRUCTURAS_HPP
