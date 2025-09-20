//
// Created by Erasmo on 12/09/25.
//

#include "BibliotecaLista.hpp"

void lista_init(Lista& L) { L.cola = nullptr; L.tam = 0; }

bool lista_vacia(const Lista& L) { return L.cola == nullptr; }
int  lista_tam(const Lista& L)   { return L.tam; }

NodoLista* lista_cabeza(const Lista& L) {
    if (!L.cola) return nullptr;
    return L.cola->sig;
}
NodoLista* lista_cola(const Lista& L) { return L.cola; }

void lista_push_back(Lista& L, int v) {
    NodoLista* n = new NodoLista;
    n->valor = v;
    if (!L.cola) {
        n->sig = n;      // primer nodo: apunta a sí mismo
        L.cola = n;
        L.tam = 1;
        return;
    }
    n->sig = L.cola->sig; // cabeza actual
    L.cola->sig = n;      // enlazar después de cola
    L.cola = n;           // nuevo último
    L.tam++;
}

void lista_destruir(Lista& L) {
    if (!L.cola) return;
    // romper el anillo para recorrer una sola vez
    NodoLista* cabeza = L.cola->sig;
    L.cola->sig = nullptr;

    NodoLista* p = cabeza;
    while (p) {
        NodoLista* q = p->sig;
        delete p;
        p = q;
    }
    L.cola = nullptr;
    L.tam = 0;
}
