//
// Created by Erasmo on 19/09/25.
//

#ifndef STACK_NODOPILA_HPP
#define STACK_NODOPILA_HPP

#include "ElementoPila.hpp"

struct NodoPila {
    struct ElementoPila elemento; /*Dato que cambia por double, char, struct */
    struct NodoPila *siguiente; /*puntero a una variable de tipo struct Nodo*/
};
#endif //STACK_NODOPILA_HPP
