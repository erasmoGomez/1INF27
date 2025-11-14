#include "src/Funciones.hpp"

int main() {
    int arreglo[]{10, 20, 15, 10, 12, 10, 13, 18};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int cuenta = cuentaIncrementos(arreglo, 0, n - 1);
    cout << "Intervalo maximo de incrementos: " << cuenta <<
         ", con indice " << (cuenta * 1.0) / n << endl;
    return 0;
}
