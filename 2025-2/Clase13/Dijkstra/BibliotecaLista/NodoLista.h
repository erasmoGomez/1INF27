//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef LISTASIMPLEMENTEENLAZADA_NODOLISTA_H
#define LISTASIMPLEMENTEENLAZADA_NODOLISTA_H
#include "ElementoLista.h"
struct NodoLista {
    struct ElementoLista elemento;
    struct NodoLista * siguiente;  //  insertar aristas
    struct NodoLista * abajo;                // insertar vertices
};
#endif //LISTASIMPLEMENTEENLAZADA_NODOLISTA_H