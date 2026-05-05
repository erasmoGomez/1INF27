//
// Created by Erasmo on 26/09/25.
//

#ifndef HANOIPILAS_HANOI_HPP
#define HANOIPILAS_HANOI_HPP
#include "Pila.hpp"

// Mueve n discos y **imprime cada paso y el estado global**.
void hanoiConImpresion(int n,
                       Pila &origen, Pila &auxiliar, Pila &destino,
                       char nombreOrigen, char nombreAux, char nombreDestino,
                       int &paso,
                       Pila &Aref, Pila &Bref, Pila &Cref);

#endif //HANOIPILAS_HANOI_HPP
