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

void plantarNodoArbolBinario(struct NodoArbol *&nodo,
                             struct NodoArbol *izq,
                             const struct ElementoArbol &elemento,
                             struct NodoArbol *der) {
    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->der = der;
    nuevo->izq = izq;
    nuevo->elemento = elemento;
    nodo = nuevo;
}

void imprimir_nodo(struct NodoArbol *nodo){
    cout<<nodo->elemento.valor<<endl;
}

void plantarArbolBinario(ArbolBinario &arbol,
                        const struct ArbolBinario &izq,
                        const struct ElementoArbol &elemento,
                        const struct ArbolBinario &der) {
    plantarNodoArbolBinario(arbol.raiz, izq.raiz, elemento, der.raiz);
}
void recorrer_in_order_recursivo(struct NodoArbol * nodo ){
    if(not esNodoVacio(nodo)){
        recorrer_in_order_recursivo(nodo->izq);
        imprimir_nodo(nodo);
        recorrer_in_order_recursivo(nodo->der);
    }
}

void recorrer_in_order(ArbolBinario &arbol) {
    recorrer_in_order_recursivo(arbol.raiz);
}
