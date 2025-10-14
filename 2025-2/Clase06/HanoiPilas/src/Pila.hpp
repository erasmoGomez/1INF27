//
// Created by Erasmo on 26/09/25.
//

#ifndef HANOIPILAS_PILA_HPP
#define HANOIPILAS_PILA_HPP

struct ElementoPila {
    int numero;   // representa el tamaño del disco
};

struct NodoPila {
    ElementoPila elemento;
    NodoPila* siguiente;
};

struct Pila {
    NodoPila* inicio; // tope de la pila
};

#endif //HANOIPILAS_PILA_HPP
