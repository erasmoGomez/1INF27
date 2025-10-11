//
// Created by Erasmo on 10/10/25.
//

#ifndef PILASLABERINTO_FUNCIONESPILAS_HPP
#define PILASLABERINTO_FUNCIONESPILAS_HPP
void construir(struct Pila & );
int longitud(const struct Pila & );
bool esPilaVacia(const struct Pila &);
void apilar(struct Pila &, struct Posicion posicion );
struct Posicion  desapilar(struct Pila &);
struct Posicion  cima(const struct Pila &);
void destruirPila(struct Pila &);
void imprimir(const struct Pila &);
#endif //PILASLABERINTO_FUNCIONESPILAS_HPP
