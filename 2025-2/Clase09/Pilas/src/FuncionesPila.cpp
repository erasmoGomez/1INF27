//
// Created by Erasmo on 19/09/25.
//

#include "FuncionesPila.hpp"

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
        cout << "La pila esta vacia no se puede mostrar" << endl;
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
        cout << "]" << endl;
    }
}

ElementoPila cima(Pila p) {
    return p.inicio->elemento;
}