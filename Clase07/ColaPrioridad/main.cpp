#include <iostream>
#include "src/ColaPrioridad.hpp"
using namespace std;

static int prioDe(char tipo) {
    if (tipo == '1') return 1;
    if (tipo == '2') return 2;
    return 3;
}

int main() {
    ColaPrioridad cp{};
    construir(cp);

    Elemento a{1, '3'}; // baja
    Elemento b{2, '2'}; // media
    Elemento c{3, '1'}; // alta
    Elemento d{4, '2'}; // media
    Elemento e{5, '1'}; // alta

    encolar(cp, a, prioDe(a.tipo)); // entra a P3 (cola vacía => head=tail=a)
    encolar(cp, b, prioDe(b.tipo)); // P2 vacío y sin P1 -> se inserta al inicio: [b][a]
    encolar(cp, c, prioDe(c.tipo)); // P1 vacío -> va al inicio: [c][b][a]
    encolar(cp, d, prioDe(d.tipo)); // P2 ya existe -> se agrega tras last2: [c][b][d][a]
    encolar(cp, e, prioDe(e.tipo)); // P1 ya existe -> tras last1: [c][e][b][d][a]

    while (!esVacia(cp)) {
        Elemento x = desencolar(cp);
        cout << "Atendiendo id=" << x.id << " tipo=" << x.tipo << "\n";
    }

    destruir(cp);
    return 0;
}
