#include "src/Knapsack.hpp"

// Fuerza bruta con poda temprana y mejores tipos para máscaras y acumuladores

int main() {
    // En algoritmia no tienen que crear un archivo o leer datos
    // Pueden Hardcodear los datos en estructuras o arreglos o matrices o cualquier tiepo de dato.
    Item items[] = {
            {10, 60},  // Item 1
            {20, 100}, // Item 2
            {30, 120}, // Item 3
            {15, 80}   // Item 4
    };
    int n = 4; // La cantidad de ese arreglo
    int capacity = 50; // Capacidad de la mochila en weight

    knapsackBruteForce(items, n, capacity, true);
    return 0;
}

// {{10, 60}, {20, 100}, {30, 120}, {15,80}}