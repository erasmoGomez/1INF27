//
// Created by erasmo on 5/11/26.
//

#ifndef ORDENACOLAS_ESTRUCTURAS_HPP
#define ORDENACOLAS_ESTRUCTURAS_HPP
struct Nodo {
    int elemento; /*Dato que cambia por double, char, struct */
    struct Nodo * siguiente; /*puntero a una variable de tipo struct Nodo*/
};

struct Lista {
    struct Nodo * cabeza; /*apunta al inicio de la lista*/
    struct Nodo * cola;
    int longitud; /*guarda la longitud de la lista*/
};

struct Pila{
    struct Lista lista;
};

struct Cola{
    struct Lista lista;
};
#endif //ORDENACOLAS_ESTRUCTURAS_HPP