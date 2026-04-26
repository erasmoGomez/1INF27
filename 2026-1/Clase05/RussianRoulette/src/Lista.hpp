//
// Created by Erasmo on 12/09/25.
//

#ifndef LINKEDLIST_LISTA_HPP
#define LINKEDLIST_LISTA_HPP

#include "NodoLista.hpp"

struct Lista {
    NodoLista* cola; // apunta al ÚLTIMO nodo; la cabeza es cola->sig
    int tam;
};
#endif //LINKEDLIST_LISTA_HPP
