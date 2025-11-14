//
// Created by Erasmo on 31/10/25.
//

#include "Funciones.hpp"

int sumaMinimaConsecutiva(int * arreglo, int inicio, int fin) {
    //Se parece mucho al MERGE SORT -> nlogn
    if (inicio == fin) return arreglo[inicio]; //CB
    int med = (inicio + fin) / 2;

    int izq = sumaMinimaConsecutiva(arreglo, inicio, med);
    int der = sumaMinimaConsecutiva(arreglo, med + 1, fin);
    int centro = sumaCentroMinimaConsecutiva(arreglo, inicio, med, fin); // Merge

    return min(min(izq, der), centro);

}

int sumaCentroMinimaConsecutiva(int * arreglo, int inicio, int med, int fin) {
    int suma = 0;
    int sumaIzq = 10000, sumaDer = 10000;
    for (int i = med; i >= inicio; i--) {
        suma += arreglo[i];
        if (suma < sumaIzq)
            sumaIzq = suma;
    }
    suma = 0;
    for (int i = med + 1; i <= fin; i++) {
        suma += arreglo[i];
        if (suma < sumaDer)
            sumaDer = suma;
    }
    return min(min(sumaIzq, sumaDer), sumaDer + sumaIzq);
}

int min(int a, int b) {
    return a < b ? a : b;
}