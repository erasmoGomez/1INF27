#include <iostream>
#include "src/Pila.hpp"
#include "src/FuncionesPila.hpp"
#include "src/Hanoi.hpp"

using namespace std;

int main() {
    /*
     *PSEUDOCODIGO
    hanoi(n, origen, auxiliar, destino):
    si n == 0: retornar
    hanoi(n-1, origen, destino, auxiliar)   // Paso 1
    mover(origen -> destino)                // Paso 2
    hanoi(n-1, auxiliar, origen, destino)   // Paso 3
    */
    // PREPARACION DEL PROBLEMA
    struct Pila A{}, B{}, C{};
    construir(A);
    construir(B);
    construir(C);

    int n = 4;
    //    cout << "Numero de discos (recomendado 3-8): ";
    //    if (!(cin >> n) || n <= 0) {
    //        cout << "Valor invalido.\n";
    //        return 0;
    //    }

    // Apilar en A: n..1 (tope = 1)
    for (int d = n; d >= 1; --d) {
        ElementoPila e{d};
        apilar(A, e);
    }
    //{1 2 3 4}

    cout << "Estado inicial:\n";
    cout << "A=";
    imprimir(A);
    cout << "  B=";
    imprimir(B);
    cout << "  C=";
    imprimir(C);
    cout << '\n';

    // SOLUCION DEL PROBLEMA
    int paso = 0;
    hanoiConImpresion(n, A, B, C,
                      'A', 'B', 'C',
                      paso,
                      A, B, C);
    cout << "Completado en " << paso << " pasos.\n";

    destruir(A);
    destruir(B);
    destruir(C);
    return 0;
}
