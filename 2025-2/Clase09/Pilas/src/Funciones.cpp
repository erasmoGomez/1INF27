//
// Created by Erasmo on 24/10/25.
//

#include "Funciones.hpp"

//alturas = [2, 1, 5, 6, 2, 3]
//Fila 0: 1 1 1 0   AREA: 3
//Fila 1: 2 0 2 0   AREA: 2
//Fila 2: 3 1 3 1   AREA: 3
//Fila 3: 4 2 4 0   AREA: 6
int calcular_max_area(int *alturas, int n) {
    Pila s{};
    construir(s);

    int solucion = 0;

    for(int i = 0; i<n; i++){
        // Mientras la barra actual sea más baja que la de la cima
        while(!esPilaVacia(s) and alturas[cima(s).numero]>=alturas[i]){
            int tp = desapilar(s).numero;
            int ancho;
            if(esPilaVacia(s))
                ancho = i;
            else
                ancho = i - cima(s).numero-1; //Restar el indice de lo q esta en la pila
            int area = alturas[tp]*ancho;
            if(area>solucion)
                solucion = area;
        }
        ElementoPila temp{};
        temp.numero = i;
        apilar(s,temp);
    }
    return solucion;
}

/*
 * int jardin[4][4] = { 1,1,1,0,
                        1,1,1,0,
                        1,1,1,1,
                        1,1,1,0
                        }*/

int area_maxima_cortes(int **jardin, int n, int m) {
    int *alturas = new int[m]();  // inicializado en 0
    int mejor = 0;

    for (int i = 0; i < n; ++i) {
        // construir histograma de la fila i (consecutivos de 1s hacia arriba)
        for (int j = 0; j < m; ++j)
            alturas[j] = (jardin[i][j] == 1) ? alturas[j] + 1 : 0;

        cout << "Fila " << i << ": ";
        for (int j=0; j<m; ++j) cout << alturas[j] << " ";
        // mayor rectángulo en el histograma actual
        int area = calcular_max_area(alturas, m);
        cout<<"  AREA: "<<area<<endl;
        if (area > mejor) mejor = area;
    }

    delete[] alturas;
    return mejor;  // área máxima (en “sectores”)
}