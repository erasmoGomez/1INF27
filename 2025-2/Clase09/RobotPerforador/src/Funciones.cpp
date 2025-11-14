//
// Created by Erasmo on 31/10/25.
//

#include "Funciones.hpp"
int cuentaCerosIzq(int * arreglo2, int inicio, int fin, int cont) {

    if (inicio > fin) return cont;
    int centro = (inicio + fin) / 2;
    //TENGO CEROS A LA IZQUIERDA
    if (arreglo2[centro] == 0)
        return cuentaCerosIzq(arreglo2, centro + 1, fin, centro + 1);
    else
        return cuentaCerosIzq(arreglo2, inicio, centro - 1, cont);
}

int cuentaCerosDer(int * arr, int ini, int fin, int cont) {

    if (ini > fin) return cont;
    int med = (ini + fin) / 2;

    //TENGO CEROS A LA DERECHA
    if (arr[med] == 0)
        return cuentaCerosDer(arr, ini, med - 1, cont + fin - med + 1);
    else
        return cuentaCerosDer(arr, med + 1, fin, cont);
}


/*Busca montaña modificado al que se hizo en clase*/
int buscaMontana(int *arreglo, int inicio, int fin, int & jMax) {
    //logn
    if (inicio == fin) {
        jMax = inicio;
        return arreglo[inicio];
    }
    int med = (inicio + fin) / 2;
    /*Dado que son 3 hay que poner una condicion mas*/
    if(arreglo[med] == arreglo[med + 1])
        if(arreglo[med + 1] < arreglo[med + 2]) // Representa que crece
            return buscaMontana(arreglo, med + 1, fin, jMax);
    if (arreglo[med] >= arreglo[med + 1])
        return buscaMontana(arreglo, inicio, med, jMax);
    else
        return buscaMontana(arreglo, med + 1, fin, jMax);
}