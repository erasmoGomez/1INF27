//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef PILA_NODOPILA_H
#define PILA_NODOPILA_H
#include "Elemento.h"
struct NodoPila {
    struct Elemento elemento; /*Dato que cambia por double, char, struct */
    struct NodoPila * siguiente; /*puntero a una variable de tipo struct Nodo*/
};
#endif //PILA_NODOPILA_H