//
// Created by Erasmo on 10/11/25.
//
#include "Funciones.hpp"
int contar_combinaciones(ArbolBinario &arbol, int peso){
    return contar_combinaciones_recursivo(arbol.raiz, peso);
}

int contar_combinaciones_recursivo(NodoArbol *&nodo, int peso){
    if(esNodoVacio(nodo)) return 0;
    if(nodo->elemento.bit == 1) peso -= nodo->elemento.valor;
    if(esNodoHoja(nodo) and peso == 0) return 1;
    return  contar_combinaciones_recursivo(nodo->izq, peso) +
            contar_combinaciones_recursivo(nodo->der, peso);
}

