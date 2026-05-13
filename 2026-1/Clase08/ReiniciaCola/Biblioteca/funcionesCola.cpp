//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "Cola.h"
#include "../Biblioteca/funcionesCola.h"
using namespace std;

void construir(struct Cola & colaTAD){
    colaTAD.inicio = nullptr;
    colaTAD.fin = nullptr;
}

void encolar(struct Cola &cola, const struct Elemento & elemento){
    struct NodoCola *nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = elemento;
    if(esColaVacia(cola)){
        cola.inicio = nuevo;
        cola.fin = nuevo;
    }
    else {
        cola.fin->siguiente = nuevo;
        cola.fin = nuevo;
    }
}

struct Elemento desencolar(struct Cola & colaTAD){
    struct NodoCola * pSale;
    struct Elemento elemento;
    pSale = colaTAD.inicio;
    colaTAD.inicio = colaTAD.inicio->siguiente;
    elemento = pSale->elemento;
    delete pSale;
    return elemento;
}

bool esColaVacia(const struct Cola & colaTAD){
    return colaTAD.inicio == nullptr;
}

void imprimir(const struct Cola & colaTAD) {
    if (esColaVacia(colaTAD)) {
        cout << "La cola esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoCola * recorrido = colaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despues del inicio*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.numero;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}