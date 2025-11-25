//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include <fstream>
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolBinarioBusqueda.h"

using namespace std;

void insertar(struct ArbolBinarioBusqueda & arbol, const struct ElementoArbolBinarioBusqueda & elemento) {
    insertarRecursivo(arbol.raiz, elemento);
}

/*Tiene modificaciones en el elemento del árbol*/
void insertarRecursivo(struct NodoArbolBinarioBusqueda *& raiz, const struct ElementoArbolBinarioBusqueda & elemento){
    if(esNodoVacio(raiz))
        plantarNodoArbolBinario(raiz, nullptr, elemento, nullptr);
    else
        if(raiz->elemento.fechavencimiento > elemento.fechavencimiento)
            insertarRecursivo(raiz->izquierda, elemento);
        else
            if(raiz->elemento.fechavencimiento < elemento.fechavencimiento)
                insertarRecursivo(raiz->derecha, elemento);
            else
                cout << "El elemento " << elemento.fechavencimiento << "Ya se encuentra en el arbol" << endl;
}


void llenarArbol(struct ArbolBinarioBusqueda &arbol, int *arreglo, int inicio, int fin) {
    llenarArbolRecursivo(arbol.raiz, arreglo, inicio, fin);
}

void llenarArbolRecursivo(struct NodoArbolBinarioBusqueda *&nodo, int *arreglo, int inicio, int fin) {
    //Lo vamos a llenar con la estrategia de divide y vencerÃ¡s
    if (inicio == fin) return;
    int centro = (inicio + fin) / 2;
    plantarNodoArbolBinario(nodo, nullptr, {arreglo[centro]}, nullptr);
    llenarArbolRecursivo(nodo->izquierda, arreglo, inicio, centro);
    llenarArbolRecursivo(nodo->derecha, arreglo, centro + 1, fin);
}
int comparaElementos(int elementoA, int elementoB){
    if(elementoA == elementoB) return 0;
    else if(elementoA < elementoB) return -1;
    else if(elementoA > elementoB) return 1;
}

bool buscarRecursivo(struct NodoArbolBinarioBusqueda * nodo,  struct ElementoArbolBinarioBusqueda & elemento){
    if(esNodoVacio(nodo))
        return false;
    if(nodo->elemento.fechavencimiento == elemento.fechavencimiento)
        return true;
    if(elemento.fechavencimiento < nodo->elemento.fechavencimiento)
        return buscarRecursivo(nodo->izquierda, elemento);
    else
        //if(elemento.numero > nodo->elemento.numero)
        return buscarRecursivo(nodo->derecha, elemento);

}

bool buscar(const struct ArbolBinarioBusqueda & arbol,  struct ElementoArbolBinarioBusqueda & elemento){
    return buscarRecursivo(arbol.raiz, elemento);
}

struct NodoArbolBinarioBusqueda * minimoArbol(struct NodoArbolBinarioBusqueda * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->izquierda))
        return nodo;
    return minimoArbol(nodo->izquierda);
}

struct NodoArbolBinarioBusqueda * eliminarRecursivo(struct NodoArbolBinarioBusqueda * nodo,
                                  const struct ElementoArbolBinarioBusqueda & elemento){
    if(esNodoVacio(nodo))
        return nodo;
    //buscamos el nodo a eliminar
    if(nodo->elemento.fechavencimiento > elemento.fechavencimiento)
        nodo->izquierda = eliminarRecursivo(nodo->izquierda, elemento);
    else
        if(nodo->elemento.fechavencimiento < elemento.fechavencimiento)
            nodo->derecha = eliminarRecursivo(nodo->derecha, elemento);
        else
            /*encontró el elemento*/
                if(esNodoVacio(nodo->izquierda)){
                    struct NodoArbolBinarioBusqueda * hijo = nodo->derecha;
                    delete nodo;
                    return hijo;
                }
                else
                    if(esNodoVacio(nodo->derecha)){
                        struct NodoArbolBinarioBusqueda * hijo = nodo->izquierda;
                        delete nodo;
                        return hijo;
                    }
                    else{
                        /* dos hijos*/ /*como voy a la derecha busco el mínimo*/
                        struct NodoArbolBinarioBusqueda * minNodo = minimoArbol(nodo->derecha);
                        nodo->elemento = minNodo->elemento; //reemplazo el elemento
                        nodo->derecha = eliminarRecursivo(nodo->derecha, minNodo->elemento); //borro el repetido
                    }

    return nodo;

}

