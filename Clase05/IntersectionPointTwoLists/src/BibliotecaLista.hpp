//
// Created by Erasmo on 12/09/25.
//

#ifndef LINKEDLIST_BIBLIOTECALISTA_HPP
#define LINKEDLIST_BIBLIOTECALISTA_HPP

#include "Lista.hpp"
#include "Utils.hpp"

void construir(struct Lista &l);

bool esListaVacia(const struct Lista &l);

void insertar_inicio(struct Lista &l, struct Elemento &e);

struct NodoLista *obtener_nodo_final(struct Lista &l);

void insertar_final(struct Lista &l, struct Elemento &e);

void insertar_ordenado(struct Lista &l, struct Elemento &e);

void eliminar_nodo(struct Lista &l, struct Elemento &e);

void destruir(struct Lista &l);

void imprimir(const struct Lista &listaTAD);

#endif //LINKEDLIST_BIBLIOTECALISTA_HPP
