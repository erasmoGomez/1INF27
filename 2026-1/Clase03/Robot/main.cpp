#define M 3

#include <iostream>

using namespace std;

int robot(int x, int y, int n, int m, int mapa[][M]) {
    int derecha = -999999;
    int abajo = -999999;
    //Caso Base
    if (x == n - 1 and y == m - 1) return mapa[x][y];
    //Caso Recursivo + Boundary
    if (y + 1 < m) derecha = robot(x, y + 1, n, m, mapa);
    if (x + 1 < n) abajo = robot(x + 1, y, n, m, mapa);
    //Condiciones de Recojo
    if (derecha > abajo) return derecha + mapa[x][y];
    return abajo + mapa[x][y];
}

int main() {
    int n = 3;
    int m = 3;

    int mapa[][M] = {{5,  3,  20},
                     {-10, -25, 1},
                     {3,  1,  4}};
    int valor = robot(0, 0, n, m, mapa);
    cout << "El valor es obtenido es: " << valor << endl;
    return 0;
}
