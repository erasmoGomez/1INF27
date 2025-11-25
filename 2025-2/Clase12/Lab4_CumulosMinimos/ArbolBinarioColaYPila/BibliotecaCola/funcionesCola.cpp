//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "Cola.h"
#include "funcionesCola.h"
#include "../BibliotecaArbolBinario/NodoArbolBinario.h"
using namespace std;

void construir(struct Cola & colaTAD){
    colaTAD.inicio = nullptr;
    colaTAD.fin = nullptr;
    colaTAD.longitud = 0;
}

/*devuelve la longitud de la cola*/
int longitud(const struct Cola & colaTAD) {
    return colaTAD.longitud;
}

void encolar(struct Cola &colaTAD, struct NodoArbolBinario * elemento){
    struct NodoCola * nuevo;
    nuevo = new NodoCola{};
    nuevo->nodo = elemento;
    if(esColaVacia(colaTAD)){
        colaTAD.inicio = nuevo;
        colaTAD.fin = nuevo;
    }
    else {
        colaTAD.fin->siguiente = nuevo;
        colaTAD.fin = nuevo;
    }
    colaTAD.longitud++;
}

struct NodoArbolBinario * desencolar(struct Cola & colaTAD){
    struct NodoCola * pSale;
    struct NodoArbolBinario * elemento;
    pSale = colaTAD.inicio;
    colaTAD.inicio = colaTAD.inicio->siguiente;
    elemento = pSale->nodo;
    colaTAD.longitud--;
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
            //cout << recorrido->nodo;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

void destruir(struct Cola & colaTAD) {

    while ( not esColaVacia(colaTAD)) {
        struct NodoArbolBinario * elemento = desencolar(colaTAD);
    }

    colaTAD.inicio = nullptr;
    colaTAD.fin = nullptr;
    colaTAD.longitud = 0;

}