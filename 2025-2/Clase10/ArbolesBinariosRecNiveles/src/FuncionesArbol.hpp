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

int altura(NodoArbol *nodo);

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

void insertar_por_nivel(ArbolBinario &arbol_nivel, int *arr, int n);

NodoArbol* crearNodo(int valor);

void imprimir_nivel(NodoArbol *nodo, int nivel);

void recorrido_por_niveles_recursivo_salto(ArbolBinario &arbol);

void imprimir_ramas(NodoArbol *nodo, int nivel);

void imprimir_arbol_horizontal(NodoArbol *raiz);

void imprimir_nivel_grafico(NodoArbol *nodo, int nivel, bool imprimirNull);

void imprimir_arbol_grafico(NodoArbol* raiz);

#endif //ARBOLESBINARIOS_FUNCIONESARBOL_HPP
