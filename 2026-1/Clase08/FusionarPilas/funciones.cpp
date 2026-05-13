//Fecha:  jueves 16 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
#include "funciones.h"

using namespace std;

void fusionarPilas(struct Pila & pilaA, struct Pila &pilaB, struct Pila &pilaC) {

    struct ElementoPila elementoA = desapilar(pilaA);
    struct ElementoPila elementoB = desapilar(pilaB);
    int cantElementosA, cantElementosB, cantElementosC;

    if (elementoA.numero < elementoB.numero) {
        apilar(pilaC, elementoB);
        apilar(pilaC, elementoA);
    }
    else {
        apilar(pilaC, elementoA);
        apilar(pilaC, elementoB);
    }
    cout << endl << "A: " ; imprimir(pilaA);
    cout << "B: " ;imprimir(pilaB);
    cout << "C: " ;imprimir(pilaC);

    while (not esPilaVacia(pilaA) and not esPilaVacia(pilaB)) {
        elementoA = cima(pilaA);
        elementoB = cima(pilaB);
        cantElementosC = longitud(pilaC);

        if (elementoA.numero > elementoB.numero) {
            hanoi(cantElementosC, pilaC, pilaB, pilaA);
            apilar(pilaC, desapilar(pilaB));
            hanoi(cantElementosC, pilaA, pilaB, pilaC);
        }
        else {
            hanoi(cantElementosC, pilaC, pilaA, pilaB);
            apilar(pilaC, desapilar(pilaA));
            hanoi(cantElementosC, pilaB, pilaA, pilaC);
        }

        cout << endl << "A: " ; imprimir(pilaA);
        cout << "B: " ;imprimir(pilaB);
        cout << "C: " ;imprimir(pilaC);

    }


    cantElementosC = longitud(pilaC);
    if (not esPilaVacia(pilaA)) {
        hanoi(cantElementosC, pilaC, pilaA, pilaB);
        apilar(pilaC, desapilar(pilaA));
        hanoi(cantElementosC, pilaB, pilaA, pilaC);
    }

    if (not esPilaVacia(pilaB)) {
        hanoi(cantElementosC, pilaC, pilaB, pilaA);
        apilar(pilaC, desapilar(pilaB));
        hanoi(cantElementosC, pilaA, pilaB, pilaC);
    }

}


void hanoi(int n, struct Pila & desde, struct Pila & auxiliar, struct Pila & hacia) {

    struct ElementoPila elemento;
    //CASO BASE
    if (n == 1) {
        elemento = desapilar(desde);
        apilar(hacia, elemento);
        return;
    }

    hanoi(n - 1, desde, hacia, auxiliar);
    elemento = desapilar(desde);
    apilar(hacia, elemento);
    hanoi(n - 1, auxiliar, desde, hacia);
}