//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

void construir(struct Lista & listaTAD) {
    listaTAD.inicio = nullptr;
    listaTAD.longitud = 0;
}

bool esListaVacia(const struct Lista & listaTAD) {
    return listaTAD.inicio == nullptr;
}

/*Inserta un elemento siempre al final de la lista*/
void insertarVertice(struct Lista & listaTAD, const struct ElementoLista & elemento) {

    struct NodoLista * ultimoNodoLista = obtenerUltimoNodo(listaTAD);
    struct NodoLista * nuevo;
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    nuevo->abajo = nullptr;  //para manejar los vétices
    nuevo->siguiente = nullptr;  //importante para ingresar aristas

    if (ultimoNodoLista == nullptr) /*Si la lista está vacía*/
        listaTAD.inicio = nuevo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene NodoListas
        ultimoNodoLista->abajo = nuevo;

    listaTAD.longitud++;
}

/*Obtiene el último NodoLista de la lista*/
struct NodoLista * obtenerUltimoNodo(const struct Lista & listaTAD) {
    struct NodoLista * ultimo = nullptr;
    struct NodoLista* recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->abajo;
    }
    return ultimo;
}

void eliminaNodo(struct Lista & listaTAD, const struct ElementoLista & elemento) {
    struct NodoLista * ultimo = nullptr;
    struct NodoLista * recorrido = listaTAD.inicio;
    /*Avanzo hasta encontrar el elemento*/
    /*Si no lo encuentra no elimina nada*/
    while ((recorrido != nullptr) and (recorrido->elemento.codigo != elemento.codigo)) {
        ultimo = recorrido;
        recorrido = recorrido->abajo;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr) /*Estoy al inicio de la lista*/
            listaTAD.inicio = recorrido->abajo;
        else
            ultimo->abajo = recorrido->abajo;
        delete recorrido; /*libera la memoria*/
    }
    listaTAD.longitud--;
}

void destruir(struct Lista & listaTAD) {
    /*recorrido apunta al inicio del tad*/
    struct NodoLista * recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        /*NodoLista auxiliar que va servir para eliminar los NodoListas*/
        struct NodoLista * NodoListaAEliminar = recorrido;
        recorrido = recorrido->abajo;
        delete NodoListaAEliminar;
    }
    /*la lista queda vacia*/
    listaTAD.inicio = nullptr;
    listaTAD.longitud = 0;
}

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprimir(const struct Lista & listaTAD) {

    if (esListaVacia(listaTAD)) {
        cout << "La lista esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoLista * vertices = listaTAD.inicio;

        while (vertices != nullptr) {
            struct NodoLista * arista = vertices->siguiente;
            /*Este artificio coloca las comas despuÃ©s de la cabeza*/
            cout << "[" << vertices->elemento.codigo << "]: ";
            while (arista != nullptr) {
                //cout << arista->elemento.codigo << " (" << arista->elemento.peso << ")  ";
                cout << arista->elemento.codigo << "  ";
                arista = arista->siguiente;
            }
            cout << endl;
            vertices = vertices->abajo;
        }
    }
}

void insertarArista(struct Lista & listaVertices, const struct ElementoLista & origen, const struct ElementoLista & destino) {

    struct NodoLista * vertice = listaVertices.inicio;
    //ACA recorro los vértices... busca el vértice
    while (vertice != nullptr) {
        if (vertice->elemento.codigo == origen.codigo) {
            break;
        }
        vertice = vertice->abajo; //en el vértice
    }

    struct NodoLista * ultimo = nullptr;
    struct NodoLista* recorrido = vertice;
    //ACA recorro las aristas... busca la última arista
    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente; //en arista
    }

    //crea la nueva conexión
    struct NodoLista * nuevo = new struct NodoLista;
    nuevo->elemento = destino;
    nuevo->siguiente = nullptr;  //importante para ingresar aristas

    //Realiza el enlace
    if (ultimo == nullptr) /*Si la lista está vacía*/
        vertice->siguiente = nuevo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene NodoListas
        ultimo->siguiente = nuevo;
}

// Función para obtener la longitud del grafo
int longitudGrafo(struct Lista & grafo) {
    return grafo.longitud;
}

// Función para buscar un vértice por su código
struct NodoLista* buscarVertice(struct Lista & grafo, int codigo) {
    struct NodoLista * vertice = grafo.inicio;
    while (vertice != nullptr) {
        if (vertice->elemento.codigo == codigo) {
            return vertice;
        }
        vertice = vertice->abajo;
    }
    return nullptr;
}
