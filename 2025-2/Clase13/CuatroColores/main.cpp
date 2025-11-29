//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "funciones.h"
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

    /*Algoritmo de los cuatro colores*/
    struct Lista grafoMapa;
    construir(grafoMapa);

    insertarVertice(grafoMapa, {0, 0, "Argentina"});
    insertarVertice(grafoMapa, {1, 0, "Bolivia"});
    insertarVertice(grafoMapa, {2, 0, "Brasil"});
    insertarVertice(grafoMapa, {3, 0, "Chile"});
    insertarVertice(grafoMapa, {4, 0, "Colombia"});
    insertarVertice(grafoMapa, {5, 0, "Ecuador"});
    insertarVertice(grafoMapa, {6, 0, "Guyana"});
    insertarVertice(grafoMapa, {7, 0, "Paraguay"});
    insertarVertice(grafoMapa, {8, 0, "Peru"});
    insertarVertice(grafoMapa, {9, 0, "Surinam"});
    insertarVertice(grafoMapa, {10,0, "Uruguay"});
    insertarVertice(grafoMapa, {11,0, "Venezuela"});

    /* 0=Argentina, 1=Bolivia, 2=Brasil, 3=Chile, 4=Colombia, 5=Ecuador,
      * 6=Guyana, 7=Paraguay, 8=Perú, 9=Surinam, 10=Uruguay, 11=Venezuela. */
    int fronteras[12][10] {
        {3, 1, 7, 2, 10, -1},
        {8, 2, 7, 0, 3, -1},
        {10, 0, 7, 1, 8, 4, 11, 6, 9, -1},
        {8, 1, 0, -1},
        {11, 2, 8, 5, -1},
        {4, 8, -1},
        {11, 2, 9, -1},
        {1, 2, 0, -1},
        {5, 4, 2, 1, 3, -1},
        {6, 2, -1},
        {2, 0, -1},
        {4, 2, 6, -1}
    };

    int grado[12][2] {};

    for (int i = 0; i < 12; i++) {
        grado[i][0] = i;  int cont = 1;
        for (int j = 0; j < 9; j++) {
                if (fronteras[i][j] == -1) break;
                insertarArista(grafoMapa, {i}, {fronteras[i][j]});
                grado[i][1] = cont++;
        }
    }

    pintaMapa(grafoMapa, grado);
    imprimir(grafoMapa);

    cout << endl;
    for(int color = 1; color <= 4; color++) {
        cout << "Color " << color << ": ";
        mostrarPaisPorColor(grafoMapa, color);
    }

    return 0;
}
