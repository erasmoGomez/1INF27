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

    struct ArbolBinarioBusqueda arbol;
    construir(arbol);

    insertar(arbol,{20220815,40});
    insertar(arbol,{20220710,50});
    insertar(arbol,{20220930,30});
    insertar(arbol,{20220630,50});

    struct ArbolBinarioBusqueda arbol2;
    construir(arbol2);

    insertar(arbol2,{20220815,20});
    insertar(arbol2,{20220710,20});
    insertar(arbol2,{20220930,30});
    insertar(arbol2,{20220630,10});


    fusion(arbol, arbol2);
    recorrerEnOrden(arbol);
    despacha(arbol,10);
    cout << endl;
    cout << "Resultado después de despachar \n";
    recorrerEnOrden(arbol);
    destruirArbolBinario(arbol);

    return 0;
}