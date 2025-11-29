//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

/*
 * IMPLEMENTACION DE GRAFOS
 * Se usa una matriz dispersa representada con
 * listas de adyacencia
 * * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */
int main(int argc, char **argv) {

    struct Lista grafoDijkstra;
    construir(grafoDijkstra);
    //Algoritmo de Dijkstra
    insertarVertice(grafoDijkstra, {1});
    insertarVertice(grafoDijkstra, {2});
    insertarVertice(grafoDijkstra, {3});
    insertarVertice(grafoDijkstra, {4});
    insertarVertice(grafoDijkstra, {5});

    insertarArista(grafoDijkstra, {1}, {2,"" ,4});
    insertarArista(grafoDijkstra, {1}, {3,"", 11});
    insertarArista(grafoDijkstra, {2}, {4,"",6});
    insertarArista(grafoDijkstra, {2}, {5,"", 2});
    insertarArista(grafoDijkstra, {3}, {2,"", 3});
    insertarArista(grafoDijkstra, {3}, {4,"", 6});
    insertarArista(grafoDijkstra, {5}, {3,"", 5});
    insertarArista(grafoDijkstra, {5}, {4,"", 3});

    cout << "IMPRIMIR GRAFO PARA DIJKSTRA" << endl;
    imprimir(grafoDijkstra);

    //Algoritmo de Dijkstra
    /*Encuentra el camino más corto de un vétice elegido a cualquier otro vértice de la
     *gráfica dónde la longitud del camino es la suma de sus pesos.*/
     algoritmoDijkstra(grafoDijkstra, 1);


    return 0;
}
