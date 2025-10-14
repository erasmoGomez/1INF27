//
// Created by Erasmo on 26/09/25.
//

#include <iostream>
#include <stdexcept>
#include "Pila.hpp"
#include "FuncionesPila.hpp"
#include "Hanoi.hpp"
using namespace std;

static void moverTope(Pila &desde, Pila &hasta) {
    cout<<"Mover Tope: "<< &desde<<"  "<< &hasta<<endl;
    ElementoPila e = desapilar(desde);
    if (!esPilaVacia(hasta)) {
        ElementoPila t = cima(hasta);
        if (e.numero > t.numero) {
            // revertir y reportar
            apilar(desde, e);
            throw runtime_error("Movimiento invalido: disco mayor sobre menor.");
        }
    }
    apilar(hasta, e);
}

static void imprimirEstado(const Pila &A, const Pila &B, const Pila &C) {
    cout << "A="; imprimir(A);
    cout << "  B="; imprimir(B);
    cout << "  C="; imprimir(C);
    cout << '\n';
}

void hanoiConImpresion(int n,
                       Pila &origen, Pila &auxiliar, Pila &destino,
                       char nOri, char nAux, char nDes,
                       int &paso,
                       Pila &Aref, Pila &Bref, Pila &Cref) {
    if (n == 0) return;

    hanoiConImpresion(n-1,
                      origen, destino, auxiliar,
                      nOri, nDes, nAux, paso,
                      Aref, Bref, Cref);

    moverTope(origen, destino);
    ++paso;
    cout << "Paso " << paso << ": " << nOri << " -> " << nDes << "   "<<endl;
    cout<<"Pilas para impresion: "<< &Aref<<"  "<< &Bref<<" "<<&Cref<<endl;
    imprimirEstado(Aref, Bref, Cref);

    hanoiConImpresion(n-1, auxiliar, origen, destino,
                      nAux, nOri, nDes, paso,
                      Aref, Bref, Cref);
}
