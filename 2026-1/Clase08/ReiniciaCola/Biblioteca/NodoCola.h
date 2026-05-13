//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_NODOCOLA_H
#define COLA_NODOCOLA_H
#include "Elemento.h"

struct NodoCola {
    struct Elemento elemento;
    NodoCola * siguiente;
};
#endif //COLA_NODOCOLA_H