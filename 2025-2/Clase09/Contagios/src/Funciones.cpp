//
// Created by Erasmo on 31/10/25.
//

#include "Funciones.hpp"

int cuentaIncrementos(int *arreglo, int inicio, int fin) {

    if (inicio == fin) return 1; //caso base un elemento
    int centro = (inicio + fin) / 2;

    int izquierda = cuentaIncrementos(arreglo, inicio, centro);
    int derecha = cuentaIncrementos(arreglo, centro + 1, fin);

    //encontrar la secuencia que sume el centro
    int sumaCentro = maxCentro(arreglo, inicio, centro, fin);
    return max(max(izquierda, derecha), sumaCentro);

}

int maxCentro(int *arreglo, int inicio, int centro, int fin) {
    //empezamos desde el centro
    int contIzquierda = 1; //inicia con el centro
    if (arreglo[centro] > arreglo[centro + 1]) return 1;
    for (int i = centro; i > inicio; i--) {
        if (arreglo[i] > arreglo[i - 1])
            contIzquierda++;
        else
            break;
    }
    int contDerecha = 1; //inicia con el centro + 1
    for (int i = centro + 1; i < fin; i++) {
        if (arreglo[i + 1] > arreglo[i])
            contDerecha++;
        else
            break;
    }

    // Verificar si podemos unir ambos lados
    if (arreglo[centro + 1] > arreglo[centro]) {
        return contIzquierda + contDerecha;
    } else {
        return max(contIzquierda, contDerecha);
    }
}

int max(int izquierda, int derecha) {
    return (izquierda > derecha) ? izquierda : derecha;
}