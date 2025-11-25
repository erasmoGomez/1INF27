//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"

using namespace std;
/*
 * IMPLEMENTACION DEL TAD ARBOL BINARIO BÚSQUEDA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */
int main(int argc, char **argv) {

    /* ABB*/
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);

    /*Insertar uno a uno los nodos en un ABB*/
    insertar(arbol, {100});
    insertar(arbol, {50});
    insertar(arbol, {150});
    insertar(arbol, {125});
    insertar(arbol, {175});
    insertar(arbol, {200});
    insertar(arbol, {25});
    insertar(arbol, {75});

    //cout << "Recorrer en Orden: " << endl;
    //    25   50   75  100  125  150  175  200
    //recorrerEnOrden(arbol); cout<<endl;

    /*Insertar por el método de divide y vencerás*/
    /*Se cuenta con un arreglo de n datos, pueden estar desordenados
     *si estuvieran así primero se ordenan con un nergeSort y después
     *se pueden ingresar al árbol ABB
     */

    struct ArbolBinarioBusqueda arbolABB;
    construir(arbolABB);

    int arreglo[]{25, 50, 75, 100, 125, 150, 175, 200};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int inicio = 0, fin = n;
    llenarArbol(arbolABB, arreglo, inicio, fin-1);

    cout << "Recorrer en Orden: " << endl;
    //    25   50   75  100  125  150  175  200
    recorrerEnOrden(arbolABB); cout<<endl;


    /*Función de busqueda*/
    cout<<"Se encuentra 125 en arbol: "<<buscar(arbolABB, {200})<<endl;
    //
    eliminar(arbolABB, {175});
    eliminar(arbolABB, {25});
    eliminar(arbolABB, {150});
    eliminar(arbolABB, {100});
    //
    // cout << "Recorrer en Orden después del borrado: " << endl;
    // //     50   75  125  200
    recorrerEnOrden(arbolABB); cout<<endl;
    //
    destruirArbolBinario(arbolABB);

    return 0;
}