#include "src/Estructuras.hpp"

/*
 Forma de solución (estrategia):
 Se usa Divide y Vencerás:
 - Dado un arreglo ORDENADO, se escoge el elemento central como raíz.
 - Se construye recursivamente el subárbol izquierdo con la mitad izquierda del arreglo.
 - Se construye recursivamente el subárbol derecho con la mitad derecha del arreglo.
 Así el árbol queda balanceado y la altura es O(log n).
 Como cada elemento se visita una sola vez, la complejidad total es O(n).
*/

int main() {
    int n = 7;
    int n2 = 9;
    int *a = new int[n];
    int *b = new int[n2];
    int aux[] = {2, 4, 6, 8, 10, 12, 14};
    int aux2[] = {-5, 1, 5, 8, 12, 16, 19, 22, 66};
    for (int i = 0; i < n; i++)
        a[i] = aux[i]; // arreglo ORDENADO

    for (int i = 0; i < n2; i++)
        b[i] = aux2[i]; // arreglo ORDENADO

    Nodo *raiz_a = construirABB(a, 0, n - 1);
    Nodo *raiz_b = construirABB(b, 0, n2 - 1);

    cout << "Preorden: ";
    preorden(raiz_a);
    cout << "\n\nNiveles:\n";
    imprimir_por_nivel(raiz_a);

    destruirArbol(raiz_a);

    cout << "Preorden: ";
    preorden(raiz_b);
    cout << "\n\nNiveles:\n";
    imprimir_por_nivel(raiz_b);

    destruirArbol(raiz_b);

    delete [] b;
    delete [] a;
    return 0;
}
