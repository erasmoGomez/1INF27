//
// Created by Erasmo on 12/09/25.
//

#ifndef LINKEDLIST_NODOLISTA_HPP
#define LINKEDLIST_NODOLISTA_HPP

#include "Elemento.hpp"

struct NodoLista {
    struct Elemento elemento;
    struct NodoLista *siguiente;
};
#endif //LINKEDLIST_NODOLISTA_HPP
