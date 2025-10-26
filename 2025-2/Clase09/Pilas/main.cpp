#include "src/Funciones.hpp"

int randomEntero(int min, int max) {
    return rand() % (max - min + 1) + min; //Transformacion matematica
}

int main() {
//    int jardin[4][4] = {1,1,1,0,
//                        1,1,1,0,
//                        1,1,1,1,
//                        0,0,0,0};
//    int n = 4, m = 4;
//    // Convertir a arreglo de punteros (int**) sin modificar la matriz original
//    int* ptrs[4];
//    for (int i = 0; i < n; ++i)
//        ptrs[i] = jardin[i];
//
//    int respuesta = area_maxima_cortes(ptrs, 4, 4);
//    cout << respuesta << "\n";

    srand(time(0)); // semilla
    int numero = randomEntero(1, 100); // número entre 10 y 50
    cout << "Número aleatorio entre 1 y 100: " << numero << endl;
    if(numero > 50) cout<<"Aprobamos"<<endl;
    else
        cout<<"Bicas"<<endl;
    //cout<<rand()<<endl;
    return 0;
}
