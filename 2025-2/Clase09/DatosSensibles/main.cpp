#include "src/Funciones.hpp"

int main() {
    /*Trafico de la red de una organizacion - 2024-1_Lab3*/
    /*suma minima consecutiva*/
    int arreglo1[]{2, 5, -6, 2, 3, -1, -5, 6};
    int arreglo2[]{2, -3, 4, -5, -7};
    int arreglo3[]{-4, 5, 6, -4, 3, -1, -5, 6};

    int n = sizeof(arreglo1) / sizeof(arreglo1[0]);
    cout << "Salida minima: " << sumaMinimaConsecutiva(arreglo1, 0, n - 1) << endl;
    n = sizeof(arreglo2) / sizeof(arreglo2[0]);
    cout << "Salida minima: " << sumaMinimaConsecutiva(arreglo2, 0, n - 1) << endl;
    n = sizeof(arreglo3) / sizeof(arreglo3[0]);
    cout << "Salida minima: " << sumaMinimaConsecutiva(arreglo3, 0, n - 1) << endl;
    int min_a = std::min(3, 4);
    int max_a = std::max(4, 5);
    cout << min_a << endl;
    cout << max_a << endl;
    return 0;
}
