//
// Created by Erasmo on 10/10/25.
//

#ifndef PILASLABERINTO_NODO_HPP
#define PILASLABERINTO_NODO_HPP
#include "Posicion.hpp"
/*Nodo esta formado por Elemento y un puntero al siguiente Nodo*/
struct Nodo {
    struct Posicion posicion;
    //int elemento; /*Dato que cambia por double, char, struct Elemento*/
    struct Nodo * siguiente; /*puntero a una variable de tipo struct Nodo*/
};
#endif //PILASLABERINTO_NODO_HPP
