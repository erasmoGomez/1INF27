#include "src/Funciones.hpp"

int main() {
    //1.

    int arreglo2[]{1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    int n = sizeof(arreglo2) / sizeof(arreglo2[0]);
    cout<<buscaSolo(arreglo2, 0, n - 1)<<endl;

    //2.

    int arreglo[]{0, 0, 0, 1, 1, 1, 1, 1}; //UNOS A LA DERECHA
    //int arreglo[]{1, 1, 1, 1, 0, 0, 0}; //UNOS A LA IZQUIERDA
    n = sizeof(arreglo) / sizeof(arreglo[0]);

    cout << "CUENTA CEROS: " << cuentaCeros(arreglo, 0, n - 1, 0) << endl;



    cout << endl;
    int arreglo3[]{8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}; //funciona por que se forma una montaña
    n = sizeof(arreglo3) / sizeof(arreglo3[0]);
    cout << "EL PUNTO MÁS ALTO DE LA MONTAÑA: " << buscaMontana(arreglo3, 0, n - 1) << endl;
//
    /* Busca el menor*/
    int arreglo4[]{5, 6, 1, 2, 3, 4};
    n = sizeof(arreglo4) / sizeof(arreglo4[0]);

    cout << "EL PUNTO MÁS BAJO ES: " << buscaMenor(arreglo4, 0, n - 1) << endl << endl;

//    /*suma máxima consecutiva*/
//    int arreglo5[8]{-2, -5, 6, -2, -3, 1, 5, -6};
//    n = sizeof(arreglo5) / sizeof(arreglo5[0]);
//    cout << "Salida máxima: " << sumaMaximaConsecutiva(arreglo5, 0, n - 1) << endl << endl;
//
//    /*Tráfico de la red de una organización - 2024-1_Lab3*/
//    /*suma mínima consecutiva*/
//    /* int arreglo6[] {2, 5, -6, 2, 3, -1, -5, 6} ;
//       int arreglo6[] {2, -3, 4, -5, -7} ; n = 5;
//       int arreglo6[] {-4, 5, 6, -4, 3, -1, -5, 6} ;
//     */
//    int arreglo6[] {2, -3, 4, -5, -7};
//    n = sizeof(arreglo6) / sizeof(arreglo6[0]);
//    cout << "Salida mínima: " << sumaMinimaConsecutiva(arreglo6, 0, n - 1) << endl;
//
//
//    /*Ejercicio Oppenheimer - 2024-1_Lab3*/
//    //int arreglo7[]{-1, 0, -1, 0, 1, 1, 2, 2, 3, 3, 4, 3, 3, 2, 2, 1, 1};
//    int arreglo7[]{0, -1, 0, -1, 0, 1, 1, 2, 2, 3, 2, 2, 1, 1};
//    n = sizeof(arreglo7) / sizeof(arreglo7[0]);
//
//    int inicio = cuentaCeros(arreglo7, 0, n - 1, 0);
//    cout << endl <<"La radiación empieza a " << inicio <<" km. Potencia máxima ";
//    buscaSolo(arreglo7, inicio, n-1); cout << " megatones" <<endl;
//
//
//    int arreglo8[]{3, 8, 4, 2, 1};
//    n = sizeof(arreglo8) / sizeof(arreglo8[0]);
//    cout << "Número de inversiones: " << numeroInversiones(arreglo8, 0, n - 1) << endl;
    return 0;
}
