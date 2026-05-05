//
// Created by Erasmo on 10/10/25.
//
#include "Posicion.hpp"


void constructor(struct Posicion & posicion, int x, int y){
    posicion.x = x;
    posicion.y = y;
}

int getX(struct Posicion posicion){
    return posicion.x;
}

int getY(struct Posicion posicion){
    return posicion.y;
}
