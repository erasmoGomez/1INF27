//
// Created by Erasmo on 31/10/25.
//

#ifndef MERGESORT_FUNCIONES_HPP
#define MERGESORT_FUNCIONES_HPP

#include "Utils.hpp"

void mergeSort(int *arreglo, int inicio, int fin);

void merge(int *arreglo, int inicio, int centro, int fin);

int busquedaBinaria(int *arreglo, int clave, int inicio, int fin);

void imprime(int *arreglo, int n);

#endif //MERGESORT_FUNCIONES_HPP