void eliminar(struct ArbolBinarioBusqueda & arbol, const struct ElementoArbolBinarioBusqueda & elemento){
    arbol.raiz = eliminarRecursivo(arbol.raiz, elemento);
}

void despacha(struct ArbolBinarioBusqueda & arbol, int cant) {
    despachaRecursivo(arbol.raiz, cant);
}

void despachaRecursivo(struct NodoArbolBinarioBusqueda *& raiz, int cant) {
    struct NodoArbolBinarioBusqueda * aux;

    if (cant == 0) return;
    aux = minimoArbol(raiz);
    if (aux->elemento.cantidad <= cant) {
        int falta = cant - aux->elemento.cantidad ;
        raiz = eliminarRecursivo(raiz, aux->elemento);
        despachaRecursivo(raiz, falta);
    } else
        aux->elemento.cantidad -= cant;
}

/*FUNCIONES DE ARBOL BINARIO
 *QUE TAMBIEN USA UN
 *ARBOL BINARIO DE BUSQUEDA*/

void construir(struct ArbolBinarioBusqueda &arbol) {
    arbol.raiz = nullptr;
}

bool esArbolVacio(const struct ArbolBinarioBusqueda &nodo) {
    return nodo.raiz == nullptr;
}

bool esNodoVacio(const struct NodoArbolBinarioBusqueda *nodo) {
    return nodo == nullptr;
}

void plantarArbolBinario(struct ArbolBinarioBusqueda &arbol, const struct ArbolBinarioBusqueda &izquierda,
               const struct ElementoArbolBinarioBusqueda &elemento, const struct ArbolBinarioBusqueda &derecha) {

    plantarNodoArbolBinario(arbol.raiz, izquierda.raiz, elemento, derecha.raiz);
}

void plantarNodoArbolBinario(struct NodoArbolBinarioBusqueda *&nodo, struct NodoArbolBinarioBusqueda *izquierda,
    const struct ElementoArbolBinarioBusqueda &elemento, struct NodoArbolBinarioBusqueda *derecha) {
    struct NodoArbolBinarioBusqueda *nuevo = new struct NodoArbolBinarioBusqueda;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nodo = nuevo;
}

void imprimirNodo(struct NodoArbolBinarioBusqueda *raiz) {
    cout<<setw(5)<<raiz->elemento.fechavencimiento<< " "<< raiz->elemento.cantidad<< ", ";
}

void recorrerPreOrden(const struct ArbolBinarioBusqueda &arbol) {
    recorrerPreOrdenRecursivo(arbol.raiz);
}

void recorrerPreOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (not esNodoVacio(nodo)) {
        imprimirNodo(nodo);
        recorrerPreOrdenRecursivo(nodo->izquierda);
        recorrerPreOrdenRecursivo(nodo->derecha);
    }
}

void recorrerEnOrden(const struct ArbolBinarioBusqueda &arbol) {
    recorrerEnOrdenRecursivo(arbol.raiz);
}

/*Va mostrar el Ã¡rbol en orden */
void recorrerEnOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimirNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

void recorrerPostOrden(const struct ArbolBinarioBusqueda &arbol) {
    recorrerPostOrdenRecursivo(arbol.raiz);
}

void recorrerPostOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerPostOrdenRecursivo(nodo->izquierda);
        recorrerPostOrdenRecursivo(nodo->derecha);
        imprimirNodo(nodo);
    }
}

