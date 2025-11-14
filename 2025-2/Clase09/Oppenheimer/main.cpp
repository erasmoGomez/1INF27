#include "src/Funciones.hpp"

int main() {
    /*Ejercicio Oppenheimer - 2024-1_Lab3*/
    int arreglo1[]{0, -1, 0, -1, 0, 1, 1, 2, 2, 3, 2, 2, 1, 1};
    int arreglo2[]{-1, 0, -1, 0, 1, 1, 2, 2, 3, 3, 4, 3, 3, 2, 2, 1, 1};
    int n = sizeof(arreglo1) / sizeof(arreglo1[0]);

    int radiacionMaxima;
    radiacionMaxima = cuentaCeros(arreglo1, 0, n - 1, 0);
    cout << "El resultado sera: La radiacion empieza a " << radiacionMaxima << " km. Potencia maxima ";
    buscaSolo(arreglo1, radiacionMaxima, n - 1);
    cout << " megatones. " << endl;

    n = sizeof(arreglo2) / sizeof(arreglo2[0]);
    radiacionMaxima = cuentaCeros(arreglo2, 0, n - 1, 0);
    cout << "El resultado sera: La radiacion empieza a " << radiacionMaxima << " km. Potencia maxima ";
    buscaSolo(arreglo2, radiacionMaxima, n - 1);
    cout << " megatones. " << endl;
}
