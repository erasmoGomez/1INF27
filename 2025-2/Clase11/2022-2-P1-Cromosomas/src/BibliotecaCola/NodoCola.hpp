//
// Created by Erasmo on 10/11/25.
//

#ifndef ARBOLESBINARIOSRECNIVELES_NODOCOLA_HPP
#define ARBOLESBINARIOSRECNIVELES_NODOCOLA_HPP

#include "../BibliotecaArboles/NodoArbol.hpp"

struct NodoCola {
    NodoArbol *nodo;      // apunta a un nodo del árbol
    NodoCola *siguiente;  // siguiente elemento en la cola
};
#endif //ARBOLESBINARIOSRECNIVELES_NODOCOLA_HPP
