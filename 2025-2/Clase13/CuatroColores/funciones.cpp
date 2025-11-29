//Fecha:  viernes 21 Noviembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include <fstream>
#include "funciones.h"

#include <math.h>

#include "BibliotecaLista/Lista.h"
using namespace std;

void mergeSort(int arreglo[12][2], int inicio, int fin) {
    //caso base
    if (inicio == fin) return;
    //centro
    int centro = (inicio + fin) / 2;
    mergeSort(arreglo, inicio, centro); //izquierda arreglo
    mergeSort(arreglo, centro+1, fin); //derecha arreglo
    merge(arreglo, inicio, centro, fin); //juntar todo
}

void merge(int arreglo[12][2], int inicio, int centro, int fin) {
    int size = fin - inicio + 1;
    int temp[size][2];
    for (int i = 0; i < size; i++) {
        temp[i][0] = arreglo[inicio + i][0];
        temp[i][1] = arreglo[inicio + i][1];
    }
    int izquierda = 0;
    int derecha = centro - inicio + 1;
    int limite_izquierda = centro - inicio;
    int limite_derecha = fin - inicio;

    for (int i = inicio; i <= fin; i++) {
         // Si aún hay elementos en ambas mitades
         if (izquierda <= limite_izquierda and derecha <= limite_derecha) {
            // Comparar por grado
            if (temp[izquierda][1] >= temp[derecha][1]) {
                arreglo[i][0] = temp[izquierda][0];
                arreglo[i][1] = temp[izquierda][1];
                izquierda++;
            } else {
                arreglo[i][0] = temp[derecha][0];
                arreglo[i][1] = temp[derecha][1];
                derecha++;
            }
         }
         // Si solo quedan elementos en la mitad izquierda
         else if (izquierda <= limite_izquierda) {
              arreglo[i][0] = temp[izquierda][0];
              arreglo[i][1] = temp[izquierda][1];
              izquierda++;
         }
         // Si solo quedan elementos en la mitad derecha
         else {
              arreglo[i][0] = temp[derecha][0];
              arreglo[i][1] = temp[derecha][1];
              derecha++;
         }
    }
}

void pintaMapa(struct Lista & grafoMapa, int grado[12][2]) {

    int MAX_DATOS = 12;

    // Ordenar por grado descendente, método de selección
    for (int i = 0; i < MAX_DATOS-1; i++) {
        int min = i;
        for (int j = i+1 ; j < MAX_DATOS; j++) {
            if (grado[j][1] > grado[min][1]) { //de mayor a menor
                min = j;
            }
        }
        int temp = grado[i][1];
        grado[i][1] = grado[min][1];
        grado[min][1] = temp;

        temp = grado[i][0];
        grado[i][0] = grado[min][0];
        grado[min][0] = temp;
    }

    // Recorrer ciudades ordenadas por grado descendente
    for (int i = 0; i < 12; i++) {
        int ciudadActual = grado[i][0]; // ID de la ciudad actual

        // Encontrar el vértice de la ciudad actual
        struct NodoLista* verticeActual = grafoMapa.inicio;
        while ((verticeActual != nullptr) and (verticeActual->elemento.codigo != ciudadActual)) {
            verticeActual = verticeActual->abajo;
        }

        //if (verticeActual == nullptr) continue;

        // Si ya tiene color, saltar
        if (verticeActual->elemento.color != 0) continue;

        // Encontrar el color más bajo disponible, se usa buffer para
        bool coloresUsados[5] {false}; // 4 colores + buffer

        // Revisar colores de vecinos
        struct NodoLista* vecino = verticeActual->siguiente;
        /*Vuelvo al inicio para buscar el vecino*/
        while (vecino != nullptr) {
            // Encontrar el vértice del vecino y su respectivo color asignado
            struct NodoLista* verticeVecino = grafoMapa.inicio;
            while (verticeVecino != nullptr and verticeVecino->elemento.codigo != vecino->elemento.codigo) {
                verticeVecino = verticeVecino->abajo;
            }

            if (verticeVecino != nullptr and verticeVecino->elemento.color != 0) {
                coloresUsados[verticeVecino->elemento.color] = true;
            }
            vecino = vecino->siguiente;
        }

        // Asignar el primer color disponible
        for (int c = 1; c <= 4; c++) {
            if ( not coloresUsados[c]) {
                verticeActual->elemento.color = c;
                break;
            }
        }

    }
}

void mostrarPaisPorColor(struct Lista & grafoMapa, int color) {

    struct NodoLista* vertice = grafoMapa.inicio;
    while (vertice != nullptr) {
        if (vertice->elemento.color == color) {
            cout <<vertice->elemento.nombre << ", ";
        }
        vertice = vertice->abajo;
    }
    cout << endl;
}