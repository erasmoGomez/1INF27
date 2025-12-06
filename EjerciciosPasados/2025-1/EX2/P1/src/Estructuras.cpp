//
// Created by erasmo on 11/27/25.
//

#include "Estructuras.hpp"
void inicializarCola(Cola &c) {
    c.frente = nullptr;
    c.final  = nullptr;
}

bool esColaVacia(const Cola &c) {
    return c.frente == nullptr;
}

void encolar(Cola &c, Nodo *n) {
    if (!n) return; // no encolamos nulos

    NodoCola *nuevo = new NodoCola;
    nuevo->nodo = n;
    nuevo->siguiente = nullptr;

    if (esColaVacia(c)) {
        c.frente = nuevo;
        c.final  = nuevo;
    } else {
        c.final->siguiente = nuevo;
        c.final = nuevo;
    }
}

// desencola y devuelve el puntero al nodo del árbol
Nodo* desencolar(Cola &c) {
    if (esColaVacia(c)) return nullptr;

    NodoCola *aux = c.frente;
    Nodo *n = aux->nodo;

    c.frente = aux->siguiente;
    if (c.frente == nullptr)
        c.final = nullptr;

    delete aux;
    return n;
}

Nodo* construirABB(int *a, int ini, int fin) {
    if (ini > fin) return nullptr;

    int mid = (ini + fin) / 2;

    Nodo *nodo = new Nodo;
    nodo->dato = a[mid];
    nodo->izq  = construirABB(a, ini, mid - 1);
    nodo->der  = construirABB(a, mid + 1, fin);

    return nodo;
}

void preorden(Nodo *raiz) {
    if (!raiz) return;
    cout << raiz->dato << " ";
    preorden(raiz->izq);
    preorden(raiz->der);
}

void imprimir_por_nivel(Nodo *raiz) {
    if (!raiz) return;

    Cola c;
    inicializarCola(c);

    encolar(c, raiz);

    while (!esColaVacia(c)) {
        // cantidad de nodos en este nivel
        int nivel = 0;

        // Primero contamos cuántos hay en el nivel actual
        NodoCola *aux = c.frente;
        while (aux) {
            nivel++;
            aux = aux->siguiente;
        }

        // Procesamos exactamente "nivel" nodos
        while (nivel--) {
            Nodo *n = desencolar(c);
            cout << n->dato << " ";

            if (n->izq) encolar(c, n->izq);
            if (n->der) encolar(c, n->der);
        }
        cout << endl; // salto de línea por nivel
    }
}

// (opcional) liberar memoria del árbol
void destruirArbol(Nodo *raiz) {
    if (raiz == nullptr) return;
    destruirArbol(raiz->izq);
    destruirArbol(raiz->der);
    delete raiz;
}