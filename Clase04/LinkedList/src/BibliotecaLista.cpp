//
// Created by Erasmo on 12/09/25.
//

#include "BibliotecaLista.hpp"

void construir(struct Lista &l) {
    //Inicializar
    l.head = nullptr;
    // l.tail = nullptr;
    l.size = 0;
}

bool esListaVacia(struct Lista &l) {
    // l.head == nullptr and l.tail == nullptr;
    return l.head == nullptr;
}

void insertar_inicio(struct Lista &l, struct Elemento &e) {
    //Creacion Nodo
    struct NodoLista *nuevo_nodo;
    //Reservar Memoria
    nuevo_nodo = new struct NodoLista;
    //Asignacion
    nuevo_nodo->elemento = e;

    //insertar al inicio
    nuevo_nodo->siguiente = l.head;
    l.head = nuevo_nodo;
}

struct NodoLista *obtener_nodo_final(struct Lista &l) {
    struct NodoLista *anterior = nullptr;
    struct NodoLista *recorrido = l.head;

    while (recorrido != nullptr) {
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    return anterior;
}

void insertar_final(struct Lista &l, struct Elemento &e) {
    struct NodoLista *nodo_final = obtener_nodo_final(l);
    struct NodoLista * nuevo_nodo;
    nuevo_nodo = new struct NodoLista;
    nuevo_nodo->elemento = e;
    nuevo_nodo->siguiente = nullptr;

    if(nodo_final == nullptr)
        l.head = nuevo_nodo;
    else
        nodo_final->siguiente = nuevo_nodo;
}

void insertar_ordenado(struct Lista& l, struct Elemento & e){
    struct NodoLista * nuevo_nodo, *recorrido = l.head, *anterior = nullptr;
    nuevo_nodo = new struct NodoLista;
    nuevo_nodo->elemento = e;
    nuevo_nodo->siguiente = nullptr;

    while(recorrido){
        if(recorrido->elemento.numero > e.numero) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    nuevo_nodo->siguiente = recorrido;

    if(anterior == nullptr) l.head = nuevo_nodo;
    else anterior->siguiente = nuevo_nodo;
}

void eliminar_nodo(struct Lista &l, struct Elemento & e){
    struct NodoLista * anterior = nullptr;
    struct NodoLista * recorrido = l.head;
    // Avanzar hasta encontrar el elemento
    while((recorrido != nullptr) and (recorrido->elemento.numero != e.numero)){
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    if(recorrido != nullptr){
        if(anterior == nullptr)// Inicio de la lista
            l.head = recorrido->siguiente;
        else
            anterior->siguiente = recorrido->siguiente;
        //Lo q quiero eliminar esta en RECORRIDO
        delete recorrido;
    }
}

void destruir(struct Lista& l){
    struct NodoLista * recorrido = l.head;
    while(recorrido!=nullptr){
        //usar un nodo auxiliar para recuperar lo q vayaos a destruir
        struct NodoLista * nodo_aux = recorrido;
        recorrido = recorrido->siguiente;
        delete nodo_aux;
    }
    //La lista debe quedar vacia
    l.head = nullptr;
}