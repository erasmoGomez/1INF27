//
// Created by erasmo on 11/28/25.
//

#ifndef ELIMINANODO_FRAME_HPP
#define ELIMINANODO_FRAME_HPP
#include "Nodo.hpp"
struct Frame {
    Nodo* nodo;
    int estado;      // 0: bajar a izq, 1: bajar a der, 2: procesar
    Frame* sig;
};


#endif //ELIMINANODO_FRAME_HPP