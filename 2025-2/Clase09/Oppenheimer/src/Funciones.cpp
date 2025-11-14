//
// Created by Erasmo on 31/10/25.
//

#include "Funciones.hpp"
// EL ALGORITMO BASE PARA ESTOS 2 ES
// BUSQUEDA BINARIA
// O(logn)

int cuentaCeros(int * arr, int ini, int fin, int cont) {
    if (ini > fin) return cont; //CB
    int med = (ini + fin) / 2; //Lanzar la piedra

    //TENGO CEROS y NEGATIVOS A LA IZQUIERDA
    if (arr[med] <= 0) //condición para irme a la derecha porque tengo los positivos mayores a cero
        return cuentaCeros(arr, med + 1, fin, med + 1); //DERECHA
    else
        return cuentaCeros(arr, ini, med - 1, cont); //IZQ
}

void buscaSolo(int * arreglo, int inicio, int fin) {

    if (inicio > fin) return;
    if (inicio == fin) {
        cout << arreglo[inicio] << endl;
        return;
    }
    int centro = (inicio + fin) / 2;
    if(arreglo[centro - 1] != arreglo[centro] and arreglo[centro]!= arreglo[centro +1]) {
        cout << arreglo[centro] ;
        return;
    }
    if (centro % 2 == 0) { //centro es par
        if (arreglo[centro] == arreglo[centro + 1])   // significa que estan emparejados
            buscaSolo(arreglo, centro + 2, fin); // segunda mitad comenzando de med +2
        else
            buscaSolo(arreglo, inicio, centro);   // debe estar en la primera mitad
    }
    else { // centro es impar
        if (arreglo[centro] == arreglo[centro - 1])   // este par esta bien, el numero en la posicion con respecto al anterior
            buscaSolo(arreglo, centro + 1, fin);  //buscar en la segunda mitad del arreglo
        else
            buscaSolo(arreglo, inicio, centro -1);  //buscar en el otro intervalo
    }
}