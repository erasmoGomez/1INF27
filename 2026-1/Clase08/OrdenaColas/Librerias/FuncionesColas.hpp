//
// Created by erasmo on 5/11/26.
//

#ifndef ORDENACOLAS_FUNCIONESCOLAS_HPP
#define ORDENACOLAS_FUNCIONESCOLAS_HPP
#include "Utils.hpp"
#include "Estructuras.hpp"
void ordenarec(struct Cola & cola, int n);

void construir(struct Cola & cola);
bool esColaVacia(const struct Cola & cola);
void encolar(struct Cola & cola, int elemento);
int desencolar(struct Cola & cola);
int longitud(const struct Cola & cola);
void imprime(const struct Cola & cola);
void destruirCola(struct Cola & cola);

void construir(struct Lista &);

void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista &, int);
void insertarAlFinal(struct Lista &, int);
void insertarEnOrden(struct Lista &, int);

struct Nodo * crearNodo(int elemento, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int);
struct Nodo * seEncuentra(const struct Lista &, int);
int retornaCabeza(const struct Lista &);
void insertarencola(struct Lista & tad, int elemento);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaNodo(struct Lista &, int);
void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista &);

void destruir_cola_chevere(struct Cola & cola);

void ordenar_cola_iterativo(struct Cola & cola);

#endif //ORDENACOLAS_FUNCIONESCOLAS_HPP