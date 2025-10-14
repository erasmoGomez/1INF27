//
// Created by Erasmo on 12/09/25.
//

#ifndef LINKEDLIST_BIBLIOTECALISTA_HPP
#define LINKEDLIST_BIBLIOTECALISTA_HPP

#include "Lista.hpp"
#include "Utils.hpp"

// Creación / destrucción
void lista_init(Lista& L);
void lista_destruir(Lista& L);

// Consulta
bool lista_vacia(const Lista& L);
int  lista_tam(const Lista& L);
NodoLista* lista_cabeza(const Lista& L); // nullptr si vacía
NodoLista* lista_cola(const Lista& L);   // nullptr si vacía

// Inserción al final (manteniendo circularidad)
void lista_push_back(Lista& L, int v);

// Utilidades para ronda
void lista_avanzar(NodoLista*& p, int pasos);       // avanza p en el anillo
int  lista_borrar_siguiente(Lista& L, NodoLista*& p); // borra p->sig y devuelve valor


#endif //LINKEDLIST_BIBLIOTECALISTA_HPP
