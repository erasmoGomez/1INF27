#include "src/BibliotecaArboles/ArbolBinario.hpp"
#include "src/FuncionesArbol.hpp"
int main() {
    struct ArbolBinario arbol, arbolVacio;
    struct ArbolBinario hijo_izquierdo, hijo_derecho;
    struct ArbolBinario arbol1, arbol2, arbol3, arbol4;
    construir(arbol);
    construir(arbolVacio);
    cout<<"Esta vacio"<< esArbolVacio(arbol)<<endl;
    /*           100
     *         /     \
     *       50      150
     *      /  \    /   \
     *    25   80 120   200
     */
    //arbol1 NODO 25 HI NULL HD NULL
    plantarArbolBinario(arbol1, arbolVacio, {25}, arbolVacio);
    //arbol2 NODO 80 HI NULL HD NULL
    plantarArbolBinario(arbol2, arbolVacio, {80}, arbolVacio);
    //arbol3 NODO 120 HI NULL HD NULL
    plantarArbolBinario(arbol3, arbolVacio, {120}, arbolVacio);
    //arbol4 NODO 200 HI NULL HD NULL
    plantarArbolBinario(arbol4, arbolVacio, {200}, arbolVacio);
    //hijo_izquierdo NODO 50 HI arbol1 HD arbol2
    plantarArbolBinario(hijo_izquierdo, arbol1, {50}, arbol2);
    //hijo_derecho NODO 150 HI arbol3 HD arbol4
    plantarArbolBinario(hijo_derecho, arbol3, {150}, arbol4);
    //arbol NODO 100 HI hijo_izquierdo HD hijo_derecho
    plantarArbolBinario(arbol, hijo_izquierdo, {100}, hijo_derecho);
    //Hasta este punto tenemos el arbol armado.

    cout<<"recorrido en order"<<endl;
    recorrer_in_order(arbol);
    return 0;
}
