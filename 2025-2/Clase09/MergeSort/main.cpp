#include "src/Funciones.hpp"

int main() {
    /*Busqueda binaria*/
    int arreglo[] = {90, 65, 7, 305, 120, 110, 8};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
    imprime(arreglo, longitud);
    /*ORDENAMOS EL ARREGLO con complejidad n log(n) */
    cout << "Ordenamos el arreglo usando MergeSort complejidad nlog(n)" << endl;
    mergeSort(arreglo, 0, longitud - 1);
    imprime(arreglo, longitud);

    cout << "Busqueda binaria" << endl;
    int clave = 110;
    cout << "Buscar: " << clave << endl;


    int indice = busquedaBinaria(arreglo, clave, 0, longitud - 1);
    if (indice != -1)
        cout << "ENCONTRADO" << endl;
    else
        cout << "NO ENCONTRADO" << endl;
    return 0;
}
