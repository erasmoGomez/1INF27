//
// Created by Erasmo on 10/10/25.
//

#ifndef PILASLABERINTO_POSICION_HPP
#define PILASLABERINTO_POSICION_HPP
struct Posicion{
    int x;
    int y;
};

void constructor(struct Posicion & posicion, int x, int y);
int getX(struct Posicion posicion);
int getY(struct Posicion posicion);
#endif //PILASLABERINTO_POSICION_HPP
