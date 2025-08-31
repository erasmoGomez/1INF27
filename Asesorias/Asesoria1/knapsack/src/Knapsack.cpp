//
// Created by Erasmo on 31/08/25.
//

#include "Knapsack.hpp"

// Calcular total de combinaciones 2^n
unsigned total_combinations(int n) {
    const unsigned totalComb = (1u << n);  // 2^n combinaciones
    return totalComb;
}

// Imprimir máscara en binario
void print_mask_binary(unsigned mask, int n) {
    // Las combinaciones se calculan debido a que se representa mask como un número binario
    // Por ejemplo:
    // Para la combinación 6 -> 0110
    // Representa que se incluye el item 2 y 3
    // Para la combinación 12 -> 1011
    // Representa que se incluye el item 1, 3 y 4
    cout << "En binario: ";
    for (int i = n - 1; i >= 0; --i) {
        cout << ((mask & (1u << i)) ? '1' : '0');
    }
}

// Recorremos los n bits; poda si nos pasamos de capacidad
bool evaluate_mask(const Item items[], int n, unsigned mask, int capacity,
                   int &currWeight, int &currValue) {
    currWeight = 0;
    currValue = 0;
    for (int j = 0; j < n; ++j) {
        // Comparamos la Mask con J, pero primero activamos el bit correspondiente de J
        // con 1u << j (1u) este 1u es un 1 pero unsigned para evitar pasarnos a números negativos con bits.
        if (mask & (1u << j)) {
            //Si cumple, aumentamos el peso del item J al currWeight
            currWeight += items[j].weight;
            // Poda temprana: si ya nos pasamos, no seguimos sumando
            if (currWeight > capacity) {
                currValue = -1; // bandera para indicar invalido
                return false;
            }
            currValue += items[j].value;
        }
    }
    return true;
}

// Actualizamos el mejor (si empata en valor, preferimos menor peso)
void update_best_if_better(int currWeight, int currValue, unsigned mask,
                           int &bestWeight, int &bestValue, unsigned &bestMask) {
    if (currValue > bestValue or (currValue == bestValue and currWeight < bestWeight)) {
        bestValue = currValue;
        bestMask = mask;
        bestWeight = currWeight;
    }
}

// Reporte final
void print_solution(const Item items[], int n, unsigned bestMask,
                    int bestWeight, int capacity, int bestValue) {
    cout << "Items a incluir en la mochila:\n";
    for (int i = 0; i < n; ++i) {
        if (bestMask & (1u << i)) {
            cout << "- Item " << (i + 1)
                 << ": Weight=" << items[i].weight
                 << ", Value=" << items[i].value << "\n";
        }
    }
    cout << "Total Weight: " << bestWeight << "/" << capacity << "\n";
    cout << "Maximum Value: " << bestValue << "\n";
}

// ---------- Algoritmo principal ----------
void knapsackBruteForce(const Item items[], int n, int capacity, bool debug) {

    int bestValue = 0;
    unsigned bestMask = 0u;
    int bestWeight = 0;

    const unsigned totalComb = total_combinations(n);
    if (debug)
        cout << "Cantidad de combinaciones posibles: " << totalComb << endl;

    for (unsigned mask = 0u; mask < totalComb; ++mask) {
        if (debug) {
            cout << "Combination: " << mask << " ";
            print_mask_binary(mask, n);
            cout << endl;
        }

        int currWeight, currValue;
        if (!evaluate_mask(items, n, mask, capacity, currWeight, currValue)) continue; // combinación inválida

        update_best_if_better(currWeight, currValue, mask, bestWeight, bestValue, bestMask);
    }

    print_solution(items, n, bestMask, bestWeight, capacity, bestValue);
}