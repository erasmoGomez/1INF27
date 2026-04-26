#include "src/FuncionesPila.hpp"

int main() {
    /*Funciones de Pila*/
    struct Pila pila{};
    struct ElementoPila elemento{};
    construir(pila);
    /*Apilamos elementos en la pila*/
    for (int i = 1; i <= 10; i++) {
        elemento.numero = i;
        apilar(pila, elemento);
    }
    imprimir(pila);

    /*Desapilamos elementos en la pila*/
    while (not esPilaVacia(pila)) {
        elemento = desapilar(pila);
        cout << "Desapilando: " << elemento.numero << endl;
    }
    imprimir(pila);
    return 0;
}
