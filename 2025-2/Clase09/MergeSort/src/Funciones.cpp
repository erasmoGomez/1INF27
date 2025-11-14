//
// Created by Erasmo on 31/10/25.
//

#include "Funciones.hpp"

/*
 * Merge Sort divide el arreglo en mitades recursivamente y
 * luego fusiona (mergea) cada mitad ordenada.
 * Por eso tiene dos fases principales:
 * Dividir (Divide) → partir el arreglo por la mitad hasta que quede de tamaño 1
 * Combinar (Merge) → juntar las mitades ordenadas
 *
 * El costo:
 * 2 * T(n/2) → porque se llama recursivamente a Merge Sort sobre las dos mitades
 * O(n) → porque la función merge() combina los resultados en tiempo lineal
 * Como en cada paso divides el arreglo a la mitad, el número de niveles es:
 * log2(n) -> log(n)
 * El costo total = costo por nivel × cantidad de niveles:
 * T(n) = O(n)*log(n) -> O(n log n)
 */

void mergeSort(int * arreglo, int inicio, int fin) {
    //caso base
    if (inicio == fin) return; //Cuando el elemento esta solo
    //centro
    int centro = (inicio + fin) / 2;
    mergeSort(arreglo, inicio, centro); //izquierda arreglo
    mergeSort(arreglo, centro+1, fin); //derecha arreglo
    merge(arreglo, inicio, centro, fin); //juntar todo
}

void merge(int * arreglo, int inicio, int centro, int fin) {
    //Complejidad: O(n) en tiempo y O(n) en espacio adicional.
    int size = fin - inicio + 1;
    int temp[size];
    for (int i = 0; i < size; i++) {
        temp[i] = arreglo[inicio + i];
    }
    int izquierda = 0;
    int derecha = centro - inicio + 1;

    for (int indice = 0; indice < size; indice++) {
        if (derecha <= fin - inicio) //verifica derecha
            if (izquierda <= centro - inicio) //verifica izquierda
                if (temp[izquierda] > temp[derecha])
                    arreglo[inicio + indice] = temp[derecha++];
                else
                    arreglo[inicio + indice] = temp[izquierda++];
            else
                arreglo[inicio + indice] = temp[derecha++];
        else
            arreglo[inicio + indice] = temp[izquierda++];
    }
}

void imprime(int * arreglo, int n) {
    for (int i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << endl;
}

int busquedaBinaria(int * arreglo, int clave, int inicio, int fin) {

    //caso base
    if (inicio > fin) return -1;

    int centro = (inicio + fin) / 2;
    if (arreglo[centro] == clave)
        return centro;
    else
    if (arreglo[centro] < clave)
        return busquedaBinaria(arreglo, clave, centro + 1, fin);
    else
        return busquedaBinaria(arreglo, clave, inicio, centro - 1);
}