#include <iostream>

using namespace std;

void print_binary_mask(int mask, int n) {
    // Imprime n bits (MSB -> LSB), sin usar string
    for (int i = n - 1; i >= 0; --i) {
        int bit = (mask >> i) & 1;
        cout << (bit ? '1' : '0');
        if (i % 4 == 0 && i != 0) cout << '\''; // separador cada 4 bits opcional
    }
}

void knapsack_bruteforce(const int *pesos, const int *valores, int n, int capacidad) {
    int mejorValor = 0;
    int mejorPeso = 0;
    int mejorMask = 0;

    const int total = 1 << n;
    for (int mask = 0; mask < total; ++mask) {
        int peso = 0, valor = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                peso += pesos[i];
                valor += valores[i];
            }
        }
        if (peso <= capacidad && valor > mejorValor) {
            mejorValor = valor;
            mejorPeso = peso;
            mejorMask = mask;
        }
    }

    // Reporte
    cout << "Mejor valor: " << mejorValor << "\n";
    cout << "Peso total: " << mejorPeso << " / Capacidad: " << capacidad << "\n";

    cout << "Cromosoma (n=" << n << " bits, MSB->LSB): ";
    print_binary_mask(mejorMask, n);
    cout << "\n";

    cout << "Items elegidos (indices 0..n-1): ";
    for (int i = 0; i < n; ++i)
        if (mejorMask & (1 << i)) cout << i << " ";
    cout << "\n";
}

int main() {
    const int n = 5;
    int pesos[n] = {2, 3, 4, 5, 9};
    int valores[n] = {3, 4, 5, 8, 10};
    int capacidad = 10;

    knapsack_bruteforce(pesos, valores, n, capacidad);
    return 0;
}

