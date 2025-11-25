//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal 

#ifndef ARBOLBINARIO_NODOARBOLBINARIO_H
#define ARBOLBINARIO_NODOARBOLBINARIO_H
#include "ElementoArbolBinario.h"
struct NodoArbolBinario {
    struct ElementoArbolBinario elemento;
    struct NodoArbolBinario * padre; // nuevo para el lab4
    struct NodoArbolBinario * izquierda;
    struct NodoArbolBinario * derecha;
};
#endif //ARBOLBINARIO_NODOARBOLBINARIO_H