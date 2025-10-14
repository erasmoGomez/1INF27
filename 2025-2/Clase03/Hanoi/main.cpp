#include <iostream>

using namespace std;

void mover(int n_discos, char source, char target) {
    cout << "Mover Disco: " << n_discos << " desde el poste " << source;
    cout << " hacia el poste " << target << endl;
}

int hanoi(int n_discos, char source, char aux, char target) {
    //Caso Base
    if (n_discos == 1) {
        mover(n_discos, source, target);
    }
    else{
        //Caso Recursivo
        hanoi(n_discos-1, source, target, aux);
        mover(n_discos, source, target);
        hanoi(n_discos-1, aux, source, target);
    }
}

int main() {
    int n_discos = 4;
    //Condiciones:
    //Poste A : Source
    //Poste B : Auxiliar
    //Poste C : Target
    cout << "El resultado de movimientos de HANOI para" << endl;
    cout << n_discos << "es: " << hanoi(n_discos, 'A', 'B', 'C');

    return 0;
}
