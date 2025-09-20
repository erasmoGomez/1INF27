#include "src/BibliotecaLista.hpp"

int main() {
    struct Elemento elemento{};
    struct Lista listaInicio, listaFinal, listaEnOrden;

    construir(listaInicio);
    construir(listaFinal);
    construir(listaEnOrden);
    cout << "La lista esta vacia: " << esListaVacia(listaInicio) << endl;

    for (int i = 1; i < 10; i+=2) {
        elemento.numero = i;
        insertar_inicio(listaInicio, elemento);
    }
    imprimir(listaInicio);

    /*Inserta datos desde el final de la lista*/
    for (int i = 4; i < 7; i++) {
        elemento.numero = i;
        insertar_final(listaFinal, elemento);
    }
    imprimir(listaFinal);

    elemento.numero = 75;
    insertar_ordenado(listaEnOrden, elemento);
    elemento.numero = 5;
    insertar_ordenado(listaEnOrden, elemento);
    elemento.numero = 25;
    insertar_ordenado(listaEnOrden, elemento);
    elemento.numero = 85;
    insertar_ordenado(listaEnOrden, elemento);


    imprimir(listaEnOrden);

    /*Elimina un nodo de la lista correspondiente al elemento ingresado*/
    // [1, 10, 6]
    // para que pueda eliminar busca el elemento dentro de la lista para eliminarlo
    elemento.numero = 85;
    eliminar_nodo(listaEnOrden, elemento);
    imprimir(listaEnOrden);

    destruir(listaEnOrden);
    imprimir(listaEnOrden);
    return 0;
}
