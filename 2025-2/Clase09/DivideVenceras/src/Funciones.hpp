//
// Created by Erasmo on 24/10/25.
//

#ifndef DIVIDEVENCERAS_FUNCIONES_HPP
#define DIVIDEVENCERAS_FUNCIONES_HPP
#include "Utils.hpp"

int mergeInversionesCentro(int * arreglo, int inicio, int centro, int fin);
int numeroInversiones(int * arreglo, int inicio, int fin);
int sumaCentroMinimaConsecutiva(int * arreglo, int inicio, int med, int fin);
int sumaMinimaConsecutiva(int * arreglo, int inicio, int fin);
int sumaCentroMaximaConsecutiva(int * arreglo, int inicio, int med, int fin);
int sumaMaximaConsecutiva(int * arreglo, int inicio, int fin);
int buscaMenor(int * arreglo, int inicio, int fin);
int buscaMontana(int *arreglo, int inicio, int fin);
int buscaSolo(int *arr, int ini, int fin);
int cuentaCeros(int * arr, int ini, int fin, int cont);
int cuentaUnos(int * arr, int ini, int fin);

#endif //DIVIDEVENCERAS_FUNCIONES_HPP
