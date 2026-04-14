//Fecha:  miércoles 15 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "funciones.h"
using namespace std;

int main(int argc, char **argv) {

    /*El problema es mostrar el movimiento de los bloques de un almacén A a un almacén C
     *sin colocar un paquete pesado sobre otro menos pesado
     *los discos se pueden mover entre almacenes adyacentes
     **/

    int numDiscos = 3;
    hanoiModificado(numDiscos, 'A', 'B', 'C');
    return 0;
}