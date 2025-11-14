#include "src/BibliotecaArboles/ArbolBinario.hpp"
#include "src/FuncionesArbol.hpp"
#include "src/FuncionesCola.hpp"

int main() {
    struct ArbolBinario arbol, arbolVacio, arbol_nivel;
    struct ArbolBinario subarbol50, subarbol150;
    struct ArbolBinario subarbol25, subarbol80, subarbol120, subarbol200;
    construir(arbol);
    construir(arbolVacio); //CONSTRUIR OBLIGATORIAMENTE
    // PARA CONSTRUIR EL ARBOL, VAMOS DESDE EL NIVEL MAS ALTO HACIA EL MAS BAJO
    cout<<"Esta vacio"<< esArbolVacio(arbol)<<endl;
    /*           100
     *         /     \
     *       50      150
     *      /  \    /   \
     *    25   80 120   200
     *  NULL NULL
     */
    // NIVEL 3
    //subarbol25 NODO 25 HI NULL HD NULL
    plantarArbolBinario(subarbol25, arbolVacio, {25}, arbolVacio);
    //subarbol80 NODO 80 HI NULL HD NULL
    plantarArbolBinario(subarbol80, arbolVacio, {80}, arbolVacio);
    //subarbol120 NODO 120 HI NULL HD NULL
    plantarArbolBinario(subarbol120, arbolVacio, {120}, arbolVacio);
    //subarbol200 NODO 200 HI NULL HD NULL
    plantarArbolBinario(subarbol200, arbolVacio, {200}, arbolVacio);

    // NIVEL 2
    //subarbol50 NODO 50 HI subarbol25 HD subarbol80
    plantarArbolBinario(subarbol50, subarbol25, {50}, subarbol80);
    //subarbol150 NODO 150 HI subarbol120 HD subarbol200
    plantarArbolBinario(subarbol150, subarbol120, {150}, subarbol200);

    // NIVEL 1
    //arbol NODO 100 HI subarbol50 HD subarbol150
    plantarArbolBinario(arbol, subarbol50, {100}, subarbol150);
    //Hasta este punto tenemos el arbol ARMADO, CONECTADO Y CON RESERVA DE MEMORIA CORRECTA.

    // RECORDDOS Y SUS FUNCIONALIDADES
    cout<<"\nRECORRIDOS DFS"<<endl;
    cout<<"\nrecorrido en order"<<endl; // IMPRIME EN ORDEN EN UN ABB
    recorrer_in_order(arbol);
    cout<<"\nrecorrido post order"<<endl; // SE USA TAMBIEN PARA ELIMINAR NODOS EN UN ARBOL
    recorrer_post_order(arbol);
    cout<<"\nrecorrido pre order"<<endl; // RECONSTRUCCION DE ARBOL
    recorrer_pre_order(arbol);

    cout<<"\n\nRECORRIDOS BFS"<<endl;
    cout<<"\nrecorrido por nivel"<<endl;
    recorrido_por_niveles(arbol);
    cout<<"\nrecorrido por nivel recursivo"<<endl;
    recorrido_por_niveles_recursivo(arbol);

    // INSERCIONES POR NIVEL
    int a[] = {30, 20, 40, 50, 10};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"\n\nINSERCION BFS"<<endl;
    cout<<"\nrecorrido por nivel recursivo"<<endl;
    insertar_por_nivel(arbol_nivel, a, n);
    recorrido_por_niveles_recursivo_salto(arbol_nivel);
    imprimir_arbol_horizontal(arbol_nivel.raiz);

    return 0;
}
