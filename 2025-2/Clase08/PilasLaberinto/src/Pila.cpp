//
// Created by Erasmo on 10/10/25.
//

/*
 * File:   funcionesPila.cpp
 * Author: Ana Roncal
 *
 * Created on 1 de setiembre de 2024, 22:30
 */

#include <iostream>
#include "Pila.hpp"
#include "FuncionesLista.hpp"
#include "FuncionesPilas.hpp"
#include "Posicion.hpp"
using namespace std;


/*constructor de Pila*/
void construir(struct Pila & pila){
    construir(pila.lista);
}

/*Determina si la pila está vacía*/
bool esPilaVacia(const struct Pila & pila){
    return esListaVacia(pila.lista);
}

/*Determina el número de elementos de la pila*/
int longitud(const struct Pila  & pila){
    return longitud(pila.lista);
}

/* Push, añade un elemento a la parte superior de la pila */
void apilar(struct Pila & pila, struct Posicion  elemento){
    insertarAlInicio(pila.lista, elemento);
    //cout<<"Apilando: "<<elemento<<endl;
}

/* Pop, elimina un elemento de la parte superior de la pila*/
struct Posicion  desapilar(struct Pila & pila){

    if (esPilaVacia(pila)){
        cout<<"La pila está vacía, por lo tanto no se puede desapilar"<<endl;
        exit(11); // valor de salida que indica que existe un error
    }

    struct Posicion  elemento = cima(pila);
    eliminaCabeza(pila.lista);
    return elemento;

}

/*examina un elemento situado en la parte superior de la pila*/
struct Posicion  cima(const struct Pila & pila){

    if (esPilaVacia(pila)){
        cout<<"La pila está vacía por lo tanto no posee cima"<<endl;
        exit(12); // valor de salida que indica que existe un error
    }
    return retornaCabeza(pila.lista);
}


/*destruye la pila*/
void destruirPila(struct Pila & pila){
    destruir(pila.lista);
}

/*Recordar que las Pilas no se recorren en forma secuencial*/
/*Se va utilizar solo para mostrar los valores*/
void imprimir(const struct Pila & pila){
    if(esPilaVacia(pila)){
        cout<<"La pila está vacía no se puede mostrar"<<endl;
    }
    else
        imprime(pila.lista);
}




