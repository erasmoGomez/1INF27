#include <iostream>
using namespace std;
#include "Biblioteca/Cola.h"
#include "Biblioteca/funcionesCola.h"
#include "Biblioteca/Pila.h"
#include "Biblioteca/funcionesPila.h"
void PasaPila(Pila & pila1, Pila & pila2) {
    Elemento auxiliar, elemento;
    int n;//me va a ayudar controlar la cantidad de elementos a desapilar/apilar

    while (!esPilaVacia(pila1)) {//Mientras tengamos elementos en la pila original
        auxiliar=desapilar(pila1);//"guardamos" el elemento para luego ponerlo en el orden final que queremos lograr
        n=0;
        while (!esPilaVacia(pila1)) {//Mientras tengamos elementos, desapilar
            apilar(pila2, auxiliar);//movemos de pila1 a pila2
            n++;//cuento los movimientos realizados
            auxiliar = desapilar(pila1);//sacamos de pila1 --- OJO CON ESTE MOVIMIENTO
        }
        while (n>0) {
            elemento = desapilar(pila2);
            apilar(pila1, elemento);//movemos de pila2 a pila1
            n--;
        }
        apilar(pila2, auxiliar);//Este elemento ya se va a encontrar en el orden final que queremos
        //que comenzó desde la línea 11 hasta la 16
    }
}
void PasaPilaRecursivo(Pila & pila1, Pila & pila2) {
    //CASO BASE
    if (esPilaVacia(pila1)) {return;}
    //PARTE RECURSIVA
    Elemento auxiliar;
    auxiliar=desapilar(pila1);
    PasaPilaRecursivo(pila1, pila2);
    apilar(pila2, auxiliar);
}


void OrdenaPila(Pila &pila1, Pila &pila2) {
    int longitud_pila = longitud(pila1);
    Elemento aux, mayor;
    int i, j;

    for (i = 0; i < longitud_pila; i++) {
        for (j = 0; j < longitud_pila - i; j++) {
            aux = desapilar(pila1);
            if (j == 0)
                mayor = aux;
            else {
                if ((aux.numero % 100) > (mayor.numero % 100)) {
                    apilar(pila2, mayor);
                    mayor = aux;
                } else {
                    apilar(pila2, aux);
                }
            }
        }
        // Colocamos el mayor encontrado nuevamente en pila1
        apilar(pila1, mayor);

        // Devolvemos los elementos de pila2 a pila1
        while (!esPilaVacia(pila2)) {
            aux = desapilar(pila2);
            apilar(pila1, aux);
        }
    }
}


void ReiniciaCola(Cola & cola, int n, Pila & pila1, Pila & pila2) {
    Elemento elemento;
    int longitud_pila1;
    int i;
    //Paso 1: Se pasan los nodos de Pila2 a Pila1.
    PasaPila(pila2, pila1);
    cout<<"Pasa Pila:"<<endl;
    cout<<"Cola: ";
    imprimir(cola);
    cout<<"Pila1: ";
    imprimir(pila1);
    cout<<"Pila2: ";
    imprimir(pila2);
    cout<<"Longitud Pila2: "<<longitud(pila2)<<endl;
    // Paso 2: Se ordena Pila1.
    OrdenaPila(pila1, pila2);
    // Paso 3:
    //  En azul: Se desencola y encola longitud Cola – longitud Pila1 espacios,
    cout<<"Ordena Pila:"<<endl;
    cout<<"Cola: ";
    imprimir(cola);
    cout<<"Pila1: ";
    imprimir(pila1);
    cout<<"Pila2: ";
    imprimir(pila2);
    cout<<endl;
    longitud_pila1=longitud(pila1);
    for (i=0; i<n-longitud_pila1;i++) {
        encolar(cola,desencolar(cola));
    }
    //seguidamente se desencola longitud Pila1 espacios y se apilan en Pila1.
    for (i=0; i<longitud_pila1; i++) {
        elemento=desencolar(cola);
        apilar(pila2, elemento);
    }
    //  En verde: Se encola longitud Pila1 espacios desde Pila1
    while (!esPilaVacia(pila1)) {
        encolar(cola,desapilar(pila1));
    }
    //  En anaranjado: Se desencola y encola longitud Cola – longitud Pila1 espacios.
    for (i=0; i<n-longitud_pila1;i++) {
        encolar(cola,desencolar(cola));
    }
    // En términos prácticos, se busca volver a tener los incidentes según orden de llegada, pero
    // como la cantidad excede la capacidad de la cola, se utiliza una de las pilas como “espacios”
    // temporales para los incidentes restantes.
}

int main() {
    Cola cola;
    int n = 8; //por enunciado, la cola sólo tiene 8 espacios
    Pila pila1, pila2;
    Elemento elemento_pila;
    Elemento elemento_cola;
    construir(cola);
    construir(pila1);
    construir(pila2);
    elemento_pila.numero = 101;
    apilar(pila1, elemento_pila);
    elemento_pila.numero = 102;
    apilar(pila1, elemento_pila);
    elemento_pila.numero = 203;
    apilar(pila2, elemento_pila);
    elemento_pila.numero = 204;
    apilar(pila2, elemento_pila);
    elemento_pila.numero = 105;
    apilar(pila1, elemento_pila);

    elemento_cola.numero = 206;
    encolar(cola, elemento_cola);
    elemento_cola.numero=107;
    encolar(cola, elemento_cola);
    elemento_cola.numero=208;
    encolar(cola, elemento_cola);
    elemento_cola.numero=109;
    encolar(cola, elemento_cola);
    elemento_cola.numero=210;
    encolar(cola, elemento_cola);
    elemento_cola.numero=211;
    encolar(cola, elemento_cola);
    elemento_cola.numero=112;
    encolar(cola, elemento_cola);
    elemento_cola.numero=113;
    encolar(cola, elemento_cola);
    cout<<"INICIAL:"<<endl;
    cout<<"Cola: ";
    imprimir(cola);
    cout<<"Pila1: ";
    imprimir(pila1);
    cout<<"Pila2: ";
    imprimir(pila2);
    cout<<endl;

    ReiniciaCola(cola, n, pila1, pila2);

    cout<<"REINICIA COLA:"<<endl;
    cout<<"Cola: ";
    imprimir(cola);
    cout<<"Pila1: ";
    imprimir(pila1);
    cout<<"Pila2: ";
    imprimir(pila2);

    return 0;
}
