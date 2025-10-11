//
// Created by Erasmo on 10/10/25.
//
#include <iostream>
#include <iomanip>
#include "Nodo.hpp"
#include "Lista.hpp"
#include "Posicion.hpp"
#include "FuncionesLista.hpp"
using namespace std;

/*Valores iniciales de la lista*/
void construir(struct Lista & lista) {
    lista.cabeza = nullptr;
    lista.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
const bool esListaVacia(const struct Lista & lista) {
    return lista.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista  & lista) {
    return lista.longitud;
}

/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & lista, struct Posicion elemento) {

    /*Se va cambiar por la función crear nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->posicion = elemento;
    nuevoNodo->siguiente = lista.cabeza;

    lista.cabeza = nuevoNodo;
    lista.longitud++;
}

/*inserta un nodo siempre al final de la lista*/
void insertarAlFinal(struct Lista & lista, struct Posicion elemento) {

    struct Nodo * ultimoNodo = obtenerUltimoNodo(lista);
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

    if (ultimoNodo == nullptr) /*Si la lista está vacia*/
        lista.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    lista.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(struct Posicion elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->posicion.x = elemento.x;
    nuevoNodo->posicion.y = elemento.y;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

//Notar que esta función retorna nulo cuando la lista es vacía

/*Obtiene el último nodo de la lista*/
struct Nodo * obtenerUltimoNodo(const struct Lista & lista) {
    struct Nodo * ultimo = nullptr;
    struct Nodo* recorrido = lista.cabeza;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

struct Posicion retornaCabeza(const struct Lista & lista){
    return lista.cabeza->posicion;
}

void eliminaCabeza(struct Lista & lista) {
    struct Nodo * nodoAEliminar = lista.cabeza;
    if (nodoAEliminar != nullptr) {
        lista.cabeza = lista.cabeza->siguiente;
        delete nodoAEliminar;
        lista.longitud--;
    }
}

/*Elimina el último elemento de la lista, es llamado cola*/
void eliminaCola(struct Lista lista) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * penultimo = nullptr;
    struct Nodo * recorrido = lista.cabeza;

    while (recorrido != nullptr) {
        if (ultimo != nullptr)
            penultimo = ultimo;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (ultimo != nullptr) {
        //Si no hay penultimo, se está¡ eliminando el Único nodo de la lista
        if (penultimo == nullptr)
            lista.cabeza = nullptr;
        else
            penultimo->siguiente = nullptr;
        delete ultimo;
        lista.longitud--;
    }
}

void destruir(struct Lista & lista) {
    /*recorrido apunta al inicio del lista*/
    struct Nodo * recorrido = lista.cabeza;

    while (recorrido != nullptr) {
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    lista.cabeza = nullptr;
    lista.longitud = 0;
}

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la proteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo lista.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/
void imprime(const struct Lista & lista) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(lista)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = lista.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout<<recorrido->posicion.x;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}