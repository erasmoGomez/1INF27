//
// Created by Erasmo on 7/11/25.
//

#include "FuncionesArbol.hpp"

void construir(ArbolBinario &arbol) {
    arbol.raiz = nullptr;
}

bool esArbolVacio(ArbolBinario &arbol) {
    return arbol.raiz == nullptr;
}

bool esNodoVacio(struct NodoArbol *nodo) {
    return nodo == nullptr;
}

int altura(NodoArbol *nodo) {
    if (nodo == nullptr) return 0;
    int alt_izq = altura(nodo->izq);
    int alt_der = altura(nodo->der);
    return 1 + (alt_izq > alt_der ? alt_izq : alt_der);
}

void plantarNodoArbolBinario(struct NodoArbol *&nodo,
                             struct NodoArbol *izq,
                             const struct ElementoArbol &elemento,
                             struct NodoArbol *der) {
    // RESERVA DE MEMORIA
    struct NodoArbol *nuevo = new struct NodoArbol;
    // HACER LAS CONEXIONES Y ASIGNACIONES
    nuevo->der = der;
    nuevo->izq = izq;
    nuevo->elemento = elemento;
    // HACEMOS ESCAPAR A NODO
    nodo = nuevo;
}

void imprimir_nodo(struct NodoArbol *nodo) {
    cout << setw(5) << nodo->elemento.valor;
}

void plantarArbolBinario(ArbolBinario &arbol,
                         const struct ArbolBinario &izq,
                         const struct ElementoArbol &elemento,
                         const struct ArbolBinario &der) {
    //Realizar el proceso a nivel de NODOS
    plantarNodoArbolBinario(arbol.raiz, izq.raiz, elemento, der.raiz);
}

/* Depth-First Search
 * Profundidad (pre/in/post order)
 */
void recorrer_in_order_recursivo(struct NodoArbol *nodo) {
    // HI RAIZ HD
    if (not esNodoVacio(nodo)) { //CB
        recorrer_in_order_recursivo(nodo->izq);
        imprimir_nodo(nodo);
        recorrer_in_order_recursivo(nodo->der);
    }
}

void recorrer_post_order_recursivo(struct NodoArbol *nodo) {
    // HI HD RAIZ
    if (not esNodoVacio(nodo)) { //CB
        recorrer_post_order_recursivo(nodo->izq);
        recorrer_post_order_recursivo(nodo->der);
        imprimir_nodo(nodo);
    }
}

void recorrer_pre_order_recursivo(struct NodoArbol *nodo) {
    // RAIZ HI HD
    if (not esNodoVacio(nodo)) { //CB
        imprimir_nodo(nodo);
        recorrer_pre_order_recursivo(nodo->izq);
        recorrer_pre_order_recursivo(nodo->der);
    }
}

void recorrer_in_order(ArbolBinario &arbol) {
    recorrer_in_order_recursivo(arbol.raiz);
}

void recorrer_post_order(ArbolBinario &arbol) {
    recorrer_post_order_recursivo(arbol.raiz);
}

void recorrer_pre_order(ArbolBinario &arbol) {
    recorrer_pre_order_recursivo(arbol.raiz);
}


/*
 * Breadth-First Search
 * Es un algoritmo fundamental para recorrer estructuras de tipo grafo o árbol,
 * visitando los nodos nivel por nivel, empezando desde la raíz.
 *      A
       / \
      B   C
     / \   \
    D   E   F
El recorrido BFS sería:
A → B → C → D → E → F

Cómo funciona?
 * Coloca la raíz del árbol en una cola.
 * Mientras la cola no esté vacía:
   * Extrae el nodo del frente de la cola (lo “visitas”).
   * Encola sus hijos izquierdo y derecho, si existen.
 * Repite hasta vaciar la cola.
El uso de la cola (FIFO) garantiza que los nodos se visiten en orden de aparición por niveles.
 */


void recorrido_por_niveles(ArbolBinario &arbol) {
    if (esArbolVacio(arbol)) return;

    Cola cola;
    construir_cola(cola);
    encolar(cola, arbol.raiz); //* Coloca la raíz del árbol en una cola.

    while (!esColaVacia(cola)) { // * Repite hasta vaciar la cola.
        NodoArbol *actual = desencolar(cola); //   * Extrae el nodo del frente de la cola (lo “visitas”).
        imprimir_nodo(actual); //Visitar
        //Encola sus hijos izquierdo y derecho, si existen.
        if (!esNodoVacio(actual->izq))
            encolar(cola, actual->izq);
        if (!esNodoVacio(actual->der))
            encolar(cola, actual->der);
    }
}

