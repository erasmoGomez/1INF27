#include <iostream>

#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
using namespace std;

int main(int argc, char **argv) {
    struct ArbolBinario arbol, abcedario;
    struct ArbolBinario arbol1, arbol2, arbol3, arbol4, arbolVacio;
    struct ArbolBinario hijoIzquierdo, hijoDerecho;

    construir(arbol);
    construir(arbolVacio);

    plantarArbolBinario(arbol1, arbolVacio, {25}, arbolVacio);
    plantarArbolBinario(arbol2, arbolVacio, {80}, arbolVacio);
    plantarArbolBinario(arbol3, arbolVacio, {120}, arbolVacio);
    plantarArbolBinario(arbol4, arbolVacio, {200}, arbolVacio);
    plantarArbolBinario(hijoIzquierdo, arbol1, {50}, arbol2);
    plantarArbolBinario(hijoDerecho, arbol3, {150}, arbol4);
    plantarArbolBinario(arbol, hijoIzquierdo, {100}, hijoDerecho);

    struct ElementoArbolBinario arreglo[]{
        { 25, 'A'},
        { 50, 'B'},
        { 80, 'C'},
        {100, 'D'},
        {120, 'E'},
        {150, 'F'},
        {200, 'G'}
    };
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    construir(abcedario);
    //este sirve para árboles ABB
    llenarArbol(abcedario, arreglo, 0, n);

    cout << "Recorrer en En orden: " << endl;
    recorrerEnOrden(abcedario);
    cout << endl;

    cout << "Recorrer en pre orden: " << endl;
    recorrerPreOrden(arbol);
    cout << endl;

    cout << "Recorrer en Post orden: " << endl;
    recorrerPostOrden(arbol);
    cout << endl;

    cout << "Numero de hojas: " << numeroHojas(arbol) << endl;
    cout << "Numero de nodos: " << numeroNodos(arbol) << endl;
    cout << "Altura arbol: " << altura(arbol) << endl;
    cout << "Es equilibrado: " << esEquilibrado(arbol) << endl;

    cout << endl;
    cout << "Imprimir por niveles: " << endl;
    recorridoPorNivel(arbol);

    cout << endl << endl;
    cout << "Imprimir por niveles con cambio de linea: " << endl;
    recorridoPorNivelCambioLinea(arbol);

    cout << endl; //Función que me deja sin arbol
    cout << "Imprimir en orden Iterativo usando una pila y apilando el nodo del arbol: " << endl;
    enOrdenIterativo(abcedario);

    cout << endl;
    cout << "Imprimir en pre orden Iterativo usando una pila y apilando el nodo del arbol: " << endl;
    postOrdenIterativo(abcedario);

    cout << endl;
    cout << "Recorrer en Post orden: " << endl;
    recorrerPostOrden(abcedario);

    /*Parte de prueba para pregunta de cúmulos*/
    struct ArbolBinario cumulo;
    construir(cumulo);
    //int arregloDatos[]{3, 5, 7, 6, 8, 9}; //en ese orden entran
    //int arregloDatos[]{3, 5, 7, 9, 8, 6};
    int arregloDatos[]{3, 5, 7, 9, 8, 6, 2};
    n = sizeof(arregloDatos) / sizeof(arregloDatos[0]);

    for (int i = 0; i < n; i++)
        insertarEnCumulo(cumulo, arregloDatos[i]);

    cout << endl << endl;
    cout << "Imprimir por niveles con cambio de linea: " << endl;
    recorridoPorNivelCambioLinea(cumulo);

    return 0;
}
