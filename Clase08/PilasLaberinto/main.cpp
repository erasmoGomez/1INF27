#include "src/FuncionesLista.hpp"
#include "src/Pila.hpp"
#include "src/FuncionesPilas.hpp"
#include "src/FuncionesLaberinto.hpp"
#include <iostream>
using namespace std;
int main() {
    struct Pila pila;

    construir(pila);
    int tablero[3][5] = {{1, 0, 1, 1, 1},
                         {1, 1, 1, 0, 1},
                         {0, 0, 1, 0, 1}};
    bool terminado;

    mostrar(tablero);
    terminado = laberinto(pila, tablero, 0, 0);
    if(terminado)
        mostrar(tablero);
    else
        cout<<"No fue posible terminar el laberinto";
    destruirPila(pila);
    return 0;
}
