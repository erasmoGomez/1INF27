#include "src/Funciones.hpp"

int main() {
    Nodo *raiz = nullptr;

    // Armamos un ABB de ejemplo.
    // Ejemplo 1: generará casos de hij@ único hoja en varios niveles
    //            (y el postorden se encargará de limpiar desde abajo).
    raiz = insertarABB(raiz, 50);
    raiz = insertarABB(raiz, 30);
    raiz = insertarABB(raiz, 70);
    raiz = insertarABB(raiz, 20);
    raiz = insertarABB(raiz, 40);
    raiz = insertarABB(raiz, 60);
    raiz = insertarABB(raiz, 80);
    raiz = insertarABB(raiz, 75); // 75 será hijo único hoja de 80, etc.

    cout << "ABB antes del proceso (inorden): ";
    imprimirInOrden(raiz);
    cout << endl;

    eliminarHijosUnicos(raiz);

    cout << "ABB despues del proceso (inorden): ";
    imprimirInOrden(raiz);
    cout << endl;

    liberarABB(raiz);
    return 0;
}
