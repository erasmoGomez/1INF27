//
// Created by Erasmo on 10/10/25.
//
#include <iostream>
#include "Posicion.hpp"
#include "FuncionesPilas.hpp"
#include "FuncionesLaberinto.hpp"
using namespace std;

#define PROBADA 3
#define RUTA 7

bool valida(int tablero[3][5], int fil, int col){
    bool resultado = false;
    /*dentro de los límites de la matriz*/
    if(fil >= 0 and fil < 3 and col >= 0 and col < 5)
        if(tablero[fil][col] == 1) /* no es pared y no ha sido probada*/
            resultado = true;
    return resultado;
}

bool laberinto(struct Pila & pila, int tablero[3][5], int fil, int col){

    struct Posicion pos;
    constructor(pos, fil, col);
    bool terminado = false;
    struct Posicion posAux;
    apilar(pila, pos); //Guardamos la primera posicion

    while(not terminado){

        pos = desapilar(pila);

        tablero[getX(pos)][getY(pos)] = PROBADA; /* ya ha sido probada*/
        //mostrar(tablero);
        if(getX(pos) == 2 and getY(pos) == 4) //verifica fin
            terminado = true;
        else{
            if(valida(tablero, getX(pos), getY(pos) + 1)){// derecha
                constructor(posAux, getX(pos), getY(pos) + 1);
                apilar(pila, posAux);
                tablero[getX(pos)][getY(pos)] = RUTA;
            }
            if(valida(tablero, getX(pos) -1 , getY(pos) )){ //arriba
                constructor(posAux, getX(pos) -1 , getY(pos));
                apilar(pila, posAux);
                tablero[getX(pos)][getY(pos)] = RUTA;
            }
            if(valida(tablero, getX(pos), getY(pos) - 1)){//izquierda
                constructor(posAux, getX(pos), getY(pos) - 1);
                apilar(pila, posAux);
                tablero[getX(pos)][getY(pos)] = RUTA;
            }
            if(valida(tablero, getX(pos) + 1, getY(pos))){//abajo
                constructor(posAux, getX(pos) + 1, getY(pos));
                apilar(pila, posAux);
                tablero[getX(pos)][getY(pos)] = RUTA;
            }

        }
        if(terminado)
            tablero[getX(pos)][getY(pos)] = RUTA;
    }
    return terminado;
}

void mostrar(int tablero[3][5]){

    for(int i = 0; i< 3; i++){
        for(int j = 0; j < 5; j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}