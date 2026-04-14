//Fecha:  miércoles 15 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "funciones.h"
#include <fstream>
using namespace std;

void hanoiModificado(int numDiscos, char desde, char auxiliar, char hacia) {

    if (numDiscos == 1) {
        cout << "Mover el paquete 1 del almacen " << desde << " hacia el almacen " <<
            auxiliar << endl;
        cout << "Mover el paquete 1 del almacen " << auxiliar << " hacia el almacen " <<
            hacia << endl;
        return;
    }
        hanoiModificado(numDiscos-1, desde, auxiliar, hacia);
        cout << "Mover el paquete " << numDiscos << " desde el almacen " << desde << " hacia el almacen " <<
            auxiliar << endl;
        hanoiModificado(numDiscos - 1, hacia, auxiliar, desde);
        cout << "Mover el paquete " << numDiscos << " desde el almacen " << auxiliar << " hacia el almacen " <<
            hacia << endl;
        hanoiModificado(numDiscos - 1, desde, auxiliar, hacia);

}