#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"

using namespace std;

int main() {

    struct ArbolBinario arbol, arbol1, arbol2, arbol3, arbol4, arbol5;
    struct ArbolBinario arbol6, arbol7, arbol8, arbol9, arbol10, arbol11, arbol12;
    struct ArbolBinario arbol13, arbol14, arbol15, arbol16, arbol17, arbol18, arbolVacio;

    construir(arbol);
    construir(arbolVacio);
    //Nivel 6
    //arbol1 O HI NULL HD NULL
    plantarArbolBinario(arbol1, arbolVacio, {'O'}, arbolVacio);
    //arbol2 S HI NULL HD NULL
    plantarArbolBinario(arbol2, arbolVacio, {'S'}, arbolVacio);
    //arbol3 S HI NULL HD NULL
    plantarArbolBinario(arbol3, arbolVacio, {'S'}, arbolVacio);

    //Nivel 5
    //arbol4 A HI arbol1 HD NULL
    plantarArbolBinario(arbol4, arbol1, {'A'}, arbolVacio);
    //arbol5 A HI NULL HD NULL
    plantarArbolBinario(arbol5, arbolVacio, {'A'}, arbolVacio);
    //arbol6 O HI NULL HD arbol2
    plantarArbolBinario(arbol6, arbolVacio, {'O'}, arbol2);
    //arbol7 A HI NULL HD NULL
    plantarArbolBinario(arbol7, arbolVacio, {'A'}, arbolVacio);
    //arbol8 O HI NULL HD arbol3
    plantarArbolBinario(arbol8, arbolVacio, {'O'}, arbol3);

    //Nivel 4
    //arbol9 A HI NULL HD NULL
    plantarArbolBinario(arbol9, arbolVacio, {'N'}, arbolVacio);
    //arbol10 A HI arbol4 HD NULL
    plantarArbolBinario(arbol10, arbol4, {'B'}, arbolVacio);
    //arbol11 N HI arbol5 HD arbol6
    plantarArbolBinario(arbol11, arbol5, {'N'}, arbol6);
    //arbol12 R HI arbol7 HD arbol8
    plantarArbolBinario(arbol12, arbol7, {'R'}, arbol8);

    //Nivel 3
    //arbol13 E HI arbol9 HD NULL
    plantarArbolBinario(arbol13, arbol9, {'E'}, arbolVacio);
    //arbol14 L HI arbol10 HD NULL
    plantarArbolBinario(arbol14, arbol10, {'L'}, arbolVacio);
    //arbol15 E HI arbol11 HD NULL
    plantarArbolBinario(arbol15, arbol11, {'E'}, arbolVacio);
    //arbol16 R HI NULL HD arbol12
    plantarArbolBinario(arbol16, arbolVacio, {'R'}, arbol12);

    //Nivel 2
    //arbol17 I HI arbol13 HD arbol14
    plantarArbolBinario(arbol17, arbol13, {'I'}, arbol14);
    //arbol18 U HI arbol15 HD arbol16
    plantarArbolBinario(arbol18, arbol15, {'U'}, arbol16);

    //Nivel 1
    //arbol B HI arbol17 HD arbol18
    plantarArbolBinario(arbol, arbol17, {'B'}, arbol18);

    recorrerPreOrdenPalabras(arbol);


    return 0;
}