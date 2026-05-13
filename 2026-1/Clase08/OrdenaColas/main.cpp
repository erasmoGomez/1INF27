#include "Librerias/Estructuras.hpp"
#include "Librerias/FuncionesColas.hpp"

int main() {
    struct Cola cola;
    construir(cola);
    cout<<"La cola está vacía: "<<esColaVacia(cola)<<endl;
    encolar(cola, 8);
    encolar(cola, 21);
    encolar(cola, 10);
    encolar(cola, 15);
    encolar(cola, 7);
    imprime(cola);
    // Ahora Ordenen la cola SOLO usando iterativas sin recursión.
    ordenar_cola_iterativo(cola);
    // ordenarec(cola,cola.lista.longitud);
    imprime(cola);

    //destruirCola(cola);
    destruir_cola_chevere(cola);
    return 0;
}