void bfs_rec(Cola &cola) {
    if (esColaVacia(cola)) return;

    NodoArbol *actual = desencolar(cola);
    imprimir_nodo(actual);

    if (!esNodoVacio(actual->izq)) encolar(cola, actual->izq);
    if (!esNodoVacio(actual->der)) encolar(cola, actual->der);

    bfs_rec(cola); // recursión de cola
}

void recorrido_por_niveles_recursivo(ArbolBinario &arbol) {
    if (esArbolVacio(arbol)) return;
    Cola cola;
    construir_cola(cola);
    encolar(cola, arbol.raiz);
    bfs_rec(cola);
}

NodoArbol *crearNodo(int valor) {
    NodoArbol *nuevo = new NodoArbol;
    nuevo->elemento.valor = valor;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}


void insertar_por_nivel(ArbolBinario &arbol, int *a, int n) {
    construir(arbol);
    for (int i = 0; i < n; i++) {
        int valor = a[i];

        // Caso 1: árbol vacío → primera inserción es la raíz
        if (arbol.raiz == nullptr) {
            arbol.raiz = crearNodo(valor);
            continue;
        }

        // Crear cola para BFS
        Cola cola;
        construir_cola(cola);

        // Encolar la raíz
        encolar(cola, arbol.raiz);

        // BFS hasta encontrar el PRIMER lugar vacío
        while (!esColaVacia(cola)) {
            NodoArbol *actual = desencolar(cola);

            // Intentar insertar como hijo izquierdo
            if (actual->izq == nullptr) {
                actual->izq = crearNodo(valor);
                break;
            } else {
                encolar(cola, actual->izq);
            }

            // Intentar insertar como hijo derecho
            if (actual->der == nullptr) {
                actual->der = crearNodo(valor);
                break;
            } else {
                encolar(cola, actual->der);
            }
        }
    }
}

void imprimir_nivel(NodoArbol *nodo, int nivel) {
    if (nodo == nullptr) return;

    if (nivel == 1) {
       cout << nodo->elemento.valor << ' ';
    } else {
        imprimir_nivel(nodo->izq, nivel - 1);
        imprimir_nivel(nodo->der, nivel - 1);
    }
}

void recorrido_por_niveles_recursivo_salto(ArbolBinario &arbol) {
    if (arbol.raiz == nullptr) return;

    int h = altura(arbol.raiz);
    for (int nivel = 1; nivel <= h; nivel++) {
        imprimir_nivel(arbol.raiz, nivel); // imprime todos los nodos de ese nivel
        std::cout << '\n';               // salto de línea entre niveles
    }
}

void imprimir_arbol_grafico_rec(NodoArbol *nodo, int espacio) {
    if (nodo == nullptr) return;

    // separación entre niveles
    espacio += 6;

    // primero imprimir rama derecha
    imprimir_arbol_grafico_rec(nodo->der, espacio);

    // imprimir nodo actual con sangría
    std::cout << std::endl;
    for (int i = 6; i < espacio; i++) std::cout << ' ';
    std::cout << nodo->elemento.valor << "\n";

    // luego imprimir rama izquierda
    imprimir_arbol_grafico_rec(nodo->izq, espacio);
}


void imprimir_arbol_grafico(NodoArbol *raiz) {
    imprimir_arbol_grafico_rec(raiz, 0);
}

void imprimir_nivel_grafico(NodoArbol *nodo, int nivel, bool imprimirNull) {
    if (nodo == nullptr) return;

    if (nivel == 1) {
        cout <<nodo->elemento.valor << "   ";
    } else {
        imprimir_nivel_grafico(nodo->izq, nivel - 1, imprimirNull);
        imprimir_nivel_grafico(nodo->der, nivel - 1, imprimirNull);
    }
}

void imprimir_arbol_horizontal(NodoArbol *raiz) {
    if (raiz == nullptr) return;

    int h = altura(raiz);

    for (int nivel = 1; nivel <= h; nivel++) {

        // sangría para centrar
        for (int i = 0; i < (h - nivel) * 3.5; i++)
            cout << ' ';

        // imprimir nodos reales del nivel
        imprimir_nivel_grafico(raiz, nivel, true);
        cout << "\n";

        // imprimir ramas si no es el último nivel
        if (nivel < h) {
            for (int i = 0; i < (h - nivel) * 3; i++)
                cout << ' ';

            imprimir_ramas(raiz, nivel);
            cout << "\n";
        }
    }
}

void imprimir_ramas(NodoArbol *nodo, int nivel) {
    if (nodo == nullptr) return;

    if (nivel == 1) {
        if (nodo->izq != nullptr) cout << "/ ";
        if (nodo->der != nullptr) cout << "\\ ";
    } else {
        imprimir_ramas(nodo->izq, nivel - 1);
        imprimir_ramas(nodo->der, nivel - 1);
    }
}
