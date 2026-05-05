//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal 

#ifndef LISTASIMPLEMENTEENLAZADA_LISTA_H
#define LISTASIMPLEMENTEENLAZADA_LISTA_H
#include "NodoLista.h"
struct Lista {
    struct NodoLista * lista;
    struct NodoLista * inicio_par;
    struct NodoLista * fim_par;
    struct NodoLista * inicio_inpar;
    struct NodoLista * fim_inpar;
};
#endif //LISTASIMPLEMENTEENLAZADA_LISTA_H