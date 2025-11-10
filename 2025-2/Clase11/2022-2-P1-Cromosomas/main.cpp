#include "src/BibliotecaArboles/ArbolBinario.hpp"
#include "src/FuncionesArbol.hpp"
#include "src/FuncionesCola.hpp"
#include "src/Funciones.hpp"

int main() {
    int array[] = {10,50,20,30,40};
    int peso = 70;

    int n = sizeof(array) / sizeof(array[0]);
    cout << n << endl;
    ArbolBinario arbol = construir_arbol_arreglo(array, n);
    recorrido_por_niveles(arbol);
    int cantidad_combinaciones = contar_combinaciones(arbol, peso);
    cout << "\nNúmero de combinaciones: " << cantidad_combinaciones << endl;
    return 0;
}
