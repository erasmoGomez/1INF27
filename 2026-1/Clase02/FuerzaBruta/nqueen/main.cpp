#include <iostream>
#include <iomanip>

using namespace std;

// Imprime un tablero 4x4 donde pos[fila] = columna de la reina en esa fila
void imprimirTablero(const int pos[4], int idx) {
    cout << "Estado #" << idx << "  [";
    for (int i = 0; i < 4; ++i) {
        cout << pos[i] << (i < 3 ? ' ' : ']');
    }
    cout << "\n";
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            cout << (pos[r] == c ? 'Q' : '.');
        }
        cout << '\n';
    }
    cout << "----\n";
    /*
     * Recorre cada fila r.

        Dentro, recorre cada columna c.

        Si en esa fila la reina está en la columna c (pos[r] == c), imprime 'Q'.

        Si no, imprime '.' (casilla vacía).

     */
}

// Valida que la configuración pos[] (pos[fila] = columna) no tenga conflictos
bool esValida(const int *pos, int N) {
    //Recorre todos los pares de reinas (i y j → filas distintas).
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (pos[i] == pos[j]) return false; // Si dos reinas están en la misma columna, se atacan.
            /* Ejemplo:
             *  fila 0 → col 2
                fila 3 → col 2   X (choque en columna 2)
             */
            if (abs(pos[i] - pos[j]) == abs(i - j)) return false; // misma diagonal
            /*
             * Dos reinas están en la misma diagonal si diferencia de filas = diferencia de columnas
             * Ejemplo:

                Reina A en (fila 0, col 1)

                Reina B en (fila 2, col 3)

                Diferencias: |1-3| = 2 y |0-2| = 2 → misma diagonal → X conflicto.
             */
        }
    }
    return true; //Si el bucle termina sin encontrar conflictos, la configuración es válida.

    /*
     * pos = {1, 3, 0, 2};  // N=4
        Comparaciones:

        (fila 0, col 1) vs (fila 1, col 3): difCol=2, difFil=1 → no choque

        (fila 0, col 1) vs (fila 2, col 0): difCol=1, difFil=2 → no choque

        (fila 0, col 1) vs (fila 3, col 2): difCol=1, difFil=3 → no choque

        (fila 1, col 3) vs (fila 2, col 0): difCol=3, difFil=1 → no choque

        (fila 1, col 3) vs (fila 3, col 2): difCol=1, difFil=2 → no choque

        (fila 2, col 0) vs (fila 3, col 2): difCol=2, difFil=1 → no choque

        {1,3,0,2} es una de las 2 soluciones de 4-Queens.
     */
}

int main() {
    // pos[r] = columna elegida (0..3) para la fila r
    int pos[4] = {0, 0, 0, 0}; // estado inicial (todas las reinas en col=0)
    /*
     * Pos[r] = la columna elegida para la reina en la fila r.
        Ejemplo: pos = {1, 3, 0, 2} significa:

        fila 0 → reina en columna 1

        fila 1 → reina en columna 3

        fila 2 → reina en columna 0

        fila 3 → reina en columna 2
     */
    int count = 0;
    bool terminado = false;
    int soluciones[10]{};
    int n_soluciones = 0;
    while (!terminado) {
        imprimirTablero(pos, count);


        if (esValida(pos, 4)) {
            soluciones[n_soluciones] = count;
            n_soluciones++;
        }
        ++count;
        // Incremento en base 4 del "odómetro": pos[3]++, con acarreos hacia la izquierda
        int k = 3;
        while (k >= 0) {
            if (pos[k] + 1 < 4) {
                pos[k] += 1;
                break;
            }
            pos[k] = 0; // acarreo
            --k;
        }
        if (k < 0) terminado = true; // overflow: ya recorrimos todas las 4^4 combinaciones
        /*
         *  {0,0,0,0}  -> estado 0
            {0,0,0,1} -> estado 1
            {0,0,0,2} -> estado 2
            {0,0,0,3} -> estado 3
            {0,0,1,0}  -> estado 4
            ...
            {3,3,3,3}  -> estado 255
         */
    }

    cout << "Total de estados impresos: " << count << "\n"; // debería ser 256
    cout << "Las soluciones : " << endl;
    for (int i = 0; i < n_soluciones; i++) cout << setw(5) << soluciones[i];
    cout << endl;
    return 0;
}
