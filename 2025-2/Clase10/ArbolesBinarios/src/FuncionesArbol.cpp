//
// Created by Erasmo on 7/11/25.
//

#include "FuncionesArbol.hpp"

void construir(ArbolBinario &arbol) {
    arbol.raiz = nullptr;
}

bool esArbolVacio(ArbolBinario &arbol) {
    return arbol.raiz == nullptr;
}

bool esNodoVacio(struct NodoArbol *nodo) {
    return nodo == nullptr;
}

void plantarNodoArbolBinario(struct NodoArbol *& nodo,
                             struct NodoArbol *izq,
                             const struct ElementoArbol &elemento,
                             struct NodoArbol *der) {
    // RESERVA DE MEMORIA
    struct NodoArbol *nuevo = new struct NodoArbol;
    // HACER LAS CONEXIONES Y ASIGNACIONES
    nuevo->der = der;
    nuevo->izq = izq;
    nuevo->elemento = elemento;
    // HACEMOS ESCAPAR A NODO
    nodo = nuevo;
}

void imprimir_nodo(struct NodoArbol *nodo) {
    cout << setw(5) << nodo->elemento.valor;
}

void plantarArbolBinario(ArbolBinario &arbol,
                         const struct ArbolBinario &izq,
                         const struct ElementoArbol &elemento,
                         const struct ArbolBinario &der) {
    //Realizar el proceso a nivel de NODOS
    plantarNodoArbolBinario(arbol.raiz, izq.raiz, elemento, der.raiz);
}

void recorrer_in_order_recursivo(struct NodoArbol *nodo) {
    // HI RAIZ HD
    if (not esNodoVacio(nodo)) { //CB
        recorrer_in_order_recursivo(nodo->izq);
        imprimir_nodo(nodo);
        recorrer_in_order_recursivo(nodo->der);
    }
}

void recorrer_post_order_recursivo(struct NodoArbol *nodo) {
    // HI HD RAIZ
    if (not esNodoVacio(nodo)) { //CB
        recorrer_post_order_recursivo(nodo->izq);
        recorrer_post_order_recursivo(nodo->der);
        imprimir_nodo(nodo);
    }
}

void recorrer_pre_order_recursivo(struct NodoArbol *nodo) {
    // RAIZ HI HD
    if (not esNodoVacio(nodo)) { //CB
        imprimir_nodo(nodo);
        recorrer_pre_order_recursivo(nodo->izq);
        recorrer_pre_order_recursivo(nodo->der);
    }
}

void recorrer_in_order(ArbolBinario &arbol) {
    recorrer_in_order_recursivo(arbol.raiz);
}

void recorrer_post_order(ArbolBinario &arbol) {
    recorrer_post_order_recursivo(arbol.raiz);
}

void recorrer_pre_order(ArbolBinario &arbol) {
    recorrer_pre_order_recursivo(arbol.raiz);
}
