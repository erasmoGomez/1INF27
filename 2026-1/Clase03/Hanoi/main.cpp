#include <iostream>

using namespace std;

void mover(int n_discos, char source, char target) {
    cout << "Mover Disco: " << n_discos << " desde el poste " << source;
    cout << " hacia el poste " << target << endl;
}

int hanoi(int n_discos, char source, char aux, char target, int &n_movimientos) {
    //Caso Base
    if (n_discos == 1) {
        mover(n_discos, source, target);
    }
    else{
        //Caso Recursivo
        hanoi(n_discos-1, source, target, aux, ++n_movimientos);
        mover(n_discos, source, target);
        cout<< "Movimiento" << n_movimientos<<endl;
        hanoi(n_discos-1, aux, source, target, ++n_movimientos);
    }
}

int main() {
    int n_discos = 3;
    //Condiciones:
    //Poste A : Source
    //Poste B : Auxiliar
    //Poste C : Target
    cout << "El resultado de movimientos de HANOI para" << endl;
    int n_movimientos = 0;
    cout << n_discos << "es: " << hanoi(n_discos, 'A', 'B', 'C', n_movimientos);

    return 0;
}
