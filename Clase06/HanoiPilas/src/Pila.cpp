//
// Created by Erasmo on 26/09/25.
//

#include <iostream>
#include <stdexcept>
#include "Pila.hpp"
#include "FuncionesPila.hpp"

using namespace std;

/*constructor de Pila*/
void construir(struct Pila &pilaTAD) {
    pilaTAD.inicio = nullptr;
}

/*Determina si la pila esta vacía*/
bool esPilaVacia(const struct Pila &pilaTAD) {
    return pilaTAD.inicio == nullptr;
}

/* Push, añade un elemento a la parte superior de la pila */
void apilar(struct Pila &pilaTAD, const struct ElementoPila &elemento) {
    struct NodoPila *nuevo;
    nuevo = new NodoPila;
    nuevo->elemento = elemento;
    nuevo->siguiente = pilaTAD.inicio;
    pilaTAD.inicio = nuevo;
}

/* Pop, elimina un elemento de la parte superior de la pila*/
struct ElementoPila desapilar(struct Pila &pilaTAD) {
    if (esPilaVacia(pilaTAD)) {
        throw runtime_error("desapilar() en pila vacia");
    }
    struct NodoPila *nodoSale;
    struct ElementoPila elemento;
    elemento = pilaTAD.inicio->elemento;
    nodoSale = pilaTAD.inicio;
    pilaTAD.inicio = pilaTAD.inicio->siguiente;
    delete nodoSale;
    return elemento;
}

void imprimir(const struct Pila &pilaTAD) {
    if (esPilaVacia(pilaTAD)) {
        cout << "[]";
    } else {
        struct NodoPila *recorrido = pilaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";
        while (recorrido != nullptr) {
            /*Este artificio coloca las comas después del inicio*/
            if (not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.numero;
            recorrido = recorrido->siguiente;
        }
        cout << "]";
    }
}

/* Opcional: inspeccionar sin retirar */
ElementoPila cima(const struct Pila &pilaTAD) {
    if (esPilaVacia(pilaTAD)) {
        throw runtime_error("cima() en pila vacia");
    }
    return pilaTAD.inicio->elemento;
}

/* Opcional: liberar toda la memoria */
void destruir(struct Pila &pilaTAD) {
    while (!esPilaVacia(pilaTAD)) {
        (void) desapilar(pilaTAD);
    }
}
