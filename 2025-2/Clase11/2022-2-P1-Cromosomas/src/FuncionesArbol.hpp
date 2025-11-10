//
// Created by Erasmo on 7/11/25.
//

#ifndef ARBOLESBINARIOS_FUNCIONESARBOL_HPP
#define ARBOLESBINARIOS_FUNCIONESARBOL_HPP

#include "Utils.hpp"
#include "BibliotecaArboles/ArbolBinario.hpp"
#include "FuncionesCola.hpp"

void construir(struct ArbolBinario &arbol);

bool esArbolVacio(struct ArbolBinario &arbol);

bool esNodoVacio(struct NodoArbol *nodo);

bool esNodoHoja(NodoArbol *nodo);

void plantarArbolBinario(ArbolBinario &arbol,
                         const struct ArbolBinario &izq,
                         const struct ElementoArbol &elemento,
                         const struct ArbolBinario &der);

void plantarNodoArbolBinario(struct NodoArbol *&nodo,
                             struct NodoArbol *izq,
                             const struct ElementoArbol &elemento,
                             struct NodoArbol *der);

void recorrer_in_order(struct ArbolBinario &arbol);

void recorrer_pre_order(struct ArbolBinario &arbol);

void recorrer_post_order(struct ArbolBinario &arbol);

void recorrido_por_niveles(ArbolBinario &arbol);

void bfs_rec(Cola &cola);

void recorrido_por_niveles_recursivo(ArbolBinario &arbol);

ArbolBinario construir_arbol_arreglo(int *arr, int n);

void insertar_elemento_arreglo_arbol(NodoArbol *&nodo, int valor, int bit = 0);

#endif //ARBOLESBINARIOS_FUNCIONESARBOL_HPP
