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

    struct Lista grafo;
    construir(grafo);

    insertarVertice(grafo, { "Boston"});
    insertarVertice(grafo, {"Nueva York" });
    insertarVertice(grafo, {"Filadelfia"});
    insertarVertice(grafo, {"Roanoke"});

    insertarArista(grafo, {"Boston"}, {"Nueva York",120});
    insertarArista(grafo, {"Boston"}, {"Filadelfia", 199});
    insertarArista(grafo, {"Nueva York"}, {"Boston", 140});
    insertarArista(grafo, {"Nueva York"}, {"Filadelfia", 225});
    insertarArista(grafo, {"Nueva York"}, {"Roanoke", 320});
    insertarArista(grafo, {"Filadelfia"}, {"Boston", 219});
    insertarArista(grafo, {"Filadelfia"}, { "Nueva York", 205});
    insertarArista(grafo, {"Roanoke"}, { "Nueva York", 240});

    imprimir(grafo);

    /*Tarea: Rutas de Boston a Roanoke, coste de ir de una ciudad a otra + conexiones*/
    //1: Boston -> Nueva York -> Roanoke
    //Coste:    120     +     320        = 440
    //2: Boston -> Filadelfia -> Nueva York -> Roanoke
    //Coste:    219     +     225     +     320       = 764

    return 0;
}
