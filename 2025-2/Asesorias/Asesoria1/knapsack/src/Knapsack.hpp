//
// Created by Erasmo on 31/08/25.
//

#ifndef KNAPSACK_KNAPSACK_HPP
#define KNAPSACK_KNAPSACK_HPP

#include "Utils.hpp"
#include "Item.hpp"

// Calcular total de combinaciones 2^n
unsigned total_combinations(int n);

// Imprimir máscara en binario
void print_mask_binary(unsigned mask, int n);

// Recorremos los n bits; poda si nos pasamos de capacidad
bool evaluate_mask(const Item items[], int n, unsigned mask, int capacity,
                   int &currWeight, int &currValue);

// Actualizamos el mejor (si empata en valor, preferimos menor peso)
void update_best_if_better(int currWeight, int currValue, unsigned mask,
                           int &bestWeight, int &bestValue, unsigned &bestMask);

// Reporte final
void print_solution(const Item items[], int n, unsigned bestMask,
                    int bestWeight, int capacity, int bestValue);

// ---------- Algoritmo principal ----------
void knapsackBruteForce(const Item items[], int n, int capacity, bool debug = false);

#endif //KNAPSACK_KNAPSACK_HPP
