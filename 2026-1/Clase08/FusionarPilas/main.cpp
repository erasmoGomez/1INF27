//Fecha:  viernes 10 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
#include "funciones.h"

using namespace std;

int main(int argc, char **argv) {


    struct Pila pilaA, pilaB, pilaC;

    construir(pilaA);
    construir(pilaB);
    construir(pilaC);

    apilar(pilaA, {20});
    apilar(pilaA, {15});
    apilar(pilaA, {5});

    apilar(pilaB, {18});
    apilar(pilaB, {12});
    apilar(pilaB, {10});
    apilar(pilaB, {2});

    cout << "INICIO" << endl;
    cout << "A: " ; imprimir(pilaA);
    cout << "B: " ;imprimir(pilaB);
    cout << "C: " ;imprimir(pilaC);

    fusionarPilas(pilaA, pilaB, pilaC);

    cout << endl << "FIN" << endl;
    cout << "A: " ; imprimir(pilaA);
    cout << "B: " ;imprimir(pilaB);
    cout << "C: " ;imprimir(pilaC);
    return 0;
}