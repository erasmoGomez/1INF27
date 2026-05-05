#include "src/FuncionesLista.hpp"
#include "src/Pila.hpp"
#include "src/FuncionesPilas.hpp"
#include "src/FuncionesLaberinto.hpp"
#include <iostream>
using namespace std;
int main() {
    //PLANTEO DEL PROBLEMA
    struct Pila pila; // Me sirve para guardar informacion secuencial.

    construir(pila);
    int tablero[3][5] = {{1, 0, 1, 1, 1},
                         {1, 1, 1, 0, 1},
                         {0, 0, 1, 0, 1}};
    // Vayan desde (0,0) hasta (2,4)
    bool terminado;

    mostrar(tablero);
    // SOLUCION
    terminado = laberinto(pila, tablero, 0, 0);
    if(terminado)
        mostrar(tablero);
    else
        cout<<"No fue posible terminar el laberinto";
    destruirPila(pila);
    return 0;
}
/*
    E
A   B   C   D
Pila
Apilar es AVANZAR
E -> B A      AQUI ESTOY EN B
E -> C B A    AQUI ESTOY EN C
Desapilar es RETROCEDER
E -> B A      AQUI ESTOY EN B
*/