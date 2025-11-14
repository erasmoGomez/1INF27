#include "src/Funciones.hpp"

int main() {
    //Empresa minera: Robot perforador
    //2024-2  pregunta 2
    int arreglo[10][10]{
            {0, 0,  0, 3, 3, 7, 5, 5, 1, 1},
            {8, 8, 10, 9, 9, 5, 4, 4, 2, 0},
            {3, 5,  8, 9, 7, 6, 4, 2, 0, 0},
            {9, 7,  7, 4, 4, 4, 2, 0, 0, 0},
            {0, 2,  2, 3, 3, 4, 4, 5, 3, 3},
            {0, 0,  0, 0, 0, 0, 2, 3, 4, 5},
            {1, 2,  2, 3, 3, 4, 3, 2, 0, 0},
            {0, 0,  0, 0, 0, 0, 3, 5, 5, 7},
            {6, 5,  5, 2, 2, 1, 0, 0, 0, 0},
            {3, 2,  2, 0, 0, 0, 0, 0, 0, 0}
    };

    int n = 10;
    int max = -99, iMax, j, jMax;
    //cout << endl << "7, 10, 9, 9, 5, 5, 4, 7, 6, 3" << endl; //para probar la salida del programa
    for(int i = 0; i < n; i++){
        int dato = buscaMontana(arreglo[i], 0, n - 1, j);
        //cout << dato << ", ";
        if(dato > max) {
            max = dato;
            iMax = i;
            jMax = j;
        }
    }
    cout <<endl<< "La maxima pureza de las muestras es: "<< max << " (encontrado en la muestra " << iMax + 1
         << ", en el estrato " << jMax + 1<<")" <<endl;

    max = -99;
    int dato;
    for(int i = 0; i < n; i++){
        if(arreglo[i][0] == 0) //observo si tienes ceros empezando por la izquierda
            dato = 10 - cuentaCerosIzq(arreglo[i], 0, n - 1, 0);
        else
            dato = 10 - cuentaCerosDer(arreglo[i], 0, n - 1, 0);
        //cout << "DATO: " << dato << endl;
        if(dato > max)
            max = dato;
    }
    cout << "Las muestras con mayor cantidad de niveles con minerales son: ";

    for(int i = 0; i < n; i++){
        if(arreglo[i][0]==0)
            dato = 10 - cuentaCerosIzq(arreglo[i], 0, n - 1, 0);
        else
            dato = 10 - cuentaCerosDer(arreglo[i], 0, n - 1, 0);
        //cout << "DATO: " << dato << endl;
        if(dato == max)
            cout << i + 1<< ", ";

    }
    cout << " ambos con " << max << " estratos de minerales. ";
    return 0;
    return 0;
}
