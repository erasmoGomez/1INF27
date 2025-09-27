#include "src/Cola.hpp"
#include "src/FuncionesColas.hpp"

int main() {
    struct Cola cola{};
    struct ElementoCola e{};
    //Construir
    construir(cola);

    cout<< "La cola esta vacia: "<<esColaVacia(cola)<<endl;

    //Encolamos datos en la cola
    for(int i = 4; i<20; i+=3){
        e.codigo = i;
        encolar(cola, e);
    }

    imprimir(cola);

    //Desencolar
    while(not esColaVacia(cola)){
        e = desencolar(cola);
        cout<<"Desencolando: "<<e.codigo<<endl;
    }
    imprimir(cola);
    return 0;
}
