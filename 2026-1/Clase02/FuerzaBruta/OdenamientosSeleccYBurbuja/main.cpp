//Autor: Erasmo Gomez

#include "funciones.hpp"

int main() {

    int arreglo[MAX_DATOS];
    leerDatos(arreglo, MAX_DATOS);
    //ordenarDatosSeleccion(arreglo, MAX_DATOS);
    ordenarDatosBurbuja(arreglo, MAX_DATOS);
    mostrarDatos(arreglo, MAX_DATOS);

    return 0;
}