//
// Created by Erasmo on 7/11/25.
//

#ifndef ARBOLESBINARIOS_FUNCIONESARBOL_HPP
#define ARBOLESBINARIOS_FUNCIONESARBOL_HPP

#include "Utils.hpp"
#include "BibliotecaArboles/ArbolBinario.hpp"

void construir(struct ArbolBinario &arbol);

bool esArbolVacio(struct ArbolBinario &arbol);

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

#endif //ARBOLESBINARIOS_FUNCIONESARBOL_HPP
