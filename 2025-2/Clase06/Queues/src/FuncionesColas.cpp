//
// Created by Erasmo on 26/09/25.
//

#include "FuncionesColas.hpp"

void construir(struct Cola &cola) {
    cola.inicio = nullptr;
    cola.fin = nullptr;
    cola.longitud = 0;
}

bool esColaVacia(const struct Cola &cola) {
    return cola.inicio == nullptr;
}

void encolar(Cola &cola, const ElementoCola &e) {
    struct NodoCola *nuevo_nodo;
    nuevo_nodo = new NodoCola{};
    nuevo_nodo->elemento = e;
    if(esColaVacia(cola)){
        cola.inicio = nuevo_nodo;
        cola.fin = nuevo_nodo;
    }
    else{
        cola.fin->siguiente = nuevo_nodo;
        cola.fin = nuevo_nodo;
    }
    cola.longitud++;
}

void imprimir(const struct Cola &cola) {
    if(esColaVacia(cola)){
        cout<<"La cola esta vacia :("<<endl;
    }else{
        struct NodoCola* recorrido = cola.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout<<"[";
        while(recorrido!= nullptr){
            if( not estaImprimiendoLaCabeza)
                cout<<",";
            estaImprimiendoLaCabeza = 0;
            cout<<recorrido->elemento.codigo;
            recorrido = recorrido->siguiente;
        }
        cout<<"]"<<endl;
    }
}


