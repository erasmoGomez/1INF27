//
// Created by erasmo on 11/28/25.
//

#include "Funciones.hpp"
// Crea un nuevo nodo
Nodo* crearNodo(int cod) {
    Nodo* nuevo = new Nodo;
    nuevo->codigo = cod;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}
// Inserta en ABB
Nodo* insertarABB(Nodo* raiz, int cod) {
    if (raiz == nullptr) return crearNodo(cod);
    if (cod < raiz->codigo)
        raiz->izq = insertarABB(raiz->izq, cod);
    else
        raiz->der = insertarABB(raiz->der, cod);
    return raiz;
}

// Impresión en inorden
void imprimirInOrden(Nodo* raiz) {
    if (raiz == nullptr) return;
    imprimirInOrden(raiz->izq);
    cout << raiz->codigo << " ";
    imprimirInOrden(raiz->der);
}

//=========================================
// PILA ADICIONAL
//=========================================

void inicializarPila(Pila &p) {
    p.cima = nullptr;
}

bool pilaVacia(Pila &p) {
    return p.cima == nullptr;
}

void apilar(Pila &p, Nodo* nodo, int estado) {
    Frame* nuevo = new Frame;
    nuevo->nodo = nodo;
    nuevo->estado = estado;
    nuevo->sig = p.cima;
    p.cima = nuevo;
}

void desapilar(Pila &p) {
    if (p.cima == nullptr) return;
    Frame* aux = p.cima;
    p.cima = p.cima->sig;
    delete aux;
}

Frame* tope(Pila &p) {
    return p.cima;
}

//====================================================
// ELIMINAR HIJOS ÚNICOS HOJA (FUNCIÓN ITERATIVA O(n))
//====================================================

// Estrategia:
// Recorremos el ABB en postorden de manera ITERATIVA usando una pila propia.
// Para cada nodo, cuando se procesa (ya se procesaron sus hijos),
// si tiene solo hijo izquierdo o solo hijo derecho, y ese hijo es hoja,
// se elimina dicho hijo. Al hacerlo en postorden, si un padre pasa a ser
// hoja y a la vez es hijo único de su propio padre, este último podrá
// eliminarlo cuando le toque procesarse. Se garantiza complejidad O(n)
// porque cada nodo se apila y desapila solo una vez.

void eliminarHijosUnicos(Nodo* raiz) {
    if (raiz == nullptr) return;

    Pila pila;
    inicializarPila(pila);

    // Iniciamos un "simulador" de recursión para postorden
    apilar(pila, raiz, 0);

    while (!pilaVacia(pila)) {
        Frame* f = tope(pila); //No estoy desapilado estoy peekeando
        Nodo* padre = f->nodo;

        if (f->estado == 0) {
            // Bajar por la izquierda
            f->estado = 1; //Cambio el estado
            if (padre->izq != nullptr)
                apilar(pila, padre->izq, 0);
        }
        else if (f->estado == 1) {
            // Bajar por la derecha
            f->estado = 2;
            if (padre->der != nullptr)
                apilar(pila, padre->der, 0);
        }
        else {
            // estado == 2 → procesar el nodo en postorden

            // CASO: solo hijo izquierdo
            if (padre->izq != nullptr && padre->der == nullptr) {
                Nodo* hijo = padre->izq;
                // Si el hijo es hoja, se elimina
                if (hijo->izq == nullptr && hijo->der == nullptr) {
                    delete hijo;
                    padre->izq = nullptr;
                }
            }
            // CASO: solo hijo derecho
            else if (padre->der != nullptr && padre->izq == nullptr) {
                Nodo* hijo = padre->der;
                // Si el hijo es hoja, se elimina
                if (hijo->izq == nullptr && hijo->der == nullptr) {
                    delete hijo;
                    padre->der = nullptr;
                }
            }
            // Si tiene dos hijos o ninguno, no se elimina nada aquí
            desapilar(pila);
        }
    }
}

//=========================================
// LIBERAR MEMORIA DEL ÁRBOL (opcional)
//=========================================

void liberarABB(Nodo *raiz) {
    if (raiz == nullptr) return;
    liberarABB(raiz->izq);
    liberarABB(raiz->der);
    delete raiz;
}