//Fecha:  viernes 08 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include <fstream>
using namespace std;
#include "funciones.hpp"

void leerDatos(int * arreglo, int m) {
    for (int i = 0; i < MAX_DATOS; i++) {
        cin >> arreglo[i];
    }
}
void ordenarDatosSeleccion(int * arreglo, int m) {
    //set_timer_start
    for (int i = 0; i <= MAX_DATOS-2; i++) {
        int min = i;
        for (int j = i+1 ; j <= MAX_DATOS-1; j++) {
            if (arreglo[j] < arreglo[min]) {
                min = j;
            }
        }
        //Intercambio
        int temp = arreglo[i];
        arreglo[i] = arreglo[min];
        arreglo[min] = temp;
    }
    //set_timer_end
}
void ordenarDatosBurbuja(int * arreglo, int m) {
    for (int i = 0; i <= MAX_DATOS-2; i++) {
        for (int j = 0; j <= MAX_DATOS-2-i; j++) {
            //0 17 29 34 45 68 89 90
            if (arreglo[j+1] < arreglo[j]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            }
            //45 68 89 29 34 17 0 90
        }
    }
}

void mostrarDatos(int * arreglo, int m) {
    for (int i = 0; i < MAX_DATOS; i++) {
        cout << arreglo[i] << " ";
    }
}