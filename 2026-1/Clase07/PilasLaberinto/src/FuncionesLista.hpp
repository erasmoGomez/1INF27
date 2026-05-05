//
// Created by Erasmo on 10/10/25.
//

#ifndef PILASLABERINTO_FUNCIONESLISTA_HPP
#define PILASLABERINTO_FUNCIONESLISTA_HPP
void construir(struct Lista &);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void insertarAlInicio(struct Lista &, struct Posicion posicion);
void insertarAlFinal(struct Lista &, struct Posicion posicion);

struct Nodo * crearNodo(struct Posicion elemento, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Posicion retornaCabeza(const struct Lista & lista);

void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista &);
#endif //PILASLABERINTO_FUNCIONESLISTA_HPP
