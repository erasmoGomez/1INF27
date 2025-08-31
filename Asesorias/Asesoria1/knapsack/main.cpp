#include "src/Knapsack.hpp"

// Fuerza bruta con poda temprana y mejores tipos para máscaras y acumuladores

int main() {
    Item items[] = {
            {10, 60},  // Item 1
            {20, 100}, // Item 2
            {30, 120}, // Item 3
            {15, 80}   // Item 4
    };
    int n = 4;
    int capacity = 50;

    knapsackBruteForce(items, n, capacity);
    return 0;
}