int numeroHojas(const struct ArbolBinarioBusqueda &arbol) {
    return numeroHojasRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}


int numeroNodos(const struct ArbolBinarioBusqueda &arbol) {
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroNodosRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);
}

int altura(const struct ArbolBinarioBusqueda & arbol){
       return alturaRecursivo(arbol.raiz);
}

int alturaRecursivo(struct NodoArbolBinarioBusqueda * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if(esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return 1 + maximo(alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int maximo(int a, int b){
    return a >= b ? a : b;
}

bool esEquilibrado(const struct ArbolBinarioBusqueda & arbol){
    return esEquilibradoRecursivo(arbol.raiz);
}

bool esEquilibradoRecursivo(struct NodoArbolBinarioBusqueda * nodo){
    if(esNodoVacio(nodo))
        return true;
    else{
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia <=1 and esEquilibradoRecursivo(nodo->izquierda) and
                esEquilibradoRecursivo(nodo->derecha);
    }
}

void destruirArbolBinario(struct ArbolBinarioBusqueda & arbol){
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(struct NodoArbolBinarioBusqueda * nodo){
    if(not (esNodoVacio(nodo))){
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
    }
}
//
//int cantidad_nodos(struct NodoArbolBinarioBusqueda * nodo){
//    int cont = 0, cont_izq, cont_der;
//    if(!esNodoVacio(nodo)){
//        cont_izq = cantidad_nodos(nodo->izquierda);
//        cont++;
//        cont_der = cantidad_nodos(nodo->derecha);
//    }
//    return cont + cont_izq + cont_der;
//}

ElementoArbolBinarioBusqueda& buscarRecursivoElemento(struct NodoArbolBinarioBusqueda * nodo, const struct ElementoArbolBinarioBusqueda & elemento){
    ElementoArbolBinarioBusqueda e{};
    if(esNodoVacio(nodo))
        return e;
    if(nodo->elemento.fechavencimiento == elemento.fechavencimiento)
        return nodo->elemento;
    if(elemento.fechavencimiento < nodo->elemento.fechavencimiento)
        return buscarRecursivoElemento(nodo->izquierda, elemento);
    else
        //if(elemento.numero > nodo->elemento.numero)
        return buscarRecursivoElemento(nodo->derecha, elemento);
}


void recorrer_insertar_recursivo(struct NodoArbolBinarioBusqueda* emisor,
                                 struct NodoArbolBinarioBusqueda* destino){
    if(!esNodoVacio(emisor)){
        // Llamada en Order al Emisor
        recorrer_insertar_recursivo(emisor->izquierda, destino); // llamada izquierda
        // procesar la raiz
        if(!buscarRecursivo(destino, emisor->elemento))
            insertarRecursivo(destino, emisor->elemento);
        else{
            //Actualizar
            ElementoArbolBinarioBusqueda encontrado = buscarRecursivoElemento(destino, emisor->elemento);
            encontrado.cantidad += emisor->elemento.cantidad;
        }
        recorrer_insertar_recursivo(emisor->derecha, destino); // llamada derecha
    }
}

void recorre_inserta(struct ArbolBinarioBusqueda& emisor,
                     struct ArbolBinarioBusqueda& destino){
    recorrer_insertar_recursivo(emisor.raiz, destino.raiz);
}

void fusion(struct ArbolBinarioBusqueda& arbol1,
            struct ArbolBinarioBusqueda& arbol2){
    int c_nodos_a1 = numeroNodosRecursivo(arbol1.raiz);
    int c_nodos_a2 = numeroNodosRecursivo(arbol2.raiz);
    struct ArbolBinarioBusqueda emisor, destino;
    if( c_nodos_a1 > c_nodos_a2){
        emisor = arbol2;
        destino = arbol1;
    }else if (c_nodos_a1 <=  c_nodos_a2){
        emisor = arbol1;
        destino = arbol2;
    }
    recorre_inserta(emisor, destino);

}